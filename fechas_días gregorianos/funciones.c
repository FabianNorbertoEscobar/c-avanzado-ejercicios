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
int julianos(tFecha f)
    {
    int i,jul;
    jul=f.dia;
    for(i=1;i<f.mes;i++)
        jul+=cant_dias_mes(i,f.anio);
    return jul;
    }
int gregorianos(tFecha f)
    {
    tFecha f_inic;
    f_inic.dia=1;
    f_inic.mes=1;
    f_inic.anio=1600;
    int dif_de_anios,dias_bisiestos,i,greg;
    //calculo la diferencia de años en días, incluyendo los días bisiestos;
    dif_de_anios=f.anio-f_inic.anio;
    dias_bisiestos=0;
    for(i=f_inic.anio;i<=f.anio;i++)//recorro los años intermedios
        if(bisiesto(i))
            dias_bisiestos++;
    greg=dif_de_anios*365+dias_bisiestos;
    //cuando llego al año actual, agrego la diferencia entre los julianos
    greg+=(julianos(f)-julianos(f_inic));
    return greg;
    }

