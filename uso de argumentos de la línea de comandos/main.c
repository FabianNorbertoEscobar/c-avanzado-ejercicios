/* Uso de argumentos en la línea de comandos */
#include <stdio.h>

int main( int argc, char *argv[] )
{
    FILE *ptrEntArchivo; /* apuntador de archivo de entrada */
    FILE *ptrSalArchivo; /* apuntador de archivo de salida */

    int c; /* define c para almacenar los caracteres introducidos por el usuario */
    /* verifica el número de argumentos de la línea de comandos */

    if ( argc != 3 )
    {
        printf( "Uso: copia archivoEnt archivoSal\n" );
    } /* fin de if */
    else
    {
        /* si el archivo de entrada se puede abrir */
        if ( ( ptrEntArchivo = fopen( argv[ 1 ], "r" ) ) != NULL )
        {
            /* si el archivo de salida se puede abrir */
            if ( ( ptrSalArchivo = fopen( argv[ 2 ], "w" ) ) != NULL )
            {
                /* lee los caracteres y los arroja */
                while ( ( c = fgetc( ptrEntArchivo ) ) != EOF )
                {
                    fputc( c, ptrSalArchivo );
                } /* fin de while */
            } /* fin de if */
            else   /* no se puede abrir el archivo de salida */
            {
                printf( "El archivo \"%s\" no se pudo abrir\n", argv[ 2 ] );
            } /* fin de else */
        } /* fin de if */
        else   /* no se puede abrir el archivo de entrada */
        {
            printf( "El archivo \"%s\" no se pudo abrir\n", argv[ 1 ] );
        } /* fin de else */
    } /* fin de else */

    return 0; /* indica terminación exitosa */
} /* fin de main */
