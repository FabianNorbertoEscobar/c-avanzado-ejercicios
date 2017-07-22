#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#define TAM     10

typedef struct
    {
    int dni;
    char apellido[25];
    char nombre[30];
    int edad;
    double sueldo;
    }t_persona;

void grabar_en_binario(char*,t_persona[],int);
void grabar_en_binario(char*,t_persona[],int);
void mostrar_archivo_binario(FILE*);
