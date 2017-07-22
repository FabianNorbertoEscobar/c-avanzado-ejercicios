#include "header.h"

void grabar_archivo_maestro(char *ruta,t_maestro registros[],int tam)
    {
    FILE *pf;
    pf=fopen(ruta,"wb");
    if(!pf)
        {
        printf("\n\n No se pudo crear el archivo %s \n\n",ruta);
        exit(EXIT_FAILURE);
        }
    fwrite(registros,sizeof(t_maestro),tam,pf);
    fclose(pf);
    }

void grabar_archivo_novedades(char *ruta,t_novedades registros[],int tam)
    {
    FILE *pf;
    pf=fopen(ruta,"wb");
    if(!pf)
        {
        printf("\n\n No se pudo crear el archivo %s \n\n",ruta);
        exit(EXIT_FAILURE);
        }
    fwrite(registros,sizeof(t_novedades),tam,pf);
    fclose(pf);
    }

void mostrar_archivo_maestro(FILE *pf)
    {
    t_maestro registro;
    rewind(pf);
    fread(&registro,sizeof(t_maestro),1,pf);
    while(!feof(pf))
        {
        printf("\n DNI: %d \t Apellido/s: \t %s \n\t\t Nombre/s: \t %s \n\t\t Edad: \t\t %d \n\t\t Sueldo: \t %.2lf \n\t\t ESTADO: \t %c \n",registro.dni,registro.apellido,registro.nombre,registro.edad,registro.sueldo,registro.estado);
        fread(&registro,sizeof(t_maestro),1,pf);
        }
    }

void mostrar_archivo_novedades(FILE *pf)
    {
    t_novedades registro;
    rewind(pf);
    fread(&registro,sizeof(t_novedades),1,pf);
    while(!feof(pf))
        {
        printf("\n DNI: %d \t Apellido/s: \t %s \n\t\t Nombre/s: \t %s \n\t\t Edad: \t\t %d \n\t\t Sueldo: \t %.2lf \n\t\t CÓDIGO: \t %c \n",registro.dni,registro.apellido,registro.nombre,registro.edad,registro.sueldo,registro.codigo);
        fread(&registro,sizeof(t_novedades),1,pf);
        }
    }

void actualizar_archivo_maestro(FILE *pf_maestro,FILE *pf_novedades,FILE *pf_maestro_actualizado,FILE *pf_errores)
    {
    int comparador;

    t_maestro registro_maestro;
    t_novedades registro_novedades;

    rewind(pf_maestro);
    rewind(pf_novedades);
    rewind(pf_maestro_actualizado);
    rewind(pf_errores);

    fread(&registro_maestro,sizeof(t_maestro),1,pf_maestro);
    fread(&registro_novedades,sizeof(t_novedades),1,pf_novedades);

    while(!feof(pf_maestro)&&!feof(pf_novedades))
        {
        comparador=comparacion_de_registros(&registro_maestro,&registro_novedades);

        if(comparador<0)
            {
            fwrite(&registro_maestro,sizeof(t_maestro),1,pf_maestro_actualizado);
            fread(&registro_maestro,sizeof(t_maestro),1,pf_maestro);
            }
        else
            if(comparador>0)
                {
                if(registro_novedades.codigo=='B'||registro_novedades.codigo=='M')
                    fwrite(&registro_novedades,sizeof(t_novedades),1,pf_errores);
                else
                    fwrite(&registro_novedades,sizeof(t_maestro),1,pf_maestro_actualizado);
                fread(&registro_novedades,sizeof(t_novedades),1,pf_novedades);
                }
            else
                {
                if(registro_novedades.codigo=='M')
                    {
                    registro_novedades.codigo=registro_maestro.estado;
                    fwrite(&registro_novedades,sizeof(t_maestro),1,pf_maestro_actualizado);
                    }
                else
                    if(registro_maestro.estado!=registro_novedades.codigo)
                        {
                        registro_maestro.estado=registro_novedades.codigo;
                        fwrite(&registro_maestro,sizeof(t_maestro),1,pf_maestro_actualizado);
                        }
                    else
                        {
                        fwrite(&registro_novedades,sizeof(t_novedades),1,pf_errores);
                        fwrite(&registro_maestro,sizeof(t_maestro),1,pf_maestro_actualizado);
                        }

                fread(&registro_maestro,sizeof(t_maestro),1,pf_maestro);
                fread(&registro_novedades,sizeof(t_novedades),1,pf_novedades);
                }
        }

    while(!feof(pf_maestro))
            {
            fwrite(&registro_maestro,sizeof(t_maestro),1,pf_maestro_actualizado);
            fread(&registro_maestro,sizeof(t_maestro),1,pf_maestro);
            }
    while(!feof(pf_novedades))
            {
            if(registro_novedades.codigo=='B'||registro_novedades.codigo=='M')
                    fwrite(&registro_novedades,sizeof(t_novedades),1,pf_errores);
                else
                    fwrite(&registro_novedades,sizeof(t_maestro),1,pf_maestro_actualizado);
            fread(&registro_novedades,sizeof(t_novedades),1,pf_novedades);
            }
    }

int comparacion_de_registros(t_maestro *registro_maestro,t_novedades *registro_novedades)
    {
    int comparador;
    if((comparador=str_cmp(registro_maestro->apellido,registro_novedades->apellido))==0)
        if((comparador=str_cmp(registro_maestro->nombre,registro_novedades->nombre))==0)
            if(registro_maestro->dni==registro_novedades->dni)
                return IGUAL;
            else
                if(registro_maestro->dni>registro_novedades->dni)
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

void exportar_maestro_a_txt_longitud_fija(FILE *pf_bin,FILE *pf_txt)
    {
    t_maestro registro;
    rewind(pf_bin);
    rewind(pf_txt);
    fprintf(pf_txt,"\n\t\t\t ARCHIVO MAESTRO");
    fprintf(pf_txt,"\n\t\t\t =============== \n");
    fprintf(pf_txt,"DNI  \t  APELLIDO/s \t\t   NOMBRE/s \t\t\t EDAD SUELDO ESTADO \n\n");
    fread(&registro,sizeof(t_maestro),1,pf_bin);
    while(!feof(pf_bin))
        {
        fprintf(pf_txt,"%8d  %-25s%-30s%2d  %.2lf  %c\n",registro.dni,registro.apellido,registro.nombre,registro.edad,registro.sueldo,registro.estado);
        fread(&registro,sizeof(t_maestro),1,pf_bin);
        }
    }

void exportar_errores_a_txt_longitud_fija(FILE *pf_bin,FILE *pf_txt)
    {
    t_novedades registro;
    rewind(pf_bin);
    rewind(pf_txt);
    fprintf(pf_txt,"\n\t\t\t ARCHIVO ERRORES");
    fprintf(pf_txt,"\n\t\t\t =============== \n");
    fprintf(pf_txt,"DNI  \t  APELLIDO/s \t\t   NOMBRE/s \t\t\t EDAD SUELDO CÓDIGO \n\n");
    fread(&registro,sizeof(t_maestro),1,pf_bin);
    while(!feof(pf_bin))
        {
        fprintf(pf_txt,"%8d  %-25s%-30s%2d  %.2lf  %c\n",registro.dni,registro.apellido,registro.nombre,registro.edad,registro.sueldo,registro.codigo);
        fread(&registro,sizeof(t_maestro),1,pf_bin);
        }
    }
