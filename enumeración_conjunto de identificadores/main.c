#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    enum estados{NADA,PUNTO,LINEA,TRIANGULO,CUADRADO,PENTAGONO};
    // la enumeración asigna a un conjunto de identificadores constantes, valores comenzando por el 0 e incrementándose en 1

    srand(time(NULL));

    switch(rand()%6)
    {
    case NADA:
        puts("NADA");
        break;

    case PUNTO:
        puts("PUNTO");
        break;

    case LINEA:
        puts("LINEA");
        break;

    case TRIANGULO:
        puts("TRIANGULO");
        break;

    case CUADRADO:
        puts("CUADRADO");
        break;

    case PENTAGONO:
        puts("PENTAGONO");
        break;
    }
    return 0;
}
