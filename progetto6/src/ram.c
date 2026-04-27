#include "../include/ram.h"
#include <stdlib.h>
#include <stdio.h>

RAM initram(int M)
{
    if (M <= 1) return NULL;
    if ((M & (M-1)) != 0) return NULL; // "se non è una potenza di 2"

    RAM r = malloc(sizeof(*r));
    if (r == NULL)
    {
        printf("initram failed to create ram node\n");
        return NULL;
    }
    r->KB = M;
    r->s = LIBERO;
    r->lbuddy = NULL;
    r->rbuddy = NULL;

    return r;
}

RAM allocram(int K, RAM ram)
{
    if (ram == NULL) return NULL;
    if (K<=0) return NULL;
    if (K > ram->KB) return NULL;

    RAM nextNode = ram;
    while (nextNode->s != LIBERO)
    {
        if (nextNode->s == OCCUPATO) return NULL;

        if (nextNode->lbuddy->s == LIBERO) nextNode = nextNode->lbuddy;
        else if (nextNode->rbuddy->s == LIBERO) nextNode = nextNode->rbuddy;
        else return NULL;
    }

    if (K > nextNode->KB / 2) // THIS NEEDS TO BE A WHILE, FIX MEEE
    {
        nextNode->parent->s = INTERNO;
        nextNode->s = OCCUPATO;
        return nextNode;
    }
    else 
    {
        RAM leftie = initram(nextNode->KB / 2);
        RAM rightie = initram(nextNode->KB / 2);

        if (leftie == NULL || rightie == NULL) return NULL;

        nextNode->s = INTERNO;
        nextNode->lbuddy = leftie;
        nextNode->rbuddy = rightie;

        leftie->parent = nextNode;
        rightie->parent = nextNode;

        leftie->s = OCCUPATO;
        return leftie;
    }
}