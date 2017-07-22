#include "header.h"
int abrir_archivo(FILE **pf,const char *ruta,const char *modo_tipo,int mensaje)
    {
    *pf=fopen(ruta,modo_tipo);
    if(!*pf)
        if(mensaje)
            {
            printf("\n\n No se pudo abrir el archivo %s con el modo_tipo %s \n\n\a\a",ruta,modo_tipo);
            return 0;
            }
    return 1;
    }
