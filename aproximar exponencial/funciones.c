#include "encabezados.h"
int factorial(int n)
    {
    if(n<=1)
        return 1;
    else
        return n*factorial(n-1);
    }
int potencia(int b,int e)
    {
    int p,i;
    p=1;
    for(i=1;i<=e;i++)
        p*=b;
    return p;
    }
float exponencial(int x,float tol)
    {
    int i;
    float f,ult;//ult=último término
    i=0;
    f=0;
    while(i==0||ult>=tol)//deja de ciclar cuando un término sea menor que la tolerancia
        {
        ult=(float)potencia(x,i)/factorial(i);
        f+=ult;
        i++;
        }
    return f;
    }
