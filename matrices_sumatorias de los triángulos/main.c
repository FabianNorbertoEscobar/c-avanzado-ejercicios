#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int mat[FIL][COL];
    printf("\a\a\a");
    printf("\n\t ***************************************************************");
    printf("\n\t * SUMATORIAS DE LOS ELEMENTOS DE LOS TRIÁNGULOS DE UNA MATRIZ *");
    printf("\n\t ***************************************************************");
    cargar_matriz(mat,FIL,COL);
    printf("\n\n Matriz \n");
    mostrar_matriz(mat,FIL,COL);
    printf("\n\n Sumatoria de los elementos del triángulo superior \n a la diagonal principal, sin incluirla: \t %d",sumar_elementos_triang_sup_diag_pral_sin_diag(mat,FIL,COL));
    printf("\n\n Sumatoria de los elementos del triángulo inferior \n a la diagonal principal, sin incluirla: \t %d",sumar_elementos_triang_inf_diag_pral_sin_diag(mat,FIL,COL));
    printf("\n\n Sumatoria de los elementos del triángulo superior \n a la diagonal secundaria, sin incluirla: \t %d",sumar_elementos_triang_sup_diag_sec_sin_diag(mat,FIL,COL));
    printf("\n\n Sumatoria de los elementos del triángulo inferior \n a la diagonal secundaria, sin incluirla: \t %d",sumar_elementos_triang_inf_diag_sec_sin_diag(mat,FIL,COL));
    printf("\n\n Sumatoria de los elementos del triángulo superior \n a la diagonal principal, incluyéndola: \t %d",sumar_elementos_triang_sup_diag_pral_con_diag(mat,FIL,COL));
    printf("\n\n Sumatoria de los elementos del triángulo inferior \n a la diagonal principal, incluyéndola: \t %d",sumar_elementos_triang_inf_diag_pral_con_diag(mat,FIL,COL));
    printf("\n\n Sumatoria de los elementos del triángulo superior \n a la diagonal secundaria, incluyéndola: \t %d",sumar_elementos_triang_sup_diag_sec_con_diag(mat,FIL,COL));
    printf("\n\n Sumatoria de los elementos del triángulo inferior \n a la diagonal secundaria, incluyéndola: \t %d",sumar_elementos_triang_inf_diag_sec_con_diag(mat,FIL,COL));
    printf("\n\n\t\t\t\t Fin del programa....... \n\n\a\a\a");
    getch();
    return 0;
    }
