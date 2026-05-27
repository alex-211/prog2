#include "../include/ram.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ramCounter(RAM ram)
{
    if (ram == NULL) return 0;
    return 1 + ramCounter(ram->lbuddy) + ramCounter(ram->rbuddy);
}

RAM initram_internal(int M) 
{
    if (M < 1) return NULL;
    if ((M & (M-1)) != 0) return NULL; // "se non è una potenza di 2"

    RAM r = malloc(sizeof(struct nodo));
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

RAM initram(int M)
{
    if (M < 2) return NULL;
    if ((M & (M-1)) != 0) return NULL; // "se non è una potenza di 2"

    RAM r = malloc(sizeof(struct nodo));
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
    if (K <= 0) return NULL;
    if (K > ram->KB) return NULL;
    if (ram->s == OCCUPATO) return NULL;

    if (ram->s == INTERNO)
    {
        RAM ris = allocram(K, ram->lbuddy);
        if (ris) return ris;
        ris = allocram(K, ram->rbuddy);
        return ris;
    }

    if (K > ram->KB / 2)
    {
        ram->s = OCCUPATO;
        return ram;
    }
    RAM left = initram_internal(ram->KB / 2);
    RAM right = initram_internal(ram->KB / 2);
    if (left == NULL || right == NULL) return NULL;
    left->parent = ram;
    right->parent = ram;
    ram->rbuddy = right;
    ram->lbuddy = left;
    ram->s = INTERNO;

    return allocram(K, left);
}

Risultato deallocram(RAM ram)
{
    if (ram == NULL) return NOK;
    if (ram->s == LIBERO) return OK;
    if (ram->s != OCCUPATO) return NOK;

    RAM currentNode = ram;
    currentNode->s = LIBERO;
    while (currentNode->parent != NULL)
    {
        RAM rParent = currentNode->parent;
        if (rParent->lbuddy->s == LIBERO && rParent->rbuddy->s == LIBERO)
        {
            freeram(&(rParent->lbuddy));
            freeram(&(rParent->rbuddy));
            rParent->s = LIBERO;
            currentNode = rParent;
        }
        else break;
    }
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
    if (ram == NULL) {
        strcat(string, "{N}");
        return;
    }

    char kb[20];
    char *s;
    if (ram->s == LIBERO) s = "L";
    else if (ram->s == OCCUPATO) s = "O";
    else s = "I";
    
    snprintf(kb, 20, "{%d,%s,[", ram->KB, s);
    strcat(string, kb);

    ram2str_rec(string, ram->lbuddy);
    strcat(string, ",");
    ram2str_rec(string, ram->rbuddy);
    
    strcat(string, "]}");
}

char* ram2str(RAM ram)
{
    if (ram == NULL) return NULL;
    int nodes = ramCounter(ram);
    char* string = malloc(nodes * 40 + 1);
    if (string == NULL) return NULL;

    string[0] = '\0';
    ram2str_rec(string, ram);
    return string;
}

RAM str2ram_rec(char **ptr, RAM parent)
{
    char *s = *ptr;
    if (strncmp(s, "{N}", 3) == 0) {
        *ptr += 3;
        return NULL;
    }

    if (*s != '{') return NULL;
    s++;

    int kb = atoi(s);
    while (*s >= '0' && *s <= '9') s++;
    if (*s != ',') return NULL;
    s++;

    Stato stato;
    if (*s == 'L') stato = LIBERO;
    else if (*s == 'O') stato = OCCUPATO;
    else if (*s == 'I') stato = INTERNO;
    else return NULL;
    s++; 
    if (*s != ',') return NULL;
    s++; 
    if (*s != '[') return NULL;
    s++;

    RAM r = initram_internal(kb);
    if (r == NULL) return NULL;
    r->s = stato;
    r->parent = parent;

    *ptr = s;
    r->lbuddy = str2ram_rec(ptr, r);
    s = *ptr;
    if (*s != ',') return NULL;
    s++; 
    *ptr = s;
    r->rbuddy = str2ram_rec(ptr, r);
    s = *ptr;

    if (*s != ']') return NULL;
    s++; 
    if (*s != '}') return NULL;
    s++; 

    *ptr = s;
    return r;
}

RAM str2ram(char *str)
{
    if (str == NULL || strlen(str) == 0 || strcmp(str, "{N}") == 0) return NULL;
    char *ptr = str;
    return str2ram_rec(&ptr, NULL);
}

Risultato freeram(RAM* ramptr)
{
    if (ramptr == NULL || *ramptr == NULL) return NOK;

    if ((*ramptr)->lbuddy != NULL) freeram((&(*ramptr)->lbuddy));
    if ((*ramptr)->rbuddy != NULL) freeram((&(*ramptr)->rbuddy));

    free(*ramptr);
    *ramptr = NULL;
    return OK;
}
