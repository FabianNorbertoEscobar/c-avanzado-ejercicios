#include "encabezados.h"
int suma_de_divisores(int n)
    {
    int i,sumdiv;
    sumdiv=0;
    for(i=1;i<n;i++)
        if(n%i==0)//si son divisores, los acumulo
            sumdiv+=i;
    return sumdiv;
    }
void perfecto_deficiente_abundante(int n)
    {
    int sumdiv;
    sumdiv=suma_de_divisores(n);
    if(n==sumdiv)
        printf("\n\n El número %d es perfecto \n\n",n);
    else
        if(n>sumdiv)
            printf("\n El número %d es deficiente \n\n",n);
        else
            printf("\n El número %d es abundante \n\n",n);
    }

