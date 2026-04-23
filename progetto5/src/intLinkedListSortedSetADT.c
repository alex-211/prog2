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

_Bool isEmptySSet(const IntSortedSetADT ss) 
{
    if (ss == NULL) return false;
    if (ss->size == 0) return true;
    return false;
}

int sset_size(const IntSortedSetADT ss) 
{
    if (ss == NULL) return -1;
    return ss->size;
}

_Bool sset_extract(IntSortedSetADT ss, int *ptr) 
{
    if (ss == NULL || *ptr == NULL) return false;
    if (isEmptySSet(ss)) return false;
    int randomNum = rand() % ss->size;
    ListNodePtr deadNode = ss->first;
    for (int i = 0; i < randomNum; i++)
    {
        deadNode = deadNode->next;
    }
    *ptr = deadNode->elem;
    sset_remove(ss, deadNode->elem);
}

_Bool sset_equals(const IntSortedSetADT s1, const IntSortedSetADT s2) 
{
    if (s1 == NULL || s2 == NULL) return false;
    if (s1->size != s2->size) return false;
    if (s1->size == 1)
    {
        if (s1->first == s2->first) return true;
        else return false;
    }
    ListNodePtr nodeS1 = s1->first;
    ListNodePtr nodeS2 = s2->first;
    for (int i = 0; i < s1->size; i++)
    {
        if (nodeS1->elem != nodeS2->elem) return false;
        nodeS1 = nodeS1->next;
        nodeS2 = nodeS2->next;
    }
    return true;
}

_Bool sset_subseteq(const IntSortedSetADT s1, const IntSortedSetADT s2) 
{
    if (s1 == NULL || s2 == NULL) return false;
    if (s1->size == 0 || s2->size == 0) return false;
    if (s1->size == 1 && s2->size == 1)
    {
        if (s1->first->elem == s2->first->elem) return true;
        else return false;
    }

    if (s1->size == s2->size)
    {
        if (sset_equals(s1, s2)) return true;
        return false;
    }
    if (s1->size > s2->size) return false;

    ListNodePtr nodeS1 = s1->first;
    ListNodePtr nodeS2 = s2->first;
    for (int i = 0; i < s1->size; i++)
    {
        bool nodePresent = false;
        for (int j = 0; j < s2->size; j++)
        {
            if (nodeS2->elem == nodeS1->elem)
            {
                nodePresent = true;
                break;
            }
            nodeS2 = nodeS2->next;
        }
        if (!(nodePresent)) return false;
        nodeS1 = nodeS1->next;
    }
    return true;
}

_Bool sset_subset(const IntSortedSetADT s1, const IntSortedSetADT s2) 
{
    if (s1 == NULL || s2 == NULL) return false;
    if (s1->size == 0) return false;
    if (s1->size >= s2->size) return false;

    ListNodePtr nodeS1 = s1->first;
    ListNodePtr nodeS2 = s2->first;
    for (int i = 0; i < s1->size; i++)
    {
        if (!(sset_member(s2, nodeS1->elem))) return false;
        nodeS1 = nodeS1->next;
    }
    return true;
}

IntSortedSetADT sset_union(const IntSortedSetADT s1, const IntSortedSetADT s2) 
{
    if (s1 == NULL || s2 == NULL) return NULL;
    if (s1->size == 0 && s2->size == 0) return mkSSet();
    if (s1->size == 0 && s2->size != 0) return s2; 
    if (s1->size != 0 && s2->size == 0) return s1;
    if (sset_subseteq(s1, s2)) return s2;
    if (sset_subset(s2, s1)) return s1;

    IntSortedSetADT unionSet = mkSSet();
    if (unionSet == NULL) return NULL;

    ListNodePtr nodeS1 = s1->first;
    for (int i = 0; i < s1->size; i++)
    {
        sset_add(unionSet, nodeS1->elem);
        nodeS1 = nodeS1->next;
    }
    ListNodePtr nodeS2 = s2->first;
    for (int i = 0; i < s2->size; i++)
    {
        if (!(sset_member(unionSet, nodeS2->elem)))
        {
            sset_add(unionSet, nodeS2->elem);
        }
        nodeS2 = nodeS2->next;
    }
    return unionSet;
}

IntSortedSetADT sset_intersection(const IntSortedSetADT s1, const IntSortedSetADT s2) 
{
    if (s1 == NULL || s2 == NULL) return NULL;
    if (s1->size == 0 && s2->size == 0) return mkSSet();
    if (s1->size == 0 && s2->size != 0) return s2; 
    if (s1->size != 0 && s2->size == 0) return s1;
    if (sset_subseteq(s1, s2)) return s1;
    if (sset_subset(s2, s1)) return s2;

    IntSortedSetADT setInters = mkSSet();
    if (setInters == NULL) return NULL;

    ListNodePtr node;
    if (s1->size <= s2->size)
    {
        node = s1->first;
        for (int i = 0; i < s1->size; i++)
        {
            if (sset_member(s2, node->elem)) sset_add(setInters, node->elem);
            node = node->next;
        }
    }
    else
    {
        node = s2->first;
        for (int i = 0; i < s2->size; i++)
        {
            if (sset_member(s1, node->elem)) sset_add(setInters, node->elem);
            node = node->next;
        }
    }
    return setInters;
}

IntSortedSetADT sset_subtraction(const IntSortedSetADT s1, const IntSortedSetADT s2) 
{
    // get the intersect of s1, s2, then remove all items of intersec from s1
    if (s1 == NULL || s2 == NULL) return NULL;
    if (s1->size == 0 && s2->size == 0) return mkSSet();
    
    IntSortedSetADT subtract = mkSSet();
    if (subtract == NULL) return NULL;

    IntSortedSetADT intersec = sset_intersection(s1, s2);
    if (intersec == NULL) return NULL;

    ListNodePtr node = intersec->first;
    for (int i = 0; i < intersec->size; i++)
    {
        sset_remove(s1, node->elem);
        node = node->next;
    }
    return NULL;   
}

_Bool sset_min(const IntSortedSetADT ss, int *ptr) 
{
    if (ss == NULL || *ptr == NULL) return false;
    if (ss->size == 0) return false;

    *ptr = ss->first->elem;
    return true;
}

_Bool sset_max(const IntSortedSetADT ss, int *ptr) 
{
    if (ss == NULL || *ptr == NULL) return false;
    if (ss->size == 0) return false;

    *ptr = ss->last->elem;
    return true;
}

_Bool sset_extractMin(IntSortedSetADT ss, int *ptr) 
{
    int remVal;
    if (!(sset_min(ss, &remVal))) return false;
    *ptr = remVal;
    return true;
}

_Bool sset_extractMax(IntSortedSetADT ss, int *ptr) 
{
    int remVal;
    if (!(sset_max(ss, &remVal))) return false;
    *ptr = remVal;
    return true;       
}