#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
typedef struct
    {
    int dia,
        mes,
        anio;
    }tFecha;
int fecha_valida(tFecha);
int cant_dias_mes(int,int);
int bisiesto(int);
int julianos(tFecha);
int diferencia_de_dias(tFecha,tFecha);
