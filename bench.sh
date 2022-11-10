#!/usr/bin/env bash

# from do-part:12
shorthostname=$(hostname | sed 's/\..*//' | tr -cd '[a-z][A-Z][0-9]' | tr '[A-Z]' '[a-z]')

dir="./bench/${shorthostname}"
datafile="./bench/${shorthostname}/data"

reset_supercop_bench_dir() {
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
  # check if we need to initialize
  if ! test -d "${dir}/lib/amd64/" -o ! -r "fastrandombytes.o"; then
    reset_supercop_bench_dir
  fi

  for s in ${1}; do
    echo "doing work: crypto_scalarmult ${s} "
    taskset 1 ./do-part crypto_scalarmult "${s}" >/dev/null
    cp "${datafile}" "${datafile}.${s}"
    eval_data
  done
  cat "${datafile}".* >"${datafile}"
}

[[ $1 =~ eval ]] && eval_data && exit 0

todo=${1:-curve25519 secp256k1}
for i in ${todo}; do
  bench "${i}"
done

# bench curve25519
# bench secp256k1

exit 0
