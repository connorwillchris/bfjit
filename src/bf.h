#ifndef BF_H
#define BF_H

typedef struct Bf Bf;

Bf *bf_new(size_t s);

void bf_close(Bf *b);

int bf_dostring(Bf *b, char *s);

#endif
