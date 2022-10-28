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

#define fe64_sqr x25519_fe64_sqr
#define fe64_mul121666 x25519_fe64_mul121666
#define fe64_add x25519_fe64_add
#define fe64_sub x25519_fe64_sub
#define fe64_tobytes x25519_fe64_tobytes

// to use the correct implementation
#ifndef __BMI2__
#define __BMI2__
#endif

#ifndef __ADX__
#define __ADX__
#endif

#endif
