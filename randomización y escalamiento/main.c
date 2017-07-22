#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
    int i;
    setlocale(LC_CTYPE,"Spanish");

    printf("\n\n RANDOMIZACIÓN Y ESCALAMIENTO \n\n");

    srand(time(NULL));
    //la función srand randomiza la función rand usando como semilla los segundos relativos indicados por el reloj del sistema

    //la función rand genera números pseudoaleatorios de acuerdo a una semilla

    for(i=0;i<50;i++)
        printf("%d \t",2+rand()%6);
    //el escalamiento es la modificación de la generación de los números pseudoaleatorios
    //su ecuación es a+rand()%b siendo a el valor de cambio que indica el primer valor del rango de números pseudoaleatorios
    //y siendo b el factor de escalamiento que indica la longitud del rango de números generados

    return 0;
}
