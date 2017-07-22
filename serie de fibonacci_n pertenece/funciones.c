#include "encabezados.h"
int es_de_fibonacci(int n)
    {
    if(n==1)
        return 1;
    int x,y,z;
    x=y=1;//primeros dos términos
    do
        {
        z=x+y;//genero un nuevo término y luego actualizo los últimos dos términos
        x=y;
        y=z;
        }
    while(z<n);
    return (n==z)?1:0;
    }
