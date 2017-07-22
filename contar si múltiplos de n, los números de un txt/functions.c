#include "header.h"

char *leer_cadena_numerica(FILE *pf)
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

int mi_atoi(char *s)
    {
    int i=0,signo=1;
    if(!s)
        return 0;
    if(!ES_DIGITO(*s))
        {
        while(*s==' ')
            s++;
        if(*s=='-')
            {
            signo=-1;
            s++;
            }
        else
            if(*s=='+')
                s++;
        }
    while(ES_DIGITO(*s))
        {
        i*=10;
        i+=(*s-'0');
        s++;
        }
    return i*signo;
    }

int es_numero(char *s)
    {
    if(!s)
        return 0;
    if(!ES_DIGITO(*s))
        {
        while(ES_BLANCO(*s))
            s++;
        if(ES_SIGNO(*s))
            {
            s++;
            }
        else
            if(!ES_DIGITO(*s))
                return 0;
        }
    while(ES_DIGITO(*s))
        {
        s++;
        }
    return *s?0:1;
    }

int es_capicua(char *s1)
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

int es_multiplo_de_5(char *s)
    {
    while(*s)
        s++;
    s--;
    return (*s=='5'||(*s=='0'))?1:0;
    }

int es_multiplo_de_6(char *s)
    {
    while(*s)
        s++;
    s--;
    if(*s!='0'&&(*s!='2')&&(*s!='4')&&(*s!='6')&&(*s!='8'))
        return 0;
    int acum=0;
    while(ES_DIGITO(*s))
        {
        acum=acum+A_NUMERO(*s);
        s--;
        }
    return acum%3==0?1:0;
    }

int es_multiplo_de_11(char *s)
    {
    int signo=1,acum=0;
    while(!ES_DIGITO(*s))
        s++;
    while(*s)
        {
        acum+=signo*A_NUMERO(*s);
        signo*=-1;
        s++;
        }
    return (acum==0||acum%11==0)?1:0;
    }

int es_mayor(char *s1,char *s2)
    {
    return (mi_atoi(s1)>mi_atoi(s2))?1:0;
    }

void nueva_cadena_numerica(FILE *pf,char *s)
    {
    fprintf(pf,"%-s\n",s);
    }
