#include "api.h"
#include "crypto_scalarmult.h"
#include "secp256k1.h"

#include "ecmult_gen_impl.h"
#include "ecmult_impl.h"
#include <stdint.h>

// from secp256k1.c
struct secp256k1_context_struct {
  secp256k1_ecmult_gen_context ecmult_gen_ctx;
  secp256k1_callback illegal_callback;
  secp256k1_callback error_callback;
  int declassify;
};

void store(unsigned char *o, secp256k1_gej *e) {

  // jac->affin
  secp256k1_ge r;
  secp256k1_ge_set_gej(&r, e);
  secp256k1_fe_normalize(&r.x);
  secp256k1_fe_normalize(&r.y);

  secp256k1_ge_storage r_store;
  secp256k1_ge_to_storage(&r_store, &r);

  memcpy(o, &r_store, sizeof(secp256k1_ge_storage));
}
int crypto_scalarmult(uint8_t out[CRYPTO_BYTES],
                      const uint8_t scalar[CRYPTO_SCALARBYTES],
                      const uint8_t point[CRYPTO_BYTES]) {

  // load
  secp256k1_ge_storage ge_store;
  memcpy(&ge_store, point, sizeof(secp256k1_ge_storage));
  secp256k1_ge ge;
  secp256k1_ge_from_storage(&ge, &ge_store);

  secp256k1_gej gej;
  secp256k1_gej_set_ge(&gej, &ge);

  secp256k1_scalar gn;
  if (!secp256k1_scalar_set_b32_seckey(&gn, scalar)) {
    exit(3);
  }
  secp256k1_gej prj;
  // calcs  r = a*na + g*ng
  /** static void secp256k1_ecmult(secp256k1_gej *r, const secp256k1_gej *a,
   * const secp256k1_scalar *na, const secp256k1_scalar *ng) { */

  secp256k1_ecmult(&prj, &gej, &gn, NULL);

  store(out, &prj);
  return 0;
}
int crypto_scalarmult_base(unsigned char out[CRYPTO_BYTES],
                           const uint8_t scalar[CRYPTO_SCALARBYTES]) {
  // get context
  secp256k1_context *ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN |
                                                    SECP256K1_CONTEXT_VERIFY);

  secp256k1_scalar gn;
  if (!secp256k1_scalar_set_b32_seckey(&gn, scalar)) {
    exit(3);
  }
  // rp = G*gn
  secp256k1_gej rp;
  secp256k1_ecmult_gen(&ctx->ecmult_gen_ctx, &rp, &gn);

  store(out, &rp);
  return 0;
}
