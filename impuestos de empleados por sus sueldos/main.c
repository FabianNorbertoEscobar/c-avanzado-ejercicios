#include "header.h"

int main()
{
    t_lista lista;
    t_arbol arbol;

    FILE *pf;

    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 9F");

    printf("\n\n IMPUESTOS DE EMPLEADOS POR SU SUELDO \n");

    crear_lista(&lista);
    printf("\n\n Se ha creado una lista \n");

    crear_arbol(&arbol);
    printf("\n\n Se ha creado un árbol \n");

    generar_lista_de_conceptos_por_empleado(&lista);
    printf("\n\n La lista de conceptos por empleado ha sido generada exitosamente \n");

    generar_arbol_de_importes_de_conceptos(&arbol);
    printf("\n\n El árbol de importes de conceptos ha sido generado exitosamente \n");

    pf=fopen("IMPUESTOS.bin","wb");
    if(!pf)
    {
        printf("\n\n No se ha podido crear el archivo de impuestos \n\n\a\a");
        exit(EXIT_FAILURE);
    }

    generar_archivo_de_impuestos(&lista,&arbol,pf);
    printf("\n\n El archivo de impuestos ha sido generado exitosamente");

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
}
