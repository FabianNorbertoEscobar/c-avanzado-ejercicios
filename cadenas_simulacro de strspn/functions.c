#include "header.h"
char *str_chr(char *s,int c)
    {
    while(*s&&*s!=c)
        s++;
    return (*s)?s:NULL;
    }
size_t str_spn(const char *s1,const char *s2)
    {
    size_t cant=0;
    while(*s1&&str_chr(s2,*s1))
        {
        cant++;
        s1++;
        }
    return cant;
    }
