#include "encabezados.h"
int factorial(int n)
    {
    int f,i;
    f=1;
    for(i=1;i<=n;i++)
        f*=i;//multiplico a 1 por los sucesivos números hasta el del que busco el factorial x la expansión del factorial
    return f;
    }
