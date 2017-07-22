#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    tFecha f;
    int band;
    band=0;
    printf("\n ***** FECHA SIGUIENTE ***** \n");
    printf("\n Ingrese una fecha en formato dd/mm/aaaa: \n\t");
    do
        {
        if(band==1)
            printf("\n La fecha ingresada no existe. Reingrésela: \n\t");
        scanf("%d/%d/%d",&f.dia,&f.mes,&f.anio);
        band=1;
        }
    while(!fecha_valida(f));
    f=fecha_siguiente(f);
    printf("\n La fecha siguiente a la ingresada es %d/%d/%d \n\n",f.dia,f.mes,f.anio);
    getch();
    return 0;
    }

