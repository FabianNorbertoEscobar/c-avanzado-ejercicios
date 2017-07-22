#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define DATO_VALIDO(x,li,ls)    ((x)>=(li)&&(x)<=(ls))
#define N 3
void cargar_matriz_cuadrada(int[][N],int);
void mostrar_matriz_cuadrada(int[][N],int);
int elemento_ij(int*,int,int,int);
void mostrar_elementos_diagonal_principal(int[][N],int);
void mostrar_elementos_diagonal_secundaria(int[][N],int);
void mostrar_diagonal_principal(int[][N],int);
void mostrar_diagonal_secundaria(int[][N],int);
