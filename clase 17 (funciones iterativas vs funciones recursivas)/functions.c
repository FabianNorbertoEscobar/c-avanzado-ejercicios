#include "header.h"

int factorial_iterativo(int x)
{
    int i,fact=1;
    for(i=1;i<=x;i++)
        fact*=i;
    return fact;
}

int factorial_recursivo(int x)
{
    return (x<=1)?1:x*factorial_recursivo(x-1);
}
