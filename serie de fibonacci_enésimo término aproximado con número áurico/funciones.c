#include "encabezados.h"
float enesimo_termino_aprox_serie_fibonacci(int x)
    {
    return (float)(pow(ORO,x)-pow(1-ORO,x))/sqrt(5);//por propiedad del enésimo término de la serie de fibonacci
    }
