#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#define     FIL     4
#define     COL     4

void cargar_matriz(int[][COL],int,int);
void mostrar_matriz(int[][COL],int,int);

int matriz_simetrica_respecto_diagonal_secundaria(int[][COL],int,int);
