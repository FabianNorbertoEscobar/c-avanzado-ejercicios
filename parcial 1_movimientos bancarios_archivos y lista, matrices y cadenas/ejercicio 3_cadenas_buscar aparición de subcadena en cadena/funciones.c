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

int str_ncmpi(const char *s1,const char *s2,size_t cant)
    {
    while(*s1&&*s2&&A_MINUSCULA(*s1)==A_MINUSCULA(*s2)&&--cant)
        {
        s1++;
        s2++;
        }
    return A_MINUSCULA(*s1)-A_MINUSCULA(*s2);
    }

int ocurrencia_de_subcadena_en_cadena(const char *s1,const char *s2)
{
    size_t tam=str_len(s2);
    int cont=0;
    while(*s1&&str_ncmpi(s1,s2,tam))
    {
        s1++;
        cont++;
    }
    return(*s1)?cont:-1;
}

int ocurrencia_de_subcadena_en_cadena_optimizada(const char *s1,const char *s2)
{
    char *lector_s1=s1;
    char *inicio_s2=s2;
    int pos=0;

    while(*s1)
    {
        if(A_MINUSCULA(*s1)==A_MINUSCULA(*s2))
        {
            lector_s1=s1;
            while(*lector_s1&&*s2&&A_MINUSCULA(*lector_s1)==A_MINUSCULA(*s2))
            {
                lector_s1++;
                s2++;
            }

            if(!*s2)
                return pos;
            else
                s2=inicio_s2;
        }
        pos++;
        s1++;
    }
    return -1;
}
