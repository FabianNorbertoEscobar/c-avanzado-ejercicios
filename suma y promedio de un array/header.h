#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<windows.h>

typedef struct
    {
    long int suma;
    float promedio;
    }t_calculos;

void cargar_array(int*,int);
void mostrar_array(int*,int);
float suma_y_promedio_main1(int*,int,long int*);
t_calculos suma_y_promedio_main2(int*,int);
