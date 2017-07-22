#include "encabezados.h"
int fibonacci(int n)//recibe el número de término
    {
    switch(n)
        {
        case 2:
        case 1: return 1; //primeros dos términos
                break;
        case 0: return 0;
        default:return fibonacci(n-1)+fibonacci(n-2);//genero un término cualquiera
        }
    }
