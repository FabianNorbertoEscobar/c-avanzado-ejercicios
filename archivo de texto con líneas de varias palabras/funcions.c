#include "header.h"

void nueva_linea(FILE *pf,int n)
    {
    int i,j;
    char caracter;
    for(i=0;i<n;i++)
        {
        for(j=0;j<6;j++)
            {
            do
                caracter=(char)rand()%100;
            while(!ES_LETRA(caracter));
            fprintf(pf,"%c",caracter);
            }
        fputs("   ",pf);
        }
    fputs("\n",pf);
    }
