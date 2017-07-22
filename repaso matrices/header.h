#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>

#define     FIL     4
#define     COL     4

#define DATO_VALIDO(x,li,ls)    ((x)>=(li)&&(x)<=(ls))

void cargar_matriz(int[][COL],int,int);
void mostrar_matriz(int[][COL],int,int);

void elementos_diagonal_principal(int[][COL],int,int);
void elementos_diagonal_secundaria(int[][COL],int,int);

void triangulo_superior_diag_pral_sin_diag(int[][COL],int,int);
void triangulo_superior_diag_pral_con_diag(int[][COL],int,int);

void triangulo_inferior_diag_pral_sin_diag(int[][COL],int,int);
void triangulo_inferior_diag_pral_con_diag(int[][COL],int,int);

void triangulo_superior_diag_secund_sin_diag(int[][COL],int,int);
void triangulo_superior_diag_secund_con_diag(int[][COL],int,int);

void triangulo_inferior_diag_secund_sin_diag(int[][COL],int,int);
void triangulo_inferior_diag_secund_con_diag(int[][COL],int,int);

void triangulito_arriba_sin_diagonal(int[][COL],int,int);
void triangulito_arriba_con_diagonal(int[][COL],int,int);
void triangulito_abajo_sin_diagonal(int[][COL],int,int);
void triangulito_abajo_con_diagonal(int[][COL],int,int);

void transpuesta_mostrar(int[][COL],int,int);
void transpuesta_in_situ(int[][COL],int,int);

void opuesta_mostrar(int[][COL],int,int);

int es_matriz_nula(int[][COL],int,int);
int es_matriz_diagonal(int[][COL],int,int);
int es_matriz_identidad(int[][COL],int,int);
int es_matriz_escalar(int[][COL],int,int);
int es_matriz_antisimetrica(int[][COL],int,int);

int es_matriz_simetrica_respecto_diag_pral(int[][COL],int,int);
int es_matriz_simetrica_respecto_diag_secund(int[][COL],int,int);
int es_matriz_simetrica_horizontalmente(int[][COL],int,int);
int es_matriz_simetrica_verticalmente(int[][COL],int,int);

void producto_matricial_cuadradas(int[][COL],int[][COL],int[][COL],int,int,int,int);
void vecinos(int[][COL],int,int,int,int);
