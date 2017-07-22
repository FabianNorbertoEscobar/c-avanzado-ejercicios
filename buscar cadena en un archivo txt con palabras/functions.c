#include "header.h"

void busqueda_de_palabra(FILE *pf,char *subcadena)
    {
    char cadena[6];
    rewind(pf);
    while(!feof(pf))
        {
        str_cpy(cadena,leer_cadena(pf));
        if(str_str(cadena,subcadena)!=NULL)
            {
            printf("\n %c La subcadena %s fue encontrada en la cadena %s \n del archivo \n\n",16,subcadena,cadena);
            //getch();
            }
        }
    }

char *leer_cadena(FILE *pf)
    {
    char s[6];
    fflush(stdin);
    fscanf(pf,"%6s",s);
    return s;
    }

char *str_upr(char *s1)
    {
    char *s2=s1;
    while(*s1)
        {
        *s1=A_MAYUSCULA(*s1);
        s1++;
        }
    return s2;
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

int str_ncmp(const char *s1,const char *s2,size_t cant)
    {
    while(*s1==*s2&&*s1&&*s2&&--cant)
        {
        s1++;
        s2++;
        }
    return *s1-*s2;
    }

char *str_str(const char *s1,const char *s2)
    {
    size_t tam=str_len(s2);
    while(*s1&&str_ncmp(s1,s2,tam))
        s1++;
    return (*s1)?s1:NULL;
    }
