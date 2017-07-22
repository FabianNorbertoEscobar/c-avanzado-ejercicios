#include<stdio.h>
#include<conio.h>
#include<locale.h>

#define FIL 4
#define COL 4
#define FIL2 2
#define COL2 3

#define FALSO 0
#define VERDADERO 1

int* buscarValor(int *mat,int i,int j,int col);

void trianguloSuperiorDerecho(int mat[][COL],int fil,int col);
void trianguloSuperiorIzquierdo(int mat[][COL],int fil,int col);
void trianguloInferiorIzquierdo(int mat[][COL],int fil,int col);
void trianguloInferiorDerecho(int mat[][COL],int fil,int col);

void trianguloInferiorIzquierdoSD(int mat[][COL],int fil,int col);
void trianguloInferiorDerechoSD(int mat[][COL],int fil,int col);
void trianguloSuperiorDerechoSD(int mat[][COL],int fil,int col);
void trianguloSuperiorIzquierdoSD(int mat[][COL],int fil,int col);

int esIdentidad(int mat[][COL],int fil,int col);
void trasponerMatriz(int mat[][COL],int fil,int col);
void mostrarMatriz(int mat[][COL2],int fil,int col);
int productoDeMatrices(int mat[][COL],int mat2[][COL2],int matRes[][COL2],int fil,int col,int fil2,int col2);
int esSimetrica2(int mat[][COL],int fil,int col);
int esSimetrica(int mat[][COL],int fil,int col);
