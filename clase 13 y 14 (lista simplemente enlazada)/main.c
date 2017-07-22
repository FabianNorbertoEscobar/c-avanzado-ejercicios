#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n LISTA SIMPLEMENTE ENLAZADA \n\a\a");

    t_lista lista;
    t_dato dato;

    crear_lista(&lista);
    printf("\n Se ha creado una lista \n");

    if(lista_vacia(&lista))
        printf("\n La lista está vacía \n");

    printf("\n Cargamos 3 elementos \n");
    cargar_dato(&dato);
    poner_en_lista_primero(&lista,&dato);
    cargar_dato(&dato);
    poner_en_lista_primero(&lista,&dato);
    cargar_dato(&dato);
    poner_en_lista_primero(&lista,&dato);

    if(lista_llena(&lista))
        printf("\n La lista está llena \n");
    else
        printf("\n La lista no está llena \n");

    printf("\n Sacamos el último \n");
    sacar_de_lista_ultimo(&lista,&dato);
    mostrar_dato(&dato);

    printf("\n Ponemos uno al final \n");
    cargar_dato(&dato);
    poner_en_lista_ultimo(&lista,&dato);

    printf("\n Sacamos el primero de la lista \n");
    sacar_de_lista_primero(&lista,&dato);
    mostrar_dato(&dato);

    printf("\n Insertamos algo por posición \n \t Ingrese posición (por favor: pos>0): \n\n\t");
    int pos;
    scanf("%d",&pos);
    cargar_dato(&dato);
    insertar_en_lista_por_posicion(&lista,&dato,&pos);

    printf("\n Saco de la pila hasta que queda vacía \n");
    while(!lista_vacia(&lista))
        {
        sacar_de_lista_primero(&lista,&dato);
        mostrar_dato(&dato);
        }

    printf("\n La lista quedó vacía \n");

    printf("\n Ingresamos un dato cualquiera: \n");
    cargar_dato(&dato);

    printf("\n Vacío la lista DE UNA \n");
    vaciar_lista(&lista);

    printf("\n\n Ahora voy a enlista los números 3, 6, 8 (en orden) \n");
    dato.numero=3;
    poner_en_lista_ultimo(&lista,&dato);
    dato.numero=6;
    poner_en_lista_ultimo(&lista,&dato);
    dato.numero=8;
    poner_en_lista_ultimo(&lista,&dato);

    printf("\n Ahora voy a ingresar el 6 en orden sin duplicado \n");
    dato.numero=3;
    if(!insertar_en_lista_ordenado_sin_duplicado(&lista,&dato,comparar_datos))
        printf("\n No se pudo insertar ya que el 3 ya está en la lista \n");

    printf("\n Ahora ingreso el 7 sin duplicado \n");
    dato.numero=7;
    if(insertar_en_lista_ordenado_sin_duplicado(&lista,&dato,comparar_datos))
        printf("\n Hecho \n");

    printf("\n Finalmente inserto en orden pero acepto duplicado--> ingreso el 6 \n");
    dato.numero=6;
    if(insertar_en_lista_ordenado_con_duplicado(&lista,&dato,comparar_datos))
        printf("\n Hecho \n");

    printf("\n Saco de la pila hasta que queda vacía \n");
    while(!lista_vacia(&lista))
        {
        sacar_de_lista_primero(&lista,&dato);
        mostrar_dato(&dato);
        }

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n");
    getch();
    return 0;
    }
