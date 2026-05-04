#include "../include/unity/unity.h"
#include "../include/ram.h"
#include "../include/tests.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(testInit);
    RUN_TEST(testAlloc);
    RUN_TEST(testDealloc);
    //RUN_TEST(testNumfree);
    return UNITY_END();
}