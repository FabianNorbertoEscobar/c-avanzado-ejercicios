#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>

#define     TAM     10

void *mem_cpy(void*,const void*,size_t);

typedef int(*t_cmp)(const void*,const void*);

void intercambio(void*,void*,size_t);

void ordenamiento_por_seleccion(void*,size_t,size_t,t_cmp);

void mostrar_vector_enteros(int[],int);

int comparar_enteros(const void*,const void*);
