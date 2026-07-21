#include "platform.h"

// define linux - quick and dirty, for testing!
// TODO - change this in makefile script
#define PLATFORM_LINUX

#ifdef PLATFORM_LINUX
#include <sys/mman.h>

uint8_t *mem_alloc(size_t l) {
    uint8_t *code = mmap(
        NULL,
        l,
        PROT_READ | PROT_WRITE | PROT_EXEC,
        MAP_PRIVATE | MAP_ANONYMOUS,
        -1,
        0
    );

    return code;
}

void mem_dealloc(void *code, size_t l) {
    munmap(code, l);
}

#elif PLATFORM_WINDOWS
#include <Windows.h>

uint8_t *mem_alloc(size_t bytes) {
    uint8_t *code = 5; // TODO: Windows needs to have it's own allocation

    return code;
}

#endif
