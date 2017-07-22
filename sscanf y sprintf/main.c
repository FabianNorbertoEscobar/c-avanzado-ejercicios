#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char nombre[20]="",entrada[81]="",salida[81]="";
    unsigned int edad=0;

    printf("\n\n SSCANF \n");
    printf("\n Esta función toma valores desde un string, que están separados por \n una variable reservada para funcionar como separador, como un espacio \n y los graba en diferentes variables y cadenas \n");
    printf("\n Veamos un ejemplo: \n\n");
    printf("\n Escriba su nombre y edad, en una misma línea, separados por un espacio: \n\n\t");
    fflush(stdin);
    gets(entrada);
    sscanf(entrada,"%s %u",nombre,&edad);
    printf("\n\n Has escrito: \t %s",entrada);
    printf("\n\n Nombre: \t %s \t Edad: \t %d \n",nombre,edad);

    printf("\n\n SPRINTF \n");
    printf("\n Esta función toma valores desde diferentes variables y cadenas, \n y los graba en otra cadena con un formato especificado \n");
    printf("\n Veamos un ejemplo: \n\n");
    printf("\n Escriba su nombre: \t");
    scanf("%s",nombre);
    printf("\n Escribe su edad: \t");
    scanf("%u",&edad);
    sprintf(salida,"\n Hola %s. Tienes %d años. \n",nombre,edad);
    puts(salida);

    printf("\n\n \t\t\t Fin del programa.. \n\n");
    getch();
    return 0;
    }

