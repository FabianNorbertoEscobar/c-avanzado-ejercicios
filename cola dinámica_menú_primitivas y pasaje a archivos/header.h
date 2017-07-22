#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#include "primitivas_cola_dinámica.h"

#define DATO_VALIDO(x,li,ls)    ((x)>=(li)&&(x)<=(ls))

void cargar_dato(t_dato*);
void mostrar_dato(t_dato*);
int menu(void);
int exportar_cola_a_archivo_bin(t_cola*);
int exportar_cola_a_archivo_txt(t_cola*);
int cargar_cola_desde_archivo_bin(t_cola*);
int cargar_cola_desde_archivo_txt(t_cola*);
