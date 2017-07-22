#include "encabezados.h"
int fibonacci(int n)//recibe el número de término
    {
    if(n>2)
        return fibonacci(n-1)+fibonacci(n-2);//genero un término cualquiera
    else
        if(n==2)
            return 1;//segundo término
        else
            if(n==1)
                return 1;//primer término
            else
                if(n==0)
                    return 0;
    }
