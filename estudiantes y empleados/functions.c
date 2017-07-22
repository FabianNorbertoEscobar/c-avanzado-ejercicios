#include "header.h"

int abrir_archivo(FILE **pf,const char *ruta,const char *modo_tipo,int mensaje)
    {
    *pf=fopen(ruta,modo_tipo);
    if(!*pf)
        if(mensaje)
            {
            printf("\n\n No se pudo abrir el archivo %s con el modo_tipo %s \n\n\a\a",ruta,modo_tipo);
            return FALSO;
            }
    return VERDADERO;
    }

void mostrar_archivo_empleados(FILE *pf)
    {
    t_empleados registro;
    rewind(pf);
    fread(&registro,sizeof(t_empleados),1,pf);
    while(!feof(pf))
        {
        printf("\n\n DNI: \t\t %d \n Apellido: \t %s \n Nombre: \t %s \n Sueldo: \t %.2lf",registro.dni,registro.apellido,registro.nombre,registro.sueldo);
        fread(&registro,sizeof(t_empleados),1,pf);
        }
    }

void mostrar_archivo_estudiantes(FILE *pf)
    {
    t_estudiantes registro;
    rewind(pf);
    fread(&registro,sizeof(t_estudiantes),1,pf);
    while(!feof(pf))
        {
        printf("\n\n DNI: \t\t %d \n Apellido: \t %s \n Nombre: \t %s \n Promedio: \t %.2f",registro.dni,registro.apellido,registro.nombre,registro.promedio);
        fread(&registro,sizeof(t_estudiantes),1,pf);
        }
    }

void modificar_archivo_empleados(FILE *pf_empleados,FILE *pf_estudiantes)
    {
    int comparador;

    t_empleados empleado;
    t_estudiantes estudiante;

    rewind(pf_empleados);
    rewind(pf_estudiantes);

    fread(&empleado,sizeof(t_empleados),1,pf_empleados);
    fread(&estudiante,sizeof(t_estudiantes),1,pf_estudiantes);

    while(!feof(pf_empleados)&&!feof(pf_estudiantes))
        {
        if(estudiante.promedio<=7)
            {
            fread(&estudiante,sizeof(t_estudiantes),1,pf_estudiantes);
            continue;
            }

        comparador=comparacion_de_registros(&empleado,&estudiante);

        if(comparador<0)
            {
            fread(&empleado,sizeof(t_empleados),1,pf_empleados);
            continue;
            }
        else
            if(comparador>0)
                {
                fread(&estudiante,sizeof(t_estudiantes),1,pf_estudiantes);
                continue;
                }
            else
                {
                empleado.sueldo+=empleado.sueldo*0.0728;
                fseek(pf_empleados,-sizeof(t_empleados),SEEK_CUR);
                fwrite(&empleado,sizeof(t_empleados),1,pf_empleados);
                fseek(pf_empleados,0L,SEEK_CUR);
                }

        fread(&empleado,sizeof(t_empleados),1,pf_empleados);
        fread(&estudiante,sizeof(t_estudiantes),1,pf_estudiantes);
        }
    }

int comparacion_de_registros(t_empleados *empleado,t_estudiantes *estudiante)
    {
    int comparador;
    if((comparador=str_cmp(empleado->apellido,estudiante->apellido))==0)
        if((comparador=str_cmp(empleado->nombre,estudiante->nombre))==0)
            if(empleado->dni==estudiante->dni)
                return IGUAL;
            else
                if(empleado->dni>estudiante->dni)
                    return MAYOR;
                else
                    return MENOR;
        else
            return comparador;
    else
        return comparador;
    }

int str_cmp(const char *s1,const char *s2)
    {
    while(*s1==*s2&&*s1&&*s2)
        {
        s1++;
        s2++;
        }
    return *s1-*s2;
    }
