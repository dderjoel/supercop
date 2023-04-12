#ifndef ASM_OSSL_H
#define ASM_OSSL_H
#include "namemapping.h"
#include <stdint.h>

typedef uint64_t fe64[4];

int x25519_fe64_eligible(void);

typedef __int128_t int128_t;
typedef __uint128_t uint128_t;
typedef uint128_t u128;
// void x25519_fe64_mul(fe64 h, const fe64 f, const fe64 g);
void x25519_fe64_sqr(fe64 h, const fe64 f);
void x25519_fe64_mul121666(fe64 h, fe64 f);
void x25519_fe64_add(fe64 h, const fe64 f, const fe64 g);
void x25519_fe64_sub(fe64 h, const fe64 f, const fe64 g);
void x25519_fe64_tobytes(uint8_t *s, const fe64 f);

#endif