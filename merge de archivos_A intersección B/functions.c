#include "header.h"

void interseccion_de_archivos_binarios(FILE *pf_A,FILE *pf_B,FILE *pf_interseccion)
    {
    int comparador;

    t_persona persona_A;
    t_persona persona_B;

    rewind(pf_A);
    rewind(pf_B);
    rewind(pf_interseccion);

    fread(&persona_A,sizeof(t_persona),1,pf_A);
    fread(&persona_B,sizeof(t_persona),1,pf_B);

    while(!feof(pf_A)&&!feof(pf_B))
        {
        comparador=comparacion_de_registros(&persona_A,&persona_B);

        if(comparador<0)
            {
            fread(&persona_A,sizeof(t_persona),1,pf_A);
            }
        else
            if(comparador>0)
                {
                fread(&persona_B,sizeof(t_persona),1,pf_B);
                }
            else
                {
                fwrite(&persona_A,sizeof(t_persona),1,pf_interseccion);
                fread(&persona_A,sizeof(t_persona),1,pf_A);
                fread(&persona_B,sizeof(t_persona),1,pf_B);
                }
        }
    }

int comparacion_de_registros(t_persona *persona_1,t_persona *persona_2)
    {
    int comparador;
    if((comparador=str_cmp(persona_1->apellido,persona_2->apellido))==0)
        if((comparador=str_cmp(persona_1->nombre,persona_2->nombre))==0)
            if(persona_1->dni==persona_2->dni)
                return IGUAL;
            else
                if(persona_1->dni>persona_2->dni)
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
