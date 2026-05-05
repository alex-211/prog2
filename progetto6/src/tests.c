#include "../include/unity/unity.h"
#include "../include/ram.h"
#include "../include/tests.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void testInit(void)
{
    RAM r = initram(0);
    TEST_ASSERT_NULL(r);

    RAM t = initram(1);
    TEST_ASSERT_NULL(t);

    RAM y = initram(-1);
    TEST_ASSERT_NULL(y);

    RAM u = initram(5);
    TEST_ASSERT_NULL(u);

    RAM o = initram(2);
    TEST_ASSERT_NOT_NULL(o);
}

void testAlloc(void)
{
    RAM r = initram(64);

    RAM t = allocram(0, NULL);
    TEST_ASSERT_NULL(t);
    
    t = allocram(-1, r);
    TEST_ASSERT_NULL(t);

    t = allocram(128, r);
    TEST_ASSERT_NULL(t);

    t = allocram(31, r);
    TEST_ASSERT_NOT_NULL(t);
    TEST_ASSERT_NOT_NULL(t->parent);
    TEST_ASSERT_NOT_NULL(r->lbuddy);
}

void testDealloc(void)
{
    RAM r = initram(64);

    Risultato ris = deallocram(NULL);
    TEST_ASSERT_EQUAL(NOK, ris);

    Risultato ris2 = deallocram(r);
    TEST_ASSERT_EQUAL(OK, ris2);
    TEST_ASSERT_EQUAL(LIBERO, r->s);

    RAM r2 = initram(32);
    allocram(16, r); // failing to allocate the ram on the line, that's great!!
    Risultato ris3 = deallocram(r2->lbuddy);
    TEST_ASSERT_EQUAL(OK, ris3);
    TEST_ASSERT_NULL(r2->lbuddy);

    RAM r3 = initram(64);
    allocram(16, r3);
    Risultato ris4 = deallocram(r3->lbuddy);
    TEST_ASSERT_EQUAL(NOK, ris4);
    TEST_ASSERT_NOT_NULL(r3->lbuddy);
}

void testNumfree(void)
{
    return;
}

void testRam2str(void)
{
    ram2str(NULL);
    return;
}

void testStr2ram(void)
{
    return;
}

void testFreeram(void)
{
    return;
}