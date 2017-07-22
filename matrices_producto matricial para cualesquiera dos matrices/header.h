#include<stdio.h>
#include<conio.h>
#include<locale.h>

#define TOPE 10
#define DATO_VALIDO(x,li,ls)    ((x)>=(li)&&(x)<=(ls))

void cargar_matriz(int[][TOPE],int,int);
void mostrar_matriz(int[][TOPE],int,int);
void producto_matricial(int[][TOPE],int[][TOPE],int[][TOPE],int,int,int,int);
