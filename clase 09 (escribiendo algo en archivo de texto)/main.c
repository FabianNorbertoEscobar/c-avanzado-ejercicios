#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n Escribiendo algo en un archivo \n");
    int num=123456789;
    char cadena[30]="Fabián Norberto Escobar";
    FILE *pf;
    pf=fopen("fichero.txt","wt");
    if(!pf)
        {
        printf("\n\n No se pudo generar el archivo");
        printf("\n\n No tiene sentido continuar con la ejecución del programa \n\n Programa evacuado \a\a");
        exit(EXIT_FAILURE);
        }
    fprintf(pf,"\n Principio del archivo de texto\n");

    fputc('a',pf);
    fputc('\n',pf);
    fputc('b',pf);
    fputc('\n',pf);
    fputc('c',pf);
    fputc('\n',pf);

    fputs("\n cada vez esto se pone más lindo \n",pf);

    fprintf(pf,"%d\n",num);
    fprintf(pf,"%-d\n",num);
    fprintf(pf," %d\n",num);
    fprintf(pf," %-d\n",num);
    fprintf(pf,"\t%d\n",num);
    fprintf(pf,"\t%-d\n",num);
    fprintf(pf," %d %d %d\n",num,num,num);
    fprintf(pf," %d%d%d\n",num,num,num);
    fprintf(pf," 0%d %d %0d0\n",num,num,num);

    fprintf(pf,"\n%s",cadena);
    fprintf(pf,"\n%-s",cadena);
    fprintf(pf,"\n %s",cadena);
    fprintf(pf,"\n %-s",cadena);
    fprintf(pf,"\n\t%s",cadena);
    fprintf(pf,"\n\t %s",cadena);
    fprintf(pf,"\n \t %s",cadena);
    fprintf(pf,"\n \t %-s",cadena);
    fprintf(pf,"\n%s%s%s",cadena,cadena,cadena);
    fprintf(pf,"\n %s %s %s",cadena,cadena,cadena);

    fprintf(pf,"\n %s %d",cadena,num);
    fprintf(pf,"\n %-s %d",cadena,num);
    fprintf(pf,"\n %s %-d",cadena,num);
    fprintf(pf,"\n %-s %-d",cadena,num);

    fprintf(pf,"\n %d %s",num,cadena);
    fprintf(pf,"\n %-d %s",num,cadena);
    fprintf(pf,"\n %d %-s",num,cadena);
    fprintf(pf,"\n %-d %-s",num,cadena);

    fprintf(pf,"\n %40s %10d",cadena,num);
    fprintf(pf,"\n %-40s %10d",cadena,num);
    fprintf(pf,"\n %40s %-10d",cadena,num);
    fprintf(pf,"\n %-40s %-10d",cadena,num);

    fprintf(pf,"\n %d %20s",num,cadena);
    fprintf(pf,"\n %-20d %s",num,cadena);
    fprintf(pf,"\n %d %-20s",num,cadena);
    fprintf(pf,"\n %-20d %-s",num,cadena);

    fclose(pf);
    printf("\n\n Se ha generado el archivo \"fichero.txt\" \n\n Fin del programa.. \n\n")
;    getch();
    return 0;
    }
