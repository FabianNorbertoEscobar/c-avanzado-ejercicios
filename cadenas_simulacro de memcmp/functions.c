#include "header.h"
int mem_cmp(const void *s1,const void *s2,size_t n)
    {
    if(!n)
        return 0;
    while(--n&&*(char*)s1==*(char*)s2)
        {
        (char*)++s1;
        (char*)++s2;
        }
    return *(unsigned char *)s1-*(unsigned char *)s2;
    }
