#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdint.h>
#include <stddef.h>

uint8_t *mem_alloc(size_t l);

void mem_dealloc(void *code, size_t l);

#endif // LINUX_H