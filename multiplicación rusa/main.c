#include "encabezados.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int factor1,factor2,prod;
    printf("\n MULTIPLICACIÓN RUSA \n");
    printf("\n Ingrese dos números enteros positivos para calcular su producto \n mediante el método de multiplicación rusa \n");
    do
        {
        printf("\n Factor 1: \t\t");
        scanf("%d",&factor1);
        }
    while(factor1<0);
    do
        {
        printf("\n Factor 2: \t\t");
        scanf("%d",&factor2);
        }
    while(factor2<0);
    prod=multiplicacion_rusa(factor1,factor2);
    printf("\n El producto es %d \n\n",prod);
    getch();
    return 0;
    }
