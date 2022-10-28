#include "crypto_scalarmult.h"
#include "libeverest.h"
#include <stdint.h>
#include <string.h>

int crypto_scalarmult(uint8_t out[32], const uint8_t scalar[32],
                      const uint8_t point[32]);

// 32 bytes = 4*8
int crypto_scalarmult_base(unsigned char *q, const unsigned char *n) {
  unsigned char basepoint[32] = {9};
  return crypto_scalarmult(q, n, basepoint);
};

int crypto_scalarmult(uint8_t out[32], const uint8_t scalar[32],
                      const uint8_t point[32]) {
  Hacl_Curve25519_51_scalarmult(out, scalar, point);

  return 0;
}
