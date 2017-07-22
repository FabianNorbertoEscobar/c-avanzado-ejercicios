#include "header.h"
size_t str_len(const char *s)
    {
    size_t cont=0;
    while(*s)
        {
        cont++;
        s++;
        }
    return cont;
    }
int str_ncmp(const char *s1,const char *s2,size_t cant)
    {
    while(*s1==*s2&&*s1&&*s2&&--cant)
        {
        s1++;
        s2++;
        }
    return *s1-*s2;
    }
char *str_str(const char *s1,const char *s2)
    {
    size_t tam=str_len(s2);
    while(*s1&&str_ncmp(s1,s2,tam))
        s1++;
    return (*s1)?s1:NULL;
    }
