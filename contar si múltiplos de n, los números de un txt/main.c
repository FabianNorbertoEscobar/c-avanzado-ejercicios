#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");

    printf("\n\n CONTAR SI MÚLTIPLOS DE N, LOS NÚMEROS DE UN TXT \n");

    FILE *pf_lectura;
    pf_lectura=fopen("datos.txt","rt");
    if(!pf_lectura)
        {
        printf("\n\n No se ha podido leer el archivo \"datos.txt\" \n\n Programa abortado.. \n\n");
        exit(EXIT_FAILURE);
        }

    FILE *pf_escritura;
    pf_escritura=fopen("mayores que 100.txt","wt");
    if(!pf_escritura)
        {
        printf("\n\n No se ha podido crear el archivo \"mayores que 100.txt\" \n\n Programa abortado.. \n\n");
        fclose(pf_lectura);
        exit(EXIT_FAILURE);
        }

    int cuenta_multiplos_de_5=0,cuenta_multiplos_de_6=0,cuenta_multiplos_de_11=0;
    char cadena[6];

    while(!feof(pf_lectura))
        {
        str_cpy(cadena,leer_cadena_numerica(pf_lectura));
        if(!es_numero(cadena))
            break;
        if(es_multiplo_de_5(cadena))
            cuenta_multiplos_de_5++;
        if(es_multiplo_de_6(cadena))
            cuenta_multiplos_de_6++;
        if(es_multiplo_de_11(cadena))
            cuenta_multiplos_de_11++;
        if(es_mayor(cadena,"100"))
            nueva_cadena_numerica(pf_escritura,cadena);
        }

    fclose(pf_lectura);
    fclose(pf_escritura);

    printf("\n RESULTADO de los números leídos del archivo \"datos.txt\" \n");
    printf("\n Cantidad de múltiplos de 5: \t %d",cuenta_multiplos_de_5);
    printf("\n Cantidad de múltiplos de 6: \t %d",cuenta_multiplos_de_6);
    printf("\n Cantidad de múltiplos de 11: \t %d",cuenta_multiplos_de_11);

    printf("\n\n Se ha generado un fichero de texto \"mayores que 100.txt\" \n donde se encuenran los números leídos del archivo \"datos.txt\" \n que cumplen con dicha condición \n\n");

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
    }
