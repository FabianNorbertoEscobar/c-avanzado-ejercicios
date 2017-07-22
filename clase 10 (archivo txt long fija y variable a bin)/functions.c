#include "header.h"

void longitud_variable_a_binario(FILE *pf_txt_var,FILE *pf_bin_var)
    {
    t_persona persona;
    rewind(pf_txt_var);
    while(fscanf(pf_txt_var,"%d|%[^|]|%d|%d/%d/%d",&persona.dni,persona.nomb,&persona.edad,&persona.f_nac.d,&persona.f_nac.m,&persona.f_nac.a)!=EOF)
        fwrite(&persona,sizeof(t_persona),1,pf_bin_var);
    }

void longitud_fija_a_binario(FILE *pf_txt_fij,FILE *pf_bin_fij)
    {
    t_persona persona;
    rewind(pf_txt_fij);
    while(fscanf(pf_txt_fij,"%8d%[^0123456789]%2d%2d/%2d/%4d",&persona.dni,persona.nomb,&persona.edad,&persona.f_nac.d,&persona.f_nac.m,&persona.f_nac.a)!=EOF)
        fwrite(&persona,sizeof(t_persona),1,pf_bin_fij);
    }

//lo próximo lo dejo acá para controlar q lo haya hecho bien
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
