#include "../include/unity/unity.h"
#include "../include/ram.h"
#include "../include/tests.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void debugRam2str(void)
{
    puts("Begin debug ram2str() fct");
    RAM r = initram(64);

    allocram(16, r);
    allocram(29, r);

    char* string = ram2str(r);
    printf("\nFINAL OUTPUT %s\n\n", string);
    return;
}

int main(void)
{
    debugRam2str();
    UNITY_BEGIN();
    RUN_TEST(testInit);
    RUN_TEST(testAlloc);
    RUN_TEST(testDealloc);
    RUN_TEST(testNumfree);
    RUN_TEST(testRam2str);
    RUN_TEST(testStr2ram);
    RUN_TEST(testFreeram);
    return UNITY_END();
}