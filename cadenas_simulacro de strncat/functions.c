#include "header.h"
char* str_ncat(char *destino,const char *origen,size_t cant)
    {
    char *s=destino;
    while(*destino)
        destino++;
    while(*origen&&cant--)
        {
        *destino=*origen;
        destino++;
        origen++;
        }
    *destino='\0';
    return s;
    }

