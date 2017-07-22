#include "header.h"

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n ÁRBOL \n\a\a");

    t_arbol arbol;
    //t_dato dato;

    crear_arbol(&arbol);
    printf("\n Se ha creado un árbol \n");

/*
    if(arbol_vacio(&arbol))
        printf("\n El árbol está vacío \n");

    printf("\n\n Cargar un árbol \n");
    int i;
    for(i=0;i<16;i++)
    {
        cargar_dato(&dato);
        if(!insertar_en_arbol_iterativa(&arbol,&dato,comparar_enteros))
            printf("\n No se pudo insertar el nodo \n");
    }
    printf("\n El árbol fue cargado \n");

    if(arbol_lleno(&arbol))
        printf("\n El árbol no está lleno \n");

    if(!es_hoja(&arbol))
        printf("\n El árbol no es hoja \n");

    printf("\n El árbol %s semibalanceado \n",arbol_semibalanceado(&arbol)?"es":"no es");
    printf("\n El árbol %s balanceado \n",arbol_balanceado(&arbol)?"es":"no es");

    printf("\n\n RECORRER EN INORDEN \n\n Notación Infija Usual: \n");
    recorrer_arbol_en_inorden(&arbol,mostrar_nodo);

    printf("\n\n RECORRER EN PREORDEN \n\n Notación Polaca: \n");
    recorrer_arbol_en_preorden(&arbol,mostrar_nodo);

    printf("\n\n RECORRER EN POSORDEN \n\n Notación Polaca Inversa \n");
    recorrer_arbol_en_posorden(&arbol,mostrar_nodo);

    printf("\n Raíz del árbol \n");
    ver_raiz(&arbol,&dato);
    mostrar_dato(&dato);

    FILE *pf_bin_inorden,*pf_bin_preorden,*pf_bin_posorden;
    FILE *pf_txt_inorden,*pf_txt_preorden,*pf_txt_posorden;

    pf_bin_inorden=fopen("arbol en inorden.bin","wb");
    if(!pf_bin_inorden)
    {
        printf("\n\n No se pudo crear el archivo binario en inorden \n");
        exit(EXIT_FAILURE);
    }

    pf_bin_preorden=fopen("arbol en preorden.bin","wb");
    if(!pf_bin_preorden)
    {
        printf("\n\n No se pudo crear el archivo binario en preorden \n");
        fclose(pf_bin_inorden);
        remove("arbol en inorden.bin");
        exit(EXIT_FAILURE);
    }

    pf_bin_posorden=fopen("arbol en posorden.bin","wb");
    if(!pf_bin_posorden)
    {
        printf("\n\n No se pudo crear el archivo binario en posorden \n");
        fclose(pf_bin_inorden);
        remove("arbol en inorden.bin");
        fclose(pf_bin_preorden);
        remove("arbol en preorden.bin");
        exit(EXIT_FAILURE);
    }

    pf_txt_inorden=fopen("arbol en inorden.txt","wt");
    if(!pf_txt_inorden)
    {
        printf("\n\n No se pudo crear el archivo de texto en inorden \n");
        fclose(pf_bin_inorden);
        remove("arbol en inorden.bin");
        fclose(pf_bin_preorden);
        remove("arbol en preorden.bin");
        fclose(pf_bin_posorden);
        remove("arbol en posorden.bin");
        exit(EXIT_FAILURE);
    }

    pf_txt_preorden=fopen("arbol en preorden.txt","wt");
    if(!pf_txt_preorden)
    {
        printf("\n\n No se pudo crear el archivo de texto en preorden \n");
        fclose(pf_bin_inorden);
        remove("arbol en inorden.bin");
        fclose(pf_bin_preorden);
        remove("arbol en preorden.bin");
        fclose(pf_bin_posorden);
        remove("arbol en posorden.bin");
        fclose(pf_txt_inorden);
        remove("arbol en inorden.txt");
        exit(EXIT_FAILURE);
    }

    pf_txt_posorden=fopen("arbol en posorden.txt","wt");
    if(!pf_txt_posorden)
    {
        printf("\n\n No se pudo crear el archivo de texto en posorden \n");
        fclose(pf_bin_inorden);
        remove("arbol en inorden.bin");
        fclose(pf_bin_preorden);
        remove("arbol en preorden.bin");
        fclose(pf_bin_posorden);
        remove("arbol en posorden.bin");
        fclose(pf_txt_inorden);
        remove("arbol en inorden.txt");
        fclose(pf_txt_preorden);
        remove("arbol en preorden.txt");
        exit(EXIT_FAILURE);
    }

    grabar_arbol_en_inorden_en_archivo_binario(&arbol,pf_bin_inorden);
    printf("\n\n Se ha grabado el árbol en inorden en archivo binario \n");
    grabar_arbol_en_preorden_en_archivo_binario(&arbol,pf_bin_preorden);
    printf("\n\n Se ha grabado el árbol en preorden en archivo binario \n");
    grabar_arbol_en_posorden_en_archivo_binario(&arbol,pf_bin_posorden);
    printf("\n\n Se ha grabado el árbol en posorden en archivo binario \n");
    grabar_arbol_en_inorden_en_archivo_de_texto(&arbol,pf_txt_inorden);
    printf("\n\n Se ha grabado el árbol en inorden en archivo de texto \n");
    grabar_arbol_en_preorden_en_archivo_de_texto(&arbol,pf_txt_preorden);
    printf("\n\n Se ha grabado el árbol en preorden en archivo de texto \n");
    grabar_arbol_en_posorden_en_archivo_de_texto(&arbol,pf_txt_posorden);
    printf("\n\n Se ha grabado el árbol en posorden en archivo de texto \n");

    fclose(pf_bin_inorden);
    fclose(pf_bin_preorden);
    fclose(pf_bin_posorden);
    fclose(pf_txt_inorden);
    fclose(pf_txt_preorden);
    fclose(pf_txt_posorden);

    //--------------------------------------------------------------------------------------------------------------------------------------------------
*/

    FILE *pf;
    pf=fopen("arbol en preorden.bin","rb");
    if(!pf)
    {
        printf("\n\n No se pudo leer el archivo \n");
        exit(EXIT_FAILURE);
    }
    if(cargar_arbol_con_archivo_binario_en_preorden(&arbol,pf,comparar_enteros))
    {
        printf("\n\n Se ha cargado el árbol con el archivo binario en preorden \n");
        fclose(pf);
    }
    else
    {
        printf("\n\n No se pudo cargar el árbol con el archivo \n\n");
        fclose(pf);
        exit(EXIT_FAILURE);
    }

    printf("\n\n RECORRER EN INORDEN \n\n Notación Infija Usual: \n");
    recorrer_arbol_en_inorden(&arbol,mostrar_nodo);

    printf("\n\n RECORRER EN PREORDEN \n\n Notación Polaca: \n");
    recorrer_arbol_en_preorden(&arbol,mostrar_nodo);

    printf("\n\n RECORRER EN POSORDEN \n\n Notación Polaca Inversa \n");
    recorrer_arbol_en_posorden(&arbol,mostrar_nodo);

    vaciar_arbol(&arbol);
    printf("\n\n El árbol fue vaciado \n");
/*
    pf=fopen("arbol en inorden.bin","rb");
    if(!pf)
    {
        printf("\n\n No se pudo leer el archivo \n");
        exit(EXIT_FAILURE);
    }
    if(cargar_arbol_con_archivo_binario_en_inorden_lo_mas_balanceado_posible(&arbol,pf,comparar_enteros))
    {
        printf("\n\n Se ha cargado el árbol con el archivo binario en inorden \n lo más balanceado posible \n");
        fclose(pf);
    }
    else
    {
        printf("\n\n No se pudo cargar el árbol con el archivo \n\n");
        fclose(pf);
        exit(EXIT_FAILURE);
    }

    printf("\n\n RECORRER EN INORDEN \n\n Notación Infija Usual: \n");
    recorrer_arbol_en_inorden(&arbol,mostrar_nodo);

    printf("\n\n RECORRER EN PREORDEN \n\n Notación Polaca: \n");
    recorrer_arbol_en_preorden(&arbol,mostrar_nodo);

    printf("\n\n RECORRER EN POSORDEN \n\n Notación Polaca Inversa \n");
    recorrer_arbol_en_posorden(&arbol,mostrar_nodo);
*/

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n \a\a");
    getch();
    return 0;
}
