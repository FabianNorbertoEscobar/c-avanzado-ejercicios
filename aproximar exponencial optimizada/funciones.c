#include "encabezados.h"
float exponencial(int x,float tol)
    {
    int i;
    float f,ult;//ult=último término
    f=ult=1;
    i=1;
    while(ult>=tol)//deja de ciclar cuando un término sea menor que la tolerancia
        {
        ult=ult*x/i;//me ahorro calcular potencias y factoriales
        f+=ult;
        i++;
        }
    return f;
    }
