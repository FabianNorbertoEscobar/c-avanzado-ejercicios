/* Uso de los operadores de bits AND, OR incluyente, OR excluyente a nivel de bits y complemento */
#include <stdio.h>

void despliegaBits( unsigned valor ); /* prototipo */

int main()
{
    unsigned numero1; /* define numero1 */
    unsigned numero2; /* define numero2 */
    unsigned mascara; /* define mascara */
    unsigned estableceBits; /* define estableceBits */

    printf("\n\n USO DE OPERADORES BINARIOS \n\n");

    /* demuestra el operador de bits AND (&) */
    numero1 = 65535;
    mascara = 1;
    printf( "El resultado de combinar los siguientes valores\n" );
    despliegaBits( numero1 );
    despliegaBits( mascara );
    printf( "con el uso del operador de bits AND (&) es\n" );
    despliegaBits( numero1 & mascara );

    /* demuestra el operador de bits OR incluyente (|) */
    numero1 = 15;
    estableceBits = 241;
    printf( "\nEl resultado de combinar los siguientes valores\n" );
    despliegaBits( numero1 );
    despliegaBits( estableceBits );
    printf( "con el uso del operador de bits OR incluyente (|) es\n" );
    despliegaBits( numero1 | estableceBits );

    /* demuestra el operador de bits OR excluyente (^) */
    numero1 = 139;
    numero2 = 199;
    printf( "\nEl resultado de combinar los siguientes valores\n" );
    despliegaBits( numero1 );
    despliegaBits( numero2 );
    printf( "con el uso del operador de bits OR excluyente (^) es\n" );
    despliegaBits( numero1 ^ numero2 );

    /* demuestra el operador de bits complemento (~) */
    numero1 = 21845;
    printf( "\nEl complemento a uno de\n" );
    despliegaBits( numero1 );
    printf( "es\n" );
    despliegaBits( ~numero1 );

    return 0; /* indica terminación exitosa */
} /* fin de main */

/* despliega los bits de un valor entero sin signo */
void despliegaBits( unsigned valor )
{
    unsigned c; /* contador */
    /* declara despliegaMarcara y desplaza 31 bits a la izquierda */
    unsigned despliegaMascara = 1 << 31;

    printf( "%10u = ", valor );

    /* ciclo a través de los bits */
    for ( c = 1; c <= 32; c++ )
    {
        putchar( valor & despliegaMascara ? '1' : '0' );
        valor <<= 1; /* desplaza el valor 1 bit a la izquierda */

        if ( c % 8 == 0 )   /* muestra un espacio después de 8 bits */
        {
            putchar( ' ');
        } /* fin de if */

    } /* fin de for */

    putchar( '\n' );
} /* fin de la función despliegaBits */
