#include "header.h"
void mostrar(int a,int b)
    {
    printf("\n Primer número: %d \n Segundo número: %d \n",a,b);
    }
void intercambiar(int *a,int *b)
    {
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
    }
