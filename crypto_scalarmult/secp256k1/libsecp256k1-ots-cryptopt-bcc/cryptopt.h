#ifndef CRYPTOPT_H
#define CRYPTOPT_H

#include "namemapping.h"
#include <stdint.h>

void secp256k1_fe_sqr_inner(uint64_t *r, const uint64_t *a);
void secp256k1_fe_mul_inner(uint64_t *r, const uint64_t *a, const uint64_t *b);
#endif
