#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    tFecha f_inf,f_sup;
    int band,band2;
    band=band2=0;
    do
        {
        if(band2==1)
            {
            printf("\n Las fechas no fueron ingresadas en el orden correcto. Reingréselas. \n\a\a");
            printf("\n Presione una tecla cualquiera para continuar \n\n");
            getch();
            system("cls");
            band=band2=0;
            }
        printf("\n ***** DIFERENCIA DE DÍAS ENTRE DOS FECHAS ***** \n");
        printf("\n Ingrese la fecha inferior en formato dd/mm/aaaa: \n\t");
        do
            {
            if(band==1)
                printf("\n La fecha ingresada no existe. Reingrésela: \n\t");
            scanf("%d/%d/%d",&f_inf.dia,&f_inf.mes,&f_inf.anio);
            band=1;
            }
        while(!fecha_valida(f_inf));
        band=0;
        printf("\n Ingrese la fecha superior en formato dd/mm/aaaa: \n\t");
        do
            {
            if(band==1)
                printf("\n La fecha ingresada no existe. Reingrésela: \n\t");
            scanf("%d/%d/%d",&f_sup.dia,&f_sup.mes,&f_sup.anio);
            band=1;
            }
        while(!fecha_valida(f_sup));
            band2=1;
            }
    while(!(f_sup.anio>f_inf.anio||(f_sup.anio==f_inf.anio&&(f_sup.mes>f_inf.mes||(f_sup.mes==f_inf.mes&&f_sup.dia>=f_inf.dia)))));
    printf("\n\n La diferencia de días entre éstas fechas es: \t %d \n\n\a\a",diferencia_de_dias(f_inf,f_sup));
    getch();
    return 0;
    }


