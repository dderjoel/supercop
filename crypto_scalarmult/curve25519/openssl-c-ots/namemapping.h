#ifndef NAMEMAPPING_H
#define NAMEMAPPING_H

#ifndef CRYPTO_NAMESPACE
#define CRYPTO_NAMESPACE(x) abc_##x
#endif
#define fe51_mul CRYPTO_NAMESPACE(fe51_mul)
#define fe51_sq CRYPTO_NAMESPACE(fe51_sq)
#define fe51_mul121666 CRYPTO_NAMESPACE(fe51_mul121666)
#endif
