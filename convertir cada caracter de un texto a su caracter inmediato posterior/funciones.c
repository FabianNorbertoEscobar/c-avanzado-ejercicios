#include "header.h"

void ingresar_texto(char texto[])
{
    int i;

    for(i=0;texto[i-1]!='.'&&i<TAM;i++)
        texto[i]=getchar();
}

void grabar_archivo(char texto[],FILE *archivo)
{
    int i;

    for(i=0;texto[i]!='.'&&i<TAM;i++)
        putc(texto[i],archivo);
}

void mostrar_texto(char texto[])
{
    int i;

    for(i=0;texto[i]!='.'&&i<TAM;i++)
        putc(texto[i],stdout);
}

void mostrar_texto_convertido(char texto[])
{
    int i;

    for(i=0;texto[i]!='.'&&i<TAM;i++)
        putc(texto[i]+1,stdout);
}
