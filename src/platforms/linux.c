#include "bf.h"
#include "platforms/platform.h"
#include "platforms/arch/x86_64.h"

/// @brief The JIT compile and execute a Brainfuck string on Windows x86_64.
typedef size_t (*f)(char*, size_t, void*, void*);

struct Bf {
    size_t s;
    char *tape;
};

static f compile_identity() {
    // allocate memory
    size_t s = 4096;
    char *mem = mmap(
        NULL,
        4096, // TODO: change this later
        PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANONYMOUS,
        -1,
        0
    );

    // error checking
    if (mem == MAP_FAILED) {
        printf("[ERROR] mmap failed!\n");
        return NULL;
    }

    // now do JIT specific code here

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
    munmap(code, 4096);
}
