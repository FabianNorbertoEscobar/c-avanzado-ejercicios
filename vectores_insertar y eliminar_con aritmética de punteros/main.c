#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int v[TAM]={2,4,6,8};
    int prim_lib=5;
    mostrar_vector(v,prim_lib,TAM);

//    if(insertar_en_posicion(v,&prim_lib,TAM,3,5))
//        printf("\n Se insertó un nuevo elemento \n");
//    else
//        printf("\n No se puede insertar \n");
//    if(!mostrar_vector(v,prim_lib,TAM))
//        printf("\n El vector está vacío \n");

//    if(insertar_en_posicion_hacia_izquierda(v,&prim_lib,TAM,7,4))
//        printf("\n Se insertó un nuevo elemento \n");
//    else
//        printf("\n No se puede insertar \n");
//    if(!mostrar_vector(v,prim_lib,TAM))
//        printf("\n El vector está vacío \n");

//    if(insertar_en_orden(v,&prim_lib,TAM,9))
//        printf("\n Se insertó un nuevo elemento \n");
//    else
//        printf("\n No se puede insertar \n");
//    if(!mostrar_vector(v,prim_lib,TAM))
//        printf("\n El vector está vacío \n");

    if(insertar_en_orden_hacia_izquierda(v,&prim_lib,TAM,2))
        printf("\n Se insertó un nuevo elemento \n");
    else
        printf("\n No se puede insertar \n");
    if(!mostrar_vector(v,prim_lib,TAM))
        printf("\n El vector está vacío \n");

//    if(eliminar_de_posicion(v,&prim_lib,TAM,1))
//        printf("\n Se eliminó un elemento \n");
//    else
//        printf("\n No se puede eliminar \n");
//    if(!mostrar_vector(v,prim_lib,TAM))
//        printf("\n El vector está vacío \n");

//    if(eliminar_primera_aparicion(v,&prim_lib,TAM,2))
//        printf("\n Se eliminó un elemento \n");
//    else
//        printf("\n No se puede eliminar \n");
//    if(!mostrar_vector(v,prim_lib,TAM))
//        printf("\n El vector está vacío \n");

//    if(eliminar_todas_las_apariciones(v,&prim_lib,TAM,4))
//        printf("\n Se eliminaron todas las apariciones del elemento \n");
//    else
//        printf("\n No se puede eliminar \n");
//    if(!mostrar_vector(v,prim_lib,TAM))
//        printf("\n El vector está vacío \n");

    printf("\n %d",prim_lib);
    getch();
    return 0 ;
    }
