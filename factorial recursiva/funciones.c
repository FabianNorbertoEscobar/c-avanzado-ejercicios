#include "encabezados.h"
int factorial(int n)
    {
    if(n<=1)
        return 1;
    else
        return n*factorial(n-1);//aplico la propiedad del factorial hasta llegar al 1
    }
