#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n PRIMITIVAS DE TDA ÍNDICE ESTÁTICO \n\n\a\a");

    t_indice indice;
    t_reg_indice registro;
    char ruta[50];

    ind_crear(&indice);
    printf("\n\n Se ha creado un índice \n");

    int i;
    for(i=0;i<5;i++)
        {
        printf("\n\n Ingrese registro a insertar: \n");
        cargar_registro(&registro);
        if(ind_insertar(&indice,&registro))
            printf("\n\n Registro insertado en orden \n");
        else
            printf("\n\n No se ha podido insertar el registro en orden \n");
        }

    printf("\n\n Ingrese registro a eliminar: \n");
    cargar_registro(&registro);
    if(ind_eliminar(&indice,&registro))
        printf("\n\n Registro eliminado exitosamente \n");
    else
        printf("\n\n No se ha podido eliminar el registro \n");

    printf("\n\n Ingrese registro a buscar: \n");
    cargar_registro(&registro);
    if(ind_buscar(&indice,&registro))
        {
        printf("\n\n Se ha encontrado el registro \n");
        mostrar_registro(&registro);
        }
    else
        printf("\n\n No se ha encontrado el registro \n");

    printf("\n\n Cargar índice desde archivo ordenado \n");
    printf("\n\n Ingrese la ruta del archivo: \n\n\t");
    fflush(stdin);
    gets(ruta);
    if(ind_cargar(&indice,ruta))
        printf("\n\n Se ha cargado el índice desde el archivo exitosamente \n");
    else
        printf("\n\n No se ha podido cargar el índice desde el archivo \n");

    printf("\n\n Grabar registro en archivo binario \n");
    printf("\n\n Ingrese la ruta del archivo: \n\n\t");
    fflush(stdin);
    gets(ruta);
    if(ind_grabar(&indice,ruta))
        printf("\n\n Se ha grabado el índice desde el archivo exitosamente \n");
    else
        printf("\n\n No se ha podido grabar el índice desde el archivo \n");

    printf("\n\n Cargar índice desde archivo ordenado \n");
    printf("\n\n Ingrese la ruta del archivo: \n\n\t");
    fflush(stdin);
    gets(ruta);
    if(ind_cargar(&indice,ruta))
        printf("\n\n Se ha cargado el índice desde el archivo exitosamente \n");
    else
        printf("\n\n No se ha podido cargar el índice desde el archivo \n");

    printf("\n\n Siguiente del índice \n");
    if(ind_siguiente(&indice,&registro))
        {
        printf("\n\n Se ha podido acceder al siguiente del índice \n");
        mostrar_registro(&registro);
        }
    else
        {
        if(ind_fin(&indice))
            printf("\n\n Se ha llegado al fin del índice. \n Para volver a recorrerlo, invoque a la función primero \n");
        else
            printf("\n\n No se ha invocado a la función primero \n");
        }
    getch();

    printf("\n\n Primero del índice \n");
    if(ind_primero(&indice,&registro))
        {
        printf("\n\n Se ha podido acceder al primero del índice \n");
        mostrar_registro(&registro);
        }
    else
        printf("\n\n El índice está vacío \n");
    getch();

    for(i=0;i<6;i++)
        {
        printf("\n\n Siguiente del índice \n");
        if(ind_siguiente(&indice,&registro))
            {
            printf("\n\n Se ha podido acceder al siguiente del índice \n");
            mostrar_registro(&registro);
            }
        else
            {
            if(ind_fin(&indice))
                printf("\n\n Se ha llegado al fin del índice. \n Para volver a recorrerlo, invoque a la función primero \n");
            else
                printf("\n\n No se ha invocado a la función primero \n");
            }
        getch();
        }

    ind_vaciar(&indice);
    printf("\n\n Se ha vaciado el indice \n");

    ind_liberar(&indice);
    printf("\n\n Se ha liberado el índice \n");

    printf("\n\n \t\t\t\t\t Fin del programa.. \n\n\a\a");
    getch();
    return 0;
    }

