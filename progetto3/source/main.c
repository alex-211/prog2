#include <stdio.h>
#include <stdbool.h>

#include <../include/charArrayQueue.h>
#include <../include/charQueueADT.h>

void tests(int fct)
{
    if (fct == 0) // mkque
    {
        printf("Testing function 0 mkqueue\n");
        CharQueueADT pQ = mkQueue();

        if (pQ == NULL)
        {
            printf("mkQueue failed and returned NULL\n");
            return;
        }

        if (pQ->capacity != INITIAL_CAPACITY) printf("test 0.1 failed\n");
        else printf("test 0.1 passed\n");

        if (pQ->size != 0) printf("test 0.2 failed\n");
        else printf("test 0.2 passed\n");

        if (pQ->rear != 0) printf("test 0.3 failed\n");
        else printf("test 0.3 passed\n");

        if (pQ->front != 0) printf("test 0.4 failed\n");
        else printf("test 0.4 passed\n");

        if (pQ->a == NULL) printf("test 0.5 failed\n");
        else printf("test 0.5 passed\n");

        // disqueue(pQ);
        return;


    }

    if (fct == 1) // disque
    {
        printf("testing function 1 disqueue\n");
        CharQueueADT pQ = mkQueue();
        dsQueue(&pQ);
        if (pQ != NULL) printf("test 1.1 failed\n");
        else printf("test 1.1 passed\n");
        return;
    }

}

int main()
{
    tests(0);
    tests(1);
    return 0;
}