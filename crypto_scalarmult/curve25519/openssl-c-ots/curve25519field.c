#include "curve25519field.h"
#include "namemapping.h"
#include <stdint.h>
typedef uint64_t fe51[5];
static const uint64_t MASK51 = 0x7ffffffffffff;
typedef __int128_t int128_t;
typedef __uint128_t uint128_t;
typedef uint128_t u128;

void fe51_mul(fe51 h, const fe51 f, const fe51 g) {
  u128 h0, h1, h2, h3, h4;
  uint64_t f_i, g0, g1, g2, g3, g4;

  f_i = f[0];
  h0 = (u128)f_i * (g0 = g[0]);
  h1 = (u128)f_i * (g1 = g[1]);
  h2 = (u128)f_i * (g2 = g[2]);
  h3 = (u128)f_i * (g3 = g[3]);
  h4 = (u128)f_i * (g4 = g[4]);

  f_i = f[1];
  h0 += (u128)f_i * (g4 *= 19);
  h1 += (u128)f_i * g0;
  h2 += (u128)f_i * g1;
  h3 += (u128)f_i * g2;
  h4 += (u128)f_i * g3;

  f_i = f[2];
  h0 += (u128)f_i * (g3 *= 19);
  h1 += (u128)f_i * g4;
  h2 += (u128)f_i * g0;
  h3 += (u128)f_i * g1;
  h4 += (u128)f_i * g2;

  f_i = f[3];
  h0 += (u128)f_i * (g2 *= 19);
  h1 += (u128)f_i * g3;
  h2 += (u128)f_i * g4;
  h3 += (u128)f_i * g0;
  h4 += (u128)f_i * g1;

  f_i = f[4];
  h0 += (u128)f_i * (g1 *= 19);
  h1 += (u128)f_i * g2;
  h2 += (u128)f_i * g3;
  h3 += (u128)f_i * g4;
  h4 += (u128)f_i * g0;

  /* partial [lazy] reduction */
  h3 += (uint64_t)(h2 >> 51);
  g2 = (uint64_t)h2 & MASK51;
  h1 += (uint64_t)(h0 >> 51);
  g0 = (uint64_t)h0 & MASK51;

  h4 += (uint64_t)(h3 >> 51);
  g3 = (uint64_t)h3 & MASK51;
  g2 += (uint64_t)(h1 >> 51);
  g1 = (uint64_t)h1 & MASK51;

  g0 += (uint64_t)(h4 >> 51) * 19;
  g4 = (uint64_t)h4 & MASK51;
  g3 += g2 >> 51;
  g2 &= MASK51;
  g1 += g0 >> 51;
  g0 &= MASK51;

  h[0] = g0;
  h[1] = g1;
  h[2] = g2;
  h[3] = g3;
  h[4] = g4;
}

void fe51_sq(fe51 h, const fe51 f) {
#if defined(OPENSSL_SMALL_FOOTPRINT)
  fe51_mul(h, f, f);
#else
  /* dedicated squaring gives 16-25% overall improvement */
  uint64_t g0 = f[0];
  uint64_t g1 = f[1];
  uint64_t g2 = f[2];
  uint64_t g3 = f[3];
  uint64_t g4 = f[4];
  u128 h0, h1, h2, h3, h4;

  h0 = (u128)g0 * g0;
  g0 *= 2;
  h1 = (u128)g0 * g1;
  h2 = (u128)g0 * g2;
  h3 = (u128)g0 * g3;
  h4 = (u128)g0 * g4;

  g0 = g4; /* borrow g0 */
  h3 += (u128)g0 * (g4 *= 19);

  h2 += (u128)g1 * g1;
  g1 *= 2;
  h3 += (u128)g1 * g2;
  h4 += (u128)g1 * g3;
  h0 += (u128)g1 * g4;

  g0 = g3; /* borrow g0 */
  h1 += (u128)g0 * (g3 *= 19);
  h2 += (u128)(g0 * 2) * g4;

  h4 += (u128)g2 * g2;
  g2 *= 2;
  h0 += (u128)g2 * g3;
  h1 += (u128)g2 * g4;

  /* partial [lazy] reduction */
  h3 += (uint64_t)(h2 >> 51);
  g2 = (uint64_t)h2 & MASK51;
  h1 += (uint64_t)(h0 >> 51);
  g0 = (uint64_t)h0 & MASK51;

  h4 += (uint64_t)(h3 >> 51);
  g3 = (uint64_t)h3 & MASK51;
  g2 += (uint64_t)(h1 >> 51);
  g1 = (uint64_t)h1 & MASK51;

  g0 += (uint64_t)(h4 >> 51) * 19;
  g4 = (uint64_t)h4 & MASK51;
  g3 += g2 >> 51;
  g2 &= MASK51;
  g1 += g0 >> 51;
  g0 &= MASK51;

  h[0] = g0;
  h[1] = g1;
  h[2] = g2;
  h[3] = g3;
  h[4] = g4;
#endif
}
void fe51_mul121666(fe51 h, fe51 f) {
  u128 h0 = f[0] * (u128)121666;
  u128 h1 = f[1] * (u128)121666;
  u128 h2 = f[2] * (u128)121666;
  u128 h3 = f[3] * (u128)121666;
  u128 h4 = f[4] * (u128)121666;
  uint64_t g0, g1, g2, g3, g4;

  h3 += (uint64_t)(h2 >> 51);
  g2 = (uint64_t)h2 & MASK51;
  h1 += (uint64_t)(h0 >> 51);
  g0 = (uint64_t)h0 & MASK51;

  h4 += (uint64_t)(h3 >> 51);
  g3 = (uint64_t)h3 & MASK51;
  g2 += (uint64_t)(h1 >> 51);
  g1 = (uint64_t)h1 & MASK51;

  g0 += (uint64_t)(h4 >> 51) * 19;
  g4 = (uint64_t)h4 & MASK51;
  g3 += g2 >> 51;
  g2 &= MASK51;
  g1 += g0 >> 51;
  g0 &= MASK51;

  h[0] = g0;
  h[1] = g1;
  h[2] = g2;
  h[3] = g3;
  h[4] = g4;
}
