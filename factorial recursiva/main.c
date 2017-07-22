#include "encabezados.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int n,fact;
    printf("\n\t\t FACTORIAL \n");
    printf("\n Ingrese un número natural (o cero) para calcular su factorial: \n\n\t\t");
    scanf("%d",&n);
    if(n<0)
        {
        printf("\n No se puede calcular el factorial de un número negativo \n\n");
        exit(0);
        }
    fact=factorial(n);
    printf("\n El factorial de %d es %d \n\n",n,fact);
    getch();
    return 0;
    }
