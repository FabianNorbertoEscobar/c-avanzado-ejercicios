#include "header.h"

void sumar_pilas(t_pila *pila1,t_pila *pila2,t_pila *pila3)
    {
    t_dato digito1,digito2,suma,carry;
    carry.numero=0;

    while(!pila_vacia(pila1)||!pila_vacia(pila2))
        {
        if(!desapilar(pila1,&digito1))
            digito1.numero=0;
        if(!desapilar(pila2,&digito2))
            digito2.numero=0;

        suma.numero=(digito1.numero+digito2.numero+carry.numero)%10;
        carry.numero=(digito1.numero+digito2.numero+carry.numero)/10;
        apilar(pila3,&suma);
        }
    if(carry.numero==1)
        apilar(pila3,&carry);
    }

