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

    RAM leftie;
    RAM rightie;
    while (K < nextNode->KB / 2)
    {
        nextNode->s = INTERNO;

        leftie = initram(nextNode->KB / 2);
        rightie = initram(nextNode->KB / 2);

        if (leftie == NULL || rightie == NULL) return NULL;

        nextNode->lbuddy = leftie;
        nextNode->rbuddy = rightie;

        leftie->parent = nextNode;
        rightie->parent = nextNode;

        nextNode = leftie;
    }
        nextNode->s = OCCUPATO;
        return nextNode;
}

Risultato deallocram(RAM ram)
{
    if (ram == NULL) return NOK;
    if (ram->s == INTERNO) return NOK; //? credo

    RAM rParent = ram->parent;

    if (rParent->lbuddy == ram) rParent->lbuddy = NULL;
    if (rParent->rbuddy == ram) rParent->rbuddy = NULL;

    free(ram);
    ram = NULL;

    return OK;
}

int numfree(RAM ram)
{
    if (ram == NULL) return -1;
    if (ram->s == LIBERO) return ram->KB;
    if (ram->s == OCCUPATO) return 0;

    int leftie = 0;
    int rightie = 0;

    if (ram->lbuddy != NULL)
    {
        leftie = numfree(ram->lbuddy);
    }
    if (ram->rbuddy != NULL);
    {
        rightie = numfree(ram->rbuddy);
    }

    return leftie + rightie;
}