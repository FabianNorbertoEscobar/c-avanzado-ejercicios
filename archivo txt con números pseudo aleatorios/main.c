#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");

    printf("\n\n \t GENERACIÓN DE ARCHIVO CON NÚMEROS PSEUDO ALEATORIOS \a\a");
    printf("\n\n Se generará un archivo de texto con líneas de entre 1 y 7 números \n enteros cortos pseudo aleatorios, cantidad que irá indicando usted mismo.");
    printf("\n Se le exigirá que al menos ingrese una vez 1 y una vez 7.");
    printf("\n Los demás números variarán a su gusto... \n\n");

    FILE *pf;
    pf=fopen("datos.txt","wt");
    if(!pf)
        {
        printf("\n\n Error al crear el fichero de texto \n\n Programa evacuado \n\n\a\a");
        exit(EXIT_FAILURE);
        }

    printf("\n\n Comience con el ingreso de números enteros del rango [1;7] ó 0 para finalizar");
    printf("\n\n No se le permitirá finalizar el proceso mientras no ingrese \n al menos una vez el número 1 y una vez el número 7. \n");

    int n=1,bandera,bandera1=0,bandera7=0;
    do
        {
        if(n==0)
            printf("\n\t No tiene permitido terminar el proceso... \n \a\a");
        bandera=0;
        do
            {
            if(bandera==1)
                printf("\n\t El número ingresado no es válido... \n \a\a");
            printf("\n Ingrese un número entero: \t");
            scanf("%d",&n);
            bandera=1;
            }
        while(!DATO_VALIDO(n,0,7));

        if(n!=0)
            {
            nueva_linea(pf,n);
            if(n==1)
                bandera1=1;
            if(n==7)
                bandera7=1;
            }
        }
    while(!(n==0&&bandera1==1&&bandera7==1));

    printf("\n\n Se ha generado exitosamente el archivo \"datos.txt\"");

    fclose(pf);

    printf("\n\n \t\t\t\t\t  Fin del programa.. \n\n");
    getch();
    return 0;
    }
