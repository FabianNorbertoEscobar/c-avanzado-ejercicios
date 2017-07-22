#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    tFecha f_nac,f_act;
    int band;
    band=0;
    printf("\n ***** CALCULAR EDAD ***** \n");
    printf("\n Ingrese la fecha de nacimiento en formato dd/mm/aaaa: \n\t");
    do
        {
        if(band==1)
            printf("\n La fecha ingresada no existe. Reingrésela: \n\t");
        scanf("%d/%d/%d",&f_nac.dia,&f_nac.mes,&f_nac.anio);
        band=1;
        }
    while(!fecha_valida(f_nac));
    band=0;
    printf("\n Ingrese la fecha actual en formato dd/mm/aaaa: \n\t");
    do
        {
        if(band==1)
            printf("\n La fecha ingresada no existe. Reingrésela: \n\t");
        scanf("%d/%d/%d",&f_act.dia,&f_act.mes,&f_act.anio);
        band=1;
        }
    while(!fecha_valida(f_act));
    if(f_act.anio>f_nac.anio||(f_act.anio==f_nac.anio&&(f_act.mes>f_nac.mes||(f_act.mes==f_nac.mes&&f_act.dia>=f_nac.dia))))
        printf("\n\t %c Edad: %d \n\n",16,calcula_edad(f_nac,f_act));
    else
        printf("\n La fecha actual es inferior a la fecha de nacimiento \n\n");
    getch();
    return 0;
    }

