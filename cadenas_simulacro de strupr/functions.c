#include "header.h"
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

