#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <assert.h>

#define DEPURAR 1
#define HOLA(x) printf("\n Hola " #x "\n")

int main()
{
    setlocale(LC_CTYPE,"Spanish");

    #if DEPURAR
        HOLA(mundo);
    #endif // DEPURAR

    #undef NULL

    #ifndef NULL
        #define NULL 1
    #endif // NULL

    #ifdef NULL
        printf("\n NULL: %i \n",NULL);
    #endif // NULL

    printf("\n Línea del código fuente actual: %d \n",__LINE__);
    printf("\n Nombre del archivo fuente: \n %s \n",__FILE__);
    printf("\n Fecha de compilación del fuente: %s \n",__DATE__);
    printf("\n Hora de compilación del fuente: %s \n\n",__TIME__);

    assert(NULL == 0); // si el argumento de assert es falso, assert imoprime un mensaje de error en la consola,
                        // y luego invoca a la función abort para que detenga la ejecución del programa

    return 0;
}
