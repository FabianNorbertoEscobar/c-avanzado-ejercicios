#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<windows.h>

#define FIL 5
#define COL 5

#define DATO_VALIDO(x,li,ls)    ((x)>=(li)&&(x)<=(ls))

void cargar_matriz(int[][COL],int,int);
void mostrar_matriz(int[][COL],int,int);
void vecinos(int[][COL],int,int,int,int);
