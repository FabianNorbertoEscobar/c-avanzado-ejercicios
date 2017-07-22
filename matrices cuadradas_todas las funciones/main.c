#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 0E");
    int mat[FIL][COL];

    printf("\a\a");
    printf("\n\t\t **********************");
    printf("\n\t\t * MATRICES CUADRADAS *");
    printf("\n\t\t **********************");

    cargar_matriz(mat,FIL,COL);
    system("cls");

    printf("\a\a");
    printf("\n\t\t **********************");
    printf("\n\t\t * MATRICES CUADRADAS *");
    printf("\n\t\t **********************");

    printf("\n\n Matriz cargada \n");
    mostrar_matriz(mat,FIL,COL);

    printf("\n\n Elementos de la diagonal principal \n\n");
    mostrar_elementos_diagonal_principal(mat,FIL,COL);
    printf("\n\n Elementos de la diagonal secundaria \n\n");
    mostrar_elementos_diagonal_secundaria(mat,FIL,COL);

    printf("\n\n Elementos del triángulo superior a la diagonal principal sin la diagonal \n\n");
    mostrar_elementos_triang_sup_diag_pral_sin_diag(mat,FIL,COL);
    printf("\n\n Elementos del triángulo inferior a la diagonal principal sin la diagonal \n\n");
    mostrar_elementos_triang_inf_diag_pral_sin_diag(mat,FIL,COL);
    printf("\n\n Elementos del triángulo superior a la diagonal secundaria sin la diagonal \n\n");
    mostrar_elementos_triang_sup_diag_sec_sin_diag(mat,FIL,COL);
    printf("\n\n Elementos del triángulo inferior a la diagonal secundaria sin la diagonal \n\n");
    mostrar_elementos_triang_inf_diag_sec_sin_diag(mat,FIL,COL);

    printf("\n\n Elementos del triángulo superior a la diagonal principal con la diagonal \n\n");
    mostrar_elementos_triang_sup_diag_pral_con_diag(mat,FIL,COL);
    printf("\n\n Elementos del triángulo inferior a la diagonal principal con la diagonal \n\n");
    mostrar_elementos_triang_inf_diag_pral_con_diag(mat,FIL,COL);
    printf("\n\n Elementos del triángulo superior a la diagonal secundaria con la diagonal \n\n");
    mostrar_elementos_triang_sup_diag_sec_con_diag(mat,FIL,COL);
    printf("\n\n Elementos del triángulo inferior a la diagonal secundaria con la diagonal \n\n");
    mostrar_elementos_triang_inf_diag_sec_con_diag(mat,FIL,COL);

    printf("\n\n Diagonal principal \n");
    mostrar_diagonal_principal(mat,FIL,COL);
    printf("\n\n Diagonal secundaria \n");
    mostrar_diagonal_secundaria(mat,FIL,COL);

    printf("\n\n Triángulo superior a la diagonal principal (sin la diagonal) \n");
    mostrar_triang_sup_diag_pral_sin_diag(mat,FIL,COL);
    printf("\n\n Triángulo inferior a la diagonal principal (sin la diagonal) \n");
    mostrar_triang_inf_diag_pral_sin_diag(mat,FIL,COL);
    printf("\n\n Triángulo superior a la diagonal secundaria (sin la diagonal) \n");
    mostrar_triang_sup_diag_sec_sin_diag(mat,FIL,COL);
    printf("\n\n Triángulo inferior a la diagonal secundaria (sin la diagonal) \n");
    mostrar_triang_inf_diag_sec_sin_diag(mat,FIL,COL);

    printf("\n\n Triángulo superior a la diagonal principal (con la diagonal) \n");
    mostrar_triang_sup_diag_pral_con_diag(mat,FIL,COL);
    printf("\n\n Triángulo inferior a la diagonal principal (con la diagonal) \n");
    mostrar_triang_inf_diag_pral_con_diag(mat,FIL,COL);
    printf("\n\n Triángulo superior a la diagonal secundaria (con la diagonal) \n");
    mostrar_triang_sup_diag_sec_con_diag(mat,FIL,COL);
    printf("\n\n Triángulo inferior a la diagonal secundaria (con la diagonal) \n");
    mostrar_triang_inf_diag_sec_con_diag(mat,FIL,COL);

    printf("\n\n Triángulo arriba de las diagonales (sin las diagonales) \n");
    mostrar_triang_arriba_diagonales_sin_diag(mat,FIL,COL);
    printf("\n\n Triángulo abajo de las diagonales (sin las diagonales) \n");
    mostrar_triang_abajo_diagonales_sin_diag(mat,FIL,COL);
    printf("\n\n Triángulo a la izquierda de las diagonales (sin las diagonales) \n");
    mostrar_triang_izquierda_diagonales_sin_diag(mat,FIL,COL);
    printf("\n\n Triángulo a la derecha de las diagonales (sin las diagonales) \n");
    mostrar_triang_derecha_diagonales_sin_diag(mat,FIL,COL);

    printf("\n\n Triángulo arriba de las diagonales (con las diagonales) \n");
    mostrar_triang_arriba_diagonales_con_diag(mat,FIL,COL);
    printf("\n\n Triángulo abajo de las diagonales (con las diagonales) \n");
    mostrar_triang_abajo_diagonales_con_diag(mat,FIL,COL);
    printf("\n\n Triángulo a la izquierda de las diagonales (con las diagonales) \n");
    mostrar_triang_izquierda_diagonales_con_diag(mat,FIL,COL);
    printf("\n\n Triángulo a la derecha de las diagonales (con las diagonales) \n");
    mostrar_triang_derecha_diagonales_con_diag(mat,FIL,COL);

    printf("\n\n Matriz transpuesta \n");
    mostrar_transpuesta(mat,FIL,COL);
    printf("\n\n Matriz opuesta \n");
    mostrar_opuesta(mat,FIL,COL);
    printf("\n\n Matriz mostrada en espiral \n");
    mostrar_en_espiral(mat,FIL,COL);
    printf("\n\n Matriz mostrada en zigzag horizontal \n");
    mostrar_en_zigzag_horizontal(mat,FIL,COL);
    printf("\n\n Matriz en lluvia desde el primer elemento de la última fila \n");
    mostrar_en_lluvia_desde_ultima_fila(mat,FIL,COL);

    printf("\n\n Traza principal de la matriz = %d \n",traza_diag_pral(mat,FIL,COL));
    printf("\n\n Traza secundaria de la matriz = %d \n",traza_diag_sec(mat,FIL,COL));

    printf("\n\n La matriz %s nula \n",es_matriz_nula(mat,FIL,COL)?"es":"no es");
    printf("\n\n La matriz %s diagonal \n",es_matriz_diagonal(mat,FIL,COL)?"es":"no es");
    printf("\n\n La matriz %s identidad \n",es_matriz_identidad(mat,FIL,COL)?"es":"no es");
    printf("\n\n La matriz %s escalar \n",es_matriz_escalar(mat,FIL,COL)?"es":"no es");

    printf("\n\n La matriz %s antisimétrica \n",es_antisimetrica(mat,FIL,COL)?"es":"no es");
    printf("\n\n La matriz %s simétrica respecto a la diagonal principal \n",es_simetrica_respecto_diag_pral(mat,FIL,COL)?"es":"no es");
    printf("\n\n La matriz %s simétrica respecto a la diagonal secundaria \n",es_simetrica_respecto_diag_secund(mat,FIL,COL)?"es":"no es");
    printf("\n\n La matriz %s simétrica horizontalmente \n",es_simetrica_horizontalmente(mat,FIL,COL)?"es":"no es");
    printf("\n\n La matriz %s simétrica verticalmente \n",es_simetrica_verticalmente(mat,FIL,COL)?"es":"no es");

    printf("\n\n\t\t\t\t\t Fin del programa.. \n\n\a\a");
    getch();
    return 0;
    }
