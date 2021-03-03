#ifndef __MYSTRING_H_
#define __MYSTRING_H

#include <stdlib.h>

size_t mystrlen(const char *src);
size_t mystrcpy(char *dst, size_t dst_len, const char *src);
size_t mystrcat(char *dst, size_t dst_len, const char *src);
int mystrcmp(const char *src, const char *dst, size_t cmp_len);

#endif // __MYSTRING_H_
