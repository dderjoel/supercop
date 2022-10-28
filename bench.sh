#!/usr/bin/env bash

overwritelib() {
  abi=amd64
  libfile_open=libopen.so.3
  libfile_boring=libboring.so

  echo overwriting libs to include ${libfile_open} and ${libfile_boring}
  sudo cp /mnt/pil/openssl/libcrypto.so.3 /usr/local/lib/${libfile_open}
  sudo cp /mnt/pil/boringssl/build/crypto/libcrypto.so /usr/local/lib/${libfile_boring}
  sudo ldconfig

  cat >"${dir}/bin/oklibs-${abi}" <<EOF
#!/bin/bash

# to link against openssl3
[[ "\$1" =~ "openssl" ]] && echo "-l:${libfile_open} -lnsl -lm " && exit 0

# to link against boringssl
[[ "\$1" =~ "boring" ]] && echo "-l:${libfile_boring} -lnsl -lm " && exit 0

# default
echo "-lcrypto -lnsl -lm "
EOF

  link_ossl_include

}

link_ossl_include() {
  echo linking ossl includes
  # this is, in order to get the openssl.3 includes
  ln -s /mnt/pil/openssl/include/openssl "${dir}/include/openssl"
}

reset_supercop_bench_dir() {
  # set -e
  ./do-part init

  #indpendent
  ./do-part crypto_verify 32
  ./do-part crypto_core salsa20
  ./do-part crypto_stream aes256ctr
  ./do-part cryptopp

  #needs cryptopp
  ./do-part crypto_stream chacha20

  # needs core_salsa20
  ./do-part crypto_stream salsa20

  # needs stream{aes256ctr,chacha20,salsa20}
  ./do-part crypto_rng

  # set +e
  # overwritelib
}
eval_data() {
  grep -e '\(ok\|unknown\) ' "${datafile}" |
    sed -re 's/^.*(ok|unknown) ([[:digit:]]+)( [[:digit:]]+){2} ([[:graph:]_]+\/){2}/\2 /' -e 's/(-O.).*$/\1/' -e 's@/mnt/pil/clang13/bin/clang@clang13@g' |
    sort -g |
    awk '{print $2 " (" $3 ") " $1}' |
    xargs printf '%20s %40s %20s\n' |
    sed -e 's/_/ /g' -e "s/\\(.*\\).../\\1k cycles/"
}

bench() {
  # curve25519
  # p256

  for s in ${1:-curve25519 p256}; do
    echo "doing work: crypto_scalarmult ${s} "
    taskset 2 ./do-part crypto_scalarmult "${s}" >/dev/null
    cp "${datafile}" "${datafile}.${s}"
    eval_data
  done
  cat "${datafile}".* >"${datafile}"
}

# from do-part:12
shorthostname=$(hostname | sed 's/\..*//' | tr -cd '[a-z][A-Z][0-9]' | tr '[A-Z]' '[a-z]')
dir="./bench/${shorthostname}"
datafile="./bench/${shorthostname}/data"
[[ $1 =~ reset ]] && reset_supercop_bench_dir && exit 0
# [[ $1 =~ lib ]] && overwritelib && exit 0

[[ $1 =~ eval ]] && eval_data && exit 0

todo=${1:-curve25519}
for i in ${todo}; do
  bench "${i}"
done

# bench curve25519
# bench p256
# bench secp256k1
# bench everest
exit 0
# bench p384

# ./do-part crypto_scalarmult p256 && eval_data
# ./do-part crypto_sign ecdonaldp256
# eval_data
