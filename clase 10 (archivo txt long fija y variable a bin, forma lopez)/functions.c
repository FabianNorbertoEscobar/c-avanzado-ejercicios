#include "header.h"

void longitud_variable_a_binario(FILE *pf_txt_var,FILE *pf_bin_var)
    {
    t_persona persona;
    rewind(pf_txt_var);
    char linea[500],*aux;
    while(fgets(linea,sizeof(linea),pf_txt_var))
        {
        aux=str_chr(linea,'\n');
        *aux='\0';
        aux=str_rchr(linea,'|');
        sscanf(aux+1,"%d/%d/%d",&persona.f_nac.d,&persona.f_nac.m,&persona.f_nac.a);
        *aux='\0';
        aux=str_rchr(linea,'|');
        sscanf(aux+1,"%d",&persona.edad);
        *aux='\0';
        aux=str_rchr(linea,'|');
        str_cpy(persona.nomb,aux+1);
        *aux='\0';
        sscanf(linea,"%d",&persona.dni);
        fwrite(&persona,sizeof(t_persona),1,pf_bin_var);
        }
    }

void longitud_fija_a_binario(FILE *pf_txt_fij,FILE *pf_bin_fij)
    {
    t_persona persona;
    rewind(pf_txt_fij);
    char linea[500],*aux;
    while(fgets(linea,sizeof(linea),pf_txt_fij))
        {
        aux=str_chr(linea,'\n');
        *aux='\0';
        aux-=11;
        sscanf(aux,"%02d/%2d/%04d",&persona.f_nac.d,&persona.f_nac.m,&persona.f_nac.a);
        *(aux-1)='\0';
        aux-=4;
        sscanf(aux,"%d",&persona.edad);
        *(aux+-1)='\0';
        aux-=32;
        str_cpy(persona.nomb,aux);
        trim(persona.nomb);
        *aux='\0';
        sscanf(linea,"%d",&persona.dni);
        fwrite(&persona,sizeof(t_persona),1,pf_bin_fij);
        }
    }

char *trim(char *s)
    {
    char *inicio=s;
    while(*s)
        s++;
    while(s>inicio&&*s==' ')
        s--;
    *s='\0';
    return inicio;
    }

char *str_chr(char *s,int c)
    {
    while(*s&&*s!=c)
        s++;
    return (*s)?s:NULL;
    }

char *str_rchr(char *s,int c)
    {
    char *inicio=s;
    while(*s)
        s++;
    while(s>inicio&&*s!=c)
        s--;
    return (*s==c)?s:NULL;
    }

char *str_cpy(char *destino,const char *origen)
    {
    char *s=destino;
    while(*origen)
        {
        *destino=*origen;
        destino++;
        origen++;
        }
    *destino='\0';
    return s;
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

