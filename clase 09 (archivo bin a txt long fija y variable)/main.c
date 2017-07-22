#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n PASAR ARCHIVO BINARIO A ARCHIVO DE TEXTO \n DE LONGITUD FIJA Y DE LONGITUD VARIABLE \n");
    FILE *pf_bin,*pf_txt_var,*pf_txt_fij;
    pf_bin=fopen("personas.dat","rb");
    if(!pf_bin)
        {
        printf("\n No se pudo leer el archivo binario \n\a\a");
        exit(EXIT_FAILURE);
        }
    pf_txt_var=fopen("longitud_variable.txt","wt");
    if(!pf_txt_var)
        {
        printf("\n No se pudo crear el archivo de texto de longitud variable \n\a\a");
        fclose(pf_bin);
        exit(EXIT_FAILURE);
        }
    pf_txt_fij=fopen("longitud_fija.txt","wt");
    if(!pf_txt_fij)
        {
        printf("\n No se pudo crear el archivo de texto de longitud fija \n\a\a");
        fclose(pf_bin);
        fclose(pf_txt_var);
        exit(EXIT_FAILURE);
        }
    a_longitud_variable(pf_bin,pf_txt_var);
    a_longitud_fija(pf_bin,pf_txt_fij);
    printf("\n\n Se ha creado el archivo de texto \"longitud_variable.txt\"");
    printf("\n\n Se ha creado el archivo de texto \"longitud_fija.txt\"");
    printf("\n\n \t\t\t\t\t Fin del programa.. \n\n");
    getch();
    return 0;
    }
