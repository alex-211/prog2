#include <stdio.h>
#include <stdbool.h>

#include <../include/charArrayQueue.h>
#include <../include/charQueueADT.h>

void tests(int fct)
{
    if (fct == 0) // mkQueue
    {
        printf("Testing function 0 mkQueue\n");
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

        dsQueue(&pQ);
        return;


    }

    if (fct == 1) // disque
    {
        printf("testing function 1 dsQueue\n");
        CharQueueADT pQ = mkQueue();
        dsQueue(&pQ);
        if (pQ != NULL) printf("test 1.1 failed\n");
        else printf("test 1.1 passed\n");
        return;
    }

    if (fct == 2) // enqueue
    {
        printf("testing function 2 enqueue\n");
        CharQueueADT pQ = mkQueue();

        //test 2.1 NULL pointer
        if (enqueue(NULL, 'a') != false) printf("test 2.1 failed\n");
        else printf("test 2.1 passed\n");

        // test 2.2 empty string
        if (enqueue(pQ, '\0') != false) printf("test 2.2 failed\n");
        else printf("test 2.2 passed\n");

        // test 2.3 just adding
        if (enqueue(pQ, 'a') != true || pQ->rear != 1 || pQ->a[pQ->rear] != 'a')
        {
            printf("test 2.3 failed\n");
            printf("Exp rear = 1, got %d | exp a[rear] = 'a', got %c\n", pQ->rear, pQ->a[pQ->rear]);
        }
        else printf("test 2.3 passed\n");

        // test 2.4 full queue
        pQ->size = pQ->capacity;
        if (enqueue(pQ, 'a') != false) printf("test 2.4 failed\n");
        else printf("test 2.4 passed\n");

    }

}

int main()
{
    tests(0);
    tests(1);
    tests(2);
    return 0;
}