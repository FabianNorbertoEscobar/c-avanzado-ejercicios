#include "header.h"
char *str_chr(char *s,int c)
    {
    while(*s&&*s!=c)
        s++;
    return (*s)?s:NULL;
    }
char* str_pbrk(const char *s1,const char *s2)
    {
    while(*s1&&!str_chr(s2,*s1))
        s1++;
    return (*s1)?(char*)s1:NULL;
    }
