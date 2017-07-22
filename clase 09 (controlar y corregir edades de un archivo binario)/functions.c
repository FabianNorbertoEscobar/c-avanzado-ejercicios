#include "header.h"
void mostrar_archivo(FILE *pf)
    {
    t_persona persona;
    rewind(pf);
    fread(&persona,sizeof(t_persona),1,pf);
    while(!feof(pf))
        {
        printf("\n DNI: \t %d \t Nombre y Apellido: \t %s \n Edad: \t %d \t Fecha de nacimiento: \t %d/%d/%d \n",persona.dni,persona.nomb,persona.edad,persona.f_nac.d,persona.f_nac.m,persona.f_nac.a);
        fread(&persona,sizeof(t_persona),1,pf);
        }
    }
void controlar_y_corregir_edad(FILE *pf)
    {
    t_persona persona;
    int edad;
    rewind(pf);
    fread(&persona,sizeof(t_persona),1,pf);
    while(!feof(pf))
        {
        if(persona.edad!=(edad=calcular_edad(&persona.f_nac)))
            {
            persona.edad=edad;
            fseek(pf,-sizeof(t_persona),SEEK_CUR);
            fwrite(&persona,sizeof(t_persona),1,pf);
            fseek(pf,0L,SEEK_CUR);
            }
        fread(&persona,sizeof(t_persona),1,pf);
        }
    }
int calcular_edad(t_fecha *f_nac)
    {
    t_fecha f_act = {13,9,2016};//debería ingresarse por teclado la edad o trabajar con la fecha del sistema ->> acá está hecho así porque la idea es utilizar este programa solo en esta oportinidad
    int edad;
    edad=f_act.a-f_nac->a;
    if(f_act.m<f_nac->m||(f_act.m==f_nac->m&&f_act.d<f_nac->d))
        edad--;
    return edad;
    }
