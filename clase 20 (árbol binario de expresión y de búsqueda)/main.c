#include "header.h"

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 5F");

    printf("\n\n \t\t ÁRBOL \n\a\a");

    t_arbol arbol;
    t_dato dato;

    crear_arbol(&arbol);
    printf("\n\n Se ha creado un árbol \n");

    if(arbol_vacio(&arbol))
        printf("\n\n El árbol está vacío \n");
    if(!arbol_lleno(&arbol))
        printf("\n\n El árbol no está lleno \n");

    printf("\n\n Cargamos cinco elementos al árbol \n");
    int i;
    for(i=0;i<5;i++)
    {
        cargar_dato(&dato);
        insertar_en_arbol_recursiva(&arbol,&dato,comparar_enteros);
        //insertar_en_arbol_iterativa(&arbol,&dato,comparar_enteros);
    }
    printf("\n\n El árbol tiene algunos elementos \n");

    printf("\n\n Recorremos el árbol \n");
    printf("\n\n INORDEN \n\t Notación Infija Usual: \t");
    recorrer_arbol_inorden_recursiva(&arbol,mostrar_nodo);
    printf("\n\n PREORDEN \n\t Notación Polaca: \t\t");
    recorrer_arbol_preorden_recursiva(&arbol,mostrar_nodo);
    printf("\n\n POSORDEN \n\t Notación Polaca Inversa: \t");
    recorrer_arbol_posorden_recursiva(&arbol,mostrar_nodo);
    /*
    printf("\n\n INORDEN \n\t Notación Infija Usual: \t");
    recorrer_arbol_inorden_iterativa(&arbol,mostrar_nodo);
    printf("\n\n PREORDEN \n\t Notación Polaca: \t");
    recorrer_arbol_preorden_iterativa(&arbol,mostrar_nodo);
    printf("\n\n POSORDEN \n\t Notación Polaca Inversa: \t");
    recorrer_arbol_posorden_iterativa(&arbol,mostrar_nodo);
    */

    FILE *pf_bin_inorden,*pf_bin_preorden,*pf_bin_posorden;
    FILE *pf_txt_inorden,*pf_txt_preorden,*pf_txt_posorden;

    pf_bin_inorden=fopen("arbol_en_inorden.dat","wb");
    if(!pf_bin_inorden)
    {
        printf("\n\n No se pudo crear el archivo binario para el árbol en inorden \n\a\a");
        exit(EXIT_FAILURE);
    }

    pf_bin_preorden=fopen("arbol_en_preorden.dat","wb");
    if(!pf_bin_preorden)
    {
        printf("\n\n No se pudo crear el archivo binario para el árbol en preorden \n\a\a");
        fclose(pf_bin_inorden);
        exit(EXIT_FAILURE);
    }

    pf_bin_posorden=fopen("arbol_en_posorden.dat","wb");
    if(!pf_bin_posorden)
    {
        printf("\n\n No se pudo crear el archivo binario para el árbol en posorden \n\a\a");
        fclose(pf_bin_inorden);
        fclose(pf_bin_preorden);
        exit(EXIT_FAILURE);
    }

    pf_txt_inorden=fopen("arbol_en_inorden.txt","wt");
    if(!pf_txt_inorden)
    {
        printf("\n\n No se pudo crear el archivo de texto para el árbol en inorden \n\a\a");
        fclose(pf_bin_inorden);
        fclose(pf_bin_preorden);
        fclose(pf_bin_posorden);
        exit(EXIT_FAILURE);
    }

    pf_txt_preorden=fopen("arbol_en_preorden.txt","wt");
    if(!pf_txt_preorden)
    {
        printf("\n\n No se pudo crear el archivo de texto para el árbol en preorden \n\a\a");
        fclose(pf_bin_inorden);
        fclose(pf_bin_preorden);
        fclose(pf_bin_posorden);
        fclose(pf_txt_inorden);
        exit(EXIT_FAILURE);
    }

    pf_txt_posorden=fopen("arbol_en_posorden.txt","wt");
    if(!pf_txt_posorden)
    {
        printf("\n\n No se pudo crear el archivo de texto para el árbol en posorden \n\a\a");
        fclose(pf_bin_inorden);
        fclose(pf_bin_preorden);
        fclose(pf_bin_posorden);
        fclose(pf_txt_inorden);
        fclose(pf_txt_preorden);
        exit(EXIT_FAILURE);
    }

    grabar_arbol_en_inorden_en_archivo_binario(&arbol,pf_bin_inorden);
    grabar_arbol_en_preorden_en_archivo_binario(&arbol,pf_bin_preorden);
    grabar_arbol_en_posorden_en_archivo_binario(&arbol,pf_bin_posorden);

    grabar_arbol_en_inorden_en_archivo_de_texto(&arbol,pf_txt_inorden);
    grabar_arbol_en_preorden_en_archivo_de_texto(&arbol,pf_txt_preorden);
    grabar_arbol_en_posorden_en_archivo_de_texto(&arbol,pf_txt_posorden);

    fclose(pf_bin_inorden);
    fclose(pf_bin_preorden);
    fclose(pf_bin_posorden);

    fclose(pf_txt_inorden);
    fclose(pf_txt_preorden);
    fclose(pf_txt_posorden);

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
}
