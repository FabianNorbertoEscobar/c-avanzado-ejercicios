#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#include "primitivas_pila_estática.h"

#define DATO_VALIDO(x,li,ls)    ((x)>=(li)&&(x)<=(ls))

int fecha_valida(t_fecha*);
int cant_dias_mes(int,int);
int bisiesto(int);
void ingresa_fecha(t_fecha*);
void cargar_dato(t_dato*);
void mostrar_dato(t_dato*);
int menu(void);
int exportar_pila_a_archivo_bin(t_pila*);
int exportar_pila_a_archivo_txt(t_pila*);
int cargar_pila_desde_archivo_bin(t_pila*);
int cargar_pila_desde_archivo_txt(t_pila*);
