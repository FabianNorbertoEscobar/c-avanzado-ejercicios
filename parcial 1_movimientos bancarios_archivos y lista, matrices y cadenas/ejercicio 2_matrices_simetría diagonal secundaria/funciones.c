#include "header.h"

void cargar_matriz(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
    {
        printf("\n");
        for(j=0;j<c;j++)
        {
            printf("\n\t m[%d][%d]= \t",i,j);
            scanf("%d",&m[i][j]);
        }
    }
}

void mostrar_matriz(int m[][COL],int f,int c)
    {
        int i,j;
        for(i=0;i<f;i++)
        {
            printf("\n\n\n\t");
            for(j=0;j<c;j++)
            {
                printf("\t %d",m[i][j]);
            }
        }
    }

int matriz_simetrica_respecto_diagonal_secundaria(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c-1-i;j++)
            if(m[i][j]!=m[f-1-j][c-1-i])
                return 0;
    return 1;
}
