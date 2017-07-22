#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<windows.h>
#define TAM    10
#define DATO_VALIDO(x,li,ls)    ((x)>=(li)&&(x)<=(ls))?1:0
void menu(int*,int,int*);
int cargar_vector(int*,int,int*);
void vaciar_vector(int*,int,int*);
int mostrar_vector(int*,int,int);
void mostrar_informe_del_vector(int*,int,int);
void burbujeo_orden_ascendente(int*,int);
void burbujeo_orden_descendente(int*,int);
void seleccion_orden_ascendente(int*,int);
void seleccion_orden_descendente(int*,int);
int insertar_en_posicion(int*,int*,int,int,int);
int insertar_en_posicion_hacia_izquierda(int*,int*,int,int,int);
int insertar_en_orden(int*,int*,int,int);
int insertar_en_orden_hacia_izquierda(int*,int*,int,int);
int eliminar_de_posicion(int*,int*,int,int);
int eliminar_primera_aparicion(int*,int*,int,int);
int eliminar_todas_las_apariciones(int*,int*,int,int);
