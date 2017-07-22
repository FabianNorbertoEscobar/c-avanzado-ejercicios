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
int sumar_elementos_triang_sup_diag_pral_sin_diag(int m[][COL],int f,int c)
    {
    int i,j,acum=0;
    for(i=0;i<f;i++)
        for(j=i+1;j<c;j++)
            acum+=m[i][j];
    return acum;
    }
int sumar_elementos_triang_inf_diag_pral_sin_diag(int m[][COL],int f,int c)
    {
    int i,j,acum=0;
    for(i=0;i<f;i++)
        for(j=0;j<i;j++)
            acum+=m[i][j];
    return acum;
    }
int sumar_elementos_triang_sup_diag_sec_sin_diag(int m[][COL],int f,int c)
    {
    int i,j,acum=0;
    for(i=0;i<f-1;i++)
        for(j=0;j<c-1-i;j++)
            acum+=m[i][j];
    return acum;
    }
int sumar_elementos_triang_inf_diag_sec_sin_diag(int m[][COL],int f,int c)
    {
    int i,j,acum=0;
    for(i=1;i<f;i++)
        for(j=c-i;j<c;j++)
            acum+=m[i][j];
    return acum;
    }
int sumar_elementos_triang_sup_diag_pral_con_diag(int m[][COL],int f,int c)
    {
    int i,j,acum=0;
    for(i=0;i<f;i++)
        for(j=i;j<c;j++)
            acum+=m[i][j];
    return acum;
    }
int sumar_elementos_triang_inf_diag_pral_con_diag(int m[][COL],int f,int c)
    {
    int i,j,acum=0;
    for(i=0;i<f;i++)
        for(j=0;j<=i;j++)
            acum+=m[i][j];
    return acum;
    }
int sumar_elementos_triang_sup_diag_sec_con_diag(int m[][COL],int f,int c)
    {
    int i,j,acum=0;
    for(i=0;i<f;i++)
        for(j=0;j<=c-1-i;j++)
            acum+=m[i][j];
    return acum;
    }
int sumar_elementos_triang_inf_diag_sec_con_diag(int m[][COL],int f,int c)
    {
    int i,j,acum=0;
    for(i=0;i<f;i++)
        for(j=c-i-1;j<c;j++)
            acum+=m[i][j];
    return acum;
    }
