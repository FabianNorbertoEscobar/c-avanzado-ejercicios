#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    char cad1[6]="lunes";
    char cad2[7]="martes";
    printf("\n\n tamaño de la cadena: \t %d",str_len(cad2));
    str_cpy(cad1,cad2);
    printf("\n\n resultado de la copia %s \n ",cad1);
    str_cat(cad1,cad2);
    printf("\n\n %s resultado e la concatenación \n",cad1);
    printf("\n\n comparación entre cadena 1 y cadena 2: %d \n",str_cmp(cad1,cad2));
    printf("\n\n comparación entre cadena 1 y cadena 2, case insensitive: %d \n",str_cmpi(cad1,cad2));
    printf("\n\n busqueda de caracter en cadena: \t %s \n\n",str_chr(cad1,'r'));
    getch();
    return 0;
    }
