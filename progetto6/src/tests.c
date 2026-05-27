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
    allocram(16, r2); // fix typo: was allocram(16, r)
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
    RAM r = initram(64);
    TEST_ASSERT_EQUAL(64, numfree(r));

    allocram(16, r);
    TEST_ASSERT_EQUAL(48, numfree(r));

    allocram(32, r);
    TEST_ASSERT_EQUAL(16, numfree(r));

    freeram(&r);
}

void testRam2str(void)
{
    RAM r = initram(64);
    char* s = ram2str(r);
    TEST_ASSERT_EQUAL_STRING("{64,L,[{N},{N}]}", s);
    free(s);

    allocram(16, r);
    s = ram2str(r);
    // Left-priority: 64 -> 32,32 -> 16(O),16(L),32(L)
    TEST_ASSERT_EQUAL_STRING("{64,I,[{32,I,[{16,O,[{N},{N}]},{16,L,[{N},{N}]}]},{32,L,[{N},{N}]}]}", s);
    free(s);

    freeram(&r);
}

void testStr2ram(void)
{
    char* s = "{64,I,[{32,O,[{N},{N}]},{32,L,[{N},{N}]}]}";
    RAM r = str2ram(s);
    TEST_ASSERT_NOT_NULL(r);
    TEST_ASSERT_EQUAL(64, r->KB);
    TEST_ASSERT_EQUAL(INTERNO, r->s);
    TEST_ASSERT_NOT_NULL(r->lbuddy);
    TEST_ASSERT_EQUAL(OCCUPATO, r->lbuddy->s);
    TEST_ASSERT_EQUAL(32, r->lbuddy->KB);
    TEST_ASSERT_NOT_NULL(r->rbuddy);
    TEST_ASSERT_EQUAL(LIBERO, r->rbuddy->s);
    TEST_ASSERT_EQUAL(32, r->rbuddy->KB);

    char* s2 = ram2str(r);
    TEST_ASSERT_EQUAL_STRING(s, s2);

    free(s2);
    freeram(&r);
}

void testFreeram(void)
{
    RAM r = initram(64);
    allocram(16, r);
    Risultato ris = freeram(&r);
    TEST_ASSERT_EQUAL(OK, ris);
    TEST_ASSERT_NULL(r);
}