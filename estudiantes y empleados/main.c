#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 4E");

    printf("\n\t\t ***************************");
    printf("\n\t\t * ESTUDIANTES Y EMPLEADOS *");
    printf("\n\t\t ***************************\n\n");

    FILE *pf_empleados,*pf_estudiantes;

    t_empleados empleados[9]={  {11111111,"Anchorena","Fernando",12999.99},
                                {22222222,"Barreda","Armando",1999.99},
                                {33333333,"Dorrego","Gonzalo",27999.99},
                                {44444444,"Fernández","Jimena",13999.99},
                                {55555555,"Higuita","Fulano",5999.99},
                                {66666666,"Lorenzetti","Mariana",22999.99},
                                {77777777,"Nicoletti","Paula",11999.99},
                                {83648466,"Pereyra","Teodoro",2999.99},
                                {99999999,"Torrente","Ramiro",17999.99}  };

    t_estudiantes estudiantes[9]={  {11111110,"Aguirre","Pancracio",4.26},
                                  {11111111,"Anchorena","Fernando",7.98},
                                  {33333333,"Dorrego","Gonzalo",7.37},
                                  {44444444,"Fernández","Jimena",7.29},
                                  {58468488,"Gladiolo","Narciso",9.87},
                                  {66666666,"Lorenzetti","Mariana",7.25},
                                  {77777777,"Nicoletti","Paula",8.26},
                                  {88888888,"Quijano","Alfonso",2.23},
                                  {99999999,"Torrente","Ramiro",6.77}  };

    abrir_archivo(&pf_empleados,"empleados.bin","wb",CON_MENSAJE);
    abrir_archivo(&pf_estudiantes,"estudiantes.bin","wb",CON_MENSAJE);

    fwrite(&empleados,sizeof(t_empleados),9,pf_empleados);
    fwrite(&estudiantes,sizeof(t_estudiantes),9,pf_estudiantes);

    fclose(pf_empleados);
    fclose(pf_estudiantes);

    printf("\n\n Se ha generado un lote de datos \n\n  --->>> archivos binarios \"empleados.bin\" y \"estudiantes.bin\" \n");
    getch();

    system("cls");

    printf("\n\t\t ***************************");
    printf("\n\t\t * ESTUDIANTES Y EMPLEADOS *");
    printf("\n\t\t ***************************");

    if(!abrir_archivo(&pf_empleados,"empleados.bin","r+b",CON_MENSAJE))
        {
        printf("\n\n Programa evacuado \n");
        exit(EXIT_FAILURE);
        }
    if(!abrir_archivo(&pf_estudiantes,"estudiantes.bin","rb",CON_MENSAJE))
        {
        fclose(pf_empleados);
        printf("\n\n Programa evacuado \n");
        exit(EXIT_FAILURE);
        }

    printf("\n\n En este programa se actualizarán los sueldos de los empleados");
    printf("\n que sean estudiantes y tengan un promedio superior a 7,");
    printf("\n otorgándoles un aumento del 7.28%c \n",37);
    getch();

    printf("\n\n\n ARCHIVO DE ESTUDIANTES \n");
    mostrar_archivo_estudiantes(pf_estudiantes);
    getch();

    printf("\n\n\n ARCHIVO DE EMPLEADOS ANTES DE LA MODIFICACIÓN \n");
    mostrar_archivo_empleados(pf_empleados);
    getch();

    modificar_archivo_empleados(pf_empleados,pf_estudiantes);

    printf("\n\n\n ARCHIVO DE EMPLEADOS DESPUÉS DE LA MODIFICACIÓN \n");
    mostrar_archivo_empleados(pf_empleados);
    getch();

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n");
    return 0;
    }
