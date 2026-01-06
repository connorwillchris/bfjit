#ifndef X86_64_H
#define X86_64_H

#define REG_RAX 0
#define REG_RCX 1
#define REG_RDX 2
#define REG_RBX 3
#define REG_RSP 4
#define REG_RBP 5
#define REG_RSI 6
#define REG_RDI 7
#define REG_R8  8
#define REG_R9  9
#define REG_R10 10
#define REG_R11 11
#define REG_R12 12
#define REG_R13 13
#define REG_R14 14
#define REG_R15 15

#define RET_INSTRUCTION_LEN 1

#define RET_INSTRUCTION 0xC3

/// @brief Returns the ret instruction as a byte.
/// @return The RET command byte.
char inst_ret() {
    return RET_INSTRUCTION;
}

/// @brief Move instruction.
/// @return a MOV-64 bit instruction.
char *inst_mov() {
    
}

/// @brief The add instruction in 3+ bytes.
/// @return The add instruction.
char *inst_add() {

}

#endif
