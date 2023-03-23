#ifndef NAMEMAPPING_H
#define NAMEMAPPING_H

#ifndef CRYPTO_NAMESPACE
#define CRYPTO_NAMESPACE(x) abc_##x
#endif

#define Hacl_Curve25519_64_scalarmult                                          \
  CRYPTO_NAMESPACE(Hacl_Curve25519_64_scalarmult)
#define Hacl_Curve25519_64_secret_to_public                                    \
  CRYPTO_NAMESPACE(Hacl_Curve25519_64_secret_to_public)
#define Hacl_Curve25519_64_ecdh CRYPTO_NAMESPACE(Hacl_Curve25519_64_ecdh)
#define fiat_curve25519_solinas_mul2                                           \
  CRYPTO_NAMESPACE(fiat_curve25519_solinas_mul2)

#endif
