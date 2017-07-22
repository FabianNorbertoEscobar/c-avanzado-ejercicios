#include "header.h"

int main()
{
    t_arbol arbol;
    t_dato dato;

    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 6B");

    printf("\n\n \t\t ÁRBOL \n");

    crear_arbol(&arbol);

    dato.numero=50;
    insertar_en_arbol_iterativa(&arbol,&dato,comparar_enteros);
    dato.numero=75;
    insertar_en_arbol_iterativa(&arbol,&dato,comparar_enteros);
    dato.numero=25;
    insertar_en_arbol_iterativa(&arbol,&dato,comparar_enteros);
    dato.numero=12;
    insertar_en_arbol_iterativa(&arbol,&dato,comparar_enteros);
    dato.numero=38;
    insertar_en_arbol_iterativa(&arbol,&dato,comparar_enteros);
    dato.numero=62;
    insertar_en_arbol_iterativa(&arbol,&dato,comparar_enteros);
    dato.numero=88;
    insertar_en_arbol_iterativa(&arbol,&dato,comparar_enteros);
    dato.numero=6;
    insertar_en_arbol_iterativa(&arbol,&dato,comparar_enteros);

    printf("\n Altura del árbol: \t %d \n",calcular_altura(&arbol));

    printf("\n El árbol %s AVL \n",(es_arbol_AVL(&arbol))?"ES":"NO ES");
    printf("\n El árbol %s balanceado \n",(es_arbol_balanceado(&arbol))?"ES":"NO ES");
    printf("\n El árbol %s completo \n",(es_arbol_completo(&arbol))?"ES":"NO ES");

    printf("\n Gráfico del árbol \n\n");
    graficar_arbol(&arbol,mostrar_nodo);

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n \a\a");
    getch();
    return 0;
}
