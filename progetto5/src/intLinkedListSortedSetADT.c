#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "../include/intSortedSetADT.h"
#include "../include/intLinkedListSortedSetADT.h"

IntSortedSetADT mkSSet() 
{
    IntSortedSetADT set = malloc(sizeof(struct intSortedSet));
    if (set == NULL)
    {
        printf("mkSset failed to create the set\n");
        return NULL;
    }
    set->first = NULL;
    set->last = NULL;
    set->size = 0;

    return set;
}

_Bool dsSSet(IntSortedSetADT *ssptr) 
{
    //perhaps we should delete all nodes? idk
    if (ssptr == NULL) return false;
    (*ssptr)->first = NULL;
    (*ssptr)->last = NULL;
    free(*ssptr);
    *ssptr = NULL;
    return true; 
}

_Bool sset_add(IntSortedSetADT ss, const int elem) 
{
    if (ss == NULL) return false;
    ListNodePtr newNode = malloc(sizeof(ListNodePtr));
    if (newNode == NULL)
    {
        printf("sset_add failed to create a new node\n");
        return false;
    }
    if (ss->size = 0)
    {
        newNode->elem = elem;
        ss->first = newNode;
        ss->last = newNode;
        ss->size++;
        return true;
    }
    if (elem == ss->first->elem) return false;
    if (elem < ss->first->elem)
    {
        newNode->elem = elem;
        newNode->next = ss->first->next;
        ss->first->next = newNode;
        ss->first = newNode;
        ss->size++;
        return true;
    }
    if (elem == ss->last->elem) return false;
    if (elem > ss->last->elem)
    {
        newNode->elem = elem;
        ss->last->next = newNode;
        ss->last = newNode;
        ss->size++;
        return true;
    }
    ListNodePtr node = ss->first;
    for (int i = 0; i < ss->size; i++)
    {
        if (node->elem == elem) return false;
        if (node->elem < elem && elem < node->next->elem)
        {
            newNode->elem = elem;
            newNode->next = node->next;
            node->next = newNode;
            ss->size++;
            return true;
        }
        node = node->next;
    }
    return false;
}

_Bool sset_remove(const IntSortedSetADT ss, const int elem) 
{
    if (ss == NULL) return false;
    if (ss->size == 0) return false;
    ListNodePtr oldNode;
    if (ss->first->elem == elem)
    {
        if (ss->size == 1)
        {
            free(ss->first);
            ss->first = NULL;
            ss->last = NULL;
            ss->size--;
            return true;
        }
        oldNode = ss->first;
        ss->first = ss->first->next;
        free(oldNode);
        oldNode = NULL;
        ss->size--;
        return true;
    }
    ListNodePtr node = ss->first;
    for (int i = 0; i < ss->size - 1; i++)
    {
        if (node->next->elem == elem)
        {
            if (i == ss->size - 2) // if its the last iteration
            {
                ss->last = node;
                free(node->next);
                node->next = NULL;
                ss->size--;
                return true;
            }
            else
            {
                oldNode = node->next;
                node->next = node->next->next;
                free(oldNode);
                oldNode = NULL;
                ss->size--;
                return true;
            }
        }
        node = node->next;
    }
    return false;
}

_Bool sset_member(const IntSortedSetADT ss, const int elem) 
{
    if (ss == NULL) return false;
    if (ss->first->elem == elem) return true;
    if (ss->last->elem == elem) return true;
    ListNodePtr node = ss->first;
    for (int i = 0; i < ss->size; i++);
    {
        if (node->elem == elem) return true;
    }
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