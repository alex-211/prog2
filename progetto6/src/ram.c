#include "../include/ram.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ramCounter(RAM ram)
{
    if (ram == NULL) return 0;
    if (ram->s == LIBERO || ram->s == OCCUPATO) return 1;

    int lefties = 0;
    int righties = 0;
    RAM leftNode = ram->lbuddy;
    RAM rightNode = ram->rbuddy;

    if (leftNode) lefties = ramCounter(leftNode);
    if (rightNode) righties = ramCounter(rightNode);
    return lefties + righties;
}

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
    if (ram->rbuddy != NULL)
    {
        rightie = numfree(ram->rbuddy);
    }

    return leftie + rightie;
}

void ram2str_rec(char* string, RAM ram)
{
    char *s;
    char kb[10];
    if (ram->s == LIBERO) s = "{L,";
    if (ram->s == OCCUPATO) s = "{O,";
    else s = "{I,";
    
    snprintf(kb, 10, "%d,[", ram->KB);
    strcat(string, s);
    strcat(string, kb);

    strcat(string, "[");
    if (ram->lbuddy) ram2str_rec(string, ram->lbuddy);
    else strcat(string, "{N},");
    strcat(string, ",");

    if (ram->rbuddy) ram2str_rec(string, ram->rbuddy);
    else strcat(string, "{N}");
    strcat(string, "]");
}

char* ram2str(RAM ram)
{
    if (ram == NULL) return NULL;
    // let's be efficient and count the nodes
    int nodes = ramCounter(ram);
    char* string = malloc(nodes*10 + 1);

    if (nodes == 0)
    {
        string = "";
        return string;
    } 
    ram2str_rec(string, ram);
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
