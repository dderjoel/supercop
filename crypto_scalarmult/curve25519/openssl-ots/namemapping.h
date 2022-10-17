#ifndef NAMEMAPPING_H
#define NAMEMAPPING_H
#include <stdint.h>
typedef uint64_t fe51[5];

#ifndef CRYPTO_NAMESPACE
#define CRYPTO_NAMESPACE(a) bc_##a
#endif

#define fe51_mul CRYPTO_NAMESPACE(x25519_fe51_mul)
#define fe51_sq CRYPTO_NAMESPACE(x25519_fe51_sqr)
#define fe51_mul121666 CRYPTO_NAMESPACE(x25519_fe51_mul121666)
void CRYPTO_NAMESPACE(x25519_fe51_mul)(fe51 h, const fe51 f, const fe51 g);
void CRYPTO_NAMESPACE(x25519_fe51_sqr)(fe51 h, const fe51 f);
void CRYPTO_NAMESPACE(x25519_fe51_mul121666)(fe51 h, fe51 f);
#endif
