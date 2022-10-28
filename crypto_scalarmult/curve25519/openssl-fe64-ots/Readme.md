- The `base.c` is based on `openssl/crypto/ec/curve25519.c`'s method `x25519_scalar_mult(out, scalar, point)`.
- It only specifies methods, to call `x25519_scalar_mult`, which is essentially scmult.
- `base.c` declares `x25519_fe64_{mul,sqr,mult121665}`, which are in the `asm_ossl.S` file.
- `asm_ossl.S` is created by calling `CC=gcc ./x25519-x86_64.pl asm_ossl.S`, which needs `x86_64-xlate.pl`

- `./x25519-xlate.pl` is from `openssl/crypto/ec/asm`, the `x86_64-xlate.pl` from `openssl/crypto/perlasm`


