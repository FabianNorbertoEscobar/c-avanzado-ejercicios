#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int m[N][N]={{1,2,3},{4,5,6},{7,8,9}};
//    printf("\n\t\t MATRICES \n\n");
    //printf("\n Elemento ubicado:\t m= %d \n",elemento_ij(m,N,2,2));
//    printf("\n Cargue la matriz: \n\n");
//    cargar_matriz_cuadrada(m,N);
//    printf("\n Esta es la matriz cargada: \n\n");
//    mostrar_matriz_cuadrada(m,N);
    int i,j,op;
    do
        {
        system("cls");
        printf("\n\t\t MATRICES \n\n");
        mostrar_matriz_cuadrada(m,N);
        printf("\n Ubique un elemento de la matriz a partir de su fila y su columna: \n");
        do
            {
            printf("\n Ingrese su fila (1 a %d): \t",N);
            scanf("%d",&i);
            }
        while(!DATO_VALIDO(i,1,N));
        do
            {
            printf("\n Ingrese su columna (1 a %d): \t",N);
            scanf("%d",&j);
            }
        while(!DATO_VALIDO(j,1,N));
        printf("\n Elemento ubicado:\t m[%d][%d]= %d \n",i,j,elemento_ij(m,N,i-1,j));
        printf("\n Para repetir presione 1. Caso contrario, presione cualquier tecla: \t");
        scanf("%d",&op);
        }
    while(op==1);
    printf("\n\n Elementos de la diagonal principal \n\n");
    mostrar_elementos_diagonal_principal(m,N);
    printf("\n\n Elementos de la diagonal secundaria \n\n");
    mostrar_elementos_diagonal_secundaria(m,N);
    printf("\n\n Diagonal Principal \n\n");
    mostrar_diagonal_principal(m,N);
    printf("\n\n Diagonal Secundaria \n\n");
    mostrar_diagonal_secundaria(m,N);
    printf("\n\n\n");
    getch();
    return 0;
    }
