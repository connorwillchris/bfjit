#include <stdio.h>
#include "bf.h"

const char *string =
    ">++++++++[<++++++++>-]<+."
;

int
main(int argc, char **argv) {
    Bf* b = bf_new(1024);

    printf("Executing : %s\n", string);
    int result = bf_dostring(b, string);
    printf("\nDONE.\n");

    bf_close(b);

    return 0;
}
