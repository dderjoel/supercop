#include "cryptopt.h"
void fiat_curve25519_solinas_sqrmod(fe64 h, const fe64 f) {
  return fiat_curve25519_solinas_mulmod(h, f, f);
};
