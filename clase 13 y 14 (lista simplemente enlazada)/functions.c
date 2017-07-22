#include "header.h"

void cargar_dato(t_dato *d)
    {
    printf("\n\n Ingrese dato a enlistar (número entero): \t");
    scanf("%d",&d->numero);
    }

void mostrar_dato(t_dato *d)
    {
    printf("\n\n Dato desenlistado: \t %d",d->numero);
    }

// A CONTINUACIÓN, FUNCIONES DE COMPARACIÓN QUE SE PUEDEN MANDAR COMO PARÁMETRO A LAS FUNCIONES DE LISTA

int comparar_datos(const void *v1,const void *v2)
    {
    t_dato *i1=(t_dato*)v1,*i2=(t_dato*)v2;
    return i1->numero - i2->numero;
    }

/*

ESTAS FUNCIONES TIENEN SENTIDO SI SE IMPLEMENTAN CON UN DATO QUE CONTENGA DNI, APELLIDO Y NOMBRE

int comparar_clave_dni(const void* v1,const void* v2)
{
    tDato *l1 = (tDato*)v1;
    long *l2 = (long*)v2;
    return l1->dni - *l2;
}

int comparar_personas(const void *v1,const void *v2)
{
    int cmp;
    tDato *a1 = (tDato*)v1, *a2 = (tDato*)v2;
    if(!(cmp = strcmp(a1->ape,a2->ape)))
        if(!(cmp = strcmp(a1->nomb,a2->nomb)))
            return a1->dni - a2->dni;
    return cmp;
}

ESTA FUNCIÓN INTENTA COMPARAR PERSONAS EN UNA SOLA CADENA, PERO NO SIRVE PARA TODOS LOS CASOS

int comparar_personas_en_cadena(const void *v1,const void *v2)
{
    tDato *a1 = (tDato*)v1, *a2 = (tDato*)v2;
    char cad1[49],cad2[49];
    char cadDni[9];
    strcat(strcat(strcpy(cad1,a1->ape),a1->nomb),ltoa(a1->dni,cadDni,10));
    strcat(strcat(strcpy(cad1,a2->ape),a2->nomb),ltoa(a2->dni,cadDni,10));
    return strcmp(cad1,cad2);
}


//  ESTA FUNCIÓN SIRVE PARA COMPARAR PERSONAS EN UNA SOLA CADENA

int comparar_personas_en_cadena(const void *v1,const void *v2)
{
    t_dato *a1 = (t_dato*)v1, *a2 = (t_dato*)v2;
    char cad1[50],cad2[50];
    sprintf(cad1,"%21s%21s%08ld",a1->ape,a1->nomb,a1->dni);
    sprintf(cad2,"%21s%21s%08ld",a2->ape,a2->nomb,a2->dni);
    return strcmp(cad1,cad2);
}

*/
