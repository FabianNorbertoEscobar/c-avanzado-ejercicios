#include "encabezados.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int m,n,comb;
    printf("\n \t\t CÁLCULO DEL NÚMERO COMBINATORIO C ( m ; n )\n");
    printf("\n m debe ser mayor o igual a n por definición del número combinatorio \n");
    printf("\n (si los números m y n ingresados no cumplen ésta condición, \n deberán volver a ser ingresados) \n\n");
    do
        {
        do
            {
            printf("\n\n Ingrese el número m entero no negativo:\n\n\t\t");
            scanf("%d",&m);
            }
        while(m<0);
        do
            {
            printf("\n\n Ingrese el número n entero no negativo:\n\n\t\t");
            scanf("%d",&n);
            }
        while(n<0);
        if(m<n)
            printf("\n No se cumple la definición del número combinatorio \n");
        }
    while(m<n);
    comb=combinatorio(m,n);
    printf("\n\n El número combinatorio C ( %d ; %d ) es %d \n\n",m,n,comb);
    getch();
    return 0;
    }
