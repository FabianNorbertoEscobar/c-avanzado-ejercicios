#include "header.h"

void cargar_matriz(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
    {
        printf("\n");
        for(j=0;j<c;j++)
        {
            printf("\n\t m[%d][%d]=\t",i,j);
            scanf("%d",&m[i][j]);
        }
    }
}

void mostrar_matriz(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
    {
        printf("\n\n\n");
        for(j=0;j<c;j++)
            printf("\t %d",m[i][j]);
    }
}

void elementos_diagonal_principal(int m[][COL],int f,int c)
{
    int i;
    for(i=0;i<f;i++)
        printf("\t %d",m[i][i]);
}

void elementos_diagonal_secundaria(int m[][COL],int f,int c)
{
    int i;
    for(i=0;i<f;i++)
        printf("\t %d",m[i][f-1-i]);
}

void triangulo_superior_diag_pral_sin_diag(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f-1;i++)
        for(j=i+1;j<c;j++)
            printf("\t %d",m[i][j]);
}

void triangulo_superior_diag_pral_con_diag(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
        for(j=i;j<c;j++)
            printf("\t %d",m[i][j]);
}

void triangulo_inferior_diag_pral_sin_diag(int m[][COL],int f,int c)
{
    int i,j;
    for(i=1;i<f;i++)
        for(j=0;j<i;j++)
            printf("\t %d",m[i][j]);
}

void triangulo_inferior_diag_pral_con_diag(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<=i;j++)
            printf("\t %d",m[i][j]);
}

void triangulo_superior_diag_secund_sin_diag(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f-1;i++)
        for(j=0;j<c-1-i;j++)
            printf("\t %d",m[i][j]);
}

void triangulo_superior_diag_secund_con_diag(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c-i;j++)
            printf("\t %d",m[i][j]);
}

void triangulo_inferior_diag_secund_sin_diag(int m[][COL],int f,int c)
{
    int i,j;
    for(i=1;i<f;i++)
        for(j=c-i;j<c;j++)
            printf("\t %d",m[i][j]);
}

void triangulo_inferior_diag_secund_con_diag(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
        for(j=c-1-i;j<c;j++)
            printf("\t %d",m[i][j]);
}

void triangulito_arriba_sin_diagonal(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f-3;i++)
        for(j=i+1;j<c-1-i;j++)
            printf("\t %d",m[i][j]);
}

void triangulito_arriba_con_diagonal(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f-2;i++)
        for(j=i;j<c-i;j++)
            printf("\t %d",m[i][j]);
}

void triangulito_abajo_sin_diagonal(int m[][COL],int f,int c)
{
    int i,j;
    for(i=3;i<f;i++)
        for(j=c-i;j<i;j++)
            printf("\t %d",m[i][j]);
}

void triangulito_abajo_con_diagonal(int m[][COL],int f,int c)
{
    int i,j;
    for(i=2;i<f;i++)
        for(j=c-1-i;j<=i;j++)
            printf("\t %d",m[i][j]);
}

void transpuesta_mostrar(int m[][COL],int f,int c)
{
    int t[f][c];
    int i,j;
    for(i=0;i<f;i++)
    {
        t[i][i]=m[i][i];
        for(j=i+1;j<c;j++)
        {
            t[i][j]=m[j][i];
            t[j][i]=m[i][j];
        }
    }
    mostrar_matriz(t,f,c);
}

void transpuesta_in_situ(int m[][COL],int f,int c)
{
    int i,j,aux;
    for(i=0;i<f;i++)
        for(j=i+1;j<c;j++)
        {
            aux=m[i][j];
            m[i][j]=m[j][i];
            m[j][i]=aux;
        }
}

void opuesta_mostrar(int m[][COL],int f,int c)
{
    int op[FIL][COL];
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            op[i][j]=-m[i][j];
    mostrar_matriz(op,f,c);
}

int es_matriz_nula(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
    {
        if(m[i][i]!=0)
            return 0;
        for(j=i+1;j<c;j++)
            if(m[i][j]!=0||m[j][i]!=0)
                return 0;
    }
    return 1;
}

int es_matriz_diagonal(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
        for(j=i+1;j<c;j++)
            if(m[i][j]!=0||m[j][i]!=0)
                return 0;
    return 1;
}

int es_matriz_identidad(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
    {
        if(m[i][i]!=1)
            return 0;
        for(j=i+1;j<c;j++)
            if(m[i][j]!=0||m[j][i]!=0)
                return 0;
    }
    return 1;
}

int es_matriz_escalar(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
    {
        if(m[i][i]!=m[0][0])
            return 0;
        for(j=i+1;j<c;j++)
            if(m[i][j]!=0||m[j][i]!=0)
                return 0;
    }
    return 1;
}

int es_matriz_antisimetrica(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
        for(j=i+1;j<c;j++)
            if(m[i][j]!=-m[j][i])
                return 0;
    return 1;
}

int es_matriz_simetrica_respecto_diag_pral(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
        for(j=i+1;j<c;j++)
            if(m[i][j]!=m[j][i])
                return 0;
    return 1;
}

int es_matriz_simetrica_respecto_diag_secund(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f-1;i++)
        for(j=0;j<c-1-i;j++)
            if(m[i][j]!=m[c-1-j][f-1-i])
                return 0;
    return 1;
}

int es_matriz_simetrica_horizontalmente(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<=f/2;i++)
        for(j=0;j<c;j++)
            if(m[i][j]!=m[f-1-i][j])
                return 0;
    return 1;
}

int es_matriz_simetrica_verticalmente(int m[][COL],int f,int c)
{
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<=c/2;j++)
            if(m[i][j]!=m[i][c-1-j])
                return 0;
    return 1;
}

void producto_matricial_cuadradas(int m1[][COL],int m2[][COL],int m3[][COL],int f,int c,int f2,int c2)
{
    int i,j,k;
    for(i=0;i<f;i++)
        for(j=0;j<c2;j++)
        {
            m3[i][j]=0;
            for(k=0;k<f2;k++)       //            for(k=0;k<c1;k++)
                m3[i][j]+=(m1[i][k]*m2[k][j]);
        }
}

//x y y coordenadas para el programador (es decir, contando a ambas coordenadas desde el cero

void vecinos(int m[][COL],int f,int c,int x,int y)//generando las posiciones que necesito
{
    int i,j;
    for(i=x-1;i<=x+1;i++)
        for(j=y-1;j<=y+1;j++)
            if(i>=0&&i<f&&j>=0&&j<c)
                if(!(x==i&&y==j))
                    printf("\t %d",m[i][j]);
}
/*
void vecinos(int m[][COL],int f,int c,int x,int y)//generando los desplazamientos necesarios
{
    int i,j;
     for(i=-1;i<2;i++)
        for(j=-1;j<2;j++)
            if(DATO_VALIDO(x+i,0,f-1)&&DATO_VALIDO(y+j,0,c-1))
              if((x+i!=x)||(y+j!=y))
                 printf("\t <%d>",m[x+i][y+j]);
}
*/
