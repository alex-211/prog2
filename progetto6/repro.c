#include <stdio.h>
#include <stdlib.h>
#include "include/ram.h"

int main() {
    RAM r = initram(64);
    if (r == NULL) {
        printf("initram failed\n");
        return 1;
    }
    printf("Calling ram2str...\n");
    char* s = ram2str(r);
    printf("Result: %s\n", s);
    return 0;
}
