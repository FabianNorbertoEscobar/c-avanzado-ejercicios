#include "encabezados.h"
int producto(int n1,int n2)
    {
    int prod,i;
    prod=0;
    for(i=0;i<n2;i++)//acumulo el factor1 factor2 veces, o viceversa
        prod+=n1;
    return prod;
    }

