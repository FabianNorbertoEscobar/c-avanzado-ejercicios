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

    printf("\n\n Cargamos elementos al árbol \n");

    dato.numero=50;
    insertar_en_arbol_recursiva(&arbol,&dato,comparar_enteros);
    dato.numero=25;
    insertar_en_arbol_recursiva(&arbol,&dato,comparar_enteros);
    dato.numero=12;
    insertar_en_arbol_recursiva(&arbol,&dato,comparar_enteros);
    dato.numero=40;
    insertar_en_arbol_recursiva(&arbol,&dato,comparar_enteros);
    dato.numero=20;
    insertar_en_arbol_recursiva(&arbol,&dato,comparar_enteros);
    dato.numero=30;
    insertar_en_arbol_recursiva(&arbol,&dato,comparar_enteros);
    dato.numero=18;
    insertar_en_arbol_recursiva(&arbol,&dato,comparar_enteros);
    dato.numero=75;
    insertar_en_arbol_recursiva(&arbol,&dato,comparar_enteros);
    dato.numero=60;
    insertar_en_arbol_recursiva(&arbol,&dato,comparar_enteros);
    dato.numero=90;
    insertar_en_arbol_recursiva(&arbol,&dato,comparar_enteros);
    dato.numero=70;
    insertar_en_arbol_recursiva(&arbol,&dato,comparar_enteros);
    dato.numero=100;
    insertar_en_arbol_recursiva(&arbol,&dato,comparar_enteros);

    printf("\n\n El árbol ha sido cargado \n\n");

    /*
    int i;
    for(i=0;i<12;i++)
    {
        cargar_dato(&dato);
        insertar_en_arbol_recursiva(&arbol,&dato,comparar_enteros);
        //insertar_en_arbol_iterativa(&arbol,&dato,comparar_enteros);
    }
    printf("\n\n El árbol tiene algunos elementos \n");

    FILE *pf;
    pf=fopen("arbol.bin","wb");
    if(!pf)
    {
        printf("\n\n No se pudo crear el archivo. \n Programa evacuado \n\n");
        exit(EXIT_FAILURE);
    }

    grabar_arbol_en_preorden_en_archivo_binario(&arbol,pf);
    fclose(pf);
    printf("\n\n El árbol fue grabado \n\n");

    vaciar_arbol(&arbol);
    printf("\n\n El árbol fue vaciado \n\n");

    pf=fopen("arbol.bin","rb");
    if(!pf)
    {
        printf("\n\n No se pudo leer el archivo \n\n");
        exit(EXIT_FAILURE);
    }

    if(cargar_arbol_en_preorden_desde_archivo_binario(&arbol,pf,comparar_enteros))
        printf("\n\n El árbol fue cargado con el archivo \n\n");
    else
        printf("\n\n El árbol no se pudo cargar \n\n");
    */

    printf("\n\n Recorremos el árbol \n");
    printf("\n\n INORDEN \n\t Notación Infija Usual: \t");
    recorrer_arbol_inorden_recursiva(&arbol,mostrar_nodo);
    printf("\n\n PREORDEN \n\t Notación Polaca: \t\t");
    recorrer_arbol_preorden_recursiva(&arbol,mostrar_nodo);
    printf("\n\n POSORDEN \n\t Notación Polaca Inversa: \t");
    recorrer_arbol_posorden_recursiva(&arbol,mostrar_nodo);


    int nivel=2;

    printf("\n\n CONTAR");

    printf("\n\n Cantidad de nodos: \t %d",contar_nodos(&arbol));
    printf("\n\n Cantidad de hojas: \t %d",contar_hojas(&arbol));
    printf("\n\n Cantidad de no hojas: \t %d",contar_no_hojas(&arbol));

    printf("\n\n Cantidad de nodos con hijos solo por izquierda: \t %d",contar_nodos_con_hijos_solo_por_izquierda(&arbol));
    printf("\n\n Cantidad de nodos con hijos solo por derecha: \t %d",contar_nodos_con_hijos_solo_por_derecha(&arbol));
    printf("\n\n Cantidad de nodos con hijos por izq o der: \t %d",contar_nodos_con_hijos_por_izquierda_o_por_derecha(&arbol));
    printf("\n\n Cantidad de nodos con hijos por izq o der exclusiva: \t %d",contar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(&arbol));
    printf("\n\n Cantidad de nodos con hijos por izq y der: \t %d",contar_nodos_con_hijos_por_izquierda_y_por_derecha(&arbol));

    printf("\n\n Cantidad de nodos del nivel %d: \t %d",nivel,contar_nodos_de_un_nivel(&arbol,nivel));
    printf("\n\n Cantidad de nodos hasta el nivel %d: \t %d",nivel,contar_nodos_hasta_un_nivel(&arbol,nivel));
    printf("\n\n Cantidad de nodos hasta el nivel %d inclusive: \t %d",nivel,contar_nodos_hasta_un_nivel_inclusive(&arbol,nivel));
    printf("\n\n Cantidad de nodos desde el nivel %d: \t %d",nivel,contar_nodos_desde_un_nivel(&arbol,nivel));
    printf("\n\n Cantidad de nodos desde el nivel %d inclusive: \t %d",nivel,contar_nodos_desde_un_nivel_inclusive(&arbol,nivel));


    printf("\n\n MOSTRAR");

    printf("\n\n Mostrar nodos: \n\n");
    mostrar_nodos(&arbol,mostrar_nodo);
    printf("\n\n Mostrar hojas: \n\n");
    mostrar_hojas(&arbol,mostrar_nodo);
    printf("\n\n Mostrar de no hojas \n\n");
    mostrar_no_hojas(&arbol,mostrar_nodo);

    printf("\n\n Mostrar nodos con hijos solo por izquierda \n\n");
    mostrar_nodos_con_hijos_solo_por_izquierda(&arbol,mostrar_nodo);
    printf("\n\n Mostrar nodos con hijos solo por derecha \n\n");
    mostrar_nodos_con_hijos_solo_por_derecha(&arbol,mostrar_nodo);
    printf("\n\n Mostrar nodos con hijos por izq o der \n\n");
    mostrar_nodos_con_hijos_por_izquierda_o_por_derecha(&arbol,mostrar_nodo);
    printf("\n\n Mostrar nodos con hijos por izq o der exclusiva \n\n");
    mostrar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(&arbol,mostrar_nodo);
    printf("\n\n Mostrar nodos con hijos por izq y der \n\n");
    mostrar_nodos_con_hijos_por_izquierda_y_por_derecha(&arbol,mostrar_nodo);

    printf("\n\n Mostrar nodos del nivel %d \n\n",nivel);
    mostrar_nodos_de_un_nivel(&arbol,nivel,mostrar_nodo);
    printf("\n\n Mostrar nodos hasta el nivel %d \n\n",nivel);
    mostrar_nodos_hasta_un_nivel(&arbol,nivel,mostrar_nodo);
    printf("\n\n Mostrar nodos hasta el nivel %d inclusive \n\n",nivel);
    mostrar_nodos_hasta_un_nivel_inclusive(&arbol,nivel,mostrar_nodo);
    printf("\n\n Mostrar nodos desde el nivel %d \n\n",nivel);
    mostrar_nodos_desde_un_nivel(&arbol,nivel,mostrar_nodo);
    printf("\n\n Mostrar nodos desde el nivel %d inclusive \n\n",nivel);
    mostrar_nodos_desde_un_nivel_inclusive(&arbol,nivel,mostrar_nodo);



    printf("\n\n MOSTRAR Y CONTAR \n\n");

    printf("\n\n nodos: \t %d \n\n",mostrar_y_contar_nodos(&arbol,mostrar_nodo));
    printf("\n\n hojas: \t %d \n\n",mostrar_y_contar_hojas(&arbol,mostrar_nodo));
    printf("\n\n no hojas: \t %d \n\n",mostrar_y_contar_no_hojas(&arbol,mostrar_nodo));

    printf("\n\n nodos con hijos solo por izquierda: \t %d \n\n",mostrar_y_contar_nodos_con_hijos_solo_por_izquierda(&arbol,mostrar_nodo));
    printf("\n\n nodos con hijos solo por derecha: \t %d \n\n",mostrar_y_contar_nodos_con_hijos_solo_por_derecha(&arbol,mostrar_nodo));
    printf("\n\n nodos con hijos por izq o der: \t %d \n\n",mostrar_y_contar_nodos_con_hijos_por_izquierda_o_por_derecha(&arbol,mostrar_nodo));
    printf("\n\n nodos con hijos por izq o der exclusiva: \t %d \n\n",mostrar_y_contar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(&arbol,mostrar_nodo));
    printf("\n\n nodos con hijos por izq y der: \t %d \n\n",mostrar_y_contar_nodos_con_hijos_por_izquierda_y_por_derecha(&arbol,mostrar_nodo));

    printf("\n\n nodos del nivel %d: \t %d \n\n",nivel,mostrar_y_contar_nodos_de_un_nivel(&arbol,nivel,mostrar_nodo));
    printf("\n\n nodos hasta el nivel %d: \t %d \n\n",nivel,mostrar_y_contar_nodos_hasta_un_nivel(&arbol,nivel,mostrar_nodo));
    printf("\n\n nodos hasta el nivel %d inclusive: \t %d \n\n",nivel,mostrar_y_contar_nodos_hasta_un_nivel_inclusive(&arbol,nivel,mostrar_nodo));
    printf("\n\n nodos desde el nivel %d: \t %d \n\n",nivel,mostrar_y_contar_nodos_desde_un_nivel(&arbol,nivel,mostrar_nodo));
    printf("\n\n nodos desde el nivel %d inclusive: \t %d \n\n",nivel,mostrar_y_contar_nodos_desde_un_nivel_inclusive(&arbol,nivel,mostrar_nodo));



/*
    printf("\n\n pos podar hojas \n\n");
    podar_hojas(&arbol);
    recorrer_arbol_inorden_recursiva(&arbol,mostrar_nodo);
*/

/*
    printf("\n\n pos podar hasta nivel \n\n");
    podar_hasta_nivel(&arbol,nivel);
    recorrer_arbol_inorden_recursiva(&arbol,mostrar_nodo);
*/
/*
    printf("\n\n pos podar hasta nivel inclusive \n\n");
    podar_hasta_nivel_inclusive(&arbol,nivel);
    recorrer_arbol_inorden_recursiva(&arbol,mostrar_nodo);
*/

//  int altura=2;
/*
    printf("\n\n pos podar hasta altura \n\n");
    podar_hasta_altura(&arbol,altura);
    recorrer_arbol_inorden_recursiva(&arbol,mostrar_nodo);
*/

/*
    printf("\n\n pos podar hasta altura inclusive \n\n");
    podar_hasta_altura_inclusive(&arbol,altura);
    recorrer_arbol_inorden_recursiva(&arbol,mostrar_nodo);
*/

    printf("\n\n Calcular altura: \t %d",calcular_altura(&arbol));
    printf("\n\n Calcular nivel: \t %d",calcular_nivel(&arbol));

    printf("\n\n El árbol %s semibalanceado",arbol_semibalanceado(&arbol)?"es":"no es");
    printf("\n\n El árbol %s balanceado",arbol_balanceado(&arbol)?"es":"no es");

    FILE *pf;
    pf=fopen("arbol.bin","wb");
    if(!pf)
    {
        printf("\n\n No se pudo crear el archivo \n\n");
        exit(EXIT_FAILURE);
    }
    grabar_arbol_en_inorden_en_archivo_binario(&arbol,pf);
    printf("\n\n Archivo grabado \n\n");
    fclose(pf);
    talar_arbol(&arbol);
    printf("\n\n árbol talado \n");

    pf=fopen("arbol.bin","rb");
    if(!pf)
    {
        printf("\n\n No se pudo leer el archivo \n\n");
        exit(EXIT_FAILURE);
    }
    printf("\n\n Archivo abierto \n\n");

    cargar_arbol_en_inorden_desde_archivo_binario_lo_mas_balanceado_posible(&arbol,pf,comparar_enteros);
    printf("\n\n Árbol cargado lo más balanceado posible \n\n");
    recorrer_arbol_preorden_recursiva(&arbol,mostrar_nodo);





    printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
}
