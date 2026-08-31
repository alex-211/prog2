Procedendo in modo iterativo e incrementale, sviluppare un modulo
intLinkedListSortedSetADT.c che implementa un insieme ordinato di interi (int)
tramite una lista linkata.

In particolare, il modulo deve soddisfare la specifica:
#ifndef GUARD_IntSortedSetADT
#define GUARD_IntSortedSetADT

/** Un tipo di dato per gli insiemi ordinati di int
*/
typedef struct intSortedSet *IntSortedSetADT;

/*
 NOTA:
 le seguenti funzioni, in base al loro tipo, devono restituire 
 NULL, -1 oppure false (0) se ricevono uno o più puntatori NULL come parametri di tipo IntSortedSetADT
 (o altri argomenti "errati")
 */

IntSortedSetADT mkSSet(); // restituisce un insieme vuoto
_Bool dsSSet(IntSortedSetADT*); // distrugge l'insieme, recuperando la memoria
_Bool sset_add(IntSortedSetADT, const int); // aggiunge un elemento all'insieme (restituisce 0 se l'elemento era gia' presente, 1 altrimenti)
_Bool sset_remove(IntSortedSetADT, const int); // toglie un elemento all'insieme (restituisce 0 se l'elemento non era presente, 1 altrimenti)
_Bool sset_member(const IntSortedSetADT, const int); // controlla se un elemento appartiene all'insieme
_Bool isEmptySSet(const IntSortedSetADT); // controlla se l'insieme e' vuoto
int sset_size(const IntSortedSetADT); // restituisce il numero di elementi presenti nell'insieme, -1 se NULL
_Bool sset_extract(IntSortedSetADT, int *); // toglie e restituisce un elemento a caso dall'insieme, restituisce false se l'insieme è NULL oppure è vuoto
_Bool sset_equals(const IntSortedSetADT, const IntSortedSetADT); // controlla se due insiemi sono uguali
_Bool sset_subseteq(const IntSortedSetADT, const IntSortedSetADT); // controlla se il primo insieme e' incluso nel secondo
_Bool sset_subset(const IntSortedSetADT, const IntSortedSetADT); // contr. se il primo ins. e' incluso strettamente nel secondo
IntSortedSetADT sset_union(const IntSortedSetADT, const IntSortedSetADT); // restituisce l'unione di due insiemi
IntSortedSetADT sset_intersection(const IntSortedSetADT, const IntSortedSetADT); // restituisce l'intersezione di due insiemi
IntSortedSetADT sset_subtraction(const IntSortedSetADT, const IntSortedSetADT); // restituisce l’insieme ottenuto dal primo togliendo gli elementi del secondo
_Bool sset_min(const IntSortedSetADT, int *); // restituisce l'elemento minimo, restituisce false se l'insieme è NULL oppure è vuoto
_Bool sset_max(const IntSortedSetADT, int *); // restituisce l'elemento massimo, restituisce false se l'insieme è NULL oppure è vuoto
_Bool sset_extractMin(IntSortedSetADT, int *); // toglie e restituisce l'elemento minimo, restituisce false se l'insieme è NULL oppure è vuoto
_Bool sset_extractMax(IntSortedSetADT, int *); // toglie e restituisce l'elemento massimo, restituisce false se l'insieme è NULL oppure è vuoto

#endif

Per cominciare la vostra implementazione locale, potete basarvi su questi file di scheletro:

#ifndef GUARD_IntLinkedListSortedSetADT
#define GUARD_IntLinkedListSortedSetADT

typedef struct listNode ListNode, *ListNodePtr;

struct listNode {
   int elem;
   ListNodePtr next;
};

struct intSortedSet {
    ListNodePtr first; /* Punta al primo nodo dell'insieme, se l'insieme e' vuoto vale NULL */
    ListNodePtr last; /* Punta all'ultimo nodo dell'insieme, se l'insieme e' vuoto vale NULL */
    int size; /* Numero di elementi presenti nell'insieme */
};

#endif

#include <stdlib.h>
#include <stdbool.h>

#include "intSortedSetADT.h"
#include "intLinkedListSortedSetADT.h"

IntSortedSetADT mkSSet() {
    return NULL;
}

_Bool dsSSet(IntSortedSetADT *ssptr) {
    return false;
}

_Bool sset_add(IntSortedSetADT ss, const int elem) {
    return false;
}

_Bool sset_remove(const IntSortedSetADT ss, const int elem) {
    return false;
}

_Bool sset_member(const IntSortedSetADT ss, const int elem) {
    return false;
}

_Bool isEmptySSet(const IntSortedSetADT ss) {
    return false;
}

int sset_size(const IntSortedSetADT ss) {
    return -1;
}

_Bool sset_extract(IntSortedSetADT ss, int *ptr) {
    return false;
}

_Bool sset_equals(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return false;
}

_Bool sset_subseteq(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return false;
}

_Bool sset_subset(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return false;
}

IntSortedSetADT sset_union(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return NULL; 
}

IntSortedSetADT sset_intersection(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return NULL;
}

IntSortedSetADT sset_subtraction(const IntSortedSetADT s1, const IntSortedSetADT s2) {
    return NULL;   
}

_Bool sset_min(const IntSortedSetADT ss, int *ptr) {
    return false;
}

_Bool sset_max(const IntSortedSetADT ss, int *ptr) {
    return false;
}

_Bool sset_extractMin(IntSortedSetADT ss, int *ptr) {
    return false;    
}

_Bool sset_extractMax(IntSortedSetADT ss, int *ptr) {
    return false;       
}


Potete iniziare a sviluppare la vostra suite di test partendo da:
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "intSortedSetADT.h"
#include "intLinkedListSortedSetADT.h"

IntSortedSetADT mkSSetv(int count, ...) {
    IntSortedSetADT set = mkSSet();

    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        int num = va_arg(args, int);
        sset_add(set,num);        
    }
    va_end(args);
    return set;
}

char *toString(IntSortedSetADT set) {
    char *sout = malloc(100*sizeof(char));

    ListNodePtr nptr = set->first;
    sprintf(sout, "{");
    while (nptr) {
        if (nptr == set->first)
            sprintf(sout+strlen(sout), "%d", nptr->elem);
        else
            sprintf(sout+strlen(sout), ",%d", nptr->elem);
        nptr = nptr->next;
    }

    sprintf(sout+strlen(sout), "}");

    return sout;
}

int check_mkSSet() {
    int passed = 1;
    printf("mkSet()\n");    
    IntSortedSetADT sptr = mkSSet();
    if (!sptr) {
        printf("FAILED");
        printf("EXPECTED: not %d\n", 0);   
    } else
        printf("OK\n");
    printf("RESULT:%ld\n\n", (long)sptr);  
    return passed;
}

int check_dsSSet() {
    int passed = 1;

    if (passed) {
        _Bool rv;
        IntSortedSetADT sptr = mkSSet();
        printf("dsSSet({})\n");    
        rv = dsSSet(&sptr);
        if (!rv || sptr) {
            printf("FAILED\n");
            printf("EXPECTED: NOT %d AND PTR %ld\n", 0, (long)NULL); 
            passed=0;  
        } else {
            printf("OK\n");
        }
        printf("RESULT:%d AND PTR %ld\n\n", rv, (long)sptr);
    }  

    if (passed) {
        _Bool rv;
        printf("dsSSet(NULL)\n");    
        rv = dsSSet(NULL);
        if (rv) {
            printf("FAILED\n");
            printf("EXPECTED: %d\n", 0);
            passed=0;   
        } else {
            printf("OK\n");
        }
        printf("RESULT:%d\n\n", rv);
    }

    return passed;
}

int check_sset_add() {
    int passed=1;

    return passed;
}

int check_sset_remove(){
    int passed=1;

    return passed;
}

int check_sset_member(){
    int passed=1;

    return passed;  
}

int check_isEmptySSet(){
    int passed=1;

    return passed;
}

int check_sset_size(){
    int passed=1;

    return passed;
}


int check_sset_extract(){
    int passed=1;

    return passed;
}

int check_sset_equals(){
    int passed=1;

    return passed;
}

int check_sset_subseteq(){
    int passed=1;

    return passed;
}

int check_sset_subset() {
    int passed=1;

    return passed;
}


int check_sset_union() {
    int passed=1;

    return passed;
}

int check_sset_intersection() {
    int passed=1;

    return passed;
}

int check_sset_subtraction() {
    int passed=1;

    return passed;
}

int check_sset_min(){
    int passed=1;

    return passed;
}

int check_sset_max(){
    int passed=1;

    return passed;
}

int check_sset_extractMin(){
    int passed=1;

    return passed;
}

int check_sset_extractMax(){
    int passed=1;

    return passed;
}

int main(int argc, char *argv[]) {
  puts("BEGIN TEST intLinkedListSortedSetADT"); 

  {
    printf("TEST mkSSet\n");
    check_mkSSet();
    printf("\n");
  }

  {
    printf("TEST dsSSet\n");
    check_dsSSet();
    printf("\n");
  }

  {
    printf("TEST sset_add\n");
    check_sset_add();
    printf("\n");
  }

  {
    printf("TEST sset_remove\n");    
    check_sset_remove();
    printf("\n");
  }

  {
    printf("TEST sset_member\n");    
    check_sset_member();
    printf("\n");
  }

  {
    printf("TEST isEmptySSet\n");    
    check_isEmptySSet();
    printf("\n");
  }

  {
    printf("TEST sset_size\n");    
    check_sset_size();
    printf("\n");
  }

  {
    printf("TEST sset_extract\n");    
    check_sset_extract();
    printf("\n");
  }

  {
    printf("TEST sset_equals\n");    
    check_sset_equals();
    printf("\n");
  }

  {
    printf("TEST sset_subseteq\n");    
    check_sset_subseteq();
    printf("\n");
  }

  {
    printf("TEST sset_subset\n");    
    check_sset_subset();
    printf("\n");
  }

  {
    printf("TEST sset_union\n");    
    check_sset_union();
    printf("\n");
  }

  {
    printf("TEST sset_intersection\n");    
    check_sset_intersection();
    printf("\n");
  }

  {
    printf("TEST sset_subtraction\n");    
    check_sset_subtraction();
    printf("\n");
  }

  {
    printf("TEST sset_min\n");    
    check_sset_min();
    printf("\n");
  }

  {
    printf("TEST sset_max\n");    
    check_sset_max();
    printf("\n");
  }

  {
    printf("TEST sset_extractMin\n");    
    check_sset_extractMin();
    printf("\n");
  }

  {
    printf("TEST sset_extractMax\n");    
    check_sset_extractMax();
    printf("\n");
  }
}


Successivamente apriremo un quiz Moodle dove potrete incollare la vostra soluzione, sottoporla a test automatici e inviarla ai docenti.

===============================

Istruzioni di compilazione con la test suite:

    Compilando i file forniti con:

    gcc -o test_intLinkedListSortedSetADT test_intLinkedListSortedSetADT_empty.c  intLinkedListSortedSetADT_empty.c

    e poi lanciando:

    ./test_intLinkedListSortedSetADT

    otterrete un paio di FAIL di test forniti come esempio.

    Il progetto richiede di completare intLinkedListSortedSetADT_empty.c (rinominandolo in intLinkedListSortedSetADT.c) e la test suite 

    test_intLinkedListSortedSetADT_empty.c (rinominandola in test_intLinkedListSortedSetADT.c)

    in modo che compilando con:

    gcc -o test_intLinkedListSortedSetADT test_intLinkedListSortedSetADT.c  intLinkedListSortedSetADT.c

e poi lanciando:

./test_intLinkedListSortedSetADT

si ottengano tutti OK