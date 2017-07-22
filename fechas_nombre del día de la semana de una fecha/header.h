#include<stdio.h>
#include<conio.h>
#include<locale.h>
typedef struct
    {
    int dia,
        mes,
        anio;
    }tFecha;
int fecha_valida(tFecha);
int cant_dias_mes(int,int);
int bisiesto(int);
int dia_de_la_semana(tFecha);
void nombre_de_dia(int);
