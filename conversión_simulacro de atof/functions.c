#include "header.h"
double mi_atof(char *s)
    {
    int signo=1;
    double val=0,pos=1;
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
        val*=10;
        val+=(*s-'0');
        s++;
        }
    if(A_MINUSCULA(*s)=='e')
        return val*pow(10,mi_atoi(++s));
    else
        if(*s!='.')
            return val*signo;
    s++;
    while(ES_NUMERO(*s))
        {
        val+=(*s-'0')*(pos/=10);
        s++;
        }
    if(A_MINUSCULA(*s)=='e')
        return  val*pow(10,mi_atoi(++s));
    return val*signo;
    }
int mi_atoi(char *s)
    {
    int i=0,signo=1;
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
