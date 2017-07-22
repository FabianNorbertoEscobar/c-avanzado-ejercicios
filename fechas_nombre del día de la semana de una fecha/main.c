#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    tFecha f;
    int band;
    band=0;
    printf("\n ***** NOMBRE DEL DÍA DE LA SEMANA DE UNA FECHA ***** \n");
    printf("\n Ingrese una fecha en formato dd/mm/aaaa: \n\t");
    do
        {
        if(band==1)
            printf("\n La fecha ingresada no existe. Reingrésela: \n\t");
        scanf("%d/%d/%d",&f.dia,&f.mes,&f.anio);
        band=1;
        }
    while(!fecha_valida(f));
    printf("\n El día de la semana de esta fecha es: ");
    nombre_de_dia(dia_de_la_semana(f));
    printf("\n\n");
    return 0;
    }

