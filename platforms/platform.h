#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdint.h>
#include <stddef.h>

/* 
 * Allocate the executable memory.
 * Must be defined for each system
 * supported.
 */
uint8_t *mem_alloc(size_t l);

void mem_dealloc(void *code, size_t l);

#endif // LINUX_H