#include "header.h"
void cargar_matriz_cuadrada(int m[][N],int n)
    {
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            {
            printf("\n Ingrese m[%d][%d]=\t",i+1,j+1);
            scanf("%d",&m[i][j]);
            }
    }
void mostrar_matriz_cuadrada(int m[][N],int n)
    {
    int i,j;
    for(i=0;i<n;i++)
        {
        for(j=0;j<n;j++)
            printf("\t %d",m[i][j]);
        printf("\n\n");
        }
    }
int elemento_ij(int m[],int n,int i,int j)
    {
    return m[i*n+j-1];
    }
void mostrar_elementos_diagonal_principal(int m[][N],int n)
    {
    int i;
    for(i=0;i<n;i++)
        {
        printf("\t %d",m[i][i]);
        }
    }
void mostrar_elementos_diagonal_secundaria(int m[][N],int n)
    {
    int i,j;
    for(i=0;i<n;i++)
        printf("\t %d",m[i][n-1-i]);
    }
void mostrar_diagonal_principal(int m[][N],int n)
    {
    int i,j;
    for(i=0;i<n;i++)
        {
        printf("\n\t");
        for(j=0;j<n;j++)
            {
            if(i==j)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_diagonal_secundaria(int m[][N],int n)
    {
    int i,j;
    for(i=0;i<n;i++)
        {
        printf("\n\t");
        for(j=0;j<n;j++)
            {
            if(j==n-1-i)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
