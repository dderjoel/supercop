#ifndef NAMEMAPPING_H
#define NAMEMAPPING_H

#ifndef CRYPTO_NAMESPACE
#define CRYPTO_NAMESPACE(a) bc_##a
#endif

#define CN_IIFY(s) CRYPTO_NAMESPACE(s)

#define secp256k1_fe_mul_inner CRYPTO_NAMESPACE(fiat_secp256k1_dettman_mul)

#define secp256k1_fe_sqr_inner CRYPTO_NAMESPACE(secp256k1_sqr_mul_inner)

#endif
