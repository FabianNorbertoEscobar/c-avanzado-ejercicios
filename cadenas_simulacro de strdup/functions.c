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
char *str_cpy(char *destino,const char *origen)
    {
    char *s=destino;
    while(*origen)
        {
        *destino=*origen;
        destino++;
        origen++;
        }
    *destino='\0';
    return s;
    }
char *str_dup(const char *s1)
    {
    char *s2=(char *)malloc(str_len(s1)+1);
    if(s2)
        str_cpy(s2,s1);
    return s2;
    }
