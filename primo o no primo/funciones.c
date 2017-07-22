#include "encabezados.h"
int primo_o_no_primo(int n)
    {
    int i,j;
    i=2;
    do
        {
        j=n%i;
        i++;
        }
    while(j!=0&&i<n);//termino si encuentro un divisor o si no encuentro ninguno
    return (j==0)?0:1;
    }

