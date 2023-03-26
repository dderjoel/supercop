#include "crypto_scalarmult.h"
#include "namemapping.h"
#include <stdint.h>
#include <string.h>

int crypto_scalarmult(uint8_t out[32], const uint8_t scalar[32],
                      const uint8_t point[32]);

// 32 bytes = 4*8
int crypto_scalarmult_base(unsigned char *q, const unsigned char *n) {
  unsigned char basepoint[32] = {9};
  return crypto_scalarmult(q, n, basepoint);
};

/** openssl/crypto/ec/curve25519.c */
/*
 * Duplicate of original x25519_scalar_mult_generic, but using
 * fe51_* subroutines.
 */

typedef uint64_t fe51[5];
static const uint64_t MASK51 = 0x7ffffffffffff;

static void fe51_add(fe51 h, const fe51 f, const fe51 g) {
  h[0] = f[0] + g[0];
  h[1] = f[1] + g[1];
  h[2] = f[2] + g[2];
  h[3] = f[3] + g[3];
  h[4] = f[4] + g[4];
}

static void fe51_sub(fe51 h, const fe51 f, const fe51 g) {
  /*
   * Add 2*modulus to ensure that result remains positive
   * even if subtrahend is partially reduced.
   */
  h[0] = (f[0] + 0xfffffffffffda) - g[0];
  h[1] = (f[1] + 0xffffffffffffe) - g[1];
  h[2] = (f[2] + 0xffffffffffffe) - g[2];
  h[3] = (f[3] + 0xffffffffffffe) - g[3];
  h[4] = (f[4] + 0xffffffffffffe) - g[4];
}
static void fe51_0(fe51 h) {
  h[0] = 0;
  h[1] = 0;
  h[2] = 0;
  h[3] = 0;
  h[4] = 0;
}

static void fe51_1(fe51 h) {
  h[0] = 1;
  h[1] = 0;
  h[2] = 0;
  h[3] = 0;
  h[4] = 0;
}

static void fe51_copy(fe51 h, const fe51 f) {
  h[0] = f[0];
  h[1] = f[1];
  h[2] = f[2];
  h[3] = f[3];
  h[4] = f[4];
}
static uint64_t load_7(const uint8_t *in) {
  uint64_t result;

  result = in[0];
  result |= ((uint64_t)in[1]) << 8;
  result |= ((uint64_t)in[2]) << 16;
  result |= ((uint64_t)in[3]) << 24;
  result |= ((uint64_t)in[4]) << 32;
  result |= ((uint64_t)in[5]) << 40;
  result |= ((uint64_t)in[6]) << 48;

  return result;
}

static uint64_t load_6(const uint8_t *in) {
  uint64_t result;

  result = in[0];
  result |= ((uint64_t)in[1]) << 8;
  result |= ((uint64_t)in[2]) << 16;
  result |= ((uint64_t)in[3]) << 24;
  result |= ((uint64_t)in[4]) << 32;
  result |= ((uint64_t)in[5]) << 40;

  return result;
}
static void fe51_frombytes(fe51 h, const uint8_t *s) {
  uint64_t h0 = load_7(s);                              /* 56 bits */
  uint64_t h1 = load_6(s + 7) << 5;                     /* 53 bits */
  uint64_t h2 = load_7(s + 13) << 2;                    /* 58 bits */
  uint64_t h3 = load_6(s + 20) << 7;                    /* 55 bits */
  uint64_t h4 = (load_6(s + 26) & 0x7fffffffffff) << 4; /* 51 bits */

  h1 |= h0 >> 51;
  h0 &= MASK51;
  h2 |= h1 >> 51;
  h1 &= MASK51;
  h3 |= h2 >> 51;
  h2 &= MASK51;
  h4 |= h3 >> 51;
  h3 &= MASK51;

  h[0] = h0;
  h[1] = h1;
  h[2] = h2;
  h[3] = h3;
  h[4] = h4;
}

static void fe51_tobytes(uint8_t *s, const fe51 h) {
  uint64_t h0 = h[0];
  uint64_t h1 = h[1];
  uint64_t h2 = h[2];
  uint64_t h3 = h[3];
  uint64_t h4 = h[4];
  uint64_t q;

  /* compare to modulus */
  q = (h0 + 19) >> 51;
  q = (h1 + q) >> 51;
  q = (h2 + q) >> 51;
  q = (h3 + q) >> 51;
  q = (h4 + q) >> 51;

  /* full reduce */
  h0 += 19 * q;
  h1 += h0 >> 51;
  h0 &= MASK51;
  h2 += h1 >> 51;
  h1 &= MASK51;
  h3 += h2 >> 51;
  h2 &= MASK51;
  h4 += h3 >> 51;
  h3 &= MASK51;
  h4 &= MASK51;

  /* smash */
  s[0] = (uint8_t)(h0 >> 0);
  s[1] = (uint8_t)(h0 >> 8);
  s[2] = (uint8_t)(h0 >> 16);
  s[3] = (uint8_t)(h0 >> 24);
  s[4] = (uint8_t)(h0 >> 32);
  s[5] = (uint8_t)(h0 >> 40);
  s[6] = (uint8_t)((h0 >> 48) | ((uint32_t)h1 << 3));
  s[7] = (uint8_t)(h1 >> 5);
  s[8] = (uint8_t)(h1 >> 13);
  s[9] = (uint8_t)(h1 >> 21);
  s[10] = (uint8_t)(h1 >> 29);
  s[11] = (uint8_t)(h1 >> 37);
  s[12] = (uint8_t)((h1 >> 45) | ((uint32_t)h2 << 6));
  s[13] = (uint8_t)(h2 >> 2);
  s[14] = (uint8_t)(h2 >> 10);
  s[15] = (uint8_t)(h2 >> 18);
  s[16] = (uint8_t)(h2 >> 26);
  s[17] = (uint8_t)(h2 >> 34);
  s[18] = (uint8_t)(h2 >> 42);
  s[19] = (uint8_t)((h2 >> 50) | ((uint32_t)h3 << 1));
  s[20] = (uint8_t)(h3 >> 7);
  s[21] = (uint8_t)(h3 >> 15);
  s[22] = (uint8_t)(h3 >> 23);
  s[23] = (uint8_t)(h3 >> 31);
  s[24] = (uint8_t)(h3 >> 39);
  s[25] = (uint8_t)((h3 >> 47) | ((uint32_t)h4 << 4));
  s[26] = (uint8_t)(h4 >> 4);
  s[27] = (uint8_t)(h4 >> 12);
  s[28] = (uint8_t)(h4 >> 20);
  s[29] = (uint8_t)(h4 >> 28);
  s[30] = (uint8_t)(h4 >> 36);
  s[31] = (uint8_t)(h4 >> 44);
}

static void fe51_invert(fe51 out, const fe51 z) {
  fe51 t0;
  fe51 t1;
  fe51 t2;
  fe51 t3;
  int i;

  /*
   * Compute z ** -1 = z ** (2 ** 255 - 19 - 2) with the exponent as
   * 2 ** 255 - 21 = (2 ** 5) * (2 ** 250 - 1) + 11.
   */

  /* t0 = z ** 2 */
  fe51_sq(t0, z);

  /* t1 = t0 ** (2 ** 2) = z ** 8 */
  fe51_sq(t1, t0);
  fe51_sq(t1, t1);

  /* t1 = z * t1 = z ** 9 */
  fe51_mul(t1, z, t1);
  /* t0 = t0 * t1 = z ** 11 -- stash t0 away for the end. */
  fe51_mul(t0, t0, t1);

  /* t2 = t0 ** 2 = z ** 22 */
  fe51_sq(t2, t0);

  /* t1 = t1 * t2 = z ** (2 ** 5 - 1) */
  fe51_mul(t1, t1, t2);

  /* t2 = t1 ** (2 ** 5) = z ** ((2 ** 5) * (2 ** 5 - 1)) */
  fe51_sq(t2, t1);
  for (i = 1; i < 5; ++i)
    fe51_sq(t2, t2);

  /* t1 = t1 * t2 = z ** ((2 ** 5 + 1) * (2 ** 5 - 1)) = z ** (2 ** 10 - 1) */
  fe51_mul(t1, t2, t1);

  /* Continuing similarly... */

  /* t2 = z ** (2 ** 20 - 1) */
  fe51_sq(t2, t1);
  for (i = 1; i < 10; ++i)
    fe51_sq(t2, t2);

  fe51_mul(t2, t2, t1);

  /* t2 = z ** (2 ** 40 - 1) */
  fe51_sq(t3, t2);
  for (i = 1; i < 20; ++i)
    fe51_sq(t3, t3);

  fe51_mul(t2, t3, t2);

  /* t2 = z ** (2 ** 10) * (2 ** 40 - 1) */
  for (i = 0; i < 10; ++i)
    fe51_sq(t2, t2);

  /* t1 = z ** (2 ** 50 - 1) */
  fe51_mul(t1, t2, t1);

  /* t2 = z ** (2 ** 100 - 1) */
  fe51_sq(t2, t1);
  for (i = 1; i < 50; ++i)
    fe51_sq(t2, t2);

  fe51_mul(t2, t2, t1);

  /* t2 = z ** (2 ** 200 - 1) */
  fe51_sq(t3, t2);
  for (i = 1; i < 100; ++i)
    fe51_sq(t3, t3);

  fe51_mul(t2, t3, t2);

  /* t2 = z ** ((2 ** 50) * (2 ** 200 - 1) */
  for (i = 0; i < 50; ++i)
    fe51_sq(t2, t2);

  /* t1 = z ** (2 ** 250 - 1) */
  fe51_mul(t1, t2, t1);

  /* t1 = z ** ((2 ** 5) * (2 ** 250 - 1)) */
  for (i = 0; i < 5; ++i)
    fe51_sq(t1, t1);

  /* Recall t0 = z ** 11; out = z ** (2 ** 255 - 21) */
  fe51_mul(out, t1, t0);
}
static void fe51_cswap(fe51 f, fe51 g, unsigned int b) {
  int i;
  uint64_t mask = 0 - (uint64_t)b;

  for (i = 0; i < 5; i++) {
    int64_t x = f[i] ^ g[i];
    x &= mask;
    f[i] ^= x;
    g[i] ^= x;
  }
}

static void x25519_scalar_mult(uint8_t out[32], const uint8_t scalar[32],
                               const uint8_t point[32]) {
  fe51 x1, x2, z2, x3, z3, tmp0, tmp1;
  uint8_t e[32];
  unsigned swap = 0;
  int pos;

  memcpy(e, scalar, 32);
  e[0] &= 0xf8;
  e[31] &= 0x7f;
  e[31] |= 0x40;
  fe51_frombytes(x1, point);
  fe51_1(x2);
  fe51_0(z2);
  fe51_copy(x3, x1);
  fe51_1(z3);

  for (pos = 254; pos >= 0; --pos) {
    unsigned int b = 1 & (e[pos / 8] >> (pos & 7));

    swap ^= b;
    fe51_cswap(x2, x3, swap);
    fe51_cswap(z2, z3, swap);
    swap = b;
    fe51_sub(tmp0, x3, z3);
    fe51_sub(tmp1, x2, z2);
    fe51_add(x2, x2, z2);
    fe51_add(z2, x3, z3);
    fe51_mul(z3, tmp0, x2);
    fe51_mul(z2, z2, tmp1);
    fe51_sq(tmp0, tmp1);
    fe51_sq(tmp1, x2);
    fe51_add(x3, z3, z2);
    fe51_sub(z2, z3, z2);
    fe51_mul(x2, tmp1, tmp0);
    fe51_sub(tmp1, tmp1, tmp0);
    fe51_sq(z2, z2);
    fe51_mul121666(z3, tmp1);
    fe51_sq(x3, x3);
    fe51_add(tmp0, tmp0, z3);
    fe51_mul(z3, x1, z2);
    fe51_mul(z2, tmp1, tmp0);
  }

  fe51_invert(z2, z2);
  fe51_mul(x2, x2, z2);
  fe51_tobytes(out, x2);

  /** OPENSSL_cleanse(e, sizeof(e)); */
}
int crypto_scalarmult(uint8_t out[32], const uint8_t scalar[32],
                      const uint8_t point[32]) {
  x25519_scalar_mult(out, scalar, point);
  return 0;
}
