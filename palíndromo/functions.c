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
int es_palindromo(char *c)
    {
    char *cadena=c,cad[TOPE];
    int i,j=0,longitud=str_len(cadena);
    for(i=0;i<=longitud;i++)
        {
        if(ES_MAYUSCULA(cadena[i]))
            cadena[i]=A_MINUSCULA(cadena[i]);
        if(cadena[i]!=' ')
            {
            cad[j]=cadena[i];
            j++;
            }
        }
    longitud=str_len(cad);
    for(i=0;i<=longitud/2;i++)
        if(cad[i]!=cad[longitud-1-i])
            {
            return 0;
            }
    return 1;
    }
