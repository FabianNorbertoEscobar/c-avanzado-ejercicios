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
void producto_matricial_cuadradas(int m1[][COL],int m2[][COL],int m3[][COL],int f,int c)
    {
    int i,j,k;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            {
            m3[i][j]=0;
            for(k=0;k<c;k++)
                m3[i][j]+=(m1[i][k]*m2[k][j]);
            }
    }
