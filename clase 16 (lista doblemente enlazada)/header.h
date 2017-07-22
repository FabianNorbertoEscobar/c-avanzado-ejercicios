#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#include "lista_doblemente_enlazada.h"

void cargar_dato(t_dato *d);
void mostrar_dato(const t_dato *d);
void ingresa_clave(int*);

int comparar_enteros(const void*,const void*);
int comparar_claves(const void*,const void*);
