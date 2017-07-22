#include "header.h"

void cargar_registro(t_reg_indice *reg_ind)
    {
    printf("\n\n NUEVO REGISTRO \n");
    printf("\n Ingrese el dni: \t");
    scanf("%ld",&reg_ind->dni);
    printf("\n Ingrese el número de registro: \t");
    scanf("%u",&reg_ind->nro_reg);
    }

void mostrar_registro(t_reg_indice *reg_ind)
    {
    printf("\n\n REGISTRO \n");
    printf("\n DNI: \t %ld \n",reg_ind->dni);
    printf("\n Número de registro: \t %u \n",reg_ind->nro_reg);
    }
