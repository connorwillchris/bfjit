#include "platforms/platform.h"
#include "platforms/arch/x86_64.h"
#include "bf.h"

#include <string.h>

struct Bf {
    size_t s;
    char *tape;
};

/// @brief The JIT compile and execute a Brainfuck string on Windows x86_64.
typedef size_t (*f)(char*, size_t, void*, void*);

static f compile_identity() {
    // allocate memory
    size_t s = 4096;
    char *mem = VirtualAlloc(
        NULL,
        s,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_EXECUTE_READWRITE
    );

    // error checking
    if (mem == NULL) {
        printf("[ERROR] VirtualAlloc failed!\n");
        return NULL;
    }

    char code[] = {
        0x48, 0x89, 0xF8,
        0xC3,
    };

    memcpy(mem, code, strlen(code));

    return (f) mem;
}

int bf_dostring_jit(Bf *b, char *s) {
    f code = compile_identity();

    if (code == NULL) {
        printf("Failed to JIT compile!\n");
        return 1;
    }

    code(b->tape, b->s, &putchar, &getchar);

    // free the memory
    VirtualFree(code, 4096, MEM_RELEASE);

    /*
    size_t p = 0;
    size_t i = 0;
    while (i < strlen(s)) {
        switch (s[i]) {
            case '+': {
                b->tape[p]++;
                break;
            }
            case '-': {
                b->tape[p]--;
                break;
            }
            case '<': {
                // if it's equal to zero
                p = (p + 1) % b->s;
                break;
            }
            case '>': {
                p = (p - 1 + b->s) % b->s;
                break;
            }
            case '.': {
                putchar(b->tape[p]);
                break;
            }
            case ',': {
                b->tape[p] = (char)getchar();
                break;
            }
            case '[': {
                if (b->tape[p] == 0) {
                    int depth = 1;
                    while (depth > 0) {
                        i++;
                        if (s[i] == '[') depth++;
                        else if (s[i] == ']') depth--;
                    }
                }
                break;
            }
            case ']': {
                if (b->tape[p] != 0) {
                    int depth = 1;
                    while (depth > 0) {
                        i--;
                        if (s[i] == ']') depth++;
                        else if (s[i] == '[') depth--;
                    }
                }
                break;
            }
            //default: break;
        }

        i++;
    }
    */
}