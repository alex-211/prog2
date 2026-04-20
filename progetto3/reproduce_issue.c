#include "include/charQueueADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Starting reproduction...\n");
    for (int j = 0; j < 100; j++) {
        CharQueueADT q = mkQueue();
        for (int i = 0; i < 100; i++) {
            enqueue(q, 'A');
        }
        // Corruption should have happened. Let's trigger it by doing more allocations.
        void* p[100];
        for (int i = 0; i < 100; i++) {
            p[i] = malloc(16);
            if (p[i]) memset(p[i], 0, 16);
        }
        for (int i = 0; i < 100; i++) {
            free(p[i]);
        }
        // dsQueue will also call free
        dsQueue(&q);
    }
    printf("Finished reproduction without crash (unexpected)\n");
    return 0;
}
