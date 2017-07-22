#include "header.h"

int* buscarValor(int *mat,int i,int j,int col)
{
    return (mat + ((i-1) * col ) + j-1);
}

void trianguloSuperiorDerecho(int mat[][COL],int fil,int col)
{
    int i,j;
    printf("\nElementos del triangulo superior derecho:");
    for(i = 0 ; i < fil ; i++)
    {
        for(j = i ; j < col ; j++)
            printf("  %d",mat[i][j]);
    }
}

void trianguloSuperiorIzquierdo(int mat[][COL],int fil,int col)
{
    int i,j;
    printf("\nElementos del triangulo superior izquierdo:");
    for(i = 0 ; i < fil ; i++)
    {
        for(j = 0 ; j < col - i ; j++)
            printf("  %d",mat[i][j]);
    }
}

void trianguloInferiorIzquierdo(int mat[][COL],int fil,int col)
{
    int i,j;
    printf("\nElementos del triangulo inferior izquierdo:");
    for(i = 0 ; i < fil ; i++)
    {
        for(j = 0 ; j <= i ; j++)
            printf("  %d",mat[i][j]);
    }
}

void trianguloInferiorDerecho(int mat[][COL],int fil,int col)
{
    int i,j;
    printf("\nElementos del triangulo inferior derecho:");
    for(i = 0 ; i < fil ; i++)
    {
        for(j = col - i - 1 ; j < col ; j++)
            printf("  %d",mat[i][j]);
    }
}

///// sin diagonal///////////////////////////////

void trianguloSuperiorDerechoSD(int mat[][COL],int fil,int col)
{
    int i,j;
    printf("\nElementos del triangulo superior derecho sin diagonal:");
    for(i = 0 ; i < fil ; i++)
    {
        for(j = i + 1 ; j < col ; j++)
            printf("  %d",mat[i][j]);
    }
}

void trianguloSuperiorIzquierdoSD(int mat[][COL],int fil,int col)
{
    int i,j;
    printf("\nElementos del triangulo superior izquierdo sin diagonal:");
    for(i = 0 ; i < fil ; i++)
    {
        for(j = 0 ; j < col - i - 1 ; j++)
            printf("  %d",mat[i][j]);
    }
}

void trianguloInferiorIzquierdoSD(int mat[][COL],int fil,int col)
{
    int i,j;
    printf("\nElementos del triangulo inferior izquierdo sin diagonal:");
    for(i = 0 ; i < fil ; i++)
    {
        for(j = 0 ; j <= i - 1; j++)
            printf("  %d",mat[i][j]);
    }
}

void trianguloInferiorDerechoSD(int mat[][COL],int fil,int col)
{
    int i,j;
    printf("\nElementos del triangulo inferior derecho sin diagonal:");
    for(i = 0 ; i < fil ; i++)
    {
        for(j = col - i  ; j < col ; j++)
            printf("  %d",mat[i][j]);
    }
}
/*
int esIdentidad(int mat[][COL],int fil,int col)
{
    int i,j;

    for(i = 0 ; i < fil ; i++)
    {
        if((mat[i][i] != 1)
           return FALSO;
        for(j = i+1 ; j < col ; j++)
        {
            if((mat[i][j] != 0) || (mat[j][i] != 0))
                return FALSO;
        }
    }

    return VERDADERO;
}
*/
void trasponerMatriz(int mat[][COL],int fil,int col)
{
    int i,j,aux;

    for(i = 0 ; i < fil ; i++)
    {
        for(j = i + 1 ; j < col ; j++)
        {
            aux = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = aux;
        }
    }
}

void mostrarMatriz(int mat[][COL2],int fil,int col)
{
    int i,j;

    printf("\n  Matriz\n\n");

    for(i = 0 ; i < fil ; i++)
    {
        for(j = 0 ; j < col ; j++)
            printf("  %d",mat[i][j]);
        printf("\n");
    }
}

int productoDeMatrices(int mat[][COL],int mat2[][COL2],int matRes[][COL2],int fil,int col,int fil2,int col2)
{
    int i,j,k;

    if(col != fil2)
        return 0;

    for(i = 0 ; i < fil ; i++)
    {
        for(j = 0 ; j < col2 ; j++)
        {
            matRes[i][j] = 0;
            for(k = 0 ; k < fil2 ; k++)
                matRes[i][j] += mat[i][k] * mat2[k][j];
        }
    }

    return 1;
}

int esSimetrica(int mat[][COL],int fil,int col)
{
    int i,j;

    for(i = 1 ; i < fil ; i++)
    {
        for(j = i + 1 ; j < col ; j++)
        {
            if(mat[i][j] != mat[j][i])
                return 0;
        }
    }

    return 1;
}

int esSimetrica2(int mat[][COL],int fil,int col)
{
    int i,j;

    for(i = 0 ; i < fil ; i++)
    {
        for(j = 0 ; j < col - i - 1 ; j++)
            if(mat[i][j] != mat[fil - i][col - j])
                return 0;
    }

    return 1;
}
