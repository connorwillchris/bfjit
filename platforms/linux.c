#include "platform.h"

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

    if (code == MAP_FAILED) {
        perror("Failed to allocate memory!\n");
        return NULL;
    }

    return code;
}

void mem_dealloc(void *code, size_t l) {
    munmap(code, l);
}

#endif
