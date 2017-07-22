#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 0E");
    int mat[FIL][COL];

    printf("\a\a\a");
    printf("\n\t\t ***************************************");
    printf("\n\t\t * VECINOS DE UN ELEMENTO DE LA MATRIZ *");
    printf("\n\t\t ***************************************");

    printf("\n\n Complete el vecindario: \n ");
    cargar_matriz(mat,FIL,COL);
    int i,j,op,band;
    do
        {
        system("cls");
        printf("\a\a\a");
        printf("\n\t\t ***************************************");
        printf("\n\t\t * VECINOS DE UN ELEMENTO DE LA MATRIZ *");
        printf("\n\t\t ***************************************");
        printf("\n\n VECINDARIO \n");
        mostrar_matriz(mat,FIL,COL);

        printf("\n\n %c Descubra cuáles son los vecinos de alguien \n a partir de sus coordenadas en el vecindario: \n",16);
        band=0;
        do
            {
            if(band==1)
                printf("\n\n Esa fila no está en el vecindario.\n\a\a");
            printf("\n Ingrese la fila (1 a %d): \t",FIL);
            scanf("%d",&i);
            band=1;
            }
        while(!DATO_VALIDO(i,1,FIL));
        band=0;
        do
            {
            if(band==1)
                printf("\n\n Esa columna no está en el vecindario.\n\a\a");
            printf("\n Ingrese la columna (1 a %d): \t",COL);
            scanf("%d",&j);
            band=1;
            }
        while(!DATO_VALIDO(j,1,COL));

        printf("\n VECINOS: \n\n\a\a");
        vecinos(mat,FIL,COL,i-1,j-1);

        printf("\n\n ----------------------------------------------------------------------------- \n");
        printf("\n Para realizar una nueva búsqueda de vecinos, presione 1. \n\t Caso contrario, presione cualquier tecla:\t");
        scanf("%d",&op);
        }
    while(op==1);

    printf("\n\n\t\t\t\t Fin del programa....... \n\n\a\a\a");
    getch();
    return 0;
    }
