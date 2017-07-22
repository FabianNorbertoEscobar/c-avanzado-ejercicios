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
int calcula_edad(tFecha f_nac,tFecha f_act);
