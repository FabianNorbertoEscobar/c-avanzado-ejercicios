#include "encabezados.h"
int factorial(int n)
    {
    if(n<=1)
        return 1;
    else
        return n*factorial(n-1);
    }
/*
ésta función funciona, pero es más eficiente la suguiente porque no guarda los cálculos en variables, ya que no es necesario

int combinatorio(int m,int n)
    {
    int fm,fn,fmn,comb;
    fm=factorial(m);
    fn=factorial(n);
    fmn=factorial(m-n);
    comb=fm/(fn*fmn);
    return comb;
    }
*/
int combinatorio(int m,int n)
    {
    return factorial(m)/(factorial(n)*factorial(m-n));
    }
