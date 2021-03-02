#include "mystring.h"

size_t mystrlen(const char *src)
{
    size_t len = 0;
    for(
        const char* ps = src;
        (len < __SIZE_MAX__) && *ps != '\0';
        ps++, len++
    );
    return len;
}

size_t mystrcpy(char *dst, size_t dst_len, const char *src)
{
    size_t len = 0;
    const char *ps = src;
    char *pd = dst;
    for(;
        (len < dst_len-1) && *ps != '\0';
        ps++, pd++, len++
    )
    {
        *pd = *ps;
    }
    dst[len] = '\0';
    return len;
}

size_t mystrcat(char *dst, size_t dst_len, const char *src)
{
    size_t len = mystrlen(src);
    const char *ps = src;
    char *pd = dst+len;
    for(;
        (len < dst_len-1) && *ps != '\0';
        ps++, pd++, len++
    )
    {
        *pd = *ps;
    }
    dst[len] = '\0';
    return len;
}

int mystrcmp(const char *src, const char *dst, size_t cmp_len)
{
    int cmp = 0;
    size_t len = 0;
    const char *ps = src;
    const char *pd = dst;
    for(;
        (len < cmp_len) && *ps == *pd && *ps != '\0' && *pd != '\0';
        ps++, pd++, len++
    );
    cmp = *ps - *pd; // Evaluate src - dst @ len
    cmp = cmp < 0 ? -1 : cmp;
    cmp = cmp > 0 ? 1 : cmp;
    return cmp;
}

