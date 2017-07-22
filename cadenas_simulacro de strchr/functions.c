#include "header.h"
char *str_chr(char *s,int c)
    {
    while(*s&&*s!=c)
        s++;
    return (*s)?s:NULL;
    }

