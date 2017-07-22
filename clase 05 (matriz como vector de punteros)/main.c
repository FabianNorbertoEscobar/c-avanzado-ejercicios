#include<stdio.h>
#include<conio.h>
#include<locale.h>
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n\t\t MATRICES \n");
    //los elementos de las matrices se almacenan de manera consecutiva en la memoria
    //se las suele ver como vectores de punteros, como si fuese un vector paralelo a las columnas de la matriz
    //y cada elemento siendo un puntero a la dirección del primer elemento de la fila a la fila que está a su lado
    //pero este vector de punteros no existe, es virtual
    int i,j;
    int mat[3][2]={{1,2},{3,4},{5,6}};//veamos los  que ocurre con esta matriz
    printf("\n MATRIZ: \t\t Contenido \t Dirección \n");
    for(i=0;i<3;i++)
        {
        for(j=0;j<2;j++)
            printf("\n m[%d][%d]:\t\t\t %d \t %p",i,j,mat[i][j],&mat[i][j]);
        printf("\n");
        }
    printf("\n VECTOR DE PUNTEROS \t Contenido \t Dirección \n");
    for(i=0;i<6;i++)
        printf("\n m[%d]: \t\t\t%p\t%p",i,mat[i],&mat[i]);
    printf("\n\n Veamos algunos casos aparte: \n");
    printf("\n Dirección de mat: %p\n",&mat);
    printf("\n Contenido de mat: %p\n\n",mat);
    printf("\n mat[0]: %p\n",mat[0]);
    printf("\n Contenido de mat[0]: %d\n",*mat[0]);
    printf("\n Dirección de mat[0]: %p\n\n",&mat[0]);
    printf("\n mat[1]: %p\n",mat[1]);
    printf("\n Contenido de mat[1]: %d\n",*mat[1]);
    printf("\n Dirección de mat[1]: %p\n",&mat[1]);
    getch();
    return;
    }
