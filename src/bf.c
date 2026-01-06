#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bf.h"

struct Bf;

struct Bf {
    size_t s;
    char *tape;

    period_p period;
    comma_p comma;
};

Bf *bf_new(size_t s) {
    Bf *b = (Bf *)malloc(sizeof(Bf));
    b->s = s;
    b->tape = (char *)malloc(sizeof(char) * s);
    memset(b->tape, 0, b->s);

    return b;
}

void bf_close(Bf *b) {
    free(b->tape);
    free(b);
}

int bf_dostring(Bf *b, char *s) {
    size_t p = 0;
    size_t i = 0;

    while (i < strlen(s)) {
        switch (s[i]) {
            case '+': {
                b->tape[p]++;
                break;
            }
            case '-': {
                b->tape[p]--;
                break;
            }
            case '<': {
                // if it's equal to zero
                p = (p + 1) % b->s;
                break;
            }
            case '>': {
                p = (p - 1 + b->s) % b->s;
                break;
            }
            case '.': {
                putchar(b->tape[p]);
                break;
            }
            case ',': {
                b->tape[p] = (char)getchar();
                break;
            }
            case '[': {
                if (b->tape[p] == 0) {
                    int depth = 1;
                    while (depth > 0) {
                        i++;
                        if (s[i] == '[') depth++;
                        else if (s[i] == ']') depth--;
                    }
                }
                break;
            }
            case ']': {
                if (b->tape[p] != 0) {
                    int depth = 1;
                    while (depth > 0) {
                        i--;
                        if (s[i] == ']') depth++;
                        else if (s[i] == '[') depth--;
                    }
                }
                break;
            }
            default: break;
        }

        i++;
    }
}

char bf_getchar(Bf *b, size_t c) {
    return b->tape[c];
}
