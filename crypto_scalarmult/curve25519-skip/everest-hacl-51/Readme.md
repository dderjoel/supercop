see everest-hacl-64

`FStar_Uint_8_16_32_64.h` from `dist/karamel/krmlib/dist/minimal/`

`Hacl_Curve25519_51_scalarmult` in  `./dist/gcc64-only/Hacl_Curve25519_51_.c`
calls `montgomery_ladder` in  `Hacl_Curve25519_51.c`


calls `point_add_and_double` in `Hacl_Curve25519_51.c`
calls `Hacl_Impl_Curve25519_Field51_f{add,sub,mul2,mul1,mul}` in `Hacl_Bignum25519_51.h` (which is C)
Also those are functions which multiply 2 fe by 2 fe in parallel to get 2 result fe's

