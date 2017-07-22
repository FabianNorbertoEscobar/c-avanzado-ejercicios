#include <stdio.h>

void despliegaBits( unsigned valor ); /* prototipo */

int main()
{
    unsigned x; /* variable para almacenar la entrada del usuario */

    printf( "Introduzca un entero sin signo: " );
    scanf( "%u", &x );

    despliegaBits( x );

    return 0; /* indica terminación exitosa */
} /* fin de main */

/* despliega los bits de un valor entero sin signo */
void despliegaBits( unsigned valor )
{
    unsigned c; /* contador */

    /* define despliegaMascara y desplaza 31 bits hacia la izquierda */
    unsigned despliegaMascara = 1 << 31;

    printf( "%10u = ", valor );

    /* ciclo a través de los bits */
    for ( c = 1; c <= 32; c++ )
    {
        putchar( valor & despliegaMascara ? '1' : '0' );
        valor <<= 1; /* desplaza valor 1 hacia la izquierda */

        if ( c % 8 == 0 )   /* despliega espacio después de 8 bits */
        {
            putchar( ' ' );
        } /* fin de if */
    } /* fin de for */

    putchar( '\n' );
} /* fin de la función despliegaBits */
