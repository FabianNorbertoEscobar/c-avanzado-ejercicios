#include "header.h"
char *str_cat(char *destino,const char *origen)
    {
    char *s=destino;
    while(*destino)
        destino++;
    while(*origen)
        {
        *destino=*origen;
        destino++;
        origen++;
        }
    *destino='\0';
    return s;
    }
