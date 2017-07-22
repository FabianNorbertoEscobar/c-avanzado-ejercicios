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
int dia_de_la_semana(tFecha f)
    {
    int result1,result2,result3,result4,result5;
    int regular[]={0,3,3,6,1,4,6,2,5,0,3,5};
    int noregular[]={0,3,4,0,2,5,0,3,6,1,4,6};
    f.mes=(bisiesto(f.anio))?noregular[f.mes-1]:regular[f.mes-1];
    result1=(f.anio-1)%7;
    result2=(f.anio-1)/4;
    result3=(3*(((f.anio-1)/100)+1))/4;
    result4=(result2-result3)%7;
    result5=f.dia%7;
    return (result1+result4+f.mes+result5)%7;
    }
void nombre_de_dia(int x)
    {
    char nombre[7][10]={"Domingo","Lunes","Martes","Miércoles","Jueves","Viernes","Sábado"};
    puts(nombre[x]);
    }
