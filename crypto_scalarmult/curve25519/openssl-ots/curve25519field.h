#include <stdint.h>
typedef uint64_t fe51[5];
#include "namemapping.h"
void fe51_mul(fe51 h, const fe51 f, const fe51 g);
void fe51_sq(fe51 h, const fe51 f);
void fe51_mul121666(fe51 h, fe51 f);
