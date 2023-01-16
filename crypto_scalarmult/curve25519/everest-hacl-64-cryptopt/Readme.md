see everest-hacl-64

`curve25519-inline.h` no longer defines `fmul2`
in `Hacl_Curve25519_64.c`:70, we now call `fiat_curve25519_solinas_mul2`

`do` uses a different folder
