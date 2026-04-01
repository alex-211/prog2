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

        dsQueue(&pQ);

    }

    if (fct == 3) // dequeue
    {
        printf("testing function 3 dequeue\n");
        CharQueueADT pQ = mkQueue();
        char res;

        // test 3.1 NULL ptrs
        if (dequeue(NULL, NULL) != false) printf("test 3.1 failed\n");
        else printf("test 3.1 passed\n");

        // test 3.2 empty que
        if (dequeue(pQ, &res) != false) printf("test 3.2 failed");
        else printf("test 3.2 passed\n");

        // test 3.3 just works
        pQ->a[pQ->rear] = 'a';
        pQ->size++;

        pQ->rear++;
        pQ->a[pQ->rear] = 'b';
        pQ->size++;

        pQ->rear++;
        pQ->a[pQ->rear] = 'c';
        pQ->size++;
        if (dequeue(pQ, &res) != true || pQ->a[pQ->front] != 'b' || pQ->size != 2 || pQ->front != 1 || pQ->rear != 2 || res != 'a')
        {
            printf("test 3.3 failed:\n");
            printf("exp pQ->a[pQ->front] = b, got %c | exp pQ->size = 2, got %d | exp pQ->front = 1, got %d | exp pQ->rear = 2, got %d | exp res = a, got %c", pQ->a[pQ->front], pQ->size, pQ->front, pQ->rear, res);
        }
        else printf("test 3.3 passed\n");

        dsQueue(&pQ);
    }

    if (fct == 4) // function 4 isEmpty
    {
        printf("testing function 4 isEmpty\n");
        CharQueueADT pQ = mkQueue();

        // 4.1 null ptr
        if (isEmpty(NULL) != false) printf("test 4.1 failed\n");
        else printf("test 4.1 passed\n");

        // 4.2 actually empty struct
        if (isEmpty(pQ) != true) printf("test 4.2 failed\n");
        else printf("test 4.2 passed\n");

        // 4.3 non-empty struct
        pQ->size++;
        if (isEmpty(pQ) != false) printf("test 4.3 failed\n");
        else printf("test 4.3 passed\n");

        dsQueue(&pQ);
    }

    if (fct == 5)
    {
        printf("Not checking function 5 yet\n");
    }

    if (fct == 6) // peek
    {
        printf("Testing function 6 peek\n");
        CharQueueADT pQ = mkQueue();
        char res;

        pQ->a[pQ->rear] = 'a';
        pQ->size++;

        pQ->rear++;
        pQ->a[pQ->rear] = 'b';
        pQ->size++;

        // 6.1 null pointer
        if (peek(NULL, 10, NULL) != 0) printf("test 6.1 failed\n");
        else printf("test 6.1 passed\n");

        // 6.2 position out of bounds
        if (peek(pQ, 100, &res) != 0) printf("test 6.2 failed\n");
        else printf("test 6.2 passed\n");

        // 6.3 invalid position neg
        if (peek(pQ, -1, &res) != 0) printf("test 6.3 failed\n");
        else printf("test 6.3 passed\n");

        // just works
        if (peek(pQ, 1, &res) != 1 || res != 'b')
        {
            printf("test 6.4 failed\n");
            printf("exp res = b, got %c", res);
        }
        else printf("test 6.4 passed\n");
        dsQueue(&pQ);
    }
}

int main()
{
    tests(0);
    tests(1);
    tests(2);
    tests(3);
    tests(4);
    tests(5);
    tests(6);
    return 0;
}