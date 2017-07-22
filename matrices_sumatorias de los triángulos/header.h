#include<stdio.h>
#include<conio.h>
#include<locale.h>

#define FIL 4
#define COL 4

void cargar_matriz(int[][COL],int,int);
void mostrar_matriz(int[][COL],int,int);

int sumar_elementos_triang_sup_diag_pral_sin_diag(int[][COL],int,int);
int sumar_elementos_triang_inf_diag_pral_sin_diag(int[][COL],int,int);
int sumar_elementos_triang_sup_diag_sec_sin_diag(int[][COL],int,int);
int sumar_elementos_triang_inf_diag_sec_sin_diag(int[][COL],int,int);

int sumar_elementos_triang_sup_diag_pral_con_diag(int[][COL],int,int);
int sumar_elementos_triang_inf_diag_pral_con_diag(int[][COL],int,int);
int sumar_elementos_triang_sup_diag_sec_con_diag(int[][COL],int,int);
int sumar_elementos_triang_inf_diag_sec_con_diag(int[][COL],int,int);
