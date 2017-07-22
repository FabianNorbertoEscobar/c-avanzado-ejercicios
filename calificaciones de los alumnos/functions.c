#include "header.h"

size_t str_len(const char *s)
    {
    size_t cont=0;
    while(*s)
        {
        cont++;
        s++;
        }
    return cont;
    }

char *str_ncpy(char *destino,const char *origen,size_t cant)
    {
    char *s=destino;
    while(*origen&&cant)
        {
        *destino=*origen;
        destino++;
        origen++;
        cant--;
        }
    while(cant--)
        *destino++='\0';
    *destino='\0';
    return s;
    }

int cargar_matrices_de_datos(char mat_apyn[][TOPE],int reg,int tope,float mat_notas[][COL],int fil,int col)
    {
    int bandera,op,j,i=0;
    char cadena[tope];
    do
        {
        printf("\n\n REGISTRO %d \n",i+1);

        printf("\n\n Ingrese apellido/s y nombre/s del alumno \n (en formato \"Apellido1 Apellido 2 ... etc, Nombre1 Nombre 2 ... etc\") \n (cuenta con %d caracteres): \n\n\t",tope-1);
        bandera=0;
        do
            {
            if(bandera==1)
                printf("\n\n El campo solicitado está vacío. Reingréselo: \n\n\t\a\a");
            fflush(stdin);
            gets(cadena);
            bandera=1;
            }
        while(str_len(cadena)==0);
        str_ncpy((char*)&mat_apyn[i],cadena,tope-1);

        for(j=0;j<COL-1;j++)
            {
            printf("\n Ingrese la calificación de la evaluación %d (decimales permitidos): \t",j+1);
            bandera=0;
            do
                {
                if(bandera==1)
                    printf("\n\n La calificación ingresada no es válida. Reingrésela: \t\a\a");
                fflush(stdin);
                scanf("%f",&mat_notas[i][j]);
                bandera=1;
                }
            while(!DATO_VALIDO(mat_notas[i][j],0,10));
            }

        printf("\n\n Registro guardado exitosamente \n\n\a\a");
        i++;

        printf("\n\n ¿Desea grabar un nuevo registro? \n 1- SI \t 2- NO \t\t Opción: \t");
        bandera=0;
        do
            {
            if(bandera==1)
                printf("\n\n La opción ingresada no es válida. Ingrese una opción correcta \n\n\t\t\t Opción: \t\a\a");
            fflush(stdin);
            scanf("%d",&op);
            bandera=1;
            }
        while(!DATO_VALIDO(op,1,2));
        }
    while(i<reg&&op==1);

    printf("\n\n Las matrices de datos se generaron exitosamente \n");
    printf("\n Cantidad de registros grabados: \t %d",i);
    return i;
    }

void mostrar_matrices_de_datos(char mat_apyn[][TOPE],int reg,int tope,float mat_notas[][COL],int fil,int col,int cant_reg)
    {
    int i,j;
    printf("\n APELLIDO/S, NOMBRE/S \t\t\t    CALIFICACIONES \n");
    for(i=0;i<cant_reg;i++)
        {
        printf("\n\n %s \n\t\t\t\t   ",mat_apyn[i]);
        for(j=0;j<col-1;j++)
            printf("  %.2f",mat_notas[i][j]);
        }
    }

void promedios_de_alumnos(float mat_notas[][COL],int fil,int col,int cant_reg)
    {
    int i;
    for(i=0;i<cant_reg;i++)
        calcular_promedio_de_alumno(mat_notas[i],col,i);
    }

void calcular_promedio_de_alumno(float alumno[],int col,int i)
    {
    int j;
    alumno[col-1]=0;
    for(j=0;j<col-1;j++)
        alumno[col-1]+=alumno[j];
    alumno[col-1]/=(col-1);
    }

void promedios_por_evaluacion_y_general(float mat_notas[][COL],int fil,int col,int cant_reg)
    {
    int i,j;
    for(j=0;j<col;j++)
        mat_notas[cant_reg][j]=0;
    for(i=0;i<cant_reg;i++)
        for(j=0;j<col;j++)
            mat_notas[cant_reg][j]+=mat_notas[i][j];
    for(j=0;j<col;j++)
        mat_notas[cant_reg][j]/=cant_reg;
    }

 int exportar_a_archivo_de_texto(char mat_apyn[][TOPE],int reg,int tope,float mat_notas[][COL],int fil,int col,int cant_reg)
    {
    int contador_de_pagina=0,i;

    FILE *pf;
    pf=fopen("calificaciones de los alumnos.txt","wt");
    if(!pf)
        return 0;

    fprintf(pf,"12 12345678901234567890123456789012345 12345 12345 12345 12345 12345 12345   12345\n");//estos números los pongo para verificar que tengo los datos perfectamente encolumnados
    fprintf(pf,"   Apellido/s, Nombre/s                 P. 1  P. 2  P. 3  P. 4  P. 5  P. 6 - Prome\n");
    fprintf(pf,"   =================================== ===== ===== ===== ===== ===== =====   =====\n\n");

    for(i=0;i<cant_reg;i++)
        {
        fprintf(pf,"%2d %-*s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f - %5.2f\n",i+1,TOPE-1,mat_apyn[i],mat_notas[i][0],mat_notas[i][1],mat_notas[i][2],mat_notas[i][3],mat_notas[i][4],mat_notas[i][5],mat_notas[i][6]);
        contador_de_pagina++;
        if(contador_de_pagina==21&&i<cant_reg-2)
            {
            fprintf(pf,"\f");
            contador_de_pagina=0;
            }
        }

    fprintf(pf,"\f\n              PROMEDIOS POR EVALUACIÓN Y PROMEDIO GENERAL DEL CURSO \n");
    fprintf(pf,"              ===================================================== \n\n");
    fprintf(pf,"                                        P. 1  P. 2  P. 3  P. 4  P. 5  P. 6 - Gral.\n");
    fprintf(pf,"                                       ===== ===== ===== ===== ===== =====   =====\n\n");
    fprintf(pf,"                                       %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f - %5.2f\n",mat_notas[i][0],mat_notas[i][1],mat_notas[i][2],mat_notas[i][3],mat_notas[i][4],mat_notas[i][5],mat_notas[i][6]);

    fclose(pf);
    return 1;
    }
