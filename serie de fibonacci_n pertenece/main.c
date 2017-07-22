#include "encabezados.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int n;
    printf("\n ¿ PERTENECE A LA SERIE DE FIBONACCI ? \n");
    do
        {
        printf("\n Ingrese un número natural para saber si pertenece a la serie de Fibonacci \n (debe ser un número natural): \n\n\t\t");
        scanf("%d",&n);
        }
    while(n<=0);
    if(es_de_fibonacci(n))
        printf("\n El número %d pertenece a la serie de Fibonacci \n\n",n);
    else
        printf("\n El número %d no pertenece a la serie de Fibonacci \n\n",n);
    getch();
    return 0;
    }
