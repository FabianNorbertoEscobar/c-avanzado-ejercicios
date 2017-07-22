#include "encabezados.h"
int multiplicacion_rusa(int n1,int n2)
    {
    int y=0;
    while(n1>=1)//hasta cociente 1
        {
        if(n1%2!=0)//si el primero es impar, acumulo el segundo
            y+=n2;
        n1/=2;//divido al primero y multiplico al segundo
        n2*=2;
        }
    return y;
    }
