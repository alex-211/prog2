#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int stoib(char *s, unsigned short b, int *r) {

    //NOTE \n and \t count as a whitespace
    // NOTE the leading whitespace needs to be counted only if there's a valid char in the string!
    // NOTE whitespace in the middle of the string need not be counted

    // check all arguments are valid
    if (s == NULL || b == 0 || r == NULL) return 0;

    *r = 0;
    int retVal = 0;
    int sign = +1;
    size_t sSize = strlen(s);

    // check base
    if (b < 2 || b > 36) return 0;

    // check when the string starts
    int i = 0;
    while (i <= sSize && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
    {
        retVal++;
        i++;
    }

    // check sign
    if (s[i] == '-')
    {
        sign = -1;
        i++;
        retVal++;
    }
    // since we assumed sign is positive, if we see "+" we just need to skip it in our for loop
    else if (s[i] == '+')
    {
        i++;
        retVal++;
    }

    // empty string/only sign means return value should be 0
    if (i == sSize) return 0;

    bool stringIsValid = false;

    for(int j = i; j < sSize; j++)
    {
        int currentValue = 0;

        // check for whitespace
        // shouldn't count this whitespace so we just need a break
        if (s[j] == ' ')
        {
            break;
        }

        // check if char is allowed in our base
        // bases 2-10
        if (b >= 2 && b <= 10)
        {
            if (!(s[j] >= '0' && s[j] < ('0' + b)))
            {
                break;
            }
            else
            {
                stringIsValid = true;
                currentValue = s[j] - '0';
            }
        }

        // bases 11-36
        else
        {
            if  (!(s[j] >= '0' && s[j] < ('0' + 10)) || // check numbers
                 !(s[j] >= 'A' && s[j] < ('A' + b - 10)) // check letters (uppercase only)
                )
            {
                break;
            }
            else
            {
                if (s[j] >= '0' && s[j] < ('0' + 10))
                {
                    stringIsValid = true;
                    currentValue = s[j] - '0';
                }
                if (s[j] >= 'A' && s[j] < ('A' + b - 10))
                {
                    stringIsValid = true;
                    currentValue = s[j] - 'A' + 10;
                }
                if (s[j] >= 'a' && s[j] < ('a' + b - 10))
                {
                    stringIsValid = true;
                    currentValue = s[j] - 'a' + 10;
                }
            }
        }

        *r = *r * b + currentValue;
        retVal++;
    }

    // this is needed cos apparently whitespace need only be counted when there's a valid char in the string
    if (stringIsValid == false)
    {
        retVal = 0;
    }

    *r = *r * sign;
    return retVal;
}

int main(void)
{
    int r = 0;

    if (stoib("D2Aa", 18, &r)) printf("TEST PASSED");
    else printf("TEST FAILED");

    return 0;
}