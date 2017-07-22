#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    tFecha f;
    printf("\n ***** VALIDACIÓN DE FECHAS ***** \n");
    printf("\n Ingrese una fecha en formato dd/mm/aaaa: \n\t");
    scanf("%d/%d/%d",&f.dia,&f.mes,&f.anio);
    printf("\n La fecha %s válida \n",fecha_valida(f)?"es":"no es");
    getch();
    return 0;
    }
