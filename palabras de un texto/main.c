#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 0B");

    char texto[TAM]="",primera_palabra[TAM]="",palabra[TAM]="",*lector=texto;
    int cuenta_palabras=0,cuenta_primera_palabra=0,mayor_long_palabra=0,long_palabra;

    printf("\n\n PALABRAS DE UN TEXTO \n\n\a\a");
    printf("\n\n Ingrese un texto u oración (si se encuentra un punto o se agotan %d caracteres \n se considera terminada la cadena de caracteres): \n\n\t ",TAM);

    fflush(stdin);
    gets(texto);

    while(*lector&&*lector!='.')
        {
        while(*lector==' ')
            lector++;
        if(*lector=='.'||!lector)
            break;

        sscanf(lector,"%[^. ]",palabra);
        long_palabra=str_len(palabra);

        cuenta_palabras++;
        if(cuenta_palabras==1)
            {
            str_cpy(primera_palabra,palabra);
            mayor_long_palabra=long_palabra;
            lector+=long_palabra;
            continue;
            }

        if(str_icmp(palabra,primera_palabra)==0)
            cuenta_primera_palabra++;
        else
            {
            if(long_palabra>mayor_long_palabra)
                mayor_long_palabra=long_palabra;
            }

        lector+=long_palabra;
        }

    printf("\n\n RESULTADO");
    printf("\n\n Primera palabra: \t %s",primera_palabra);
    printf("\n\n Repeticiones de la primera palabra en el texto: \t %d",cuenta_primera_palabra);
    printf("\n\n Cantidad de palabras del texto: \t %d",cuenta_palabras);
    printf("\n\n Longitud de la palabra más larga: \t %d",mayor_long_palabra);

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
    }
