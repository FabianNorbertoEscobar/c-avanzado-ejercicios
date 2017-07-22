#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<windows.h>

#define FIL 5
#define COL 5

void cargar_matriz(int[][COL],int,int);
void mostrar_matriz(int[][COL],int,int);

void mostrar_elementos_diagonal_principal(int[][COL],int,int);
void mostrar_elementos_diagonal_secundaria(int[][COL],int,int);

void mostrar_elementos_triang_sup_diag_pral_sin_diag(int[][COL],int,int);
void mostrar_elementos_triang_inf_diag_pral_sin_diag(int[][COL],int,int);
void mostrar_elementos_triang_sup_diag_sec_sin_diag(int[][COL],int,int);
void mostrar_elementos_triang_inf_diag_sec_sin_diag(int[][COL],int,int);

void mostrar_elementos_triang_sup_diag_pral_con_diag(int[][COL],int,int);
void mostrar_elementos_triang_inf_diag_pral_con_diag(int[][COL],int,int);
void mostrar_elementos_triang_sup_diag_sec_con_diag(int[][COL],int,int);
void mostrar_elementos_triang_inf_diag_sec_con_diag(int[][COL],int,int);

void mostrar_diagonal_principal(int[][COL],int,int);
void mostrar_diagonal_secundaria(int[][COL],int,int);

void mostrar_triang_sup_diag_pral_sin_diag(int[][COL],int,int);
void mostrar_triang_inf_diag_pral_sin_diag(int[][COL],int,int);
void mostrar_triang_sup_diag_sec_sin_diag(int[][COL],int,int);
void mostrar_triang_inf_diag_sec_sin_diag(int[][COL],int,int);

void mostrar_triang_sup_diag_pral_con_diag(int[][COL],int,int);
void mostrar_triang_inf_diag_pral_con_diag(int[][COL],int,int);
void mostrar_triang_sup_diag_sec_con_diag(int[][COL],int,int);
void mostrar_triang_inf_diag_sec_con_diag(int[][COL],int,int);

void mostrar_triang_arriba_diagonales_sin_diag(int[][COL],int,int);
void mostrar_triang_abajo_diagonales_sin_diag(int[][COL],int,int);
void mostrar_triang_izquierda_diagonales_sin_diag(int[][COL],int,int);
void mostrar_triang_derecha_diagonales_sin_diag(int[][COL],int,int);

void mostrar_triang_arriba_diagonales_con_diag(int[][COL],int,int);
void mostrar_triang_abajo_diagonales_con_diag(int[][COL],int,int);
void mostrar_triang_izquierda_diagonales_con_diag(int[][COL],int,int);
void mostrar_triang_derecha_diagonales_con_diag(int[][COL],int,int);

void mostrar_transpuesta(int[][COL],int,int);
void mostrar_opuesta(int m[][COL],int,int);
void array_a_matriz(int v[],int m[][COL],int,int);
void mostrar_en_espiral(int[][COL],int,int);
void mostrar_en_zigzag_horizontal(int[][COL],int,int);
void mostrar_en_lluvia_desde_ultima_fila(int[][COL],int,int);

int traza_diag_pral(int[][COL],int,int);
int traza_diag_sec(int[][COL],int,int);

int es_matriz_nula(int[][COL],int,int);
int es_matriz_diagonal(int[][COL],int,int);
int es_matriz_identidad(int[][COL],int,int);
int es_matriz_escalar(int[][COL],int,int);

int es_antisimetrica(int[][COL],int,int);
int es_simetrica_respecto_diag_pral(int[][COL],int,int);
int es_simetrica_respecto_diag_secund(int[][COL],int,int);
int es_simetrica_horizontalmente(int[][COL],int,int);
int es_simetrica_verticalmente(int[][COL],int,int);
