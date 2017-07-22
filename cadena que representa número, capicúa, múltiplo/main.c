#include "header.h"

int  main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n Cadena que representa un número entero \n");
    printf("\n Ingrese un cadena de caracteres cualquiera (menos de 50 caracteres): \n\n\t");

    char cadena[50];
    fflush(stdin);
    gets(cadena);
    printf("\n\n ¿La cadena \"%s\" representa un número entero? \t %s \n",cadena,es_numero(cadena)?"SI":"NO");

    if(es_numero(cadena))
        {
        printf("\n Es capicúa? \t %s \n",es_capicua(cadena)?"SI":"NO");
        printf("\n Es múltiplo de 5? \t %s \n",es_multiplo_de_5(cadena)?"SI":"NO");
        printf("\n Es múltiplo de 6? \t %s \n",es_multiplo_de_6(cadena)?"SI":"NO");
        printf("\n Es múltiplo de 11? \t %s \n",es_multiplo_de_11(cadena)?"SI":"NO");
        printf("\n Es mayor que %s? \t %s \n","100",es_mayor(cadena,"100")?"SI":"NO");
        printf("\n Es del intervalo de los short int? \t %s \n",es_del_intervalo_de_los_short_int(cadena)?"SI":"NO");
        }

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n");
    getch();
    return 0;
    }
