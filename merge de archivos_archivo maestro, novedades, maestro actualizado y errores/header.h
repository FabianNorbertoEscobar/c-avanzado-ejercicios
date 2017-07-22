#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#define TAM_MAESTRO     20
#define TAM_NOVEDADES   18

#define     MENOR       -1
#define     IGUAL       0
#define     MAYOR       1

typedef struct
    {
    int dni;
    char apellido[25];
    char nombre[30];
    int edad;
    double sueldo;
    char estado;
    }t_maestro;

typedef struct
    {
    int dni;
    char apellido[25];
    char nombre[30];
    int edad;
    double sueldo;
    char codigo;
    }t_novedades;

void grabar_archivo_maestro(char*,t_maestro[],int);
void grabar_archivo_novedades(char*,t_novedades[],int);
void mostrar_archivo_maestro(FILE*);
void mostrar_archivo_novedades(FILE*);
void actualizar_archivo_maestro(FILE*,FILE*,FILE*,FILE*);
int comparacion_de_registros(t_maestro*,t_novedades*);
int str_cmp(const char*,const char*);
void exportar_maestro_a_txt_longitud_fija(FILE*,FILE*);
void exportar_errores_a_txt_longitud_fija(FILE*,FILE*);
