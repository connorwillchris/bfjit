#include <stdio.h>
#include <stdlib.h>

#include "bf.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);

        return 1;
    }

    // by default, open a 30_000 byte array for brainfuck using JIT
    Bf *state = bf_open(30000);
    // error if returns NULL. Just a quick and easy return for now.
    if (!state) return 1;

    // execute file here...


    // now we close.
    bf_close(state);

    return 0;
}