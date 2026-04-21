#include "../include/charQueueADT.h"
#include "../include/charArrayQueue.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

CharQueueADT mkQueue() // fct 0
{
    CharQueueADT pQueue = malloc(sizeof(struct charQueue));
    // check if mem is actually allocated
    if (pQueue == NULL)
    {
        printf("mkQueue failed to create the struct\n");
        return NULL;
    }
    pQueue->capacity = INITIAL_CAPACITY;
    pQueue->a = malloc((sizeof(char))*(pQueue->capacity));
    if (pQueue->a == NULL)
    {
        printf("mkQueue failed to create the array inside the struct - aborting");
        dsQueue(&pQueue);
        return NULL;
    }
    pQueue->size = 0;
    pQueue->rear = 0;
    pQueue->front = 0;
    return pQueue;
}

void dsQueue(CharQueueADT *pq) // fct 1
{
    if (*pq == NULL) return;
    if ((*pq)->a != NULL) free((*pq)->a); // why this syntax?? why??!!?
    free(*pq);
    *pq = NULL; // perché dereferenziare un puntatore? perché abbiamo un puntatore a puntatore
}

bool enqueue(CharQueueADT q, const char e) // fct 2
{
    if (q == NULL) return false;
    if (q->size == q->capacity)
    {
        q->capacity = q->capacity * 2;
        char* na = malloc(sizeof(char)*(q->capacity));
        if (na == NULL)
        {
            printf("Failed to creat an expanded array, aborting");
            return false;
        }
        for (int i = 0; i < q->size; i++) na[i] = q->a[(q->front + i)  % q->capacity];
        free(q->a);
        q->a = na;
        q->front = 0;
        q->rear = q->size;
    }
    q->a[q->rear] = e;
    q->rear = (q->rear + 1)  % q->capacity;
    q->size++;
    return true;
}

bool dequeue(CharQueueADT q, char*res) // fct 3
{
    if (q == NULL || res == NULL) return false;
    if (q->size == 0) return false;
    *res = q->a[q->front];
    q->a[q->front] = '\0';
    q->front = (q->front + 1) % q->capacity;
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
    if (position < 0 || position >= q->size) return false;

    *res = q->a[(q->front + position)  % q->capacity];
    return true;
}