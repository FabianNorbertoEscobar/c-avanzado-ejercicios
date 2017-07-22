#include<stdio.h>
#include<conio.h>
#include<locale.h>

#define EQUIPOS 6
#define DATO_VALIDO(x,li,ls)    ((x)>=(li)&&(x)<=(ls))

void inicializar_vector(int[],int);
void cargar_tabla(int[][EQUIPOS],int);
void puntos_por_equipo(int[][EQUIPOS],int[],int);
void mostrar_puntos(int[],int);
void campeon_del_torneo(int[],int);
