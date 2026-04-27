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