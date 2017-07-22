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

void vecinos(int m[][COL],int f,int c,int x,int y)
    {
    int i,j;
     for(i=-1;i<2;i++)
        for(j=-1;j<2;j++)
            if(DATO_VALIDO(x+i,0,f-1)&&DATO_VALIDO(y+j,0,c-1))
              if((x+i!=x)||(y+j!=y))
                 printf("\t <%d>",m[x+i][y+j]);
    }
