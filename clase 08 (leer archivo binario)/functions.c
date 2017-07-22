#include "header.h"
void leer_archivo(FILE **pf)
    {
    t_persona per;
    fread(&per,sizeof(t_persona),1,*pf);
    while(!feof(*pf))
        {
        printf("\n\n DNI: \t %d \t Nombre y apellido: \t %s \n Edad: \t %d \t Fecha de nacimiento: \t %d/%d/%d \n",per.dni,per.nomb,per.edad,per.f_nac.d,per.f_nac.m,per.f_nac.a);
        fread(&per,sizeof(t_persona),1,*pf);
        }
    }
