#include "header.h"
int fecha_valida(tFecha f)
    {
    return (f.anio>=1600&&f.mes>=1&&f.mes<=12&&f.dia>=1&&f.dia<=cant_dias_mes(f.mes,f.anio))?1:0;
    }
int cant_dias_mes(int m,int a)
    {
    int dias[]={31,28,31,30,31,30,31,31,30,31,30,31};
    return (m==2)?28+bisiesto(a):dias[m-1];
    }
int bisiesto(int a)
    {
    return ((a%4==0&&a%100!=0)||a%400==0)?1:0;
    }
tFecha fecha_anterior(tFecha f)
    {
    if(f.dia>1)
        f.dia--;
    else
        {
        if(f.mes==1)
            {
            f.mes=12;
            f.anio--;
            }
        else
            f.mes--;
        f.dia=cant_dias_mes(f.mes,f.anio);
        }
    return f;
    }
