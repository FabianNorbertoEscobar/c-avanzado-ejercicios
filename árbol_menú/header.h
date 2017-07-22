#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#include "primitivas_árbol.h"

#define     DATO_VALIDO(x,li,ls)    ((x)>=(li)&&(x)<=(ls))

void cargar_dato(t_dato*);
void mostrar_dato(const t_dato*);
void mostrar_nodo(const void*);
int comparar_enteros(const void*,const void*);

int menu(void);

int recursiva_o_iterativa(void);
int submenu_recorrer(void);

int binario_o_texto(void);
int submenu_exportar(void);

int submenu_contar(void);
int submenu_mostrar(void);
int submenu_mostrar_y_contar(void);
int submenu_podar(void);

int ingresa_nivel(void);
int ingresa_altura(void);
