#include "header.h"
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
