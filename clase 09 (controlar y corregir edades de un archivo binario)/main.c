#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n CONTROLAR Y CORREGIR EDADES \n");
    printf("\n\n Con este programa controlamos que las edades \n de los registros del archivo \"personas.dat\" tengan las edades que corresponden, \n y de no ser así, las corregimos \n");

    FILE *pf;
    pf=fopen("personas.dat","r+b");
    if(!pf)
        {
        printf("\n\n No se pudo abrir el archivo. \n No tiene sentido continuar con la ejecución del progra \n");
        printf("\n Programa abortado \n\n\a\a");
        exit(EXIT_FAILURE);
        }

    printf("\n ARCHIVO ANTES DEL CONTROL \n");
    mostrar_archivo(pf);

    printf("\n ARCHIVO DESPUÉS DEL CONTROL \n");
    controlar_y_corregir_edad(pf);
    mostrar_archivo(pf);

    fclose(pf);
    printf("\n\n \t\t\t\t\t Fin del programa.. \n\n");
    getch();
    return 0;
    }
