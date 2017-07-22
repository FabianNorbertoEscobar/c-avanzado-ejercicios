#include "encabezados.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int i,tope;
    printf("\n SERIE DE FIBONACCI \n\n");
    do
        {
        printf("\n Ingrese la cantidad de términos que desea calcular \n de la serie de Fibonacci: \n\n\t\t");
        scanf("%d",&tope);
        }
    while(tope<0);
    if(tope==0)//por si acaso
        {
        printf("\n\n Udted no desea generar ningún término de la serie \n\n\t\t\t Fin del programa.. \n\n\a\a");
        exit(0);
        }
    printf("\n Los primeros %d términos de la serie de Fibonacci son: \n",tope);
    for(i=1;i<=tope;i++)
        {
        printf("\n\t %d",fibonacci(i));
        }
    printf("\n\n");
    getch();
    return 0;
    }
