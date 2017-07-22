#include "header.h"
int mem_icmp(const void *s1,const void *s2,size_t n)
    {
    if(!n)
        return 0;
    while(--n&&A_MAYUSCULA(*(char*)s1)==A_MAYUSCULA(*(char*)s2))
        {
        (char*)++s1;
        (char*)++s2;
        }
    return A_MAYUSCULA(*(unsigned char *)s1)-A_MAYUSCULA(*(unsigned char *)s2);
    }

