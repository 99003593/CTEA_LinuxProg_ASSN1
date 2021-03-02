#include "myutils.h"
#include <math.h>
#include <stdio.h>

unsigned long factorial(unsigned int number)
{
    unsigned long fact = 1, t;

    if(number < 2)
    {
        fact = 1; // Factorial is 1 for 0 & 1
    }
    else
    {
        for(; number > 1; number--)
        {
            t = fact * number;
            if(t < fact)
            {
                fact = 0; // Detect overflow and stop
                break;
            }
            fact = t;
        }
    }

    return fact;
}

bool isPrime(unsigned long number)
{
    bool result;
    unsigned long factor = 3;
    double limit_sqrt = sqrt(number);
    unsigned long limit_rounded = ceil(limit_sqrt);

    if (number < 2)
    {
        result = false;
    }
    else if (number < factor)
    {
        result = true;
    }
    else
    {
        // True by default
        result = true;
        // loop by 2 from 3
        for(; factor < limit_rounded; factor+=2)
        {
            if ((factor < 5 && number%factor == 0) ||
                (factor > 5 && factor%3 != 0 && factor%5 != 0 && number%factor == 0))
            {
                result = false;
                break;
            }
        }
    }

    return result;
}

bool isPalindrome(unsigned long number)
{
    unsigned long reverse = 0;
    int digit = 0;
    for (unsigned long t = number; t > 0; t /= 10)
    {
        digit = t%10;
        reverse = reverse*10 + digit;
    }

    return number == reverse;
}

long vsum(unsigned int n, ...)
{
    long result = 0;

    va_list vl;
    va_start(vl, n);
    for (int i = 0; i < n; i++)
    {
        int t = va_arg(vl, int);
        // printf("vsum[%d]: %d\n", i, t);
        result += t;
    }
    va_end(vl);

    return result;
}
