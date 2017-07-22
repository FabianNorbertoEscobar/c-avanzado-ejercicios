#include "header.h"
char *str_rchr(char *s,int c)
    {
    char *inicio=s;
    while(*s)
        s++;
    while(s>inicio&&*s!=c)
        s--;
    return (*s==c)?s:NULL;
    }
