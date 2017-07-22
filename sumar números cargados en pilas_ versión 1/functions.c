#include "header.h"

void sumar_pilas(t_pila *pila1,t_pila *pila2,t_pila *pila3)
    {
    t_dato digito1,digito2,suma,carry;
    carry.numero=0;

    while(!pila_vacia(pila1)&&!pila_vacia(pila2))
        {
        desapilar(pila1,&digito1);
        desapilar(pila2,&digito2);

        suma.numero=digito1.numero+digito2.numero+carry.numero;
        if(suma.numero>9)
            {
            suma.numero-=10;
            carry.numero=1;
            }
        else
            carry.numero=0;

        apilar(pila3,&suma);
        }

    while(!pila_vacia(pila1))
        {
        desapilar(pila1,&digito1);
        suma.numero=digito1.numero+carry.numero;

        if(suma.numero>9)
            {
            suma.numero-=10;
            carry.numero=1;
            }
        else
            carry.numero=0;

        apilar(pila3,&suma);
        }

    while(!pila_vacia(pila2))
        {
        desapilar(pila2,&digito2);
        suma.numero=digito2.numero+carry.numero;

        if(suma.numero>9)
            {
            suma.numero-=10;
            carry.numero=1;
            }
        else
            carry.numero=0;

        apilar(pila3,&suma);
        }

    if(carry.numero==1)
        apilar(pila3,&carry);
    }
