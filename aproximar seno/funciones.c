#include "encabezados.h"
float seno(float x,float tol)
    {
    int i,signo;
    float sen,ult;//ult=(último término)
    i=2;
    sen=ult=x;//primer término
    signo=-1;//comienzo con signo negativo porque el segundo término es negativo
    while(fabs(ult)>tol)//deja de ciclar cuando el módulo del último término no sea mayor que la tolerancia
        {//fabs calcula el módulo de un flotante
        ult=ult*x*x/i/(i+1);//calculo un nuevo término
        sen+=(signo*ult);
        signo*=-1;//cambio de signo;
        i+=2;//los exponentes se incrementan de a dos
        }
    return(sen);
    }
