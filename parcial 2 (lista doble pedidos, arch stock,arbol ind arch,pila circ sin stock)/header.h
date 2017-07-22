#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#include "lista_doblemente_enlazada.h"
#include "arbol_binario_de_busqueda.h"
#include "pila_circular.h"

typedef struct
{
    char nombre_producto[36];
    char codigo_producto[6];
    int stock;
}t_registro;

char *str_cpy(char*,const char*);
int str_cmp(const char*,const char*);

int comparar_dato_contra_dato(const void*,const void*);     // usada en la lista
int comparar_dato_contra_clave(const void*,const void*);    // usada en el arbol

void generar_archivo_de_productos(FILE*);
void generar_indice_del_archivo_en_el_arbol(FILE*,t_arbol*,t_cmp);
void generar_lista_de_pedidos(t_lista*);

void procesar_pedido_completo(FILE*,const t_arbol*,t_pila*,t_dato_lista*,int);
void mostrar_pedidos_sin_stock(t_pila*);
