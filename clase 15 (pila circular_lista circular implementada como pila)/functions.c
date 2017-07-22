#include "header.h"

void cargar_dato(t_dato *d)
    {
    printf("\n\n Ingrese dato (número): \t");
    scanf("%d",&d->numero);
    }

void mostrar_dato(const t_dato *d)
    {
    printf("\n DATO: \t %d \n",d->numero);
    }
