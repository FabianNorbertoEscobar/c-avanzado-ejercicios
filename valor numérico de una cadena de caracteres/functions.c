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
size_t valor_numerico_cadena(char *c)
    {
    size_t acum=0;
    char *cadena=c;
    int longitud=str_len(cadena);
    while(longitud--)
        acum+=*cadena++;
    return acum;
    }

