#include<stdio.h>
#include<conio.h>
#include<locale.h>
typedef struct
    {
    int d,
        m,
        a;
    }t_fecha;
void mostrar_fecha(t_fecha);
int fecha_valida(t_fecha);
int cant_dias_mes(int,int);
int bisiesto(int);
t_fecha incrementar_un_dia(t_fecha);
t_fecha sumar_dias_a_fecha(t_fecha,int);
