#include "header.h"

void mostrar_nodo(const void *v)
{
    t_dato *dato=(t_dato*)v;
    printf("%d",dato->numero);
}

int comparar_enteros(const void *void1,const void *void2)
{
    t_dato *dato1=(t_dato*)void1;
    t_dato *dato2=(t_dato*)void2;
    return dato1->numero-dato2->numero;
}
