#ifndef CRYPTOPT_H
#define CRYPTOPT_H

#include "curve25519_solinas.h"
#include "namemapping.h"
#include <stdint.h>

typedef uint64_t fe64[4];

void fiat_curve25519_solinas_mulmod(fe64 h, const fe64 f, const fe64 g);

#endif