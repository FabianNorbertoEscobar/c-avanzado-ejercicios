#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");

    printf("\n\n SIMETRÍA DE MATRIZ CUADRADA RESPECTO DIAGONAL SECUNDARIA \n\a\a");

    int mat[FIL][COL];

    printf("\n\n Ingrese una matriz de %dx%d \n",FIL,COL);
    cargar_matriz(mat,FIL,COL);

    printf("\n\n\t\t\t MATRIZ \n");
    mostrar_matriz(mat,FIL,COL);

    printf("\n\n La matriz %s simétrica respecto la diagonal secundaria \n",\
    matriz_simetrica_respecto_diagonal_secundaria(mat,FIL,COL)?"es":"no es");

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
    }
