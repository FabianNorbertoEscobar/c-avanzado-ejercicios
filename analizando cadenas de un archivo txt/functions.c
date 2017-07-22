#include "header.h"

char *leer_cadena(FILE *pf)
    {
    char s[6];
    fflush(stdin);
    fscanf(pf,"%6s",s);
    return s;
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

int es_uniletra(char *s)
    {
    if(str_len(s)==1)
        return 1;
    else
        return 0;
    }

int es_de_cant_par_de_letras(char *s)
    {
    if(str_len(s)%2==0)
        return 1;
    else
        return 0;
    }

int empieza_con_n(char *s,char c)
    {
    if(*s==c)
        return 1;
    else
        return 0;
    }

int empieza_con_prefijo(char *s,char *prefijo)
    {
    while(*prefijo)
        {
        if(*s!=*prefijo)
            return 0;
        s++;
        prefijo++;
        }
    return 1;
    }

int tiene_mas_de_3_vocales(char *s)
    {
    int cont=0;
    while(*s)
        {
        if(ES_VOCAL(*s))
                cont++;
        s++;
        }
    return (cont>3)?1:0;
    }

int empieza_y_termina_con_vocal(char *s)
    {
    if(!ES_VOCAL(A_MAYUSCULA(*s)))
            return 0;
    while(*s)
        s++;
    s--;
    return (!ES_VOCAL(A_MAYUSCULA(*s)))?0:1;
    }

int contiene_digitos(char *s)
    {
    while(*s)
        {
        if(ES_DIGITO(*s))
            return 1;
        s++;
        }
    return 0;
    }

int tiene_solo_numeros(char *s)
    {
    while(*s)
        {
        if(!ES_DIGITO(*s))
            return 0;
        s++;
        }
    return 1;
    }

int es_palindromo(char *s1)
    {
    while(ES_BLANCO(*s1)||ES_SIGNO(*s1))
        s1++;
    int i,longitud=str_len(s1),punto_medio=longitud/2;
    char *s2=s1+longitud-1;
    for(i=0;i<=punto_medio;i++)
        if(*s1++!=*s2--)
            return 0;
    return 1;
    }
