#include "header.h"
char *str_lwr(char *s1)
    {
    char *s2=s1;
    while(*s1)
        {
        *s1=A_MINUSCULA(*s1);
        s1++;
        }
    return s2;
    }

