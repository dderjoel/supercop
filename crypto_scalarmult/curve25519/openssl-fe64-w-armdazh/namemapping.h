#ifndef NAMEMAPPING_H
#define NAMEMAPPING_H

#ifndef CRYPTO_NAMESPACE
#define CRYPTO_NAMESPACE(a) bc_##a
#endif

// used in the function

// #define mul_EltFp25519_1w_x64 CRYPTO_NAMESPACE(mul_EltFp25519_1w_x64)

#define x25519_fe64_sqr CRYPTO_NAMESPACE(x25519_fe64_sqr)
#define x25519_fe64_mul121666 CRYPTO_NAMESPACE(x25519_fe64_mul121666)
#define x25519_fe64_add CRYPTO_NAMESPACE(x25519_fe64_add)
#define x25519_fe64_sub CRYPTO_NAMESPACE(x25519_fe64_sub)
#define x25519_fe64_tobytes CRYPTO_NAMESPACE(x25519_fe64_tobytes)

// to use the correct implementation
#define __BMI2__
#define __ADX__

#endif
