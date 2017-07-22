#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int hs,min,band;
    printf("\n ÁNGULO ENTRE MANECILLAS DEL RELOJ ANALÓGICO \n");
    printf("\n Ingrese un horario (hora y minutos) en formato de 12hs \n");
    band=0;
    do
        {
        if(band==1)
            printf("\n La hora ingresada no existe. Reingrésela: \n");
        printf("\n Hora (0 a 11): \n\n\t\t");
        scanf("%d",&hs);
        }
    while(!validadato(hs,0,11));
    band=0;
    do
        {
        if(band==1)
            printf("\n Los minutos ingresados no existen. Reingréselos: \n");
        printf("\n Minutos (0 a 59): \n\n\t\t");
        scanf("%d",&min);
        }
    while(!validadato(min,0,59));
    printf("\n Ángulo entre manecillas: \n");
    printf("\n\t en grados sexagesimales: %.2f \n",angulo_entre_manecillas(hs,min));
    printf("\n\t en radianes: %.2f \n\n\n",sexagesimales_a_radianes(angulo_entre_manecillas(hs,min)));
    getch();
    return 0;
    }
