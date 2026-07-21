#include "bf.h"

typedef struct Bf {
    size_t l;
    char * t;
} Bf;

Bf *bf_open(size_t l) {
    Bf *b = malloc(sizeof(Bf));
    if (!b) return NULL;

    b->l = l;
    b->t = calloc(l, sizeof(char));

    if (!b->t) {
        free(b);
        return NULL;
    }

    return b;
}

void bf_close(Bf *b) {
    if (!b) return;
    
    free(b->t);
    free(b);
}

int bf_dostring(Bf *b, char *s) {

}
