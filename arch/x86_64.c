#include "x86_64.h"

void addb_immediate_reg(Microasm *a, Register r, unsigned imm8) {
    asm_write(a, 0x80, (unsigned)r, imm8);
}
