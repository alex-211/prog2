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
    (*pq)->size = 0;
    (*pq)->front = NULL;
    (*pq)->rear = NULL;
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

_Bool isEmpty(CharQueueADT q)
{
    if (q == NULL) return false;
    if (q->size <= 0) return true;
    return false;
}

int size(CharQueueADT q)
{
    if (q == NULL) return -1;
    else return q->size;
}

_Bool peek(CharQueueADT q, int position, char* res)
{
    if (q == NULL || res == NULL) return false;
    if (position < 0 || position >= q->size) return false;
    if (q->size == 0) return false;

    ListNodePtr addr = q->front;

    for (int i = 0; i < position; i++) addr = addr->next;

    *res = addr->data;
    return true;
}