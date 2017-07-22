#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\t ORDENAMIENTO DE VECTOR, CON INDIRECCIONES \n");
    int a[TAM],b[TAM],c[TAM],d[TAM];
    printf("\n %c Cargar vector: \n",16);
    cargar_vector(a,TAM);
    printf("\n\n El vector cargado es: \n\n");
    mostrar_vector(a,TAM);
    //copio el vector para tener cuatro copias
    //cada copia la envío a una función diferente para corroborar que todas las funciones ordenan completamente desde cero
    copiar_vector(a,b,TAM);
    copiar_vector(a,c,TAM);
    copiar_vector(a,d,TAM);
    //burbujeo
    printf("\n\n\t Burbujeo orden ascendente: \n\n");
    burbujeo_orden_ascendente(a,TAM);
    mostrar_vector(a,TAM);
    printf("\n\n\t Burbujeo orden descendente: \n\n");
    burbujeo_orden_descendente(b,TAM);
    mostrar_vector(b,TAM);
    //selección
    printf("\n\n\t Selección orden ascendente: \n\n");
    seleccion_orden_ascendente(c,TAM);
    mostrar_vector(c,TAM);
    printf("\n\n\t Selección orden descendente: \n\n");
    seleccion_orden_descendente(d,TAM);
    mostrar_vector(d,TAM);
    printf("\n\n");
    getch();
    return 0;
    }

