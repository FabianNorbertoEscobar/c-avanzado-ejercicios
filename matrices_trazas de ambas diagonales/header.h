#include<stdio.h>
#include<conio.h>
#include<locale.h>

#define FIL 4
#define COL 4

void cargar_matriz(int[][COL],int,int);
void mostrar_matriz(int[][COL],int,int);

int traza_diag_pral(int[][COL],int,int);
int traza_diag_sec(int[][COL],int,int);
