#ifndef NAMEMAPPING_H
#define NAMEMAPPING_H

#ifndef CRYPTO_NAMESPACE
#define CRYPTO_NAMESPACE(x) abc_##x
#endif

#define Hacl_Curve25519_51_scalarmult                                          \
  CRYPTO_NAMESPACE(Hacl_Curve25519_51_scalarmult)
#define Hacl_Curve25519_51_secret_to_public                                    \
  CRYPTO_NAMESPACE(Hacl_Curve25519_51_secret_to_public)
#define Hacl_Curve25519_51_ecdh CRYPTO_NAMESPACE(Hacl_Curve25519_51_ecdh)

#endif
