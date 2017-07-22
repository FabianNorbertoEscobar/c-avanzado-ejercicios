#include "header.h"

int menor(int *x,int *y)
    {
    return (*x<*y)?*x:*y;
    }

void intercambio(int *x,int *y)
    {
    int aux;
    aux=*x;
    *x=*y;
    *y=aux;
    }
