#ifndef NAMEMAPPING_H
#define NAMEMAPPING_H

#ifndef CRYPTO_NAMESPACE
#define CRYPTO_NAMESPACE(a) bc_##a
#endif

// used in the function
#define x25519_fe64_mul CRYPTO_NAMESPACE(x25519_fe64_mul)
#define x25519_fe64_sqr CRYPTO_NAMESPACE(x25519_fe64_sqr)
#define x25519_fe64_mul121666 CRYPTO_NAMESPACE(x25519_fe64_mul121666)
#define x25519_fe64_add CRYPTO_NAMESPACE(x25519_fe64_add)
#define x25519_fe64_sub CRYPTO_NAMESPACE(x25519_fe64_sub)
#define x25519_fe64_tobytes CRYPTO_NAMESPACE(x25519_fe64_tobytes)

#endif
