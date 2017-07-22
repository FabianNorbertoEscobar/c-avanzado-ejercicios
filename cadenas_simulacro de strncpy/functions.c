#include "header.h"
char *str_ncpy(char *destino,const char *origen,size_t cant)
    {
    char *s=destino;
    while(*origen&&cant)
        {
        *destino=*origen;
        destino++;
        origen++;
        cant--;
        }
    while(cant--)
        *destino++='\0';
    *destino='\0';
    return s;
    }
