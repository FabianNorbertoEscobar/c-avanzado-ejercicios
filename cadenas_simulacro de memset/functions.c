#include "header.h"
void *mem_set(void *s1,int c,size_t n)
    {
    void *s2=s1;
    while(n--)
        {
        *(char *)s1=(char)c;
        (char*)s1++;
        }
    return s2;
    }
