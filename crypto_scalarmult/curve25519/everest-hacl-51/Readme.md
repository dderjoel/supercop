- declaring the needed method in `./libeverest.h`

https://project-everest.github.io/
- to get `./libeverest.a`
1. `docker run -i -t projecteverest/everest-linux:foobar /bin/bash --login`
1. copying file `docker cp  b0549396f006:/home/test/hacl-start/dist/gcc64-only/libevercrypt.a .` (or whatever hash the container has)


`Hacl_Curve25519_64_scalarmult` in  `./dist/gcc64-only/Hacl_Curve25519_64_.c`
calls `montgomery_ladder` in  `Hacl_Curve25519_64.c`
calls `point_add_and_double` in `Hacl_Curve25519_64.c`
calls `fsqr20` in `Hacl_Curve25519_64.c`
which maps to `fsqr2`  in `dist/vale/curve25519-inline.h` which looks like hand optimized assembly.
Also those are functions which multiply 2 fe by 2 fe in parallel to get 2 result fe's

