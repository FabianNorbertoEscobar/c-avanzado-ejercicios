#include "encabezados.h"
float raiz(float x,float tol)
    {
    float t_ant,t_act;
    t_act=1;//primer término de la serie
    do
        {
        t_ant=t_act;
        t_act=(t_ant+x/t_ant)/2;
        }
    while(fabs(t_act-t_ant)>=tol);//dejo de ciclar cuando el módulo de la diferencia entre dos términos sucesivos sea menor que la tolerancia
    return t_act;
    }
