/* Craps */

/*
Uno de los juegos de azar más populares es el juego de dados conocido como “craps”, el cual se juega en casinos
y patios traseros alrededor del mundo. Las reglas del juego son simples.

El jugador tira dos dados. Cada dado tiene seis caras. Estas caras contienen 1, 2, 3, 4, 5 y 6 puntos. Una vez que
los dados caen, se calcula la suma de los puntos que se encuentran en las caras que ven hacia arriba.

Si la suma es igual a 7 u 11 en el primer tiro, el jugador gana.

Si la suma es 2, 3 o 12 en el primer tiro (llamado “craps”),el jugador pierde (es decir, la “casa” gana).

Si la suma es 4, 5, 6, 8, 9, o 10 en el primer tiro, entonces la suma se convierte en el “punto” del jugador.

Para ganar, usted debe continuar tirando los dados hasta que “haga su
punto”. El jugador pierde si tira un 7 antes de hacer su punto.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* contiene el prototipo de la función time, quien retorna la hora indicada por el reloj del sistema, en segundos*/

/* constantes de enumeración que representan el estado del juego */
enum Estatus { CONTINUA, GANA, PIERDE };

int tiraDados( void ); /* prototipo de la función para tirar los dados */

/* la función main comienza la ejecución del programa */
int main()
{
    int suma; /* suma del tiro de dados */
    int miPunto; /* punto ganado */

    enum Estatus estatusJuego; /* puede contener CONTINUA, GANA o PIERDE */

    printf("\n\n CRAPS \n\n");

    /* randomiza el generador de números aleatorios mediante la función time, asignando como semilla a la hora del sistema, en segundos*/
    srand( time( NULL ) );

    suma = tiraDados(); /* primer tiro de los dados */

    /* determina el estado del juego basado en la suma de los dados */
    switch( suma )
    {

    /* gana en el primer tiro */
    case 7:
    case 11:
        estatusJuego = GANA;
        break;

    /* pierde en el primer tiro */
    case 2:
    case 3:
    case 12:
        estatusJuego = PIERDE;
        break;

    /* recuerda el punto */
    default:
        estatusJuego = CONTINUA;
        miPunto = suma;
        printf( "Su punto es %d\n", miPunto );
        break; /* opcional */

    } /* fin de switch */

    /* mientras el juego no se complete */
    while ( estatusJuego == CONTINUA )
    {
        suma = tiraDados(); /* tira de nuevo los dados */

        /* determina el estatus del juego */
        if ( suma == miPunto )   /* gana por punto */
        {
            estatusJuego = GANA; /* fin del juego, el jugador gana */
        } /* fin de if */
        else
        {
            if ( suma == 7 )   /* pierde al tirar 7 */
            {
                estatusJuego = PIERDE; /* termina el juego, el jugador pierde */
            } /* fin de if */

        } /* fin de else */

    } /* fin de while */

    /* despliega mensaje de triunfo o derrota */
    if ( estatusJuego == GANA )   /* ¿Ganó el jugador? */
    {
        printf( "El jugador gana \n" );
    } /* fin de if */
    else   /* el jugador pierde */
    {
        printf( "El jugador pierde\n" );
    } /* fin de else */

    return 0; /* indica terminación exitosa */

} /* fin de main */

/* tiro de dados, calcula la suma y despliega los resultados */
int tiraDados( void )
{
    int dado1; /* primer dado */
    int dado2; /* segundo dado */
    int sumaTemp; /* suma de los dados */

    dado1 = 1 + ( rand() % 6 ); /* toma el aleatorio para el dado1 */
    dado2 = 1 + ( rand() % 6 ); /* toma el aleatorio para el dado2 */

    sumaTemp = dado1 + dado2; /* suma el dado1 y el dado2 */

    /* despliega los resultados de este tiro */
    printf( "El jugador tiro %d + %d = %d\n", dado1, dado2, sumaTemp );

    return sumaTemp; /* devuelve la suma de los dados */

} /* fin de la función tiraDados */
