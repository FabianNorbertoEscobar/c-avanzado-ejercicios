#include "encabezados.h"
float coseno(float x,float tol)
    {
    int i,signo;
    float cos,ult;//ult=último término
    i=1;
    cos=ult=1;//primer término
    signo=-1;//comienzo con signo negativo porque el segundo término es negativo
    while(fabs(ult)>tol)//deja de ciclar cuando el módulo del último término no sea mayor que la tolerancia
        {//fabs calcula el módulo de un flotante
        ult=ult*x*x/i/(i+1);//calculo un nuevo término
        cos+=(signo*ult);
        signo*=-1;//cambio de signo
        i+=2;//los exponentes se incrementan de a dos
        }
    return cos;
    }
