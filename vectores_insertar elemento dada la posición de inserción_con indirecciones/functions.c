#include "header.h"
int validadato(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
int menu()
    {
    int op,band;
    band=0;
    printf("\n\n\t <<<MENÚ>>> \n");
    printf("\n\t 1-Llenar vector");
    printf("\n\t 2-Mostrar vector");
    printf("\n\t 3-Insertar un elemento en el vector dada la posición de inserción");
    printf("\n\t 4-Salir");
    do
        {
        if(band==1)
            printf("\n La opción ingresada no existe. Preste atención a lo que hace. \n\a\a");
        printf("\n\t\t\t Opción: \t\t");
        scanf("%d",&op);
        band=1;
        }
    while(!validadato(op,1,4));
    return op;
    }
void llenar_vector(int *v,int *prim_lib)
    {
    int i,op,band=0;
    if(*prim_lib!=0)
        {
        printf("\n El vector ya ha sido llenado. Si continúa se borrarán \n los datos del vector. ¿Desea continuar? \n\a\a");
        printf("\n\t 1-SI \n\t 2-NO \n");
        do
            {
            if(band==1)
                printf("\n La opción ingresada no existe. Preste atención a lo que hace. \n\a\a");
            printf("\n\t\t Opción: \t\t");
            scanf("%d",&op);
            band=1;
            }
        while(!validadato(op,1,2));
        if(op==2)
            return;
        *prim_lib=0;
        printf("\n Se han borrado todos los datos del vector \n\n\a\a");
        }
    printf("\n Proceda a la carga del vector \n (cuenta con %d posiciones para almacenar números enteros)\n",TAM);
    for(i=0;i<TAM;i++)
        {
        printf("\n Ingrese el elemento de la posición %d: \n\n\t\t",i+1);
        scanf("%d",v+i);
        *prim_lib+=1;
        if(i!=TAM-1)
            {
            printf("\n ¿Desea seguir ingresando elementos? \n");
            printf("\n\t 1-SI \n\t 2-NO \n");
            band=0;
            do
                {
                if(band==1)
                    printf("\n La opción ingresada no existe. Preste atención a lo que hace. \n\a\a");
                printf("\n\t\t Opción: \t\t");
                scanf("%d",&op);
                band=1;
                }
            while(!validadato(op,1,2));
            if(op==2)
                break;
            }
        }
    printf("\n El vector ha sido cargado exitosamente \n");
    printf("\n Cantidad de posiciones llenas: %d \n ",*prim_lib);
    printf("\n Cantidad de posiciones vacías: %d \n ",TAM-*prim_lib);
    }
void mostrar_vector(int *v,int prim_lib)
    {
    int i;
    if(prim_lib!=0)
        {
        printf("\n POSICIÓN \t CONTENIDO \n");
        for(i=0;i<prim_lib;i++)
            printf("\n %d \t\t %d",i+1,*(v+i));
        printf("\n\n Cantidad de posiciones llenas: %d \n ",prim_lib);
        printf("\n Cantidad de posiciones vacías: %d \n ",TAM-prim_lib);
        }
    else
        printf("\n El vector que quiere mostrar está vacío \n");
    }
void insertar_elemento(int *v,int *prim_lib)
    {
    int op,band=0;
    if(*prim_lib==TAM)
        {
        printf("\n El vector está lleno. Si continúa perderá algún dato.");
        printf("\n ¿Desea continuar? \n");
        printf("\n\t 1-SI \n\t 2-NO \n");
        do
            {
            if(band==1)
                printf("\n La opción ingresada no existe. Preste atención a lo que hace. \n\a\a");
            printf("\n\t\t Opción: \t\t");
            scanf("%d",&op);
            band=1;
            }
        while(!validadato(op,1,2));
        if(op==1)
            {
            printf("\n Al insertar, desplazar datos a la: \n");
            printf("\n\t 1-izquierda \n\t 2-derecha \n");
            band=0;
            do
                {
                if(band==1)
                    printf("\n La opción ingresada no existe. Preste atención a lo que hace. \n\a\a");
                printf("\n\t\t Opción: \t\t");
                scanf("%d",&op);
                band=1;
                }
            while(!validadato(op,1,2));
            if(op==1)
                {
                printf("\n Se perderá el primer elemento: \n");
                insertar_y_desplazar_a_izquierda(v,*prim_lib);
                }
            else
                {
                printf("\n Se perderá el último elemento: \n");
                insertar_y_desplazar_a_derecha(v,*prim_lib);
                }
            }
        else
            return;
        }
    else
        {
        printf("\n El vector no está lleno.");
        if(*prim_lib==0)
            {
            printf("\n\t De hecho, el vector está vacío \n");
            printf("\n Usted puede cargar su primer elemento: \n");
            *prim_lib+=1;
            insertar_y_desplazar_a_derecha(v,*prim_lib);
            return;
            }
        printf("\n Al insertar, desplazar datos a la: \n");
        printf("\n\t 1-izquierda \n\t 2-derecha \n");
        band=0;
        do
            {
            if(band==1)
                printf("\n La opción ingresada no existe. Preste atención a lo que hace. \n\a\a");
            printf("\n\t\t Opción: \t\t");
            scanf("%d",&op);
            band=1;
            }
        while(!validadato(op,1,2));
        band=0;
        if(op==1)
            {
            printf("\n Si continúa perderá el primer elemento. ¿Desea continuar? \n\a\a");
            printf("\n\t 1-SI \n\t 2-NO \n");
            do
                {
                if(band==1)
                    printf("\n La opción ingresada no existe. Preste atención a lo que hace. \n\a\a");
                printf("\n\t\t Opción: \t\t");
                scanf("%d",&op);
                band=1;
                }
            while(!validadato(op,1,2));
            if(op==1)
                {
                printf("\n Se perderá el primer elemento: \n");
                insertar_y_desplazar_a_izquierda(v,*prim_lib);
                }
            else
                return;
            }
        else
            {
            *prim_lib+=1;
            insertar_y_desplazar_a_derecha(v,*prim_lib);
            }
        }
    }
void insertar_y_desplazar_a_izquierda(int *v,int prim_lib)
    {
    int band,pos,nuevo,aux,aux2,i;
    printf("\n Ingrese la posición de inserción \n (1 a %d)",TAM);
    printf("\n (La posición de inserción debe ser menor o igual a %d): \n\n\t\t",prim_lib);
    band=0;
    do
        {
        if(band==1)
            printf("\n La posición ingresada no es correcta. Reingrésela: \n\n\t\t\a\a");
        scanf("%d",&pos);
        band=1;
        }
    while(!validadato(pos,1,TAM)||pos>prim_lib);
    printf("\n Ingrese el elemento a insertar en la posición %d: \n\n\t\t",pos);
    scanf("%d",&nuevo);
    aux=*(v+(pos-1));
    *(v+(pos-1))=nuevo;
    for(i=pos-2;i>=0;i--)
        {
        aux2=*(v+i);
        *(v+i)=aux;
        aux=aux2;
        }
    printf("\n\n El elemento ha sido insertado exitosamente \n\n");
    }
void insertar_y_desplazar_a_derecha(int *v,int prim_lib)
    {
    int band,pos,nuevo,aux,aux2,i;
    printf("\n Ingrese la posición de inserción \n (1 a %d)",TAM);
    printf("\n (La posición de inserción debe ser menor o igual a %d): \n\n\t\t",prim_lib);
    band=0;
    do
        {
        if(band==1)
            printf("\n La posición ingresada no es correcta. Reingrésela: \n\n\t\t\a\a");
        scanf("%d",&pos);
        band=1;
        }
    while(!validadato(pos,1,TAM)||pos>prim_lib);
    printf("\n Ingrese el elemento a insertar en la posición %d: \n\n\t\t",pos);
    scanf("%d",&nuevo);
    aux=*(v+(pos-1));
    *(v+(pos-1))=nuevo;
    for(i=pos;i<prim_lib+1;i++)
        {
        aux2=*(v+i);
        *(v+i)=aux;
        aux=aux2;
        }
    printf("\n\n El elemento ha sido insertado exitosamente \n\n");
    }

