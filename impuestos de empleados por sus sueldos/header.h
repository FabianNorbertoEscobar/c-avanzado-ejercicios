#include "lista_doblemente_enlazada.h"
#include "arbol.h"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

typedef struct
{
    char cuit[12];
    float sueldo_total;
    float importe_impuesto;
}t_registro;

/// prototipos cadena
char *str_cpy(char *destino,const char *origen);
int str_cmp(const char *s1,const char *s2);

/// prototipos comparaciones
int comparar_cuit(const void *v1,const void *v2);
int comparar_codigo_concepto(const void *v1,const void *v2);

/// prototipos funciones
void generar_lista_de_conceptos_por_empleado(t_lista *l);
void generar_arbol_de_importes_de_conceptos(t_arbol *a);
void generar_archivo_de_impuestos(t_lista *l,t_arbol *a,FILE *pf);
float calcular_impuesto(float sueldo);
