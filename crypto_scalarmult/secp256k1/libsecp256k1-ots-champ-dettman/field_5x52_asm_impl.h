#ifndef SECP256K1_FIELD_INNER5X52_IMPL_H
#define SECP256K1_FIELD_INNER5X52_IMPL_H

#include "namemapping.h"
#include <stdint.h>

void secp256k1_fe_mul_inner(uint64_t *r, const uint64_t *a, const uint64_t *b);

void secp256k1_fe_sqr_inner(uint64_t *r, const uint64_t *a);

#endif /* SECP256K1_FIELD_INNER5X52_IMPL_H */
