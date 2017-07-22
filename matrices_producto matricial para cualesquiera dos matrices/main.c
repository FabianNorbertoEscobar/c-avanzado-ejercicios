#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int f1,c1,f2,c2,band;
    printf("\a\a\a");
    printf("\n\t ************************");
    printf("\n\t * MULTIPLICAR MATRICES *");
    printf("\n\t ************************");
    printf("\n Ingrese los datos de la primera matriz que desea cargar \n (orden máximo: %d*%d) \n",TOPE,TOPE);
    band=0;
    do
        {
        if(band==1)
            printf("\n No es posible que una matriz tenga esa cantidad de filas. \n Reingrese el dato: \n");
        printf("\n FILAS: \n\n\t\t");
        scanf("%d",&f1);
        band=1;
        }
    while(!DATO_VALIDO(f1,1,10));
    band=0;
    do
        {
        if(band==1)
            printf("\n No es posible que una matriz tenga esa cantidad de columnas. \n Reingrese el dato: \n");
        printf("\n COLUMNAS: \n\n\t\t");
        scanf("%d",&c1);
        band=1;
        }
    while(!DATO_VALIDO(c1,1,10));
    printf("\n Ingrese los datos de la segunda matriz que desea cargar \n (orden máximo: %d*%d) \n",TOPE,TOPE);
    band=0;
    do
        {
        if(band==1)
            printf("\n No es posible que una matriz tenga esa cantidad de filas. \n Reingrese el dato: \n");
        printf("\n FILAS: \n\n\t\t");
        scanf("%d",&f2);
        band=1;
        }
    while(!DATO_VALIDO(f2,1,10));
    band=0;
    do
        {
        if(band==1)
            printf("\n No es posible que una matriz tenga esa cantidad de columnas. \n Reingrese el dato: \n");
        printf("\n COLUMNAS: \n\n\t\t");
        scanf("%d",&c2);
        band=1;
        }
    while(!DATO_VALIDO(c2,1,10));
    if(c1==f2)
        {
        int mat1[f1][c1];
        cargar_matriz(mat1,f1,c1);
        int mat2[f2][c2];
        cargar_matriz(mat2,f2,c2);
        printf("\n\n Matriz 1 \n");
        mostrar_matriz(mat1,f1,c1);
        printf("\n\n Matriz 2 \n");
        mostrar_matriz(mat2,f2,c2);
        int mat3[f1][c2];
        producto_matricial(mat1,mat2,mat3,f1,c1,f2,c2);
        printf("\n\n Matriz resultante del producto matricial \n\n");
        mostrar_matriz(mat3,f1,c2);
        }
    else
        printf("\n\n Matrices con esas dimensiones no se pueden mulitiplicar porque la cantidad \n de columnas de la primera matriz es diferente a la cantidad \n de filas de la segunda matriz \n\n");
    printf("\n\n\t\t\t\t Fin del programa....... \n\n\a\a\a");
    getch();
    return 0;
    }

