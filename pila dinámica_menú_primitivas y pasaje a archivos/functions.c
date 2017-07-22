#include "header.h"

void cargar_dato(t_dato *d)
    {
    printf("\n Ingrese dato a apilar (número): \t\a\a");
    scanf("%d",&d->numero);
    }

void mostrar_dato(t_dato *d)
    {
    printf("\n Dato desapilado: \t %d \n",d->numero);
    }

int menu(void)
    {
    int op,bandera;
    bandera=0;
    do
        {
        if(bandera==1)
            {
            system("cls");
            printf("\n\n La opción ingresada no existe \a\a");
            getch();
            system("cls");
            }

        printf("\n\t\t ************************");
        printf("\n\t\t * MENÚ - PILA DINÁMICA *\a\a");
        printf("\n\t\t ************************");

        printf("\n\n Seleccione una de las siguientes opciones: \n");

        printf("\n 1- Crear pila");
        printf("\n 2- Apilar");
        printf("\n 3- Desapilar");
        printf("\n 4- ¿Pila llena?");
        printf("\n 5- ¿Pila vacía?");
        printf("\n 6- Ver tope");
        printf("\n 7- Vaciar pila");
        printf("\n 8- Borrar pila");
        printf("\n 9- Exportar pila a archivo binario");
        printf("\n 10- Exportar pila a archivo de texto");
        printf("\n 11- Cargar pila desde archivo binario");
        printf("\n 12- Cargar pila desde archivo de texto");
        printf("\n\n 0- SALIR");

        printf("\n\n \t\t\t\t Opción: \t");
        scanf("%d",&op);
        bandera=1;
        }
    while(!DATO_VALIDO(op,0,12));

    return op;
    }

int exportar_pila_a_archivo_bin(t_pila *pila)
    {
    FILE *pf;
    pf=fopen("pila.bin","wb");
    if(!pf)
        return 0;

    t_dato dato;
    t_pila pila_inversa;
    crear_pila(&pila_inversa);

    while(!pila_vacia(pila))
        {
        desapilar(pila,&dato);
        apilar(&pila_inversa,&dato);
        }

    while(!pila_vacia(&pila_inversa))
        {
        desapilar(&pila_inversa,&dato);
        fwrite(&dato,sizeof(t_dato),1,pf);
        }

    fclose(pf);
    return 1;
    }

int exportar_pila_a_archivo_txt(t_pila *pila)
    {
    FILE *pf;
    pf=fopen("pila.txt","wt");
    if(!pf)
        return 0;

    t_dato dato;
    t_pila pila_inversa;
    crear_pila(&pila_inversa);

    while(!pila_vacia(pila))
        {
        desapilar(pila,&dato);
        apilar(&pila_inversa,&dato);
        }

    while(!pila_vacia(&pila_inversa))
        {
        desapilar(&pila_inversa,&dato);
        fprintf(pf,"%d|",dato.numero);
        }

    fclose(pf);
    return 1;
    }

int cargar_pila_desde_archivo_bin(t_pila *pila)
    {
    t_dato dato;
    FILE *pf;
    pf=fopen("pila.bin","rb");
    if(!pf)
        return 0;

    fread(&dato,sizeof(t_dato),1,pf);
    while(!feof(pf))
        {
        apilar(pila,&dato);
        fread(&dato,sizeof(t_dato),1,pf);
        }

    fclose(pf);
    return 1;
    }

int cargar_pila_desde_archivo_txt(t_pila *pila)
    {
    t_dato dato;

    FILE *pf;
    pf=fopen("pila.txt","rt");
    if(!pf)
        return 0;

    fscanf(pf,"%d|",&dato.numero);
    while(!feof(pf))
        {
        apilar(pila,&dato);
        fscanf(pf,"%d|",&dato.numero);
        }

    fclose(pf);
    return 1;
    }
