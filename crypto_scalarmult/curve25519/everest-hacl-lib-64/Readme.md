see everest-hacl-64

`FStar_Uint_8_16_32_64.h` from `dist/karamel/krmlib/dist/minimal/`

`Hacl_Curve25519_64_scalarmult` in  `./dist/gcc64-only/Hacl_Curve25519_64_.c`
calls `montgomery_ladder` in  `Hacl_Curve25519_64.c`


calls `point_add_and_double` in `Hacl_Curve25519_64.c`
calls `fadd0` and stuff from `curve25519-inline.h`
Also those are functions which multiply 2 fe by 2 fe in parallel to get 2 result fe's


the `add_scalar_e` functions are declared in `./internal/Vale.h` but shall not be used
could be imported from `./hacl-star/dist/vale/curve25519-x86_64-linux.S`
