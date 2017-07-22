#include "header.h"
size_t str_len(const char *s)
    {
    size_t cont=0;
    while(*s) // es mejor que escribir while(*s!='\0') ya que solo va a dar falso si es el caracter nulo
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
int str_cmp(const char *s1,const char *s2)
    {
    while(*s1==*s2&&*s1&&*s2)
        {
        s1++;
        s2++;
        }
    return *s1-*s2;
    }
int str_cmpi(const char *s1,const char *s2)
    {
    while(tolower(*s1)==tolower(*s2)&&*s1&&*s2)//luego, cambiar la función tolower por la macro hecha por nosotros
        {
        s1++;
        s2++;
        }
    return tolower(*s1)-tolower(*s2);
    }
char *str_chr(char *s,int c)
    {
    while(*s&&*s!=c)
        s++;
    return (*s)?s:NULL;
    }
