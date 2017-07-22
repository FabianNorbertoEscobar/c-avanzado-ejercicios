#include "lista_doblemente_enlazada.h"

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

void cargar_dato(t_dato*);
void mostrar_dato(const t_dato*);
int comparar_dato(const void*,const void*);
int comparar_clave(const void*,const void*);
void mostrar_nodo(const void*);
