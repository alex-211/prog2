#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "../include/charQueueADT.h"
#include "../include/linkedListQueue.h"

CharQueueADT mkQueue()
{
    CharQueueADT q = malloc(sizeof(struct charQueue));

    if (q == NULL) 
    {
        printf("mkQueue failed to create list\n");
        return NULL;
    }

    q->front = NULL;
    q->rear = NULL;

    return q;
}

void dsQueue(CharQueueADT *pq)
{
    free(*pq);
    *pq = NULL;
}

_Bool enqueue(CharQueueADT q, const char e)
{
    if (q == NULL || e == '\0') return false;
    ListNodePtr pLn = malloc(sizeof(ListNode));
    pLn->data = e;
    if (q->size == 0)
    {
        q->front = pLn;
        q->rear = pLn;
        q->size++;
        return true;
    }
    q->rear->next = pLn;
    q->rear = pLn;
    q->size++;
    return true;
}

_Bool dequeue(CharQueueADT q, char*res)
{
    if (q == NULL || res == NULL) return false;
    if (q->size == 0) return false;

    *res = q->front->data;
    q->front = q->front->next;
    q->size--;
    return true;
}