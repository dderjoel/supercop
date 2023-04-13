#ifndef DETTMANN_H
#define DETTMANN_H

#include "namemapping.h"
#include <stdint.h>

void fiat_secp256k1_dettman_mul(uint64_t out1[5], const uint64_t arg1[5],
                                const uint64_t arg2[5]);
void fiat_secp256k1_dettman_square(uint64_t out1[5], const uint64_t arg1[5]);
#endif
