#ifndef __MYUTILS_H_
#define __MYUTILS_H_

#include <stdbool.h>
#include <stdarg.h>

unsigned long factorial(unsigned int number);
bool isPrime(unsigned long number);
bool isPalindrome(unsigned long number);
long vsum(unsigned int n, ...);

#endif // __MYUTILS_H_
