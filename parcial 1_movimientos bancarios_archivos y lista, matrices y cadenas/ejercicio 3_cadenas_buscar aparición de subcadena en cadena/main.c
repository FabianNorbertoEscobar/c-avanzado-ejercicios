#include "header.h"

int main()
    {
        setlocale(LC_CTYPE,"Spanish");
        printf("\n\n \t\t *** OCURRENCIA DE UNA CADENA EN OTRA *** \n\a\a");

        printf("\n A partir de 2 cadenas, comprueba si la segunda es subcadena de la primera. \n");

        char cadena_1[20],cadena_2[20];

        printf("\n Ingrese una cadena: \n\n\t");
        fflush(stdin);
        gets(cadena_1);

        printf("\n Ingrese otra cadena: \n\n\t");
        fflush(stdin);
        gets(cadena_2);

        int retorno;

        //USANDO LA FUNCIÓN QUE LLAMA A STRLEN Y A STRNCMPI
        retorno=ocurrencia_de_subcadena_en_cadena(cadena_1,cadena_2);
        printf("\n\n Usando la primera función: \n");
        if(retorno==-1)
            printf("\n\n No hay ocurrencia de la subcadena en la cadena \n\n");
        else
            printf("\n\n La segunda cadena es subcadena del la primera cadena \n y su ocurrencia se da en la posición %d \n\n",retorno);

        //USANDO UNA ÚNICA FUNCIÓN--> VERSIÓN OPTIMIZADA OPTIMIZADA
        retorno=ocurrencia_de_subcadena_en_cadena_optimizada(cadena_1,cadena_2);
        printf("\n\n Usando la segunda función: \n");
        if(retorno==-1)
            printf("\n\n No hay ocurrencia de la subcadena en la cadena \n\n");
        else
            printf("\n\n La segunda cadena es subcadena del la primera cadena \n y su ocurrencia se da en la posición %d \n\n",retorno);

        printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
        getch();
        return 0;
    }
