#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int mat[FIL][COL];
    printf("\a\a\a");
    printf("\n\t ***********************");
    printf("\n\t * TRAZAS DE LA MATRIZ *");
    printf("\n\t ***********************");
    cargar_matriz(mat,FIL,COL);
    printf("\n\n Matriz \n");
    mostrar_matriz(mat,FIL,COL);
    printf("\n\n Traza principal de la matriz = %d \n",traza_diag_pral(mat,FIL,COL));
    printf("\n\n Traza secundaria de la matriz = %d \n",traza_diag_sec(mat,FIL,COL));
    printf("\n\n\t\t\t\t Fin del programa....... \n\n\a\a\a");
    getch();
    return 0;
    }
