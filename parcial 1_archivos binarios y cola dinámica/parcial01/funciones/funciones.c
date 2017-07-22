#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <funciones.h>

void crearArchivo()
    {
    FILE *pf=fopen("archivos/histor.dat","wb");
    if(!pf)
        {
        printf("\n No se pudo crear el archivo binario \"archivos/histor.dat\" \n\n\a\a");
        printf("\n Programa evacuado \n");
        exit(EXIT_FAILURE);
        }

        t_historial hist[15]={ {123456789,"soy una descripción",123,1,2},
                                {123456789,"soy otra descripción",123,1,2},
                                {123456789,"soy descripción",123,1,2},
                                {123456789,"soy la descripción",123,1,2},
                                {123456789,"soy descripción",123,1,2},
                                {123456789,"soy la descripción",123,1,2},
                                {123456789,"soy una descripción",123,1,2},
                                {123456789,"soy otra descripción",123,1,2},
                                {123456789,"soy una descripción",123,1,2},
                                {123456789,"soy otra descripción",123,1,2},
                                {123456789,"soy la descripción",123,1,2},
                                {123456789,"soy la descripción",123,1,2},
                                {123456789,"soy la descripción",123,1,2},
                                {123456789,"soy una descripción",123,1,2},
                                {123456789,"soy una descripción",123,1,2}   };

    fwrite(hist,sizeof(t_historial),15,pf);
    fclose(pf);
    }

int aperturaDeArchivos(FILE **archivo, const char *ruta, const char *modo)
    {
    *archivo=fopen(ruta,modo);
    if(!*archivo)
        return 0;
    return 1;
    }

int es_vocal(char s)
{
    if(s!='A'&&s!='E'&&s!='I'&&s!='O'&&s!='U'&&s!='a'&&s!='e'&&s!='i'&&s!='o'&&s!='u')
        return 0;
    return 1;
}

int cantVocalesIni(char *s)
{
    int vocales=0;
    while(*s)
        {
        if(es_vocal(*s))
            vocales=1;
        while(*s&&!ES_BLANCO(*s))
            s++;
        if(ES_BLANCO(*s))
            s++;
        }
    if(vocales==0)
        return 0;
    return 1;
}

char *str_cpy(char *destino,const char *origen)
{
    char *inicio=destino;
    while(*origen)
    {
        *destino=*origen;
        destino++;
        origen++;
    }
    *destino='\0';
    return inicio;
}

void cargaInfoDeArchivo(FILE *entrada,t_historial *his,t_cola *cola,char descripcion[][46], long valores[][4], int *fila)
{
    t_info info;
    rewind(entrada);

    fread(his,sizeof(t_historial),1,entrada);
    while(!feof(entrada))
    {
        if(cantVocalesIni(his->desc))
        {
            str_cpy(descripcion[*fila],his->desc);
            valores[*fila][0]=his->clave;
            valores[*fila][1]=his->prepo;
            valores[*fila][2]=his->exist;
            valores[*fila][3]=his->pengr;
            (*fila)++;
        }
        else
        {
            info=his->clave;
            ponerEnCola(cola,&info);
        }
        fread(his,sizeof(t_historial),1,entrada);
    }
}


void crearArchivoActual(FILE *entrada, FILE *salida, t_historial *his,t_cola *cola)
{
   t_info info;
   rewind(entrada);
   rewind(salida);

   fread(his,sizeof(t_historial),1,entrada);
   while(!feof(entrada))
   {
        primeroEnCola(cola,&info);
        if(his->clave==info)
        {
            sacarDeCola(cola,&info);
            fwrite(his,sizeof(t_historial),1,salida);
        }
        fread(his,sizeof(t_historial),1,entrada);
   }
}

void mostrarInfo(char descripcion[][46], long valores[][4], int *cant)
{
    int i;
    printf("\n CLAVE \t\t DESC \t\t\t\t PREPO \t EXIST \t PENGR \n");
    for(i=0;i<*cant;i++)
        printf("\n %ld \t %s \t\t %ld \t %ld \t %ld",valores[i][0],descripcion[i],valores[i][1],valores[i][2],valores[i][3]);
}
