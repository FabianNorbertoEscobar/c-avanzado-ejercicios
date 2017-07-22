// Lanza un dado de seis lados 6000 veces */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANIO 7

/* la función main comienza la ejecución del programa */
int main()
{
    int cara; /* valor aleatorio del dado entre 1 a 6 */
    int tiro; /* contador de tiros 1 a 6000 */
    int frecuencia[ TAMANIO ] = { 0 }; /* inicializa a cero la cuenta */

    srand( time( NULL ) ); /* generador de la semilla de números aleatorios */

    printf("\n\n LANZAMIENTO DE DADO \n\n");

    /* tira el dado 6000 veces */
    for ( tiro = 1; tiro <= 6000; tiro++ )
    {
        cara = 1 + rand() % 6;
        ++frecuencia[ cara ];
    } /* fin de for */

    printf( "%s%17s\n", "Cara", "Frecuencia" );

    /* muestra los elementos 1-6 de frecuencia en forma tabular */
    for ( cara = 1; cara < TAMANIO; cara++ )
    {
        printf( "%4d%17d\n", cara, frecuencia[ cara ] );
    } /* fin de for */

    return 0; /* indica terminación exitosa */
} /* fin de main */
