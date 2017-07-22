#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n PASAR ARCHIVO DE TEXTO DE LONGITUD FIJA Y VARIABLE \n A ARCHIVO DE TEXTO \n\n");
    FILE *pf_txt_var,*pf_txt_fij,*pf_bin_fij,*pf_bin_var;
    pf_txt_fij=fopen("longitud_fija.txt","rb");
    if(!pf_txt_fij)
        {
        printf("\n No se pudo leer el archivo de texto de longitud fija \n\a\a");
        exit(EXIT_FAILURE);
        }
    pf_txt_var=fopen("longitud_variable.txt","rb");
    if(!pf_txt_var)
        {
        printf("\n No se pudo leer el archivo de texto de longitud variable \n\a\a");
        fclose(pf_txt_fij);
        exit(EXIT_FAILURE);
        }
    pf_bin_fij=fopen("personas_fija.bin","wb");
    if(!pf_bin_fij)
        {
        printf("\n No se pudo crear el archivo binario para pasar \n el archivo de texto de longitud fija \n\a\a");
        fclose(pf_txt_fij);
        fclose(pf_txt_var);
        exit(EXIT_FAILURE);
        }
    pf_bin_var=fopen("personas_variable.bin","wb");
    if(!pf_bin_var)
        {
        printf("\n No se pudo crear el archivo binario para pasar \n el archivo de texto de longitud variable \n\a\a");
        fclose(pf_txt_fij);
        fclose(pf_txt_var);
        fclose(pf_bin_fij);
        exit(EXIT_FAILURE);
        }
    longitud_variable_a_binario(pf_txt_var,pf_bin_var);
    longitud_fija_a_binario(pf_txt_fij,pf_bin_fij);
    fclose(pf_txt_var);
    fclose(pf_txt_fij);
    fclose(pf_bin_var);
    fclose(pf_bin_fij);
    printf("\n\n Se ha creado el archivo binario \"personas_fija.bin\"");
    printf("\n\n Se ha creado el archivo binario \"personas_variable.bin\"");

    //----------------------------------------------------------------------------
    //acá controlo que esté todo funcionando OK

    FILE *pf,*pf2;
    printf("\n\n BIN VAR \n\n");
    pf=fopen("personas_variable.bin","rb");

    if(!pf)
        {
        printf("\n\n No se pudo abrir el archivo \n\n\a\a");
        return 0;
        }
    leer_archivo(&pf);
    printf("\n\n El archivo fue leído correctamente \n\n");
    fclose(pf);

    printf("\n\n BIN FIJ \n\n");

    pf2=fopen("personas_fija.bin","rb");

    if(!pf2)
        {
        printf("\n\n No se pudo abrir el archivo \n\n\a\a");
        return 0;
        }
    leer_archivo(&pf2);
    printf("\n\n El archivo fue leído correctamente \n\n");
    fclose(pf2);


    printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
    }

