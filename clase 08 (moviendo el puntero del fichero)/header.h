#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
typedef struct
    {
    int d,
        m,
        a;
    }t_fecha;
typedef struct
    {
    int dni;
    char nomb[30];
    int edad;
    t_fecha f_nac;
    }t_persona;

