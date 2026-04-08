#include "../include/charQueueADT.h"
#include "../include/charArrayQueue.h"
#include <stdbool.h>
#include <stdlib.h>

CharQueueADT mkQueue() // fct 0
{
    CharQueueADT pQueue = malloc(sizeof(struct charQueue));
    // check if mem is actually allocated
    if (pQueue == NULL)
    {
        return NULL;
    }
    pQueue->capacity = INITIAL_CAPACITY;
    pQueue->a = malloc((sizeof(char))*(pQueue->capacity));
    pQueue->size = 0;
    pQueue->rear = 0;
    pQueue->front = 0;
    return pQueue;
}

void dsQueue(CharQueueADT *pq) // fct 1
{
    if (*pq == NULL) return;
    free((*pq)->a); // why this syntax?? why??!!?
    free(*pq);
    *pq = NULL; // perché dereferenziare un puntatore? perché abbiamo un puntatore a puntatore
}

bool enqueue(CharQueueADT q, const char e) // fct 2
{
    // this fails teacher's test, dont know why
    // collegue suggests:
    // 👀ricorda che e un Array circolare( cose tanto brutte negli indici quando fai resize)
    if (q == NULL) return false;
    if (q->size == q->capacity) return false;
    if (e == '\0') return false;
    q->rear++;
    q->a[q->rear] = e;
    return true;
}

bool dequeue(CharQueueADT q, char*res) // fct 3
{
    if (q == NULL || res == NULL) return false;
    if (q->size == 0) return false;
    *res = q->a[q->front];
    q->a[q->front] = '\0';
    q->front++;
    q->size--;
    return true;
}

bool isEmpty(CharQueueADT q) // fct 4
{
    if (q == NULL) return false;
    if (q->size == 0) return true;
    return false;
}

int size(CharQueueADT q) // fct 5
{
    if (q == NULL) return 0;
    return q->size;
}

bool peek(CharQueueADT q, int position, char* res) // fct 6
{
    if (q == NULL || res == NULL) return false;
    if (position > q->rear || position < q->front) return false;

    *res = q->a[position];
    return true;
}