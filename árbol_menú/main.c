#include "header.h"

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 5F");

    int op,band,hay_arbol=0,nivel,altura;

    t_arbol arbol;
    t_nodo **padre;
    t_dato dato;
    t_arbol *nodo;

    FILE *pf;
    char path[20];

    op=menu();
    while(op)
    {
        switch(op)
        {
        case 1:
            if(hay_arbol)
            {
                printf("\n\n Ya se ha creado un árbol. Si continúa, lo perderá.\a\a");
                printf("\n\n ¿Desea continuar? \n\n\t 1- Si \t 2-No \t Opción: \t");

                band=0;
                do
                {
                    if(band==1)
                    {
                        system("cls");
                        printf("\n\n La opción ingresada no existe. Ingrese una opción válida: \t\a\a");
                    }
                    scanf("%d",&op);
                }
                while(!DATO_VALIDO(op,1,2));

                system("cls");
                if(op==2)
                {
                    printf("\n\n Creación de árbol abortada \n\a\a");
                    getch();
                    break;
                }

                vaciar_arbol(&arbol);
                hay_arbol=0;
                printf("\n\n El árbol ha sido descartado \n\a\a");
                getch();
                system("cls");
            }

            crear_arbol(&arbol);
            hay_arbol=1;
            printf("\n\n Se ha creado un nuevo árbol exitosamente \n\n\a\a");
            getch();
            break;

        case 2:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No puede talarlo. \n\n\a\a");
                getch();
                break;
            }

            printf("\n\n Si tala el árbol, éste dejará de existir");
            printf("\n\n Además, no se liberará la memoria de los nodos");
            printf("\n\n Se cortará el árbol directamente desde la ráiz");
            printf("\n\n ¿Desea continuar? \n\n\t 1- Si \t 2-No \t Opción: \t\a\a");

            band=0;
            do
            {
                if(band==1)
                {
                    system("cls");
                    printf("\n\n La opción ingresada no existe. Ingrese una opción válida: \t\a\a");
                }
                scanf("%d",&op);
            }
            while(!DATO_VALIDO(op,1,2));

            system("cls");
            if(op==2)
            {
                printf("\n\n Tala de árbol abortada \n\a\a");
                getch();
                break;
            }

            talar_arbol(&arbol);
            hay_arbol=0;
            printf("\n\n Se ha talado el árbol exitosamente \n\n\a\a");
            getch();
            break;

        case 3:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No puede vaciarlo. \n\n\a\a");
                getch();
                break;
            }

            if(arbol_vacio(&arbol))
            {
                printf("\n\n El árbol está vacío. No tiene sentido vaciarlo. \n\n\a\a");
                getch();
                break;
            }

            printf("\n\n Si vacía el árbol, perderá todos sus datos, \a\a");
            printf("\n pero el árbol seguirá existiendo");
            printf("\n\n ¿Desea continuar? \n\n\t 1- Si \t 2-No \t Opción: \t");

            band=0;
            do
            {
                if(band==1)
                {
                    system("cls");
                    printf("\n\n La opción ingresada no existe. Ingrese una opción válida: \t\a\a");
                }
                scanf("%d",&op);
            }
            while(!DATO_VALIDO(op,1,2));

            system("cls");
            if(op==2)
            {
                printf("\n\n Vaciamiento de árbol abortado \n\a\a");
                getch();
                break;
            }

            vaciar_arbol(&arbol);
            printf("\n\n Se ha vaciado el árbol exitosamente \n\n\a\a");
            getch();
            break;

        case 4:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No puede preguntar si está vacío. \n\n\a\a");
                getch();
                break;
            }

            printf("\n\n El árbol %s vacío \n\n\a\a",arbol_vacio(&arbol)?"está":"no está");
            getch();
            break;

        case 5:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No puede preguntar si está lleno. \n\n\a\a");
                getch();
                break;
            }

            printf("\n\n El árbol %s lleno \n\n\a\a",arbol_lleno(&arbol)?"está":"no está");
            getch();
            break;

            break;

        case 6:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No puede recorrerlo. \n\n\a\a");
                getch();
                break;
            }

            if(arbol_vacio(&arbol))
            {
                printf("\n\n El árbol está vacío. No tiene sentido recorrerlo. \n\n\a\a");
                getch();
                break;
            }

            op=submenu_recorrer();
            while(op)
            {
                switch(op)
                {
                case 1:
                    if(recursiva_o_iterativa()==1)
                    {
                        printf("\n\n Notación Infija Usual \n\n\a\a");
                        recorrer_arbol_inorden_recursiva(&arbol,mostrar_nodo);
                    }
                    else
                    {
                        printf("\n\n Notación Infija Usual \n\n\a\a");
                        recorrer_arbol_inorden_iterativa(&arbol,mostrar_nodo);
                    }
                    getch();
                    break;

                case 2:
                    if(recursiva_o_iterativa()==1)
                    {
                        printf("\n\n Notación Polaca \n\n\a\a");
                        recorrer_arbol_preorden_recursiva(&arbol,mostrar_nodo);
                    }
                    else
                    {
                        printf("\n\n Notación Polaca \n\n\a\a");
                        recorrer_arbol_preorden_iterativa(&arbol,mostrar_nodo);
                    }
                    getch();
                    break;

                case 3:
                    if(recursiva_o_iterativa()==1)
                    {
                        printf("\n\n Notación Polaca Inversa \n\n\a\a");
                        recorrer_arbol_posorden_recursiva(&arbol,mostrar_nodo);
                    }
                    else
                    {
                        printf("\n\n Notación Polaca Inversa \n\n\a\a");
                        recorrer_arbol_posorden_iterativa(&arbol,mostrar_nodo);
                    }
                    getch();
                    break;
                }

                op=submenu_recorrer();
            }

            printf("\n\n \t\t SUBMENU ABORTADO \n\a\a");
            getch();
            break;

        case 7:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No puede insertar un dato. \n\n\a\a");
                getch();
                break;
            }

            band=0;
            do
            {
                system("cls");
                printf("\n\n Carga de dato a insertar \n\a\a");
                fflush(stdin);
                cargar_dato(&dato);
                system("cls");

                if(recursiva_o_iterativa()==1)
                {
                    if(insertar_en_arbol_recursiva(&arbol,&dato,comparar_enteros))
                        printf("\n\n Se ha insertado el dato exitosamente \n\n\a\a");
                    else
                        printf("\n\n No se ha logrado concretar la inserción \n\n\a\a");
                }
                else
                {
                    if(insertar_en_arbol_iterativa(&arbol,&dato,comparar_enteros))
                        printf("\n\n Se ha insertado el dato exitosamente \n\n\a\a");
                    else
                        printf("\n\n No se ha logrado concretar la inserción \n\n\a\a");
                }

                getch();
                system("cls");
                printf("\n\n ¿Desea insertar otro dato? \n\n\t 1- Si \t 2-No \t Opción: \t\a\a");

                band=0;
                do
                {
                    if(band==1)
                    {
                        system("cls");
                        printf("\n\n La opción ingresada no existe. Ingrese una opción válida: \t\a\a");
                    }
                    scanf("%d",&op);
                }
                while(!DATO_VALIDO(op,1,2));
            }
            while(op==1);

            system("cls");
            printf("\n\n Inserción finalizada \n\n\a\a");
            getch();
            break;

        case 8:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No puede buscar un dato. \n\n\a\a");
                getch();
                break;
            }

            if(arbol_vacio(&arbol))
            {
                printf("\n\n El árbol está vacío. No tiene sentido buscar algo. \n\n\a\a");
                getch();
                break;
            }

            band=0;
            do
            {
                system("cls");
                printf("\n\n Carga de dato a buscar \n\a\a");
                fflush(stdin);
                cargar_dato(&dato);
                system("cls");

                printf("\n\n Elija el resultado que espera de la búsqueda:\a\a");
                printf("\n 1- Dato encontrado \t 2- Padre del dato buscado \n\n\t\t Opción: \t");
                fflush(stdin);

                band=0;
                do
                {
                    if(band==1)
                    {
                        system("cls");
                        printf("\n\n La opción ingresada no existe. Ingrese una opción válida: \t\a\a");
                    }
                    scanf("%d",&op);
                }
                while(!DATO_VALIDO(op,1,2));

                system("cls");
                if(op==1)
                {
                    if(recursiva_o_iterativa()==1)
                    {
                        if(buscar_en_arbol_recursiva(&arbol,&dato,comparar_enteros))
                        {
                            printf("\n\n El dato ha sido encontrado \a\a");
                            mostrar_dato(&dato);
                        }
                        else
                            printf("\n\n No se ha encontrado el dato \n\n\a\a");
                    }
                    else
                    {
                        if(buscar_en_arbol_iterativa(&arbol,&dato,comparar_enteros))
                        {
                            printf("\n\n El dato ha sido encontrado \a\a");
                            mostrar_dato(&dato);
                        }
                        else
                            printf("\n\n No se ha encontrado el dato \n\n\a\a");
                    }
                }
                else
                {
                    if(recursiva_o_iterativa()==1)
                    {
                        if((padre=buscar_en_arbol_y_retornar_direccion_padre_recursiva(&arbol,&dato,comparar_enteros)))
                        {
                            printf("\n\n El dato ha sido encontrado \a\a");
                            printf("\n\n Padre el dato: \n");
                            mostrar_dato(&(*padre)->dato);
                        }
                        else
                            printf("\n\n No se ha encontrado al padre del dato buscado \n\n\a\a");
                    }
                    else
                    {
                        if((padre=buscar_en_arbol_y_retornar_direccion_padre_iterativa(&arbol,&dato,comparar_enteros)))
                        {
                            printf("\n\n El dato ha sido encontrado \a\a");
                            printf("\n\n Padre del dato: \n");
                            mostrar_dato(&(*padre)->dato);
                        }
                        else
                            printf("\n\n No se ha encontrado al padre del dato buscado \n\n\a\a");
                    }
                }

                getch();
                system("cls");
                printf("\n\n ¿Desea buscar otro dato? \n\n\t 1- Si \t 2-No \t Opción: \t\a\a");

                band=0;
                do
                {
                    if(band==1)
                    {
                        system("cls");
                        printf("\n\n La opción ingresada no existe. Ingrese una opción válida: \t\a\a");
                    }
                    scanf("%d",&op);
                }
                while(!DATO_VALIDO(op,1,2));
            }
            while(op==1);

            system("cls");
            printf("\n\n Búsqueda finalizada \n\n\a\a");
            getch();
            break;

        case 9:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No puede grabarlo en un archivo. \n\n\a\a");
                getch();
                break;
            }

            if(arbol_vacio(&arbol))
            {
                printf("\n\n El árbol está vacío. No tiene sentido grabarlo en un archivo. \n\n\a\a");
                getch();
                break;
            }

            op=submenu_exportar();
            while(op)
            {
                switch(op)
                {
                case 1:
                    if(binario_o_texto()==1)
                    {
                        printf("\n\n Ingrese el path del archivo binario a grabar \n\n\a\a");
                        fflush(stdin);
                        gets(path);
                        system("cls");

                        pf=fopen(path,"wb");
                        if(!pf)
                        {
                            printf("\n\n No se ha podido crear el archivo \"%s\" \a\a",path);
                            printf("\n\n No se puede exportar el árbol \n\n");
                            getch();
                            break;
                        }

                        grabar_arbol_en_inorden_en_archivo_binario(&arbol,pf);
                        fclose(pf);
                        printf("\n\n El árbol fue exportado exitosamente en inorden a binario \n\n\a\a");
                    }
                    else
                    {
                        printf("\n\n Ingrese el path del archivo de texto a grabar \n\n\a\a");
                        fflush(stdin);
                        gets(path);
                        system("cls");

                        pf=fopen(path,"wt");
                        if(!pf)
                        {
                            printf("\n\n No se ha podido crear el archivo \"%s\" \a\a",path);
                            printf("\n\n No se puede exportar el árbol \n\n");
                            getch();
                            break;
                        }

                        grabar_arbol_en_inorden_en_archivo_de_texto(&arbol,pf);
                        fclose(pf);
                        printf("\n\n El árbol fue exportado exitosamente en inorden a texto \n\n\a\a");
                    }
                    getch();
                    break;

                case 2:
                    if(binario_o_texto()==1)
                    {
                        printf("\n\n Ingrese el path del archivo binario a grabar \n\n\a\a");
                        fflush(stdin);
                        gets(path);
                        system("cls");

                        pf=fopen(path,"wb");
                        if(!pf)
                        {
                            printf("\n\n No se ha podido crear el archivo \"%s\" \a\a",path);
                            printf("\n\n No se puede exportar el árbol \n\n");
                            getch();
                            break;
                        }

                        grabar_arbol_en_preorden_en_archivo_binario(&arbol,pf);
                        fclose(pf);
                        printf("\n\n El árbol fue exportado exitosamente en preorden a binario \n\n\a\a");
                    }
                    else
                    {
                        printf("\n\n Ingrese el path del archivo de texto a grabar \n\n\a\a");
                        fflush(stdin);
                        gets(path);
                        system("cls");

                        pf=fopen(path,"wt");
                        if(!pf)
                        {
                            printf("\n\n No se ha podido crear el archivo \"%s\" \a\a",path);
                            printf("\n\n No se puede exportar el árbol \n\n");
                            getch();
                            break;
                        }

                        grabar_arbol_en_preorden_en_archivo_de_texto(&arbol,pf);
                        fclose(pf);
                        printf("\n\n El árbol fue exportado exitosamente en preorden a texto \n\n\a\a");
                    }
                    getch();
                    break;

                case 3:
                    if(binario_o_texto()==1)
                    {
                        printf("\n\n Ingrese el path del archivo binario a grabar \n\n\a\a");
                        fflush(stdin);
                        gets(path);
                        system("cls");

                        pf=fopen(path,"wb");
                        if(!pf)
                        {
                            printf("\n\n No se ha podido crear el archivo \"%s\" \a\a",path);
                            printf("\n\n No se puede exportar el árbol \n\n");
                            getch();
                            break;
                        }

                        grabar_arbol_en_posorden_en_archivo_binario(&arbol,pf);
                        fclose(pf);
                        printf("\n\n El árbol fue exportado exitosamente en posorden a binario \n\n\a\a");
                    }
                    else
                    {
                        printf("\n\n Ingrese el path del archivo de texto a grabar \n\n\a\a");
                        fflush(stdin);
                        gets(path);
                        system("cls");

                        pf=fopen(path,"wt");
                        if(!pf)
                        {
                            printf("\n\n No se ha podido crear el archivo \"%s\" \a\a",path);
                            printf("\n\n No se puede exportar el árbol \n\n");
                            getch();
                            break;
                        }

                        grabar_arbol_en_posorden_en_archivo_de_texto(&arbol,pf);
                        fclose(pf);
                        printf("\n\n El árbol fue exportado exitosamente en posorden a texto \n\n\a\a");
                    }
                    getch();
                    break;
                }

                op=submenu_exportar();
            }

            printf("\n\n \t\t SUBMENU ABORTADO \n\a\a");
            getch();
            break;

        case 10:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No puede cargarlo. \n\n\a\a");
                getch();
                break;
            }

            if(!arbol_vacio(&arbol))
            {
                printf("\n\n Ya se ha cargado un árbol. Si continúa, lo perderá.\a\a");
                printf("\n\n ¿Desea continuar? \n\n\t 1- Si \t 2-No \t Opción: \t");

                band=0;
                do
                {
                    if(band==1)
                    {
                        system("cls");
                        printf("\n\n La opción ingresada no existe. Ingrese una opción válida: \t\a\a");
                    }
                    scanf("%d",&op);
                }
                while(!DATO_VALIDO(op,1,2));

                system("cls");
                if(op==2)
                {
                    printf("\n\n Carga de árbol abortada \n\a\a");
                    getch();
                    break;
                }

                vaciar_arbol(&arbol);
                hay_arbol=0;
                printf("\n\n El árbol ha sido descartado \n\a\a");
                getch();
                system("cls");
            }

            printf("\n\n Ingrese el recorrido en el que fue grabado el árbol a levantar:\a\a");
            printf("\n 1- Preorden \t 2- Posorden \n\n\t\t Opción: \t");
            fflush(stdin);

            band=0;
            do
            {
                if(band==1)
                {
                    system("cls");
                    printf("\n\n La opción ingresada no existe. Ingrese una opción válida: \t\a\a");
                }
                scanf("%d",&op);
            }
            while(!DATO_VALIDO(op,1,2));

            system("cls");
            if(op==1)
            {
                if(binario_o_texto()==1)
                {
                    printf("\n\n Ingrese el path del archivo binario a levantar \n\n\a\a");
                    fflush(stdin);
                    gets(path);
                    system("cls");

                    pf=fopen(path,"rb");
                    if(!pf)
                    {
                        printf("\n\n No se ha podido leer el archivo \"%s\" \a\a",path);
                        printf("\n\n No se puede cargar el árbol \n\n");
                        getch();
                        break;
                    }

                    if(cargar_arbol_en_preorden_desde_archivo_binario(&arbol,pf,comparar_enteros))
                        printf("\n\n El árbol fue cargado exitosamente en preorden desde binario \n\n\a\a");
                    else
                    {
                        printf("\n\n No se pudo cargar el árbol \n\n\a\a");
                        break;
                    }
                    fclose(pf);
                }
                else
                {
                    printf("\n\n Ingrese el path del archivo de texto a levantar \n\n\a\a");
                    fflush(stdin);
                    gets(path);
                    system("cls");

                    pf=fopen(path,"rt");
                    if(!pf)
                    {
                        printf("\n\n No se ha podido leer el archivo \"%s\" \a\a",path);
                        printf("\n\n No se puede cargar el árbol \n\n");
                        getch();
                        break;
                    }

                    if(cargar_arbol_en_preorden_desde_archivo_de_texto(&arbol,pf,comparar_enteros))
                        printf("\n\n El árbol fue cargado exitosamente en preorden desde texto \n\n\a\a");
                    else
                    {
                        printf("\n\n No se pudo cargar el árbol \n\n\a\a");
                        break;
                    }
                    fclose(pf);
                }
            }
            else
            {
                if(binario_o_texto()==1)
                {
                    printf("\n\n Ingrese el path del archivo binario a levantar \n\n\a\a");
                    fflush(stdin);
                    gets(path);
                    system("cls");

                    pf=fopen(path,"rb");
                    if(!pf)
                    {
                        printf("\n\n No se ha podido leer el archivo \"%s\" \a\a",path);
                        printf("\n\n No se puede cargar el árbol \n\n");
                        getch();
                        break;
                    }

                    if(cargar_arbol_en_posorden_desde_archivo_binario(&arbol,pf,comparar_enteros))
                        printf("\n\n El árbol fue cargado exitosamente en posorden desde binario \n\n\a\a");
                    else
                    {
                        printf("\n\n No se pudo cargar el árbol \n\n\a\a");
                        break;
                    }
                    fclose(pf);
                }
                else
                {
                    printf("\n\n Ingrese el path del archivo de texto a levantar \n\n\a\a");
                    fflush(stdin);
                    gets(path);
                    system("cls");

                    pf=fopen(path,"rt");
                    if(!pf)
                    {
                        printf("\n\n No se ha podido leer el archivo \"%s\" \a\a",path);
                        printf("\n\n No se puede cargar el árbol \n\n");
                        getch();
                        break;
                    }

                    if(cargar_arbol_en_posorden_desde_archivo_de_texto(&arbol,pf,comparar_enteros))
                        printf("\n\n El árbol fue cargado exitosamente en posorden desde texto \n\n\a\a");
                    else
                    {
                        printf("\n\n No se pudo cargar el árbol \n\n\a\a");
                        break;
                    }
                    fclose(pf);
                }
            }

            hay_arbol=1;
            getch();
            break;

        case 11:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No puede contar. \n\n\a\a");
                getch();
                break;
            }

            op=submenu_contar();
            while(op)
            {
                switch(op)
                {
                case 1:
                    printf("\n\n Cantidad de nodos: \t %d \n\n\a\a",contar_nodos(&arbol));
                    break;

                case 2:
                    printf("\n\n Cantidad de hojas: \t %d \n\n\a\a",contar_hojas(&arbol));
                    break;

                case 3:
                    printf("\n\n Cantidad de no hojas: \t %d \n\n\a\a",contar_no_hojas(&arbol));
                    break;

                case 4:
                    printf("\n\n Cantidad de nodos con hijos solo por izquierda: \t %d \n\n\a\a",contar_nodos_con_hijos_solo_por_izquierda(&arbol));
                    break;

                case 5:
                    printf("\n\n Cantidad de nodos con hijos solo por derecha: \t %d \n\n\a\a",contar_nodos_con_hijos_solo_por_derecha(&arbol));
                    break;

                case 6:
                    printf("\n\n Cantidad de nodos con hijos por izquierda o por derecha: \t %d \n\n\a\a",contar_nodos_con_hijos_por_izquierda_o_por_derecha(&arbol));
                    break;

                case 7:
                    printf("\n\n Cantidad de nodos con hijos por izquierda o por derecha, exclusiva: \t %d \n\n\a\a",contar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(&arbol));
                    break;

                case 8:
                    printf("\n\n Cantidad de nodos con hijos por izquierda y por derecha: \t %d \n\n\a\a",contar_nodos_con_hijos_por_izquierda_y_por_derecha(&arbol));
                    break;

                case 9:
                    nivel=ingresa_nivel();
                    printf("\n\n Cantidad de nodos del nivel %d: \t %d \n\n\a\a",nivel,contar_nodos_de_un_nivel(&arbol,nivel));
                    break;

                case 10:
                    nivel=ingresa_nivel();
                    printf("\n\n Cantidad de nodos hasta el nivel %d: \t %d \n\n\a\a",nivel,contar_nodos_hasta_un_nivel(&arbol,nivel));
                    break;

                case 11:
                    nivel=ingresa_nivel();
                    printf("\n\n Cantidad de nodos hasta el nivel %d inclusive: \t %d \n\n\a\a",nivel,contar_nodos_hasta_un_nivel_inclusive(&arbol,nivel));
                    break;

                case 12:
                    nivel=ingresa_nivel();
                    printf("\n\n Cantidad de nodos desde el nivel %d: \t %d \n\n\a\a",nivel,contar_nodos_desde_un_nivel_inclusive(&arbol,nivel));
                    break;

                case 13:
                    nivel=ingresa_nivel();
                    printf("\n\n Cantidad de nodos desde el nivel %d inclusive: \t %d \n\n\a\a",nivel,contar_nodos_desde_un_nivel_inclusive(&arbol,nivel));
                    break;
                }

                getch();
                op=submenu_contar();
            }

            printf("\n\n \t\t SUBMENU ABORTADO \n\a\a");
            getch();
            break;

        case 12:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No puede mostrar. \n\n\a\a");
                getch();
                break;
            }

            op=submenu_mostrar();
            while(op)
            {
                switch(op)
                {
                case 1:
                    printf("\n\n Nodos \n\n\a\a");
                    mostrar_nodos(&arbol,mostrar_nodo);
                    break;

                case 2:
                    printf("\n\n Hojas \n\n\a\a");
                    mostrar_hojas(&arbol,mostrar_nodo);
                    break;

                case 3:
                    printf("\n\n No hojas \n\n\a\a");
                    mostrar_no_hojas(&arbol,mostrar_nodo);
                    break;

                case 4:
                    printf("\n\n Nodos con hijos solo por izquierda \n\n\a\a");
                    mostrar_nodos_con_hijos_solo_por_izquierda(&arbol,mostrar_nodo);
                    break;

                case 5:
                    printf("\n\n Nodos con hijos solo por derecha \n\n\a\a");
                    mostrar_nodos_con_hijos_solo_por_derecha(&arbol,mostrar_nodo);
                    break;

                case 6:
                    printf("\n\n Nodos con hijos por izquierda o por derecha \n\n\a\a");
                    mostrar_nodos_con_hijos_por_izquierda_o_por_derecha(&arbol,mostrar_nodo);
                    break;

                case 7:
                    printf("\n\n Nodos con hijos por izquierda o por derecha, exclusiva \n\n\a\a");
                    mostrar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(&arbol,mostrar_nodo);
                    break;

                case 8:
                    printf("\n\n Nodos con hijos por izquierda y por derecha \n\n\a\a");
                    mostrar_nodos_con_hijos_por_izquierda_y_por_derecha(&arbol,mostrar_nodo);
                    break;

                case 9:
                    nivel=ingresa_nivel();
                    printf("\n\n Nodos del nivel %d \n\n\a\a",nivel);
                    mostrar_nodos_de_un_nivel(&arbol,nivel,mostrar_nodo);
                    break;

                case 10:
                    nivel=ingresa_nivel();
                    printf("\n\n Nodos hasta el nivel %d \n\n\a\a",nivel);
                    mostrar_nodos_hasta_un_nivel(&arbol,nivel,mostrar_nodo);
                    break;

                case 11:
                    nivel=ingresa_nivel();
                    printf("\n\n Nodos hasta el nivel %d inclusive \n\n\a\a",nivel);
                    mostrar_nodos_hasta_un_nivel_inclusive(&arbol,nivel,mostrar_nodo);
                    break;

                case 12:
                    nivel=ingresa_nivel();
                    printf("\n\n Nodos desde el nivel %d \n\n\a\a",nivel);
                    mostrar_nodos_desde_un_nivel(&arbol,nivel,mostrar_nodo);
                    break;

                case 13:
                    nivel=ingresa_nivel();
                    printf("\n\n Nodos desde el nivel %d inclusive \n\n\a\a",nivel);
                    mostrar_nodos_desde_un_nivel_inclusive(&arbol,nivel,mostrar_nodo);
                    break;
                }

                getch();
                op=submenu_mostrar();
            }

            printf("\n\n \t\t SUBMENU ABORTADO \n\a\a");
            getch();
            break;

        case 13:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No puede mostrar y contar. \n\n\a\a");
                getch();
                break;
            }

            op=submenu_mostrar_y_contar();
            while(op)
            {
                switch(op)
                {
                case 1:
                    printf("\n\n Nodos \n\n\a\a");
                    printf("\n\n Cantidad de nodos: \t %d \n\n",mostrar_y_contar_nodos(&arbol,mostrar_nodo));
                    break;

                case 2:
                    printf("\n\n Hojas \n\n\a\a");
                    printf("\n\n Cantidad de hojas: \t %d \n\n",mostrar_y_contar_hojas(&arbol,mostrar_nodo));
                    break;

                case 3:
                    printf("\n\n No hojas \n\n\a\a");
                    printf("\n\n Cantidad de no hojas: \t %d \n\n",mostrar_y_contar_no_hojas(&arbol,mostrar_nodo));
                    break;

                case 4:
                    printf("\n\n Nodos con hijos solo por izquierda \n\n\a\a");
                    printf("\n\n Cantidad de nodos con hijos solo por izquierda: \t %d \n\n",mostrar_y_contar_nodos_con_hijos_solo_por_izquierda(&arbol,mostrar_nodo));
                    break;

                case 5:
                    printf("\n\n Nodos con hijos solo por derecha \n\n\a\a");
                    printf("\n\n Cantidad de nodos con hijos solo por derecha: \t %d \n\n",mostrar_y_contar_nodos_con_hijos_solo_por_derecha(&arbol,mostrar_nodo));
                    break;

                case 6:
                    printf("\n\n Nodos con hijos por izquierda o por derecha \n\n\a\a");
                    printf("\n\n Cantidad de nodos con hijos por izquierda o por derecha: \t %d \n\n",mostrar_y_contar_nodos_con_hijos_por_izquierda_o_por_derecha(&arbol,mostrar_nodo));
                    break;

                case 7:
                    printf("\n\n Nodos con hijos por izquierda o por derecha, exclusiva \n\n\a\a");
                    printf("\n\n Cantidad de nodos con hijos por izquierda o por derecha, exclusiva: \t %d \n\n",mostrar_y_contar_nodos_con_hijos_por_izquierda_o_por_derecha_exclusiva(&arbol,mostrar_nodo));
                    break;

                case 8:
                    printf("\n\n Nodos con hijos por izquierda y por derecha \n\n\a\a");
                    printf("\n\n Cantidad de nodos con hijos por izquierda y por derecha: \t %d \n\n",mostrar_y_contar_nodos_con_hijos_por_izquierda_y_por_derecha(&arbol,mostrar_nodo));
                    break;

                case 9:
                    nivel=ingresa_nivel();
                    printf("\n\n Nodos del nivel %d \n\n\a\a",nivel);
                    printf("\n\n Cantidad de nodos del nivel %d: \t %d \n\n",nivel,mostrar_y_contar_nodos_de_un_nivel(&arbol,nivel,mostrar_nodo));
                    break;

                case 10:
                    nivel=ingresa_nivel();
                    printf("\n\n Nodos hasta el nivel %d \n\n\a\a",nivel);
                    printf("\n\n Cantidad de nodos hasta el nivel %d: \t %d \n\n",nivel,mostrar_y_contar_nodos_hasta_un_nivel(&arbol,nivel,mostrar_nodo));
                    break;

                case 11:
                    nivel=ingresa_nivel();
                    printf("\n\n Nodos hasta el nivel %d inclusive \n\n\a\a",nivel);
                    printf("\n\n Cantidad de nodos hasta el nivel %d inclusive: \t %d \n\n",nivel,mostrar_y_contar_nodos_hasta_un_nivel_inclusive(&arbol,nivel,mostrar_nodo));
                    break;

                case 12:
                    nivel=ingresa_nivel();
                    printf("\n\n Nodos desde el nivel %d \n\n\a\a",nivel);
                    printf("\n\n Cantidad de nodos desde el nivel %d: \t %d \n\n",nivel,mostrar_y_contar_nodos_desde_un_nivel_inclusive(&arbol,nivel,mostrar_nodo));
                    break;

                case 13:
                    nivel=ingresa_nivel();
                    printf("\n\n Nodos desde el nivel %d inclusive \n\n\a\a",nivel);
                    printf("\n\n Cantidad de nodos desde el nivel %d inclusive: \t %d \n\n",nivel,mostrar_y_contar_nodos_desde_un_nivel_inclusive(&arbol,nivel,mostrar_nodo));
                    break;
                }

                getch();
                op=submenu_mostrar_y_contar();
            }

            printf("\n\n \t\t SUBMENU ABORTADO \n\a\a");
            getch();
            break;

        case 14:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No puede podar. \n\n\a\a");
                getch();
                break;
            }

            op=submenu_podar();
            while(op)
            {
                switch(op)
                {
                case 1:
                    podar_hojas(&arbol);
                    printf("\n\n Se han podado las hojas exitosamente \n\a\a");
                    break;

                case 2:
                    nivel=ingresa_nivel();
                    podar_hasta_nivel(&arbol,nivel);
                    printf("\n\n Se ha podado el árbol hasta el nivel %d \n\a\a",nivel);
                    break;

                case 3:
                    nivel=ingresa_nivel();
                    podar_hasta_nivel_inclusive(&arbol,nivel);
                    printf("\n\n Se ha podado el árbol hasta el nivel %d inclusive \n\a\a",nivel);
                    break;

                case 4:
                    altura=ingresa_altura();
                    podar_hasta_altura(&arbol,altura);
                    printf("\n\n Se ha podado el árbol hasta la altura %d \n\a\a",altura);
                    break;

                case 5:
                    altura=ingresa_altura();
                    podar_hasta_altura_inclusive(&arbol,altura);
                    printf("\n\n Se ha podado el árbol hasta la altura %d inclusive \n\a\a",altura);
                    break;
                }

                getch();
                op=submenu_podar();
            }

            printf("\n\n \t\t SUBMENU ABORTADO \n\a\a");
            getch();
            break;

        case 15:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No se puede calcular el nivel. \n\n\a\a");
                getch();
                break;
            }

            printf("\n\n Nivel del árbol: \t %d \n\n\a\a",calcular_nivel(&arbol));
            getch();
            break;

        case 16:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No se puede calcular el altura. \n\n\a\a");
                getch();
                break;
            }

            printf("\n\n Altura del árbol: \t %d \n\n\a\a",calcular_altura(&arbol));
            getch();
            break;

        case 17:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No puede preguntar si es semibalanceado. \n\n\a\a");
                getch();
                break;
            }

            printf("\n\n El árbol %s semibalanceado \n\n\a\a",arbol_semibalanceado(&arbol)?"es":"no es");
            getch();
            break;

        case 18:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No puede preguntar si es balanceado. \n\n\a\a");
                getch();
                break;
            }

            printf("\n\n El árbol %s balanceado \n\n\a\a",arbol_balanceado(&arbol)?"es":"no es");
            getch();
            break;

        case 19:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No puede preguntar si es completo. \n\n\a\a");
                getch();
                break;
            }

            printf("\n\n El árbol %s completo \n\n\a\a",arbol_completo(&arbol)?"es":"no es");
            getch();
            break;

        case 20:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No puede cargarlo. \n\n\a\a");
                getch();
                break;
            }

            if(!arbol_vacio(&arbol))
            {
                printf("\n\n Ya se ha cargado un árbol. Si continúa, lo perderá.\a\a");
                printf("\n\n ¿Desea continuar? \n\n\t 1- Si \t 2-No \t Opción: \t");

                band=0;
                do
                {
                    if(band==1)
                    {
                        system("cls");
                        printf("\n\n La opción ingresada no existe. Ingrese una opción válida: \t\a\a");
                    }
                    scanf("%d",&op);
                }
                while(!DATO_VALIDO(op,1,2));

                system("cls");
                if(op==2)
                {
                    printf("\n\n Carga de árbol abortada \n\a\a");
                    getch();
                    break;
                }

                vaciar_arbol(&arbol);
                hay_arbol=0;
                printf("\n\n El árbol ha sido descartado \n\a\a");
                getch();
            }

            system("cls");
            printf("\n\n Ingrese el path del archivo binario en inorden a levantar \n\n\a\a");
            fflush(stdin);
            gets(path);
            system("cls");

            pf=fopen(path,"rb");
            if(!pf)
            {
                printf("\n\n No se ha podido leer el archivo \"%s\" \a\a",path);
                printf("\n\n No se puede cargar el árbol \n\n");
                getch();
                break;
            }

            if(cargar_arbol_en_inorden_desde_archivo_binario_lo_mas_balanceado_posible(&arbol,pf,comparar_enteros))
                printf("\n\n El árbol fue cargado desde inorden lo más balanceado posible \n\n\a\a");
            else
            {
                printf("\n\n No se pudo cargar el árbol \n\n\a\a");
                break;
            }
            fclose(pf);
            hay_arbol=1;
            getch();
            break;

        case 21:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No se tiene sentido ver si es hoja. \n\n\a\a");
                getch();
                break;
            }

            if(arbol_vacio(&arbol))
            {
                printf("\n\n El árbol está vacío. No tiene sentido ver si es hoja. \n\n\a\a");
                getch();
                break;
            }

            printf("\n\n El árbol %s una hoja \n\n\a\a",hoja(&arbol)?"es":"no es");
            getch();
            break;

        case 22:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No se puede buscar el nodo menor. \n\n\a\a");
                getch();
                break;
            }

            if((nodo=buscar_nodo_menor(&arbol)))
            {
                printf("\n\n El nodo menor es: \a\a");
                mostrar_dato(&(*nodo)->dato);
            }
            else
                printf("\n\n El árbol está vacío. No hay nodo menor \n\n\a\a");
            getch();
            break;

        case 23:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No se puede buscar el nodo mayor. \n\n\a\a");
                getch();
                break;
            }

            if((nodo=buscar_nodo_mayor(&arbol)))
            {
                printf("\n\n El nodo mayor es: \a\a");
                mostrar_dato(&(*nodo)->dato);
            }
            else
                printf("\n\n El árbol está vacío. No hay nodo mayor \n\n\a\a");
            getch();
            break;

        case 24:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No se puede eliminar un nodo. \n\n\a\a");
                getch();
                break;
            }

            if(arbol_vacio(&arbol))
            {
                printf("\n\n El árbol está vacío. No tiene sentido eliminar un nodo. \n\n\a\a");
                getch();
                break;
            }

            printf("\n\n Carga de dato a eliminar \n\a\a");
            fflush(stdin);
            cargar_dato(&dato);
            system("cls");

            if(recursiva_o_iterativa()==1)
            {
                if(eliminar_nodo_y_acomodar_ramas_recursiva(&arbol,&dato,comparar_enteros))
                    printf("\n\n El nodo fue eliminado y sus ramas fueron acomodadas \n\n\a\a");
                else
                    printf("\n\n No se ha encontrado el dato a eliminar \n\n\a\a");
            }
            else
            {
                if(eliminar_nodo_y_acomodar_ramas_iterativa(&arbol,&dato,comparar_enteros))
                    printf("\n\n El nodo fue eliminado y sus ramas fueron acomodadas \n\n\a\a");
                else
                    printf("\n\n No se ha encontrado el dato a eliminar \n\n\a\a");
            }
            getch();
            break;

        case 25:
            if(hay_arbol==0)
            {
                printf("\n\n No se ha creado un árbol. No se puede graficar el árbol. \n\n\a\a");
                getch();
                break;
            }

            if(arbol_vacio(&arbol))
            {
                printf("\n\n El árbol está vacío. No tiene sentido graficar el árbol. \n\n\a\a");
                getch();
                break;
            }

            printf("\n\n Árbol gráfico \n\n\a\a");
            arbol_grafico(&arbol,mostrar_nodo);

            getch();
            break;
        }

        op=menu();
    }
    printf("\n\n \t\t MENU ABORTADO \n\a\a");
    getch();
    printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
}
