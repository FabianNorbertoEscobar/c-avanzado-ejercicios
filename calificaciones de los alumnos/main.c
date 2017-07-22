#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 17");

    char mat_apyn[REG][TOPE];
    float mat_notas[FIL][COL];
    int cant_reg;

    printf("\n\t\t *********************************");
    printf("\n\t\t * CALIFICACIONES DE LOS ALUMNOS *");
    printf("\n\t\t *********************************");

    printf("\n\n\a\a En este programa, usted podrá ingresar los datos de sus alumnos,");
    printf("\n apellido/s, nombre/s y calificaciones obtenidas en cada una de las");
    printf("\n 6 evaluaciones que se han tomado, pudiendo finalmente calcular:");
    printf("\n los promedios por alumno, por evaluación y general del curso.");
    printf("\n\n Al finalizar se exportarán los datos a un archivo de texto \n");
    getch();

    printf("\n\n CARGA DE LOS REGISTROS \n\n");
    cant_reg=cargar_matrices_de_datos(mat_apyn,REG,TOPE,mat_notas,FIL,COL);
    getch();

    printf("\n\n\n MATRICES DE DATOS \n\n");
    mostrar_matrices_de_datos(mat_apyn,REG,TOPE,mat_notas,FIL,COL,cant_reg);
    getch();

    promedios_de_alumnos(mat_notas,FIL,COL,cant_reg);
    promedios_por_evaluacion_y_general(mat_notas,FIL,COL,cant_reg);
    printf("\n\n Se han calculado exitosamente los promedios por alumno, \n por evaluación y general del alumno \n");
    getch();

    if(exportar_a_archivo_de_texto(mat_apyn,REG,TOPE,mat_notas,FIL,COL,cant_reg))
        printf("\n\n Se han exportado los registros exitosamente \n al archivo de texto \"calificaciones de los alumnos.txt\" \n\n");
    else
        printf("\n\n No se han podido exportar los registros a un archivo de texto \n\n");
    getch();

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
    }
