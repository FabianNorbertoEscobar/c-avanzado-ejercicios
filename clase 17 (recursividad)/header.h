#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>

#include "lista_simplemente_enlazada.h"

void cadena_encolumnada(char*);
void cadena_encolumnada_al_reves(char*);

void cadena_encolumnada_doble_con_repeticion(char*);
void cadena_encolumnada_doble_sin_repeticion(char*);

void cadena_en_triangulo_1(char*);
void cadena_en_triangulo_2(char*);

void cadena_en_triangulo_3(char*);
void cadena_en_triangulo_3_recursiva(char*,int);

void cadena_en_triangulo_4(char*);
void cadena_en_triangulo_4_recursiva(char*,int);

void numero_encolumnado(int);
void numero_encolumnado_al_reves(int);

void numero_encolumnado_doble_con_repeticion(int);
void numero_encolumnado_doble_sin_repeticion(int);

void numero_en_triangulo_1(int);
void numero_en_triangulo_2(int);

void cambio_de_base(int,int);

void caracter_en_triangulo(char,int);
void caracter_en_triangulo_inverso(char,int);
void caracter_en_doble_triangulo_con_repeticion(char,int);
void caracter_en_doble_triangulo_sin_repeticion(char,int);

void mostrar_lista_ordenada(const t_lista *l);
void mostrar_en_reversa_lista_ordenada(const t_lista*);
