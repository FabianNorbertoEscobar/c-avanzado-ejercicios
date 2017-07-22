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
void mostrar_elementos_diagonal_principal(int m[][COL],int f,int c)
    {
    int i;
    for(i=0;i<f;i++)
        {
        printf("\t %d",m[i][i]);
        }
    }
void mostrar_elementos_diagonal_secundaria(int m[][COL],int f,int c)
    {
    int i;
    for(i=0;i<f;i++)
        printf("\t %d",m[i][c-1-i]);
    }
void mostrar_elementos_triang_sup_diag_pral_sin_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=i+1;j<c;j++)
            printf("\t %d",m[i][j]);
    }
void mostrar_elementos_triang_inf_diag_pral_sin_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<i;j++)
            printf("\t %d",m[i][j]);
    }
void mostrar_elementos_triang_sup_diag_sec_sin_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f-1;i++)
        for(j=0;j<c-1-i;j++)
            printf("\t %d",m[i][j]);
    }
void mostrar_elementos_triang_inf_diag_sec_sin_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=1;i<f;i++)
        for(j=c-i;j<c;j++)
            printf("\t %d",m[i][j]);
    }
void mostrar_elementos_triang_sup_diag_pral_con_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=i;j<c;j++)
            printf("\t %d",m[i][j]);
    }
void mostrar_elementos_triang_inf_diag_pral_con_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<=i;j++)
            printf("\t %d",m[i][j]);
    }
void mostrar_elementos_triang_sup_diag_sec_con_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<=c-1-i;j++)
            printf("\t %d",m[i][j]);
    }
void mostrar_elementos_triang_inf_diag_sec_con_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=c-i-1;j<c;j++)
            printf("\t %d",m[i][j]);
    }
void mostrar_diagonal_principal(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(i==j)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_diagonal_secundaria(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(j==c-1-i)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_triang_sup_diag_pral_sin_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(i<j)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_triang_inf_diag_pral_sin_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(j<i)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_triang_sup_diag_sec_sin_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(j<c-1-i)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_triang_inf_diag_sec_sin_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(j>c-1-i)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_triang_sup_diag_pral_con_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(i<=j)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_triang_inf_diag_pral_con_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(j<=i)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_triang_sup_diag_sec_con_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(j<=c-1-i)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_triang_inf_diag_sec_con_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(j>=c-1-i)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_triang_arriba_diagonales_sin_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(i<j&&j<c-1-i)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_triang_abajo_diagonales_sin_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(j<i&&j>c-1-i)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_triang_izquierda_diagonales_sin_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(j<i&&j<c-1-i)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_triang_derecha_diagonales_sin_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(i<j&&j>c-1-i)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_triang_arriba_diagonales_con_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(i<=j&&j<=c-1-i)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_triang_abajo_diagonales_con_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(j<=i&&j>=c-1-i)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_triang_izquierda_diagonales_con_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(j<=i&&j<=c-1-i)
                printf(" %d",m[i][j]);
            else
                printf("  ");
            }
        }
    }
void mostrar_triang_derecha_diagonales_con_diag(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<c;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            if(i<=j&&j>=c-1-i)
                printf(" %d",m[i][j]);
            else
                printf("  ");
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
void mostrar_opuesta(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        printf("\n\t");
        for(j=0;j<c;j++)
            {
            printf(" %d",-m[i][j]);
            }
        }
    }
void array_a_matriz(int v[],int m[][COL],int f,int c)
    {
    int i,j,n;
    n=0;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++,n++)
            m[i][j]=v[n];
    }
void mostrar_en_espiral(int m[][COL],int f,int c)
    {
    int aux[f*c],aux2[f][c],tope,i,j,a,n;
    n=0;
    if(c%2)
        tope=c/2+1;
    else
        tope=c/2;
    for(a=0;a<tope;a++)
        {
        for(j=a,i=a;j<c-a;j++,n++)
            aux[n]=m[i][j];
        for(i=a+1,j--;i<c-a;i++,n++)
            aux[n]=m[i][j];
        for(i--,j--;j>=a;j--,n++)
            aux[n]=m[i][j];
        for(j++,i--;i>a;i--,n++)
            aux[n]=m[i][j];
        }
    array_a_matriz(aux,aux2,f,c);
    mostrar_matriz(aux2,f,c);
    }
void mostrar_en_zigzag_horizontal(int m[][COL],int f,int c)
    {
    int aux[f*c],aux2[f][c],i,j,t;
    t=0;
    for(i=0;i<f;i++)
        {
        if(i%2==0)
            for(j=0;j<c;j++,t++)
                aux[t]=m[i][j];
            else
                for(j=c-1;j>=0;j--,t++)
                    aux[t]=m[i][j];
        }
    array_a_matriz(aux,aux2,f,c);
    mostrar_matriz(aux2,f,c);
    }
void mostrar_en_lluvia_desde_ultima_fila(int m[][COL],int f,int c)
    {
    int aux[f*c],aux2[f][c],i,j,k,t,p;
    i=0;
    t=0;
    for(j=c-1;j>=0;j--)
        {
        for(k=j,i=0;k<c;k++,i++,t++)
            aux[t]=m[k][i];
        }
    for(p=1;p<c;p++)
        for(k=0,i=p;i<f;k++,i++,t++)
            aux[t]=m[k][i];
    array_a_matriz(aux,aux2,f,c);
    mostrar_matriz(aux2,f,c);
    }
int traza_diag_pral(int m[][COL],int f,int c)
    {
    int i,acum;
    acum=0;
    for(i=0;i<f;i++)
        acum+=m[i][i];
    return acum;
    }
int traza_diag_sec(int m[][COL],int f,int c)
    {
    int i,acum;
    acum=0;
    for(i=0;i<f;i++)
        acum+=m[i][c-1-i];
    return acum;
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
int es_antisimetrica(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f-2;i++)
        for(j=i+1;j<c;j++)
            if(m[i][j]!=-m[j][i])
                return 0;
    return 1;
    }
int es_simetrica_respecto_diag_pral(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=i+1;j<c;j++)
            if(m[i][j]!=m[j][i])
                return 0;
    return 1;
    }
int es_simetrica_respecto_diag_secund(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<f-1;i++)
        for(j=0;j<c-i-1;j++)
            if(m[i][j]!=m[c-j-1][f-i-1])
                return 0;
    return 1;
    }
int es_simetrica_horizontalmente(int m[][COL],int f,int c)
    {
    int i,j;
    for(i=0;i<=f/2;i++)
        for(j=0;j<c;j++)
            if(m[i][j]!=m[f-1-i][j])
                return 0;
    return 1;
    }
int es_simetrica_verticalmente(int m[][COL],int f,int c)
    {
    int i,j;
    for(j=0;j<=c/2;j++)
        for(i=0;i<f;i++)
            if(m[i][j]!=m[i][c-1-j])
                return 0;
    return 1;
    }
