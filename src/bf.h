#ifndef BF_H
#define BF_H

#include <stddef.h>

typedef struct Bf Bf;

typedef void (*period_p)(Bf*);

typedef char (*comma_p)(Bf*, size_t);

/// @brief Creates a new given BF state with tape size `s`.
/// @param s Size of tape in bytes.
/// @return The BF state as a pointer.
Bf *bf_new(size_t s);

/// @brief Closes the state and frees all data on the heap.
/// @param b Brainfuck state pointer.
void bf_close(Bf *b);

/// @brief Executes a given string `s` as code. Does not use JIT.
/// @param b Brainfuck state pointer.
/// @param s Char pointer to bf code.
/// @return Error code. 0 on success, 1 on fail.
int bf_dostring(Bf *b, char *s);

char bf_getchar(Bf *b, size_t c);

#endif
