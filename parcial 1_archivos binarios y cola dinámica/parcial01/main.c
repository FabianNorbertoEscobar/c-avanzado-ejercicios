///ESCOBAR, FABIÁN NORBERTO         DNI:    39210915

#include <stdio.h>
#include <stdlib.h>
#include <funciones.h>
#include <conio.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE,"Spanish");

    FILE *entrada;
    FILE *salida;

    t_historial his;
    t_cola cola;

    int fila = 0;
    char descripcion[TAM][46];
    long valores[TAM][4];

    printf("\n\n\t PARCIAL 1 \n");

    crearCola(&cola);
    printf("\n Se ha creado una cola \n\a\a");

    crearArchivo();
    printf("\n Se ha generado el archivo \"histor.dat\" \n");

    if(!aperturaDeArchivos(&entrada, "archivos/histor.dat", "rb"))
        return 5;
    if(!aperturaDeArchivos(&salida, "archivos/actual.dat", "wb"))
        return 5;

    printf("\n Se ha leído el archivo \"histor.dat\" correctamente \n");

    cargaInfoDeArchivo(entrada, &his, &cola, descripcion, valores, &fila);
    printf("\n Se han cargado los arrays bidimensionales y la cola \n");
    printf("\n En los arrays, están los registros que tienen alguna palabra \n que empieza con vocal en su descripción \n");
    printf("\n En la cola, están las claves de los registros restantes \n");

    crearArchivoActual(entrada, salida, &his, &cola);
    printf("\n Los registros del archivo de entrada que figuraban en la cola \n fueron grabados en el archivo de salida \n");

    printf("\n Los registros de los arrays son los siguientes \n");
    puts("\n\n *** ARRAYS *** \n");
    mostrarInfo(descripcion, valores, &fila);

    fclose(entrada);
    fclose(salida);
    printf("\n\n\n Los archivos fueron cerrados exitosamente \n");

    vaciarCola(&cola);
    printf("\n La cola fue vaciada \n");

    printf("\n\n \t\t\t\t\t Fin del programa.. \n\n\a\a");
    return 0;
    getch();
}
