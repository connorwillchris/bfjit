#ifndef BF_H
#define BF_H

#include <stdlib.h>
#include <stdint.h>

/*
 * Bf - A simple Brainfuck interpreter state.
 */
typedef struct Bf Bf;

/*
 * Open a new brainfuck state. Returns `NULL` on failure.
 */
Bf *bf_open(size_t l);

/*
 * Deinitialize a brainfuck state.
 */
void bf_close(Bf *b);

/* 
 *
 */
int bf_dostring(Bf *b, char *s);

#endif // BF_H