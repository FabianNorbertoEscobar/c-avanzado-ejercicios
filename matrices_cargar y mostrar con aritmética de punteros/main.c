#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int f,c,band;
    printf("\n CARGAR Y MOSTRAR MATRIZ USANDO ARITMÉTICA DE PUNTEROS \n");
    printf("\n Ingrese los datos de la matriz que desea cargar \n (orden máximo: %d*%d) \n",FIL,COL);
    band=0;
    do
        {
        if(band==1)
            printf("\n No es posible que esta matriz tenga esa cantidad de filas. \n Reingrese el dato: \n");
        printf("\n FILAS: \n\n\t\t");
        scanf("%d",&f);
        band=1;
        }
    while(!DATO_VALIDO(f,1,FIL));
    band=0;
    do
        {
        if(band==1)
            printf("\n No es posible que esta matriz tenga esa cantidad de columnas. \n Reingrese el dato: \n");
        printf("\n COLUMNAS: \n\n\t\t");
        scanf("%d",&c);
        band=1;
        }
    while(!DATO_VALIDO(c,1,COL));
    int mat[f][c];
    cargar_matriz_con_aritmetica(&mat,f,c);
    mostrar_matriz(&mat,f,c);
    printf("\n\n");
    getch();
    return 0;
    }

