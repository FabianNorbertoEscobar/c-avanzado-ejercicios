#include "header.h"
long int mi_atol(char *s)
    {
    long int i=0,signo=1;
    if(!s)
        return 0;
    if(!ES_NUMERO(*s))
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
    while(ES_NUMERO(*s))
        {
        i*=10;
        i+=(*s-'0');
        s++;
        }
    return i*signo;
    }

