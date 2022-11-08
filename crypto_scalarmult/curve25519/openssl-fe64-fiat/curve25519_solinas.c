#include "curve25519_solinas.h"
/** #if false */
/*
 * The function fiat_curve25519_solinas_mul multiplies two field elements.
 *
 * Postconditions:
 *   eval out1 mod
 * 57896044618658097711785492504343953926634992332820282019728792003956564819949
 * = (eval arg1 * eval arg2) mod
 * 57896044618658097711785492504343953926634992332820282019728792003956564819949
 *
 * Input Bounds:
 *   arg1: [[0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~>
 * 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff]] arg2: [[0x0 ~>
 * 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~>
 * 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff]] Output Bounds: out1: [[0x0
 * ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~>
 * 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff]]
 */
void fiat_curve25519_solinas_mul(uint64_t out1[4], const uint64_t arg1[4],
                                 const uint64_t arg2[4]) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  uint64_t x4;
  uint64_t x5;
  uint64_t x6;
  uint64_t x7;
  uint64_t x8;
  uint64_t x9;
  uint64_t x10;
  uint64_t x11;
  uint64_t x12;
  uint64_t x13;
  uint64_t x14;
  uint64_t x15;
  uint64_t x16;
  uint64_t x17;
  uint64_t x18;
  uint64_t x19;
  uint64_t x20;
  uint64_t x21;
  uint64_t x22;
  uint64_t x23;
  uint64_t x24;
  uint64_t x25;
  uint64_t x26;
  uint64_t x27;
  uint64_t x28;
  uint64_t x29;
  uint64_t x30;
  uint64_t x31;
  uint64_t x32;
  uint64_t x33;
  fiat_curve25519_solinas_uint1 x34;
  uint64_t x35;
  fiat_curve25519_solinas_uint1 x36;
  uint64_t x37;
  uint64_t x38;
  fiat_curve25519_solinas_uint1 x39;
  uint64_t x40;
  fiat_curve25519_solinas_uint1 x41;
  uint64_t x42;
  fiat_curve25519_solinas_uint1 x43;
  uint64_t x44;
  uint64_t x45;
  fiat_curve25519_solinas_uint1 x46;
  uint64_t x47;
  fiat_curve25519_solinas_uint1 x48;
  uint64_t x49;
  fiat_curve25519_solinas_uint1 x50;
  uint64_t x51;
  fiat_curve25519_solinas_uint1 x52;
  uint64_t x53;
  fiat_curve25519_solinas_uint1 x54;
  uint64_t x55;
  uint64_t x56;
  fiat_curve25519_solinas_uint1 x57;
  uint64_t x58;
  fiat_curve25519_solinas_uint1 x59;
  uint64_t x60;
  fiat_curve25519_solinas_uint1 x61;
  uint64_t x62;
  fiat_curve25519_solinas_uint1 x63;
  uint64_t x64;
  fiat_curve25519_solinas_uint1 x65;
  uint64_t x66;
  fiat_curve25519_solinas_uint1 x67;
  uint64_t x68;
  fiat_curve25519_solinas_uint1 x69;
  uint64_t x70;
  fiat_curve25519_solinas_uint1 x71;
  uint64_t x72;
  fiat_curve25519_solinas_uint1 x73;
  uint64_t x74;
  fiat_curve25519_solinas_uint1 x75;
  uint64_t x76;
  fiat_curve25519_solinas_uint1 x77;
  uint64_t x78;
  fiat_curve25519_solinas_uint1 x79;
  uint64_t x80;
  fiat_curve25519_solinas_uint1 x81;
  uint64_t x82;
  fiat_curve25519_solinas_uint1 x83;
  uint64_t x84;
  fiat_curve25519_solinas_uint1 x85;
  uint64_t x86;
  fiat_curve25519_solinas_uint1 x87;
  uint64_t x88;
  fiat_curve25519_solinas_uint1 x89;
  uint64_t x90;
  fiat_curve25519_solinas_uint1 x91;
  uint64_t x92;
  fiat_curve25519_solinas_uint1 x93;
  uint64_t x94;
  fiat_curve25519_solinas_uint1 x95;
  uint64_t x96;
  uint64_t x97;
  uint64_t x98;
  uint64_t x99;
  uint64_t x100;
  uint64_t x101;
  uint64_t x102;
  uint64_t x103;
  uint64_t x104;
  fiat_curve25519_solinas_uint1 x105;
  uint64_t x106;
  fiat_curve25519_solinas_uint1 x107;
  uint64_t x108;
  fiat_curve25519_solinas_uint1 x109;
  uint64_t x110;
  uint64_t x111;
  fiat_curve25519_solinas_uint1 x112;
  uint64_t x113;
  fiat_curve25519_solinas_uint1 x114;
  uint64_t x115;
  fiat_curve25519_solinas_uint1 x116;
  uint64_t x117;
  fiat_curve25519_solinas_uint1 x118;
  uint64_t x119;
  uint64_t x120;
  uint64_t x121;
  uint64_t x122;
  fiat_curve25519_solinas_uint1 x123;
  uint64_t x124;
  fiat_curve25519_solinas_uint1 x125;
  uint64_t x126;
  fiat_curve25519_solinas_uint1 x127;
  uint64_t x128;
  fiat_curve25519_solinas_uint1 x129;
  uint64_t x130;
  fiat_curve25519_solinas_uint128 x131;
  uint64_t x132;

  fiat_curve25519_solinas_mulx_u64(&x1, &x2, (arg1[3]), (arg2[3]));
  fiat_curve25519_solinas_mulx_u64(&x3, &x4, (arg1[3]), (arg2[2]));
  fiat_curve25519_solinas_mulx_u64(&x5, &x6, (arg1[3]), (arg2[1]));
  fiat_curve25519_solinas_mulx_u64(&x7, &x8, (arg1[3]), (arg2[0]));
  fiat_curve25519_solinas_mulx_u64(&x9, &x10, (arg1[2]), (arg2[3]));
  fiat_curve25519_solinas_mulx_u64(&x11, &x12, (arg1[2]), (arg2[2]));
  fiat_curve25519_solinas_mulx_u64(&x13, &x14, (arg1[2]), (arg2[1]));
  fiat_curve25519_solinas_mulx_u64(&x15, &x16, (arg1[2]), (arg2[0]));
  fiat_curve25519_solinas_mulx_u64(&x17, &x18, (arg1[1]), (arg2[3]));
  fiat_curve25519_solinas_mulx_u64(&x19, &x20, (arg1[1]), (arg2[2]));
  fiat_curve25519_solinas_mulx_u64(&x21, &x22, (arg1[1]), (arg2[1]));
  fiat_curve25519_solinas_mulx_u64(&x23, &x24, (arg1[1]), (arg2[0]));
  fiat_curve25519_solinas_mulx_u64(&x25, &x26, (arg1[0]), (arg2[3]));
  fiat_curve25519_solinas_mulx_u64(&x27, &x28, (arg1[0]), (arg2[2]));
  fiat_curve25519_solinas_mulx_u64(&x29, &x30, (arg1[0]), (arg2[1]));
  fiat_curve25519_solinas_mulx_u64(&x31, &x32, (arg1[0]), (arg2[0]));
  fiat_curve25519_solinas_addcarryx_u64(&x33, &x34, 0x0, x28, x7);
  fiat_curve25519_solinas_addcarryx_u64(&x35, &x36, x34, x26, x5);
  x37 = (x36 + x18);
  fiat_curve25519_solinas_addcarryx_u64(&x38, &x39, 0x0, x33, x13);
  fiat_curve25519_solinas_addcarryx_u64(&x40, &x41, x39, x35, x8);
  fiat_curve25519_solinas_addcarryx_u64(&x42, &x43, x41, x37, 0x0);
  x44 = (x43 + x10);
  fiat_curve25519_solinas_addcarryx_u64(&x45, &x46, 0x0, x30, x15);
  fiat_curve25519_solinas_addcarryx_u64(&x47, &x48, x46, x38, x16);
  fiat_curve25519_solinas_addcarryx_u64(&x49, &x50, x48, x40, x11);
  fiat_curve25519_solinas_addcarryx_u64(&x51, &x52, x50, x42, x3);
  fiat_curve25519_solinas_addcarryx_u64(&x53, &x54, x52, x44, 0x0);
  x55 = (x54 + x2);
  fiat_curve25519_solinas_addcarryx_u64(&x56, &x57, 0x0, x45, x21);
  fiat_curve25519_solinas_addcarryx_u64(&x58, &x59, x57, x47, x19);
  fiat_curve25519_solinas_addcarryx_u64(&x60, &x61, x59, x49, x14);
  fiat_curve25519_solinas_addcarryx_u64(&x62, &x63, x61, x51, x6);
  fiat_curve25519_solinas_addcarryx_u64(&x64, &x65, x63, x53, 0x0);
  fiat_curve25519_solinas_addcarryx_u64(&x66, &x67, x65, x55, 0x0);
  fiat_curve25519_solinas_addcarryx_u64(&x68, &x69, 0x0, x32, x23);
  fiat_curve25519_solinas_addcarryx_u64(&x70, &x71, x69, x56, x24);
  fiat_curve25519_solinas_addcarryx_u64(&x72, &x73, x71, x58, x22);
  fiat_curve25519_solinas_addcarryx_u64(&x74, &x75, x73, x60, x17);
  fiat_curve25519_solinas_addcarryx_u64(&x76, &x77, x75, x62, x9);
  fiat_curve25519_solinas_addcarryx_u64(&x78, &x79, x77, x64, x1);
  fiat_curve25519_solinas_addcarryx_u64(&x80, &x81, x79, x66, 0x0);
  fiat_curve25519_solinas_addcarryx_u64(&x82, &x83, 0x0, x68, x29);
  fiat_curve25519_solinas_addcarryx_u64(&x84, &x85, x83, x70, x27);
  fiat_curve25519_solinas_addcarryx_u64(&x86, &x87, x85, x72, x25);
  fiat_curve25519_solinas_addcarryx_u64(&x88, &x89, x87, x74, x20);
  fiat_curve25519_solinas_addcarryx_u64(&x90, &x91, x89, x76, x12);
  fiat_curve25519_solinas_addcarryx_u64(&x92, &x93, x91, x78, x4);
  fiat_curve25519_solinas_addcarryx_u64(&x94, &x95, x93, x80, 0x0);
  fiat_curve25519_solinas_mulx_u64(&x96, &x97, UINT8_C(0x26), x94);
  fiat_curve25519_solinas_mulx_u64(&x98, &x99, UINT8_C(0x26), x92);
  fiat_curve25519_solinas_mulx_u64(&x100, &x101, UINT8_C(0x26), x90);
  fiat_curve25519_solinas_mulx_u64(&x102, &x103, UINT8_C(0x26), x88);
  fiat_curve25519_solinas_addcarryx_u64(&x104, &x105, 0x0, x82, x100);
  fiat_curve25519_solinas_addcarryx_u64(&x106, &x107, x105, x84, x98);
  fiat_curve25519_solinas_addcarryx_u64(&x108, &x109, x107, x86, x96);
  x110 = (x109 + x97);
  fiat_curve25519_solinas_addcarryx_u64(&x111, &x112, 0x0, x31, x102);
  fiat_curve25519_solinas_addcarryx_u64(&x113, &x114, x112, x104, x103);
  fiat_curve25519_solinas_addcarryx_u64(&x115, &x116, x114, x106, x101);
  fiat_curve25519_solinas_addcarryx_u64(&x117, &x118, x116, x108, x99);
  x119 = (x118 + x110);
  fiat_curve25519_solinas_mulx_u64(&x120, &x121, UINT8_C(0x26), x119);
  fiat_curve25519_solinas_addcarryx_u64(&x122, &x123, 0x0, x111, x120);
  fiat_curve25519_solinas_addcarryx_u64(&x124, &x125, x123, x113, 0x0);
  fiat_curve25519_solinas_addcarryx_u64(&x126, &x127, x125, x115, 0x0);
  fiat_curve25519_solinas_addcarryx_u64(&x128, &x129, x127, x117, 0x0);
  fiat_curve25519_solinas_cmovznz_u64(&x130, x129, 0x0, UINT8_C(0x26));
  x131 = ((fiat_curve25519_solinas_uint128)x130 + x122);
  x132 = (uint64_t)(x131 & UINT64_C(0xffffffffffffffff));
  out1[0] = x132;
  out1[1] = x124;
  out1[2] = x126;
  out1[3] = x128;
}

/*
 * The function fiat_curve25519_solinas_square squares a field element.
 *
 * Postconditions:
 *   eval out1 mod
 * 57896044618658097711785492504343953926634992332820282019728792003956564819949
 * = (eval arg1 * eval arg1) mod
 * 57896044618658097711785492504343953926634992332820282019728792003956564819949
 *
 * Input Bounds:
 *   arg1: [[0x0 ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~>
 * 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff]] Output Bounds: out1: [[0x0
 * ~> 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff], [0x0 ~>
 * 0xffffffffffffffff], [0x0 ~> 0xffffffffffffffff]]
 */
void fiat_curve25519_solinas_square(uint64_t out1[4], const uint64_t arg1[4]) {
  uint64_t x1;
  uint64_t x2;
  uint64_t x3;
  uint64_t x4;
  uint64_t x5;
  uint64_t x6;
  uint64_t x7;
  uint64_t x8;
  uint64_t x9;
  uint64_t x10;
  uint64_t x11;
  fiat_curve25519_solinas_uint1 x12;
  uint64_t x13;
  fiat_curve25519_solinas_uint1 x14;
  uint64_t x15;
  fiat_curve25519_solinas_uint1 x16;
  uint64_t x17;
  fiat_curve25519_solinas_uint1 x18;
  uint64_t x19;
  uint64_t x20;
  uint64_t x21;
  uint64_t x22;
  fiat_curve25519_solinas_uint1 x23;
  uint64_t x24;
  fiat_curve25519_solinas_uint1 x25;
  uint64_t x26;
  fiat_curve25519_solinas_uint1 x27;
  uint64_t x28;
  fiat_curve25519_solinas_uint1 x29;
  uint64_t x30;
  fiat_curve25519_solinas_uint1 x31;
  uint64_t x32;
  fiat_curve25519_solinas_uint1 x33;
  uint64_t x34;
  fiat_curve25519_solinas_uint1 x35;
  uint64_t x36;
  fiat_curve25519_solinas_uint1 x37;
  uint64_t x38;
  fiat_curve25519_solinas_uint1 x39;
  uint64_t x40;
  fiat_curve25519_solinas_uint1 x41;
  uint64_t x42;
  uint64_t x43;
  uint64_t x44;
  uint64_t x45;
  uint64_t x46;
  uint64_t x47;
  uint64_t x48;
  uint64_t x49;
  uint64_t x50;
  uint64_t x51;
  fiat_curve25519_solinas_uint1 x52;
  uint64_t x53;
  fiat_curve25519_solinas_uint1 x54;
  uint64_t x55;
  fiat_curve25519_solinas_uint1 x56;
  uint64_t x57;
  fiat_curve25519_solinas_uint1 x58;
  uint64_t x59;
  fiat_curve25519_solinas_uint1 x60;
  uint64_t x61;
  fiat_curve25519_solinas_uint1 x62;
  uint64_t x63;
  fiat_curve25519_solinas_uint1 x64;
  uint64_t x65;
  uint64_t x66;
  uint64_t x67;
  uint64_t x68;
  uint64_t x69;
  uint64_t x70;
  uint64_t x71;
  uint64_t x72;
  uint64_t x73;
  fiat_curve25519_solinas_uint1 x74;
  uint64_t x75;
  fiat_curve25519_solinas_uint1 x76;
  uint64_t x77;
  fiat_curve25519_solinas_uint1 x78;
  uint64_t x79;
  uint64_t x80;
  fiat_curve25519_solinas_uint1 x81;
  uint64_t x82;
  fiat_curve25519_solinas_uint1 x83;
  uint64_t x84;
  fiat_curve25519_solinas_uint1 x85;
  uint64_t x86;
  fiat_curve25519_solinas_uint1 x87;
  uint64_t x88;
  uint64_t x89;
  uint64_t x90;
  uint64_t x91;
  fiat_curve25519_solinas_uint1 x92;
  uint64_t x93;
  fiat_curve25519_solinas_uint1 x94;
  uint64_t x95;
  fiat_curve25519_solinas_uint1 x96;
  uint64_t x97;
  fiat_curve25519_solinas_uint1 x98;
  uint64_t x99;
  fiat_curve25519_solinas_uint128 x100;
  uint64_t x101;
  fiat_curve25519_solinas_mulx_u64(&x1, &x2, (arg1[0]), (arg1[3]));
  fiat_curve25519_solinas_mulx_u64(&x3, &x4, (arg1[0]), (arg1[2]));
  fiat_curve25519_solinas_mulx_u64(&x5, &x6, (arg1[0]), (arg1[1]));
  fiat_curve25519_solinas_mulx_u64(&x7, &x8, (arg1[3]), (arg1[2]));
  fiat_curve25519_solinas_mulx_u64(&x9, &x10, (arg1[3]), (arg1[1]));
  fiat_curve25519_solinas_addcarryx_u64(&x11, &x12, 0x0, x6, x3);
  fiat_curve25519_solinas_addcarryx_u64(&x13, &x14, x12, x4, x1);
  fiat_curve25519_solinas_addcarryx_u64(&x15, &x16, x14, x2, x9);
  fiat_curve25519_solinas_addcarryx_u64(&x17, &x18, x16, x10, x7);
  x19 = (x18 + x8);
  fiat_curve25519_solinas_mulx_u64(&x20, &x21, (arg1[1]), (arg1[2]));
  fiat_curve25519_solinas_addcarryx_u64(&x22, &x23, 0x0, x13, x20);
  fiat_curve25519_solinas_addcarryx_u64(&x24, &x25, x23, x15, x21);
  fiat_curve25519_solinas_addcarryx_u64(&x26, &x27, x25, x17, 0x0);
  fiat_curve25519_solinas_addcarryx_u64(&x28, &x29, x27, x19, 0x0);
  fiat_curve25519_solinas_addcarryx_u64(&x30, &x31, 0x0, x5, x5);
  fiat_curve25519_solinas_addcarryx_u64(&x32, &x33, x31, x11, x11);
  fiat_curve25519_solinas_addcarryx_u64(&x34, &x35, x33, x22, x22);
  fiat_curve25519_solinas_addcarryx_u64(&x36, &x37, x35, x24, x24);
  fiat_curve25519_solinas_addcarryx_u64(&x38, &x39, x37, x26, x26);
  fiat_curve25519_solinas_addcarryx_u64(&x40, &x41, x39, x28, x28);
  x42 = (((uint64_t)x41 + x29) + (uint64_t)x29);
  fiat_curve25519_solinas_mulx_u64(&x43, &x44, (arg1[3]), (arg1[3]));
  fiat_curve25519_solinas_mulx_u64(&x45, &x46, (arg1[2]), (arg1[2]));
  fiat_curve25519_solinas_mulx_u64(&x47, &x48, (arg1[1]), (arg1[1]));
  fiat_curve25519_solinas_mulx_u64(&x49, &x50, (arg1[0]), (arg1[0]));
  fiat_curve25519_solinas_addcarryx_u64(&x51, &x52, 0x0, x30, x50);
  fiat_curve25519_solinas_addcarryx_u64(&x53, &x54, x52, x32, x47);
  fiat_curve25519_solinas_addcarryx_u64(&x55, &x56, x54, x34, x48);
  fiat_curve25519_solinas_addcarryx_u64(&x57, &x58, x56, x36, x45);
  fiat_curve25519_solinas_addcarryx_u64(&x59, &x60, x58, x38, x46);
  fiat_curve25519_solinas_addcarryx_u64(&x61, &x62, x60, x40, x43);
  fiat_curve25519_solinas_addcarryx_u64(&x63, &x64, x62, x42, x44);
  fiat_curve25519_solinas_mulx_u64(&x65, &x66, UINT8_C(0x26), x63);
  fiat_curve25519_solinas_mulx_u64(&x67, &x68, UINT8_C(0x26), x61);
  fiat_curve25519_solinas_mulx_u64(&x69, &x70, UINT8_C(0x26), x59);
  fiat_curve25519_solinas_mulx_u64(&x71, &x72, UINT8_C(0x26), x57);
  fiat_curve25519_solinas_addcarryx_u64(&x73, &x74, 0x0, x51, x69);
  fiat_curve25519_solinas_addcarryx_u64(&x75, &x76, x74, x53, x67);
  fiat_curve25519_solinas_addcarryx_u64(&x77, &x78, x76, x55, x65);
  x79 = (x78 + x66);
  fiat_curve25519_solinas_addcarryx_u64(&x80, &x81, 0x0, x49, x71);
  fiat_curve25519_solinas_addcarryx_u64(&x82, &x83, x81, x73, x72);
  fiat_curve25519_solinas_addcarryx_u64(&x84, &x85, x83, x75, x70);
  fiat_curve25519_solinas_addcarryx_u64(&x86, &x87, x85, x77, x68);
  x88 = (x87 + x79);
  fiat_curve25519_solinas_mulx_u64(&x89, &x90, UINT8_C(0x26), x88);
  fiat_curve25519_solinas_addcarryx_u64(&x91, &x92, 0x0, x80, x89);
  fiat_curve25519_solinas_addcarryx_u64(&x93, &x94, x92, x82, 0x0);
  fiat_curve25519_solinas_addcarryx_u64(&x95, &x96, x94, x84, 0x0);
  fiat_curve25519_solinas_addcarryx_u64(&x97, &x98, x96, x86, 0x0);
  fiat_curve25519_solinas_cmovznz_u64(&x99, x98, 0x0, UINT8_C(0x26));
  x100 = ((fiat_curve25519_solinas_uint128)x99 + x91);
  x101 = (uint64_t)(x100 & UINT64_C(0xffffffffffffffff));
  out1[0] = x101;
  out1[1] = x93;
  out1[2] = x95;
  out1[3] = x97;
}

/** #endif */
