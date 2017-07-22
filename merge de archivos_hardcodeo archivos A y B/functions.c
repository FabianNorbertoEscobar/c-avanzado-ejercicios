#include "header.h"

void grabar_en_binario(char *ruta,t_persona registros[],int tam)
    {
    FILE *pf;
    pf=fopen(ruta,"wb");
    if(!pf)
        {
        printf("\n\n No se pudo crear el archivo %s \n\n",ruta);
        exit(EXIT_FAILURE);
        }
    fwrite(registros,sizeof(t_persona),tam,pf);
    fclose(pf);
    }

void mostrar_archivo_binario(FILE *pf)
    {
    t_persona registro;
    rewind(pf);
    fread(&registro,sizeof(t_persona),1,pf);
    while(!feof(pf))
        {
        printf("\n DNI: %d \t Apellido/s: \t %s \n\t\t Nombre/s: \t %s \n\t\t Edad: \t\t %d \n\t\t Sueldo: \t %.2lf \n",registro.dni,registro.apellido,registro.nombre,registro.edad,registro.sueldo);
        fread(&registro,sizeof(t_persona),1,pf);
        }
    }
