#ifndef X86_64_H
#define X86_64_H

#include <stdarg.h>

typedef size_t (*fn)(size_t);

typedef struct {
    char *dest;
} Microasm;

typedef enum {
    R_RAX = 0,
    R_RCX = 1,
    R_RDX = 2,
    R_RBX = 3,
    R_RSP = 4, // `80 04 24 imm8` for ADDB
    R_RBP = 5, // `80 45 00 imm8` for ADDB
    R_RSI = 6,
    R_RDI = 7,
} Register;

void asm_write(Microasm *a, int n, ...) {
    va_list bytes;
    int i;
    va_start(bytes, n);
    for (i = 0; i < n; ++i) *(a->dest++) = (char) va_arg(bytes, int);
    va_end(bytes);
}

/* 
    addb $imm8, (%reg64)
    80 /0 ib
    opcode: 80
    ModRM
    mod reg r/m
    reg = 000 (ADD)

    NO DISPLACEMENT:

    REGISTER | r/m bits | ModRM
    (%rax)   | 000      | 00
    (%rcx)   | 001      | 01
    (%rdx)   | 010      | 02
    (%rbx)   | 011      | 03
    (%rsp)   | 100      | 04 *
    (%rbp)   | 101      | 05 **
    (%rsi)   | 110      | 06
    (%rdi)   | 111      | 07

    addb $5, (%rax) ...
    80 00 05

    /ib         ==      SINGLE BYTE VALUE
    imm8        ==      SIGNED OR UNSIGNED BYTE VALUE
    r/m8        ==      A byte operand that is either the contents of a byte general-purpose register (AL, CL, DL, BL, AH, CH, DH, BH, BPL, SPL, DIL, and SIL) or a byte from memory. Byte registers R8B - R15B are available using REX.R
*/
void addb_immediate_reg(Microasm *a, Register r, unsigned imm8);

#endif
