#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<windows.h>

#define DATO_VALIDO(x,li,ls)    ((x)>=(li)&&(x)<=(ls))

typedef struct
    {
    float num;
    }t_registro;

int cargar_array_float(float*,int);
void mostrar_array_float(float*,int);
int menu(void);
void minimo(float*,int);
void promedio_valores_posiciones_pares(float*,int);
void mostrar_orden_inverso(float*,int);
void grabar_en_archivo_binario(float*,int,FILE*);
void grabar_en_archivo_de_texto(float*,int,FILE*);
