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

char *str_cat(char *destino,const char *origen)
{
    char *inicio=destino;
    while(*destino)
        destino++;
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

int str_icmp(const char *s1,const char *s2)
{
    while(*s1&&*s2&&A_MAYUSCULA(*s1)==A_MAYUSCULA(*s2))
    {
        s1++;
        s2++;
    }
    return A_MAYUSCULA(*s1)-A_MAYUSCULA(*s2);
}
/*
int str_icmp(const char *s1,const char *s2)
{
    while(*s1&&*s2&&A_MINUSCULA(*s1)==A_MINUSCULA(*s2))
    {
        s1++;
        s2++;
    }
    return A_MINUSCULA(*s1)-A_MINUSCULA(*s2);
}
*/

char *str_ncpy(char *destino,const char *origen,int cant)
{
    char *inicio=destino;
    while(*origen&&cant--)
    {
        *destino=*origen;
        destino++;
        origen++;
    }
    *destino='\0';
    return inicio;
}

char *str_ncat(char *destino,const char *origen,int cant)
{
    char *inicio=destino;
    while(*destino)
        destino++;
    while(*origen&&cant--)
    {
        *destino=*origen;
        destino++;
        origen++;
    }
    *destino='\0';
    return inicio;
}

int str_ncmp(const char *s1,const char *s2,int cant)
{
    while(*s1&&*s2&&*s1==*s2&&cant--)
    {
        s1++;
        s2++;
    }
    return *s1-*s2;
}

char *str_chr(const char *s,int c)
{
    while(*s&&*s!=c)
        s++;
    return (*s)?s:NULL;
}

char *str_rchr(const char *s,int c)
{
    char *inicio=s;
    while(*s)
        s++;
    while(s>inicio&&*s!=c)
        s--;
    return (*s==c)?s:NULL;
}

char *str_str(const char *s1,const char *s2)
{
    size_t tam=str_len(s2);
    while(*s1&&str_ncmp(s1,s2,tam))
        s1++;
    return (*s1)?s1:NULL;
}

char *str_upr(char *s)
{
    char *inicio=s;
    while(*s)
    {
        *s=A_MAYUSCULA(*s);
        s++;
    }
    return inicio;
}

char *str_lwr(char *s)
{
    char *inicio=s;
    while(*s)
    {
        *s=A_MINUSCULA(*s);
        s++;
    }
    return inicio;
}
