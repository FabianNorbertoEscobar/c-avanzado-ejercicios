#include "header.h"

int menu(void)
{
    int op,band=0;
    do
    {
        if(band==1)
        {
            system("cls");
            printf("\n\n La opción ingresada es inválida. Elija una opción válida. \n\n\a\a");
            getch();
        }

        system("cls");
        printf("\n \t\t ****************");
        printf("\n \t\t * MENU - ÁRBOL * \a\a");
        printf("\n \t\t **************** \n\n");

        printf("\n Seleccione una de las siguientes opciones: \n");

        printf("\n 1- Crear árbol");
        printf("\n 2- Talar árbol");
        printf("\n 3- Vaciar árbol");
        printf("\n 4- ¿Está vacío el árbol?");
        printf("\n 5- ¿Está lleno el árbol?");
        printf("\n 6- Recorrer árbol");
        printf("\n 7- Insertar en árbol");
        printf("\n 8- Buscar en árbol");
        printf("\n 9- Exportar árbol a archivo");
        printf("\n 10- Cargar árbol desde archivo");
        printf("\n 11- Contar...");
        printf("\n 12- Mostrar...");
        printf("\n 13- Mostrar y contar...");
        printf("\n 14- Podar...");
        printf("\n 15- Calcular nivel");
        printf("\n 16- Calcular altura");
        printf("\n 17- ¿Es semibalanceado el árbol?");
        printf("\n 18- ¿Es balanceado el árbol?");
        printf("\n 19- ¿Es completo el árbol?");
        printf("\n 20- Cargar árbol desde archivo en inorden lo más balanceado posible");
        printf("\n 21- ¿Es hoja?");
        printf("\n 22- Buscar nodo menor");
        printf("\n 23- Buscar nodo mayor");
        printf("\n 24- Eliminar nodo y acomodar ramas");
        printf("\n 25- Árbol gráfico");

        printf("\n\n 0- SALIR");

        printf("\n\n\t\t OPCIÓN: \t");
        fflush(stdin);
        scanf("%d",&op);
        band=1;
    }
    while(!DATO_VALIDO(op,0,25));

    system("cls");
    return op;
}

int recursiva_o_iterativa(void)
{
    int op,band=0;
    do
    {
        if(band==1)
        {
            system("cls");
            printf("\n\n La opción ingresada es inválida. Elija una opción válida. \n\n\a\a");
            getch();
        }

        system("cls");
        printf("\n\n Elija el tipo de función que desea implementar: \n\a\a");
        printf("\n 1- Recursiva \t 2- Iterativa \t Opción: \t");
        fflush(stdin);
        scanf("%d",&op);
        band=1;
    }
    while(!DATO_VALIDO(op,1,2));

    system("cls");
    return op;
}

int submenu_recorrer(void)
{
    int op,band=0;
    do
    {
        if(band==1)
        {
            system("cls");
            printf("\n\n La opción ingresada es inválida. Elija una opción válida. \n\n\a\a");
            getch();
        }

        system("cls");
        printf("\n\n \t\t SUBMENU - RECORRER ÁRBOL \n\a\a");

        printf("\n Seleccione una de las siguientes opciones: \n");

        printf("\n 1- Recorrer el árbol en INORDEN");
        printf("\n 2- Recorrer el árbol en PREORDEN");
        printf("\n 3- Recorrer el árbol en POSORDEN");

        printf("\n\n 0- RETORNAR AL MENU PRINCIPAL");

        printf("\n\n\t\t OPCIÓN: \t");
        fflush(stdin);
        scanf("%d",&op);
        band=1;
    }
    while(!DATO_VALIDO(op,0,3));

    system("cls");
    return op;
}

int binario_o_texto(void)
{
    int op,band=0;
    do
    {
        if(band==1)
        {
            system("cls");
            printf("\n\n La opción ingresada es inválida. Elija una opción válida. \n\n\a\a");
            getch();
        }

        system("cls");
        printf("\n\n Elija el tipo de archivo que desea implementar: \n\a\a");
        printf("\n 1- Binario \t 2- De Texto \t Opción: \t");
        fflush(stdin);
        scanf("%d",&op);
        band=1;
    }
    while(!DATO_VALIDO(op,1,2));

    system("cls");
    return op;
}

int submenu_exportar(void)
{
    int op,band=0;
    do
    {
        if(band==1)
        {
            system("cls");
            printf("\n\n La opción ingresada es inválida. Elija una opción válida. \n\n\a\a");
            getch();
        }

        system("cls");
        printf("\n\n \t\t SUBMENU - EXPORTAR ÁRBOL \n\a\a");

        printf("\n Seleccione una de las siguientes opciones: \n");

        printf("\n 1- Exportar el árbol en INORDEN");
        printf("\n 2- Exportar el árbol en PREORDEN");
        printf("\n 3- Exportar el árbol en POSORDEN");

        printf("\n\n 0- RETORNAR AL MENU PRINCIPAL");

        printf("\n\n\t\t OPCIÓN: \t");
        fflush(stdin);
        scanf("%d",&op);
        band=1;
    }
    while(!DATO_VALIDO(op,0,3));

    system("cls");
    return op;
}

int submenu_contar(void)
{
    int op,band=0;
    do
    {
        if(band==1)
        {
            system("cls");
            printf("\n\n La opción ingresada es inválida. Elija una opción válida \n\n\a\a");
            getch();
        }

        system("cls");
        printf("\n\n \t\t SUBMENÚ - CONTAR \n\a\a");

        printf("\n Seleccione una de las siguientes opciones: \n");

        printf("\n 1- Contar nodos");
        printf("\n 2- Contar hojas");
        printf("\n 3- Contar no hojas");
        printf("\n 4- Contar nodos con hijos solo por izquierda");
        printf("\n 5- Contar nodos con hijos solo por derecha");
        printf("\n 6- Contar nodos con hijos por izquierda o derecha");
        printf("\n 7- Contar nodos con hijos por izquierda o derecha, excluciva");
        printf("\n 8- Contar nodos con hijos por izquierda y por derecha");
        printf("\n 9- Contar nodos de un nivel");
        printf("\n 10- Contar nodos hasta un nivel");
        printf("\n 11- Contar nodos hasta un nivel inclusive");
        printf("\n 12- Contar nodos desde un nivel");
        printf("\n 13- Contar nodos desde un nivel inclusive");

        printf("\n\n 0- RETORNAR AL MENÚ PRINCIPAL");

        printf("\n\n\t\t OPCIÓN: \t");
        fflush(stdin);
        scanf("%d",&op);
        band=1;
    }
    while(!DATO_VALIDO(op,0,13));

    system("cls");
    return op;
}

int submenu_mostrar(void)
{
    int op,band=0;
    do
    {
        if(band==1)
        {
            system("cls");
            printf("\n\n La opción ingresada es inválida. Elija una opción válida \n\n\a\a");
            getch();
        }

        system("cls");
        printf("\n\n \t\t SUBMENÚ - MOSTRAR \n\a\a");

        printf("\n Seleccione una de las siguientes opciones: \n");

        printf("\n 1- Mostrar nodos");
        printf("\n 2- Mostrar hojas");
        printf("\n 3- Mostrar no hojas");
        printf("\n 4- Mostrar nodos con hijos solo por izquierda");
        printf("\n 5- Mostrar nodos con hijos solo por derecha");
        printf("\n 6- Mostrar nodos con hijos por izquierda o derecha");
        printf("\n 7- Mostrar nodos con hijos por izquierda o derecha, excluciva");
        printf("\n 8- Mostrar nodos con hijos por izquierda y por derecha");
        printf("\n 9- Mostrar nodos de un nivel");
        printf("\n 10- Mostrar nodos hasta un nivel");
        printf("\n 11- Mostrar nodos hasta un nivel inclusive");
        printf("\n 12- Mostrar nodos desde un nivel");
        printf("\n 13- Mostrar nodos desde un nivel inclusive");

        printf("\n\n 0- RETORNAR AL MENÚ PRINCIPAL");

        printf("\n\n\t\t OPCIÓN: \t");
        fflush(stdin);
        scanf("%d",&op);
        band=1;
    }
    while(!DATO_VALIDO(op,0,13));

    system("cls");
    return op;
}

int submenu_mostrar_y_contar(void)
{
    int op,band=0;
    do
    {
        if(band==1)
        {
            system("cls");
            printf("\n\n La opción ingresada es inválida. Elija una opción válida \n\n\a\a");
            getch();
        }

        system("cls");
        printf("\n\n \t\t SUBMENÚ - MOSTRAR Y CONTAR \n\a\a");

        printf("\n Seleccione una de las siguientes opciones: \n");

        printf("\n 1- Mostrar y contar nodos");
        printf("\n 2- Mostrar y contar hojas");
        printf("\n 3- Mostrar y contar no hojas");
        printf("\n 4- Mostrar y contar nodos con hijos solo por izquierda");
        printf("\n 5- Mostrar y contar nodos con hijos solo por derecha");
        printf("\n 6- Mostrar y contar nodos con hijos por izquierda o derecha");
        printf("\n 7- Mostrar y contar nodos con hijos por izquierda o derecha, excluciva");
        printf("\n 8- Mostrar y contar nodos con hijos por izquierda y por derecha");
        printf("\n 9- Mostrar y contar nodos de un nivel");
        printf("\n 10- Mostrar y contar nodos hasta un nivel");
        printf("\n 11- Mostrar y contar nodos hasta un nivel inclusive");
        printf("\n 12- Mostrar y contar nodos desde un nivel");
        printf("\n 13- Mostrar y contar nodos desde un nivel inclusive");

        printf("\n\n 0- RETORNAR AL MENÚ PRINCIPAL");

        printf("\n\n\t\t OPCIÓN: \t");
        fflush(stdin);
        scanf("%d",&op);
        band=1;
    }
    while(!DATO_VALIDO(op,0,13));

    system("cls");
    return op;
}

int submenu_podar()
{
    int op,band=0;
    do
    {
        if(band==1)
        {
            system("cls");
            printf("\n\n La opción ingresada es inválida. Elija una opción válida \n\n\a\a");
            getch();
        }

        system("cls");
        printf("\n\n \t\t SUBMENÚ - PODAR \n\a\a");

        printf("\n Seleccione una de las siguientes opciones: \n");

        printf("\n 1- Podar hojas");
        printf("\n 2- Podar hasta nivel");
        printf("\n 3- Podar hasta nivel inclusive");
        printf("\n 4- Podar hasta altura");
        printf("\n 5- Podar hasta altura inclusive");

        printf("\n\n 0- RETORNAR AL MENÚ PRINCIPAL");

        printf("\n\n\t\t OPCIÓN: \t");
        fflush(stdin);
        scanf("%d",&op);
        band=1;
    }
    while(!DATO_VALIDO(op,0,5));

    system("cls");
    return op;
}
