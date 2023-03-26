#ifndef CRYPTIOPT_H
#define CRYPTIOPT_H
#include <stdint.h>

#include "namemapping.h"
void fiat_curve25519_solinas_mul(uint64_t out1[4], const uint64_t arg1[4],
                                 const uint64_t arg2[4]);
void fiat_curve25519_solinas_square(uint64_t out1[4], const uint64_t arg1[4]);
#endif
