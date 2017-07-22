#include "header.h"
int str_ncmp(const char *s1,const char *s2,size_t cant)
    {
    while(*s1==*s2&&*s1&&*s2&&--cant)
        {
        s1++;
        s2++;
        }
    return *s1-*s2;
    }

