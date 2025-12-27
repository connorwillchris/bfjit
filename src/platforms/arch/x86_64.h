#ifndef X86_64_H
#define X86_64_H

#define RET_INSTRUCTION 0xC3

/// @brief Returns the ret instruction as a byte.
/// @return The RET command byte.
char inst_ret() {
    return RET_INSTRUCTION;
}

#endif
