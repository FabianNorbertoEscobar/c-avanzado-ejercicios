#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int mat1[FIL][COL],mat2[FIL][COL],mat3[FIL][COL];
    printf("\a\a\a");
    printf("\n\t *************************************************");
    printf("\n\t * MULTIPLICAR MATRICES CUADRADAS DE MISMO ORDEN *");
    printf("\n\t *************************************************");
    printf("\n Se le pedirá que ingrese dos matrices para luego multiplicarlas \n");
    cargar_matriz(mat1,FIL,COL);
    cargar_matriz(mat2,FIL,COL);
    printf("\n\n Matriz 1 \n");
    mostrar_matriz(mat1,FIL,COL);
    printf("\n\n Matriz 2 \n");
    mostrar_matriz(mat2,FIL,COL);
    producto_matricial_cuadradas(mat1,mat2,mat3,FIL,COL);
    printf("\n\n Producto entre las matrices 1 y 2 \n");
    mostrar_matriz(mat3,FIL,COL);
    printf("\n\n\t\t\t\t Fin del programa....... \n\n\a\a\a");
    getch();
    return 0;
    }
