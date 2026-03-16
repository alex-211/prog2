#include <stdio.h>
#include <string.h>

#include "../include/contact.h"

int main()
{
    int cef = test_contactEqEff();
    printf("test contactEqEff returned %d", cef);
    return 0;
}