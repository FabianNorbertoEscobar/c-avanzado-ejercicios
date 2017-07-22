#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#define     REG     99
#define     TOPE    36
#define     FIL     100
#define     COL     7

#define     VERDADERO       1
#define     FALSO           0

#define     DATO_VALIDO(x,li,ls)        ((x)>=(li)&&(x)<=(ls))

size_t str_len(const char*);
char *str_ncpy(char*,const char*,size_t);
int cargar_matrices_de_datos(char[][TOPE],int,int,float[][COL],int,int);
void mostrar_matrices_de_datos(char[][TOPE],int,int,float[][COL],int,int,int);
void promedios_de_alumnos(float[][COL],int,int,int);
void calcular_promedio_de_alumno(float[],int,int);
void promedios_por_evaluacion_y_general(float[][COL],int,int,int);
int exportar_a_archivo_de_texto(char[][TOPE],int,int,float[][COL],int,int,int);
