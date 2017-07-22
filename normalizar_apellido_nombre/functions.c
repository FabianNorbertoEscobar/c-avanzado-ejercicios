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

void normalizar_apellido_nombre(char *s)
{
    char cadena[40],*aux=cadena,*inicio_s=s;

    while(ES_BLANCO(*s))
        s++;

    *aux=A_MAYUSCULA(*s);
    aux++;
    s++;

    while(ES_LETRA(*s))
    {
        *aux=A_MINUSCULA(*s);
        aux++;
        s++;
    }

    while(!ES_LETRA(*s))
        s++;

    *aux=',';
    aux++;

    while(*s)
    {
        *aux=' ';
        aux++;

        *aux=A_MAYUSCULA(*s);
        aux++;
        s++;

        while(ES_LETRA(*s))
        {
            *aux=A_MINUSCULA(*s);
            aux++;
            s++;
        }

        while(*s && ES_BLANCO(*s))
            s++;
    }

    *aux='\0';

    s=inicio_s;
    str_cpy(s,cadena);
}
