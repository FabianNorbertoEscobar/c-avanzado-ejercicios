#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int band,op,cant,ocupados;
    printf("\n\n ARRAY DE FLOAT \n");
    printf("\n\n Usted debe cargar un array de números flotantes \n");
    printf("\n Para ello, se le solicita que ingrese la cantidad máxima \n de elementos a ingresar en el array: \t");
    band=0;
    do
        {
        if(band==1)
            printf("\n\n El número ingresado no es lógico. Ingrese un nuevo número: \t\a\a");
        scanf("%d",&cant);
        band=1;
        }
    while(cant<=0);
    float v[cant];
    ocupados=cargar_array_float(v,cant);
    if(ocupados==0)
        {
        printf("\n\n El array está vacío \n No tiene sentido continuar con la ejecución del programa \n\n\a\a");
        printf("\n\n Programa evacuado \n\n");
        exit(1);
        }
    printf("\n El vector ingresado tiene %d posiciones ocupadas \n",ocupados);
    printf("\n Sus elementos son: \n\n");
    mostrar_array_float(v,ocupados);
    op=menu();
    while(op!=4)
        {
        switch(op)
            {
            case 1: minimo(v,ocupados);
                    break;
            case 2: promedio_valores_posiciones_pares(v,ocupados);
                    break;
            case 3: mostrar_orden_inverso(v,ocupados);
                    break;
            }
        op=menu();
        }
    printf("\n\n Menú abortado \n\n");
    FILE *pf;
    pf=fopen("array_de_flotantes.dat","wb");
    if(!pf)
        {
        printf("\n\n No se pudo grabar el array en un archivo binario \n\n\a\a");
        printf("\n\n Programa evacuado \n\n");
        exit(EXIT_FAILURE);
        }
    grabar_en_archivo_binario(v,ocupados,pf);
    fclose(pf);
    printf("\n Se ha grabado el array en el archivo binario \"array_de_flotantes.dat\"");
    pf=fopen("array de flotantes.txt","wt");
    if(!pf)
        {
        printf("\n\n No se pudo grabar el array en un archivo de texto \n\n\a\a");
        printf("\n\n Programa evacuado \n\n");
        exit(EXIT_FAILURE);
        }
    grabar_en_archivo_de_texto(v,ocupados,pf);
    fclose(pf);
    printf("\n Se ha grabado el array en el archivo de texto \"array_de_flotantes.txt\"");
    printf("\n\n \t\t\t\t\t Fin del programa.. \n\n");
    getch();
    return 0;
    }
