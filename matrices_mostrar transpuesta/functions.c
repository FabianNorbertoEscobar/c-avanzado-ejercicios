#include "header.h"
void cargar_matriz(int m[][COL],int f,int c)
    {
    int i,j;
    printf("\n\n %c Cargue los datos de la matriz de orden %dx%d \n",16,f,c);
    for(i=0;i<f;i++)
        {
        printf("\n");
        for(j=0;j<c;j++)
            {
            printf("\t mat[%d][%d]: \t",i+1,j+1);
            scanf("%d",&m[i][j]);
            }
        }
    }
void mostrar_matriz(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            printf(" %d",m[i][j]);
            }
        }
    }
void mostrar_transpuesta(int m[][COL],int f,int c)
    {
    int i,j,n[c][f];
    for(i=0;i<f;i++)
        {
        n[i][i]=m[i][i];
        for(j=i+1;j<c;j++)
            {
            n[j][i]=m[i][j];
            n[i][j]=m[j][i];
            }
        }
    mostrar_matriz(n,f,c);
    }
