#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <tipo.h>
#include <cola.h>

#define TAM 50
#define ES_BLANCO(x)      ((x)==' ')

void crearArchivo();
int aperturaDeArchivos(FILE **archivo, const char *ruta, const char *modo);

void cargaInfoDeArchivo(FILE *entrada,t_historial *his,t_cola *cola,char descripcion[][46], long valores[][4], int *fila);
void crearArchivoActual(FILE *entrada, FILE *salida, t_historial *his,t_cola *cola);
void mostrarInfo(char descripcion[][46], long valores[][4], int *cant);
int cantVocalesIni(char *s);
int es_vocal(char c);
char *str_cpy(char*,const char*);

#endif // FUNCIONES_H_INCLUDED
