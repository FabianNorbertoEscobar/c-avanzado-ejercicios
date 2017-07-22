#include "header.h"

void nueva_linea(FILE *pf,int n)
    {
    int i;
    for(i=0;i<n;i++)
        fprintf(pf,"%6hd ",rand());
    fputs("\n",pf);
    }
