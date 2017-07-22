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

int str_icmp(const char *s1,const char *s2)
    {
    while(A_MAYUSCULA(*s1)==A_MAYUSCULA(*s2)&&*s1&&*s2)
        {
        s1++;
        s2++;
        }
    return A_MAYUSCULA(*s1)-A_MAYUSCULA(*s2);
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
