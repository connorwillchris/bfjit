#include "bf.h"
#include "platforms/platform.h"
#include "platforms/arch/x86_64.h"

#include <string.h>

typedef void (*period_p)(Bf*);
typedef char (*comma_p)(Bf*, size_t);

struct Bf {
    size_t s;
    char *tape;

    period_p period;
    comma_p comma;
};

//void (*period_p)(Bf*);
static void period_f(Bf *b) {
    putchar(bf_getchar());
}

typedef enum {
    T_ADD,
    T_SUB,
    T_LEFT,
    T_RIGHT,
    T_lOOP_L,
    T_LOOP_R,
    T_PERIOD,
    T_COMMA,

    T_END,
} Token;

/// @brief The JIT compile and execute a Brainfuck string on Windows x86_64.
typedef size_t (*f)(char*, size_t, period_p, comma_p);

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

    // get BF in the form of tokens
    char *code = NULL;

    memcpy(mem, code, strlen(code));

    return (f) mem;
}

int bf_dostring_jit(Bf *b, char *s) {
    f code = compile_identity();

    if (code == NULL) {
        printf("Failed to JIT compile!\n");
        return 1;
    }

    code(b->tape, b->s, b->period, b->comma);

    // free the memory
    VirtualFree(code, 4096, MEM_RELEASE);
}