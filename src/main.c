#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "bf.h"
#include "platforms/platform.h"

const char *string =
    ">++++++++[<++++++++>-]<+."
;

int main(int argc, char **argv) {
    Bf* b = bf_new(1024);
    char string[1024];

    if (argc <= 1) {
        printf("Usage: %s [file.bf]\n", argv[0]);
        return 0;
    }

    FILE *f = fopen(argv[1], "rb");
    if ((f == NULL)) {
        perror("Error opening file %s\n");
        return 1;
    }
    fgets(string, 1024, f);

    //printf("CODE: %s\n\n", string);

    bf_dostring(b, string);

    fclose(f);
    bf_close(b);

    return 0;
}
