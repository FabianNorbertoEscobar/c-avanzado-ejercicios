#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    system("COLOR A0");

    printf("\n\n MEMORIA DINÁMICA \n\n");

    int *numPtr, i;
    size_t tamanyo=0;

    printf( "\n Introduzca el tamaño de la lista: \n\t" );
    scanf( "%d", &tamanyo );

    puts( "\n Adjudicamos espacio a la lista. \n\t" );
    numPtr = (int *)malloc( tamanyo*sizeof(int) );

    for( i=0; i<tamanyo-1; i++ )
        printf( "%d, ", numPtr[i] = rand() % 100 + 1 );
    printf( "%d\n", numPtr[i] = rand() % 100 + 1 );

    numPtr = (int *)realloc( numPtr, tamanyo/=2 );
    printf( "\n Recortamos la lista a la mitad: %d \n\t", tamanyo );

    for( i=0; i<tamanyo-1; i++ )
        printf( "%d, ", numPtr[i] );
    printf( "%d\n", numPtr[i] );

    puts( "\n Liberamos el espacio." );
    free( numPtr );

    puts("\n\n \t\t\t\t\t Fin del programa... \n\n");
    getch();
    return 0;
}
