#include "header.h"

int main()
{
    FILE *pf=NULL;
    t_arbol arbol;
    t_lista lista;
    t_pila pila;

    t_dato_lista dato_anterior;
    t_dato_lista dato_lista;
    int cantidad_pedida=0;

    crear_arbol(&arbol);
    crear_lista(&lista);
    crear_pila(&pila);

    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 5F");

    printf("\n\n\t\t ENCARGO DE PRODUCTOS \a\a\n\n");

    //---------------------------------------------------------------------------------------------------------------------------------------------------

    generar_archivo_de_productos(pf);
    printf("\n\n Se generó el archivo de productos \n");

    generar_indice_del_archivo_en_el_arbol(pf,&arbol,comparar_dato_contra_dato);
    printf("\n\n Se generó el árbol binario de búsqueda, índice del archivo \n");

    generar_lista_de_pedidos(&lista);
    printf("\n\n Se generó la lista de pedidos \n");

    //---------------------------------------------------------------------------------------------------------------------------------------------------

    pf=fopen("PRODUCTO.dat","ab");
    if(!pf)
        exit(EXIT_FAILURE);

    //veo el primer pedido
    ver_primero_de_lista(&lista,&dato_anterior);

    while(!lista_vacia(&lista))
    {
        //leo un pedido
        sacar_primero_de_la_lista(&lista,&dato_lista);

        //comparo el código de producto del pedido actual con el anterior
        if(!comparar_dato_contra_dato(&dato_anterior,&dato_lista))
            cantidad_pedida+=dato_lista.cantidad_pedida;            //si no cambia, sigo acumulando la cantidad pedida
        else
        {
            procesar_pedido_completo(pf,&arbol,&pila,&dato_lista,cantidad_pedida);      // si cambia, entonces proceso el pedido

            //trato al último pedido que fue ingresadop
            dato_anterior=dato_lista;
            cantidad_pedida=dato_lista.cantidad_pedida;
        }
    }

    //proceso el último pedido

    procesar_pedido_completo(pf,&arbol,&pila,&dato_lista,cantidad_pedida);

    //--------------------------------------------------------------------------------------------------------------------------------------------------

    printf("\n\n --->>> Los pedidos fueron realizados exitosamente \n");

    vaciar_arbol(&arbol);
    printf("\n\n El árbol fue vaciado \n");

    printf("\n\n Se ha vaciado la lista de pedidos sin stock \n");

    fclose(pf);
    printf("\n Se ha actualizado el archivo de productos \n");

    printf("\n\n \t\t\t\t\t Fin del programa... \a\a \n\n");
    getch();
    return 0;
}
