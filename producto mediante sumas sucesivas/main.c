#include "encabezados.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int factor1,factor2,prod;
    printf("\n PRODUCTO POR SUMAS SUCESIVAS \n");
    printf("\n Ingrese dos números enteros positivos para calcular su producto \n mediante el método de sumas sucesivas \n");
    do
        {
        printf("\n Número 1: \t\t");
        scanf("%d",&factor1);
        }
    while(factor1<0);
    do
        {
        printf("\n Número 2: \t\t");
        scanf("%d",&factor2);
        }
    while(factor2<0);
    prod=producto(factor1,factor2);
    printf("\n El producto es %d \n\n",prod);
    getch();
    return 0;
    }
