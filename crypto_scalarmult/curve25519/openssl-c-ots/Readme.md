TBD
usually there is the pl file generating the asm for CRYPTO_NAMESPACE(x25519_fe51_mul)
but there is C nor that in ec/curve25519.c
in this folder (openssl-c-ots), we use that instead of the asm.






















- The `base.c` is based on `openssl/crypto/ec/curve25519.c`'s method `x25519_scalar_mult(out, scalar, point)`.
- It only specifies methods, to call `x25519_scalar_mult`, which is essentially scmult.
- `base.c` declares `x25519_fe51_{mul,sqr,mult121665}`, which are in the `asm.s` file.
- `asm.s` is created by calling `./x25519-x86_64.pl > asm.s`, which needs `x86_64-xlate.pl`

- `./x25519-xlate.pl` is from `openssl/crypto/ec/asm`, the `x86_64-xlate.pl` from `openssl/crypto/perlasm`



