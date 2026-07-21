#include "platform.h"

// TODO - Put these defines in the makefile, later
#define PLATFORM_WINDOWS

#ifdef PLATFORM_WINDOWS
#include <Windows.h>

uint8_t *mem_alloc(size_t l) {
    uint8_t *code = VirtualAlloc(
        NULL,
        l,
        MEM_COMMIT,
        PAGE_READWRITE
    );

    return code;
}

void mem_dealloc(void *code, size_t l) {
    VirtualFree(
        code,
        0,
        MEM_RELEASE
    );
}

#endif
