#include "header.h"
char *str_chr(char *s,int c)
    {
    while(*s&&*s!=c)
        s++;
    return (*s)?s:NULL;
    }
char *str_tok(char *s, const char *sep)
    {
    static char *sig;
    char *aux;
    if(s)
        sig=s;
    while(*sig&&str_chr(sep,*sig))
        sig++;
    aux=sig;
    while(*sig&&!strchr(sep,*sig))
        sig++;
    if(*sig)
        *sig++='\0';
    return (*aux)?aux:NULL;
    }
