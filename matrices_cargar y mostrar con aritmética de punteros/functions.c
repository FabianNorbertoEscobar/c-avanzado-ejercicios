#include "header.h"

void cargar_matriz_con_aritmetica(int *m,int f,int c)
    {
    int i,j;
    printf("\n Cargue los datos de la matriz \n");
    for(i=0;i<f;i++)
        {
        printf("\n");
        for(j=0;j<c;j++)
            {
            printf("\t mat[%d][%d]: \t",i,j);
            scanf("%d",m);
            m++;
            }
        }
    }
void mostrar_matriz(int *m,int f,int c)
    {
    int i,j;
    printf("\n MATRIZ \n");
    for(i=0;i<f;i++)
        {
        printf("\n\n");
        for(j=0;j<c;j++)
            {
            printf("   %d",*m);
            m++;
            }
        }
    }
