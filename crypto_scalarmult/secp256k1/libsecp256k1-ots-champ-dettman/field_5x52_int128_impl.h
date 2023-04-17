/***********************************************************************
 * Copyright (c) 2013, 2014 Pieter Wuille                              *
 * Distributed under the MIT software license, see the accompanying    *
 * file COPYING or https://www.opensource.org/licenses/mit-license.php.*
 ***********************************************************************/

#ifndef SECP256K1_FIELD_INNER5X52_IMPL_H
#define SECP256K1_FIELD_INNER5X52_IMPL_H

#include <stdint.h>

SECP256K1_INLINE static void
secp256k1_fe_mul_inner(uint64_t *r, const uint64_t *a,
                       const uint64_t *SECP256K1_RESTRICT b) {
  asm volatile("mov    %%rdx,%%rax\n"
               "mov    (%%rdx),%%rdx\n"
               "mulx   0x20(%%rsi),%%r10,%%r11\n"
               "mov    0x10(%%rax),%%rdx\n"
               "mulx   0x8(%%rsi),%%rcx,%%r8\n"
               "mov    (%%rax),%%rdx\n"
               "mov    %%rbx,-0x80(%%rsp)\n"
               "mulx   0x18(%%rsi),%%r9,%%rbx\n"
               "mov    0x8(%%rax),%%rdx\n"
               "mov    %%rbp,-0x78(%%rsp)\n"
               "mov    %%r12,-0x70(%%rsp)\n"
               "mulx   0x10(%%rsi),%%rbp,%%r12\n"
               "add    %%rbp,%%r9\n"
               "adcx   %%rbx,%%r12\n"
               "mov    0x20(%%rsi),%%rdx\n"
               "mulx   0x20(%%rax),%%rbx,%%rbp\n"
               "movabs $0xfffffffffffff,%%rdx\n"
               "mov    %%r13,-0x68(%%rsp)\n"
               "mov    %%rbx,%%r13\n"
               "and    %%rdx,%%r13\n"
               "adox   %%rcx,%%r9\n"
               "adox   %%r12,%%r8\n"
               "shrd   $0x34,%%rbp,%%rbx\n"
               "mov    0x18(%%rsi),%%rdx\n"
               "mulx   0x8(%%rax),%%rcx,%%r12\n"
               "mov    0x10(%%rax),%%rdx\n"
               "mov    %%r14,-0x60(%%rsp)\n"
               "mulx   0x10(%%rsi),%%rbp,%%r14\n"
               "mov    0x18(%%rax),%%rdx\n"
               "mov    %%r15,-0x58(%%rsp)\n"
               "mov    %%rdi,-0x50(%%rsp)\n"
               "mulx   0x8(%%rsi),%%r15,%%rdi\n"
               "xor    %%rdx,%%rdx\n"
               "adox   %%rcx,%%r10\n"
               "adox   %%r11,%%r12\n"
               "mov    0x18(%%rax),%%rdx\n"
               "mulx   (%%rsi),%%r11,%%rcx\n"
               "adcx   %%rbp,%%r10\n"
               "adcx   %%r12,%%r14\n"
               "movabs $0x1000003d10,%%rdx\n"
               "mulx   %%rbx,%%rbp,%%r12\n"
               "add    %%r11,%%r9\n"
               "adcx   %%r8,%%rcx\n"
               "mulx   %%r13,%%r8,%%rbx\n"
               "add    %%r9,%%r8\n"
               "adcx   %%rbx,%%rcx\n"
               "mov    %%r8,%%r13\n"
               "shrd   $0x34,%%rcx,%%r13\n"
               "xor    %%r11,%%r11\n"
               "adox   %%r15,%%r10\n"
               "adox   %%r14,%%rdi\n"
               "mov    (%%rsi),%%rdx\n"
               "mulx   0x20(%%rax),%%r15,%%r14\n"
               "movabs $0xfffffffffffff,%%rdx\n"
               "and    %%rdx,%%r8\n"
               "adox   %%r15,%%r10\n"
               "adox   %%rdi,%%r14\n"
               "adcx   %%r10,%%r13\n"
               "adc    $0x0,%%r14\n"
               "xor    %%r9,%%r9\n"
               "adox   %%r13,%%rbp\n"
               "adox   %%r12,%%r14\n"
               "mov    0x8(%%rax),%%rdx\n"
               "mulx   0x20(%%rsi),%%r11,%%r12\n"
               "mov    0x18(%%rax),%%rdx\n"
               "mulx   0x10(%%rsi),%%rbx,%%rcx\n"
               "mov    0x10(%%rax),%%rdx\n"
               "mulx   0x18(%%rsi),%%rdi,%%r15\n"
               "adcx   %%rdi,%%r11\n"
               "adcx   %%r12,%%r15\n"
               "mov    0x20(%%rax),%%rdx\n"
               "mulx   0x8(%%rsi),%%r10,%%r13\n"
               "test   %%al,%%al\n"
               "adox   %%rbx,%%r11\n"
               "adox   %%r15,%%rcx\n"
               "adcx   %%r10,%%r11\n"
               "adcx   %%rcx,%%r13\n"
               "movabs $0xfffffffffffff,%%rdx\n"
               "mov    %%rbp,%%r12\n"
               "and    %%rdx,%%r12\n"
               "mov    0x20(%%rsi),%%rdx\n"
               "mulx   0x10(%%rax),%%rbx,%%rdi\n"
               "mov    %%r12,%%rdx\n"
               "shr    $0x30,%%rdx\n"
               "shrd   $0x34,%%r14,%%rbp\n"
               "add    %%r11,%%rbp\n"
               "adc    $0x0,%%r13\n"
               "movabs $0xfffffffffffff,%%r14\n"
               "mov    %%rbp,%%r15\n"
               "and    %%r14,%%r15\n"
               "movabs $0xffffffffffff,%%r10\n"
               "and    %%r10,%%r12\n"
               "shl    $0x4,%%r15\n"
               "shrd   $0x34,%%r13,%%rbp\n"
               "mov    %%rdx,%%rcx\n"
               "mov    0x18(%%rsi),%%rdx\n"
               "mulx   0x18(%%rax),%%r11,%%r13\n"
               "lea    (%%r15,%%rcx,1),%%r15\n"
               "movabs $0x1000003d1,%%rdx\n"
               "mulx   %%r15,%%rcx,%%r9\n"
               "test   %%al,%%al\n"
               "adox   %%r11,%%rbx\n"
               "adox   %%rdi,%%r13\n"
               "mov    0x10(%%rsi),%%rdx\n"
               "mulx   0x20(%%rax),%%rdi,%%r11\n"
               "adcx   %%rdi,%%rbx\n"
               "adcx   %%r13,%%r11\n"
               "add    %%rbx,%%rbp\n"
               "adc    $0x0,%%r11\n"
               "mov    0x20(%%rsi),%%rdx\n"
               "mulx   0x18(%%rax),%%r15,%%r13\n"
               "mov    0x20(%%rax),%%rdx\n"
               "mulx   0x18(%%rsi),%%rdi,%%rbx\n"
               "xor    %%rdx,%%rdx\n"
               "adox   %%rdi,%%r15\n"
               "adox   %%r13,%%rbx\n"
               "mov    (%%rax),%%rdx\n"
               "mulx   (%%rsi),%%r13,%%rdi\n"
               "mov    %%rbp,%%rdx\n"
               "and    %%r14,%%rdx\n"
               "movabs $0x1000003d10,%%r10\n"
               "mov    %%r12,-0x48(%%rsp)\n"
               "mulx   %%r10,%%r14,%%r12\n"
               "mov    0x10(%%rax),%%rdx\n"
               "mov    %%r8,-0x40(%%rsp)\n"
               "mulx   (%%rsi),%%r10,%%r8\n"
               "mov    (%%rsi),%%rdx\n"
               "mov    %%r8,-0x38(%%rsp)\n"
               "mov    %%r10,-0x30(%%rsp)\n"
               "mulx   0x8(%%rax),%%r8,%%r10\n"
               "adox   %%r13,%%rcx\n"
               "adox   %%r9,%%rdi\n"
               "mov    (%%rax),%%rdx\n"
               "mulx   0x8(%%rsi),%%r9,%%r13\n"
               "mov    %%rcx,%%rdx\n"
               "shrd   $0x34,%%rdi,%%rdx\n"
               "test   %%al,%%al\n"
               "adox   %%r8,%%r9\n"
               "adox   %%r13,%%r10\n"
               "adcx   %%r9,%%rdx\n"
               "adc    $0x0,%%r10\n"
               "shrd   $0x34,%%r11,%%rbp\n"
               "xor    %%r11,%%r11\n"
               "adox   %%rdx,%%r14\n"
               "adox   %%r12,%%r10\n"
               "adcx   %%r15,%%rbp\n"
               "adc    $0x0,%%rbx\n"
               "movabs $0xfffffffffffff,%%r15\n"
               "mov    %%rbp,%%r12\n"
               "and    %%r15,%%r12\n"
               "shrd   $0x34,%%rbx,%%rbp\n"
               "mov    %%r14,%%r8\n"
               "and    %%r15,%%r8\n"
               "mov    0x10(%%rsi),%%rdx\n"
               "mulx   (%%rax),%%rdi,%%r13\n"
               "mov    0x8(%%rsi),%%rdx\n"
               "mulx   0x8(%%rax),%%r9,%%rbx\n"
               "adox   %%r9,%%rdi\n"
               "adox   %%r13,%%rbx\n"
               "adcx   -0x30(%%rsp),%%rdi\n"
               "adcx   -0x38(%%rsp),%%rbx\n"
               "shrd   $0x34,%%r10,%%r14\n"
               "movabs $0x1000003d10,%%rdx\n"
               "mulx   %%r12,%%r10,%%r13\n"
               "test   %%al,%%al\n"
               "adox   %%rdi,%%r14\n"
               "adox   %%r11,%%rbx\n"
               "adcx   %%r14,%%r10\n"
               "adcx   %%r13,%%rbx\n"
               "mov    %%r10,%%r12\n"
               "and    %%r15,%%r12\n"
               "shrd   $0x34,%%rbx,%%r10\n"
               "and    %%r15,%%rcx\n"
               "mulx   %%rbp,%%r9,%%rdi\n"
               "mov    -0x50(%%rsp),%%rbp\n"
               "mov    %%rcx,0x0(%%rbp)\n"
               "add    -0x40(%%rsp),%%r10\n"
               "test   %%al,%%al\n"
               "adox   %%r10,%%r9\n"
               "adox   %%r11,%%rdi\n"
               "mov    %%r9,%%r13\n"
               "shrd   $0x34,%%rdi,%%r13\n"
               "add    -0x48(%%rsp),%%r13\n"
               "and    %%r15,%%r9\n"
               "mov    %%r8,0x8(%%rbp)\n"
               "mov    %%r12,0x10(%%rbp)\n"
               "mov    %%r13,0x20(%%rbp)\n"
               "mov    %%r9,0x18(%%rbp)\n"
               "mov    -0x80(%%rsp),%%rbx\n"
               "mov    -0x78(%%rsp),%%rbp\n"
               "mov    -0x70(%%rsp),%%r12\n"
               "mov    -0x68(%%rsp),%%r13\n"
               "mov    -0x60(%%rsp),%%r14\n"
               "mov    -0x58(%%rsp),%%r15\n"
               :
               // rdi rsi rdx
               //  D S d
               : "D"(r), "S"(a), "d"(b)
               : "cc", "memory"

  );
}

SECP256K1_INLINE static void secp256k1_fe_sqr_inner(uint64_t *r,
                                                    const uint64_t *a) {

  asm volatile("mov    0x20(%%rsi),%%rdx\n"
               "mulx   %%rdx,%%rax,%%r10\n"
               "imul   $0x2,0x8(%%rsi),%%r11\n"
               "mov    0x10(%%rsi),%%rdx\n"
               "mulx   %%rdx,%%rcx,%%r8\n"
               "mov    0x10(%%rsi),%%rdx\n"
               "mov    %%rbx,-0x80(%%rsp)\n"
               "mulx   %%r11,%%r9,%%rbx\n"
               "imul   $0x2,(%%rsi),%%rdx\n"
               "mov    %%rbp,-0x78(%%rsp)\n"
               "mov    %%r12,-0x70(%%rsp)\n"
               "mulx   0x18(%%rsi),%%rbp,%%r12\n"
               "add    %%rbp,%%r9\n"
               "adcx   %%rbx,%%r12\n"
               "mulx   0x10(%%rsi),%%rbx,%%rbp\n"
               "mov    %%r13,-0x68(%%rsp)\n"
               "mov    %%r14,-0x60(%%rsp)\n"
               "mulx   0x20(%%rsi),%%r13,%%r14\n"
               "mov    %%r15,-0x58(%%rsp)\n"
               "mov    %%rdi,-0x50(%%rsp)\n"
               "mulx   0x8(%%rsi),%%r15,%%rdi\n"
               "movabs $0xfffffffffffff,%%rdx\n"
               "mov    %%rbp,-0x48(%%rsp)\n"
               "mov    %%rax,%%rbp\n"
               "and    %%rdx,%%rbp\n"
               "mov    0x18(%%rsi),%%rdx\n"
               "mov    %%rbx,-0x40(%%rsp)\n"
               "mov    %%rdi,-0x38(%%rsp)\n"
               "mulx   %%r11,%%rbx,%%rdi\n"
               "adox   %%rbx,%%rcx\n"
               "adox   %%r8,%%rdi\n"
               "movabs $0x1000003d10,%%rdx\n"
               "mulx   %%rbp,%%r8,%%rbx\n"
               "adcx   %%r9,%%r8\n"
               "adcx   %%rbx,%%r12\n"
               "mov    %%r8,%%r9\n"
               "shrd   $0x34,%%r12,%%r9\n"
               "test   %%al,%%al\n"
               "adox   %%r13,%%rcx\n"
               "adox   %%rdi,%%r14\n"
               "adcx   %%rcx,%%r9\n"
               "adc    $0x0,%%r14\n"
               "shrd   $0x34,%%r10,%%rax\n"
               "mulx   %%rax,%%r10,%%r13\n"
               "test   %%al,%%al\n"
               "adox   %%r9,%%r10\n"
               "adox   %%r13,%%r14\n"
               "movabs $0xfffffffffffff,%%rbp\n"
               "and    %%rbp,%%r8\n"
               "imul   $0x2,0x10(%%rsi),%%rdi\n"
               "mov    %%rdi,%%rdx\n"
               "mulx   0x18(%%rsi),%%rdi,%%rbx\n"
               "mulx   0x20(%%rsi),%%r12,%%rcx\n"
               "mov    %%r10,%%r9\n"
               "shrd   $0x34,%%r14,%%r9\n"
               "mov    0x20(%%rsi),%%rdx\n"
               "mulx   %%r11,%%rax,%%r13\n"
               "add    %%rax,%%rdi\n"
               "adcx   %%rbx,%%r13\n"
               "xor    %%rdx,%%rdx\n"
               "adox   %%rdi,%%r9\n"
               "adox   %%rdx,%%r13\n"
               "mov    %%r9,%%r11\n"
               "shrd   $0x34,%%r13,%%r11\n"
               "and    %%rbp,%%r9\n"
               "and    %%rbp,%%r10\n"
               "mov    0x18(%%rsi),%%r14\n"
               "lea    (%%r14,%%r14,1),%%rbx\n"
               "mov    %%r10,%%r14\n"
               "shr    $0x30,%%r14\n"
               "shl    $0x4,%%r9\n"
               "mov    0x18(%%rsi),%%rdx\n"
               "mulx   %%rdx,%%rax,%%rdi\n"
               "lea    (%%r9,%%r14,1),%%r9\n"
               "movabs $0x1000003d1,%%rdx\n"
               "mulx   %%r9,%%r13,%%r14\n"
               "xor    %%r9,%%r9\n"
               "adox   %%r12,%%rax\n"
               "adox   %%rdi,%%rcx\n"
               "adcx   %%rax,%%r11\n"
               "adc    $0x0,%%rcx\n"
               "mov    (%%rsi),%%rdx\n"
               "mulx   %%rdx,%%r12,%%rdi\n"
               "xor    %%rdx,%%rdx\n"
               "adox   %%r12,%%r13\n"
               "adox   %%r14,%%rdi\n"
               "mov    %%r13,%%r9\n"
               "and    %%rbp,%%r9\n"
               "shrd   $0x34,%%rdi,%%r13\n"
               "test   %%al,%%al\n"
               "adox   %%r15,%%r13\n"
               "mov    -0x38(%%rsp),%%r14\n"
               "adox   %%rdx,%%r14\n"
               "mov    %%r11,%%r15\n"
               "and    %%rbp,%%r15\n"
               "mov    -0x50(%%rsp),%%rax\n"
               "mov    %%r9,(%%rax)\n"
               "movabs $0x1000003d10,%%r12\n"
               "mov    %%r15,%%rdx\n"
               "mulx   %%r12,%%r15,%%rdi\n"
               "adox   %%r13,%%r15\n"
               "adox   %%rdi,%%r14\n"
               "mov    %%r15,%%r9\n"
               "and    %%rbp,%%r9\n"
               "shrd   $0x34,%%r14,%%r15\n"
               "mov    0x8(%%rsi),%%rdx\n"
               "mulx   %%rdx,%%r13,%%rdi\n"
               "xor    %%rdx,%%rdx\n"
               "adox   -0x40(%%rsp),%%r13\n"
               "adox   -0x48(%%rsp),%%rdi\n"
               "adcx   %%r13,%%r15\n"
               "adc    $0x0,%%rdi\n"
               "mov    %%r9,0x8(%%rax)\n"
               "shrd   $0x34,%%rcx,%%r11\n"
               "mov    0x20(%%rsi),%%rdx\n"
               "mulx   %%rbx,%%rcx,%%r14\n"
               "add    %%rcx,%%r11\n"
               "adc    $0x0,%%r14\n"
               "mov    %%r11,%%rdx\n"
               "and    %%rbp,%%rdx\n"
               "mulx   %%r12,%%rbx,%%r9\n"
               "adox   %%r15,%%rbx\n"
               "adox   %%r9,%%rdi\n"
               "mov    %%rbx,%%r13\n"
               "shrd   $0x34,%%rdi,%%r13\n"
               "shrd   $0x34,%%r14,%%r11\n"
               "mov    %%r12,%%rdx\n"
               "mulx   %%r11,%%r12,%%r15\n"
               "lea    (%%r8,%%r13,1),%%r8\n"
               "add    %%r8,%%r12\n"
               "adc    $0x0,%%r15\n"
               "mov    %%r12,%%rcx\n"
               "shrd   $0x34,%%r15,%%rcx\n"
               "and    %%rbp,%%rbx\n"
               "mov    %%rbx,0x10(%%rax)\n"
               "movabs $0xffffffffffff,%%r14\n"
               "and    %%r14,%%r10\n"
               "and    %%rbp,%%r12\n"
               "lea    (%%r10,%%rcx,1),%%r10\n"
               "mov    %%r12,0x18(%%rax)\n"
               "mov    %%r10,0x20(%%rax)\n"
               "mov    -0x80(%%rsp),%%rbx\n"
               "mov    -0x78(%%rsp),%%rbp\n"
               "mov    -0x70(%%rsp),%%r12\n"
               "mov    -0x68(%%rsp),%%r13\n"
               "mov    -0x60(%%rsp),%%r14\n"
               "mov    -0x58(%%rsp),%%r15\n"
               // rdi rsi
               //  D S
               :
               : "D"(r), "S"(a)
               : "cc", "memory"

  );
}

#endif /* SECP256K1_FIELD_INNER5X52_IMPL_H */
