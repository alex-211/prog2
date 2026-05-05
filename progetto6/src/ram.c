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
    r->parent = NULL;
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
    while (K <= nextNode->KB / 2)
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
    if (rParent != NULL)
    {
        if (rParent->lbuddy->s == LIBERO && rParent->rbuddy->s == LIBERO)
        {
            free(rParent->lbuddy);
            rParent->lbuddy = NULL;
            free(rParent->rbuddy);
            rParent->rbuddy = NULL;
            rParent->s = LIBERO;
            return OK;
        }
    }
    ram->s = LIBERO;
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

char* ram2str(RAM ram)
{
    if (ram == NULL) return NULL;
    char* string = malloc(696969);
    if (string == NULL)
    {
        printf("ram2str failed to allocate memory for a string");
        return NULL;
    }

    if (ram->s == LIBERO) snprintf(string, sizeof(string), "{%s%s,", string, "L");
    if (ram->s == OCCUPATO) snprintf(string, sizeof(string), "{%s%s,", string, "O");
    if (ram->s == INTERNO) snprintf(string, sizeof(string), "{%s%s,", string, "I");
    snprintf(string, sizeof(string), "%s%d,", string, ram->KB);

    if (ram->lbuddy == NULL) snprintf(string, sizeof(string), "%s[{%s},", string, "N");
    else snprintf(string, sizeof(string), "%s[%s],", string, ram2str(ram->lbuddy));

    if (ram->rbuddy == NULL) snprintf(string, sizeof(string), "%s{%s},", string, "N");
    else snprintf(string, sizeof(string), "%s[%s],", string, ram2str(ram->rbuddy));

    snprintf(string, sizeof(string), "%s}", string);

    return string;
}

RAM str2ram(char *str)
{
    return NULL;
}

Risultato freeram(RAM* ramptr)
{
    if (ramptr == NULL || *ramptr == NULL) return NOK;
    // mhh quanto adoro i puntatori a puntatori
    RAM node = *ramptr;
    if (node->s == LIBERO || node->s == OCCUPATO)
    {
        free(*ramptr);
        *ramptr = NULL;
    }

    RAM lnode = node->lbuddy;
    RAM rnode = node->rbuddy;

    if (lnode != NULL) freeram(&lnode);

    if (rnode != NULL) freeram(&rnode);

    // quindi ha senso fare la ricorsione...
    return OK;
}
