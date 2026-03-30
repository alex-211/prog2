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
    if (q == NULL) return false;
    if (q->size == q->capacity) return false;
    if (e == '\0') return false;
    q->rear++;
    q->a[q->rear] = e;
    return true;
}

bool dequeue(CharQueueADT q, char*res) // fct 3
{

}

bool isEmpty(CharQueueADT q) // fct 4
{

}

int size(CharQueueADT q) // fct 5
{

}

bool peek(CharQueueADT q, int position, char* res) // fct 6
{

}