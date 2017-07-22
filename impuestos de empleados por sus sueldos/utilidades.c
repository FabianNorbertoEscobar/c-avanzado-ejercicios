#include "header.h"

char *str_cpy(char *destino,const char *origen)
{
    char *inicio=destino;

    while(*origen)
    {
        *destino=*origen;
        destino++;
        origen++;
    }

    *destino='\0';
    return inicio;
}

int str_cmp(const char *s1,const char *s2)
{
    while(*s1&&*s2&&*s1==*s2)
    {
        s1++;
        s2++;
    }

    return *s1-*s2;
}

int comparar_cuit(const void *v1,const void *v2)
{
    t_dato_lista *dato1=(t_dato_lista*)v1;
    t_dato_lista *dato2=(t_dato_lista*)v2;
    return str_cmp(dato1->cuit,dato2->cuit);
}

int comparar_codigo_concepto(const void *v1,const void *v2)
{
    t_dato_lista *dato=(t_dato_lista*)v1;
    int *codigo_concepto=(int*)v2;
    return dato->codigo_concepto-*codigo_concepto;
}
