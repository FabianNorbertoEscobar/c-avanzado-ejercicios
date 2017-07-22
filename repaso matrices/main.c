#include "header.h"

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n \t\t MATRICES \n \a\a");

    int mat[FIL][COL];

    printf("\n\n Cargar matriz: \n");
    cargar_matriz(mat,FIL,COL);

    printf("\n\n Mostrar matriz: \n");
    mostrar_matriz(mat,FIL,COL);



    printf("\n\n\n Elementos de la diagonal principal \n\n");
    elementos_diagonal_principal(mat,FIL,COL);

    printf("\n\n Elementos de la diagonal secundaria \n\n");
    elementos_diagonal_secundaria(mat,FIL,COL);



    printf("\n\n Elementos triángulo superior a diagonal principal sin diag \n\n");
    triangulo_superior_diag_pral_sin_diag(mat,FIL,COL);

    printf("\n\n Elementos triángulo superior a diagonal principal con diag \n\n");
    triangulo_superior_diag_pral_con_diag(mat,FIL,COL);



    printf("\n\n Elementos triángulo superior a diagonal secundaria sin diag \n\n");
    triangulo_superior_diag_secund_sin_diag(mat,FIL,COL);

    printf("\n\n Elementos triángulo superior a diagonal secundaria con diag \n\n");
    triangulo_superior_diag_secund_con_diag(mat,FIL,COL);



    printf("\n\n Elementos triángulo inferior a diagonal principal sin diag \n\n");
    triangulo_inferior_diag_pral_sin_diag(mat,FIL,COL);

    printf("\n\n Elementos triángulo inferior a diagonal principal con diag \n\n");
    triangulo_inferior_diag_pral_con_diag(mat,FIL,COL);



    printf("\n\n Elementos triángulo inferior a diagonal secundaria sin diag \n\n");
    triangulo_inferior_diag_secund_sin_diag(mat,FIL,COL);

    printf("\n\n Elementos triángulo inferior a diagonal secundaria con diag \n\n");
    triangulo_inferior_diag_secund_con_diag(mat,FIL,COL);



    printf("\n\n Triangulito arriba sin diagonal \n\n");
    triangulito_arriba_sin_diagonal(mat,FIL,COL);

    printf("\n\n Triangulito arriba con diagonal \n\n");
    triangulito_arriba_con_diagonal(mat,FIL,COL);



    printf("\n\n Triangulito abajo sin diagonal \n\n");
    triangulito_abajo_sin_diagonal(mat,FIL,COL);

    printf("\n\n Triangulito abajo con diagonal \n\n");
    triangulito_abajo_con_diagonal(mat,FIL,COL);



    printf("\n\n\n Matriz original \n\n");
    mostrar_matriz(mat,FIL,COL);

    printf("\n\n\n Mostrar transpuesta \n\n");
    transpuesta_mostrar(mat,FIL,COL);

    printf("\n\n\n Transpuesta in situ \n\n");
    transpuesta_in_situ(mat,FIL,COL);
    mostrar_matriz(mat,FIL,COL);

    printf("\n\n\n Transpuesta in situ \n\n ");
    transpuesta_in_situ(mat,FIL,COL);
    mostrar_matriz(mat,FIL,COL);

    printf("\n\n\n Mostrar opuesta \n\n");
    opuesta_mostrar(mat,FIL,COL);



    printf("\n\n\n La matriz %s nula \n",es_matriz_nula(mat,FIL,COL)?"es":"no es");

    printf("\n\n La matriz %s diagonal \n",es_matriz_diagonal(mat,FIL,COL)?"es":"no es");

    printf("\n\n La matriz %s identidad \n",es_matriz_identidad(mat,FIL,COL)?"es":"no es");

    printf("\n\n La matriz %s escalar \n",es_matriz_escalar(mat,FIL,COL)?"es":"no es");

    printf("\n\n La matriz %s antisimétrica \n",es_matriz_antisimetrica(mat,FIL,COL)?"es":"no es");



    printf("\n\n La matriz %s simétrica respecto diagonal principal \n",es_matriz_simetrica_respecto_diag_pral(mat,FIL,COL)?"es":"no es");

    printf("\n\n La matriz %s simétrica respecto diagonal secundaria \n",es_matriz_simetrica_respecto_diag_secund(mat,FIL,COL)?"es":"no es");

    printf("\n\n La matriz %s simétrica horizontalmente \n",es_matriz_simetrica_horizontalmente(mat,FIL,COL)?"es":"no es");

    printf("\n\n La matriz %s simétrica verticalmente \n",es_matriz_simetrica_verticalmente(mat,FIL,COL)?"es":"no es");



    printf("\n\n PRODUCTO MATRICIAL \n");
    int mat2[FIL][COL];
    int mat3[FIL][COL];

    printf("\n\n Cargar una matriz con que multiplicar a la otra: \n");
    cargar_matriz(mat2,FIL,COL);

    printf("\n\n MATRIZ 1 \n");
    mostrar_matriz(mat,FIL,COL);

    printf("\n\n MATRIZ 2: \n");
    mostrar_matriz(mat2,FIL,COL);

    printf("\n\n PRODUCTO \n");
    producto_matricial_cuadradas(mat,mat2,mat3,FIL,COL,FIL,COL);
    mostrar_matriz(mat3,FIL,COL);

    int i,j,op,band;
    do
        {
        printf("\a\a\a");
        printf("\n\n\n\t\t * VECINOS DE UN ELEMENTO DE LA MATRIZ *");
        printf("\n\n VECINDARIO \n");
        mostrar_matriz(mat,FIL,COL);

        printf("\n\n %c Descubra cuáles son los vecinos de alguien \n a partir de sus coordenadas en el vecindario: \n",16);
        band=0;
        do
            {
            if(band==1)
                printf("\n\n Esa fila no está en el vecindario.\n\a\a");
            printf("\n Ingrese la fila (1 a %d): \t",FIL);
            scanf("%d",&i);
            band=1;
            }
        while(!DATO_VALIDO(i,1,FIL));
        band=0;
        do
            {
            if(band==1)
                printf("\n\n Esa columna no está en el vecindario.\n\a\a");
            printf("\n Ingrese la columna (1 a %d): \t",COL);
            scanf("%d",&j);
            band=1;
            }
        while(!DATO_VALIDO(j,1,COL));

        printf("\n VECINOS: \n\n\a\a");
        vecinos(mat,FIL,COL,i-1,j-1);

        printf("\n\n ----------------------------------------------------------------------------- \n");
        printf("\n Para realizar una nueva búsqueda de vecinos, presione 1. \n\t Caso contrario, presione cualquier tecla:\t");
        scanf("%d",&op);
        }
    while(op==1);

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n");
    getch();
    return 0;
}
