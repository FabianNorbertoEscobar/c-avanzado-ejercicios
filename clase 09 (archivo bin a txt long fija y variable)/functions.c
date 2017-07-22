#include "header.h"
a_longitud_variable(FILE *pf_bin,FILE *pf_txt)
    {
    t_persona persona;
    rewind(pf_bin);
    fread(&persona,sizeof(t_persona),1,pf_bin);
    while(!feof(pf_bin))
        {
        fprintf(pf_txt,"%d|%s|%d|%d/%d/%d\n",persona.dni,persona.nomb,persona.edad,persona.f_nac.d,persona.f_nac.m,persona.f_nac.a);
        fread(&persona,sizeof(t_persona),1,pf_bin);
        }
    }
a_longitud_fija(FILE *pf_bin,FILE *pf_txt)
    {
    t_persona persona;
    rewind(pf_bin);
    fread(&persona,sizeof(t_persona),1,pf_bin);
    while(!feof(pf_bin))
        {
        fprintf(pf_txt,"%8d %-31s %2d %02d/%02d/%02d \n",persona.dni,persona.nomb,persona.edad,persona.f_nac.d,persona.f_nac.m,persona.f_nac.a);
        fread(&persona,sizeof(t_persona),1,pf_bin);
        }
    }
