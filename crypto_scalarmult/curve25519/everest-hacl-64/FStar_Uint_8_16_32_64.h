#include <stdint.h>
static inline uint64_t FStar_UInt64_eq_mask(uint64_t a, uint64_t b) {
  uint64_t x = a ^ b;
  uint64_t minus_x = ~x + (uint64_t)1U;
  uint64_t x_or_minus_x = x | minus_x;
  uint64_t xnx = x_or_minus_x >> (uint32_t)63U;
  return xnx - (uint64_t)1U;
}
static inline uint64_t FStar_UInt64_gte_mask(uint64_t a, uint64_t b) {
  uint64_t x = a;
  uint64_t y = b;
  uint64_t x_xor_y = x ^ y;
  uint64_t x_sub_y = x - y;
  uint64_t x_sub_y_xor_y = x_sub_y ^ y;
  uint64_t q = x_xor_y | x_sub_y_xor_y;
  uint64_t x_xor_q = x ^ q;
  uint64_t x_xor_q_ = x_xor_q >> (uint32_t)63U;
  return x_xor_q_ - (uint64_t)1U;
}
static inline uint8_t FStar_UInt8_eq_mask(uint8_t a, uint8_t b) {
  uint8_t x = a ^ b;
  uint8_t minus_x = ~x + (uint8_t)1U;
  uint8_t x_or_minus_x = x | minus_x;
  uint8_t xnx = x_or_minus_x >> (uint32_t)7U;
  return xnx - (uint8_t)1U;
}
