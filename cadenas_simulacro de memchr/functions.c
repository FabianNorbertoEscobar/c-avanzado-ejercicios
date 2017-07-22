#include "header.h"
void *mem_chr(const void *s,int c,size_t n)
    {
    while(n&&*(char*)s!=(char)c)
        {
        n--;
        (char*)s++;
        }
    return n?s:NULL;
    }
