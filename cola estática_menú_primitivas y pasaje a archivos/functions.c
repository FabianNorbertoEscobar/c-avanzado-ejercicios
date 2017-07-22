#include "header.h"

void cargar_dato(t_dato *d)
    {
    printf("\n Ingrese dato a acolar (número): \t\a\a");
    scanf("%d",&d->numero);
    }

void mostrar_dato(t_dato *d)
    {
    printf("\n Dato acolado: \t %d \n",d->numero);
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
        printf("\n\t\t * MENÚ - COLA ESTÁTICA *\a\a");
        printf("\n\t\t ************************");

        printf("\n\n Seleccione una de las siguientes opciones: \n");

        printf("\n 1- Crear cola");
        printf("\n 2- Acolar");
        printf("\n 3- Desacolar");
        printf("\n 4- ¿Cola llena?");
        printf("\n 5- ¿Cola vacía?");
        printf("\n 6- Ver primero en cola");
        printf("\n 7- Ver último en cola");
        printf("\n 8- Vaciar cola");
        printf("\n 9- Borrar cola");
        printf("\n 10- Exportar cola a archivo binario");
        printf("\n 11- Exportar cola a archivo de texto");
        printf("\n 12- Cargar cola desde archivo binario");
        printf("\n 13- Cargar cola desde archivo de texto");
        printf("\n\n 0- SALIR");

        printf("\n\n \t\t\t\t Opción: \t");
        scanf("%d",&op);
        bandera=1;
        }
    while(!DATO_VALIDO(op,0,13));

    return op;
    }

int exportar_cola_a_archivo_bin(t_cola *cola)
    {
    FILE *pf;
    pf=fopen("cola.bin","wb");
    if(!pf)
        return 0;

    t_dato dato;
    t_cola cola_inversa;
    crear_cola(&cola_inversa);

    while(!cola_vacia(cola))
        {
        desacolar(cola,&dato);
        acolar(&cola_inversa,&dato);
        }

    while(!cola_vacia(&cola_inversa))
        {
        desacolar(&cola_inversa,&dato);
        fwrite(&dato,sizeof(t_dato),1,pf);
        }

    fclose(pf);
    return 1;
    }

int exportar_cola_a_archivo_txt(t_cola *cola)
    {
    FILE *pf;
    pf=fopen("cola.txt","wt");
    if(!pf)
        return 0;

    t_dato dato;
    t_cola cola_inversa;
    crear_cola(&cola_inversa);

    while(!cola_vacia(cola))
        {
        desacolar(cola,&dato);
        acolar(&cola_inversa,&dato);
        }

    while(!cola_vacia(&cola_inversa))
        {
        desacolar(&cola_inversa,&dato);
        fprintf(pf,"%d|",dato.numero);
        }

    fclose(pf);
    return 1;
    }

int cargar_cola_desde_archivo_bin(t_cola *cola)
    {
    t_dato dato;
    FILE *pf;
    pf=fopen("cola.bin","rb");
    if(!pf)
        return 0;

    fread(&dato,sizeof(t_dato),1,pf);
    while(!feof(pf))
        {
        acolar(cola,&dato);
        fread(&dato,sizeof(t_dato),1,pf);
        }

    fclose(pf);
    return 1;
    }

int cargar_cola_desde_archivo_txt(t_cola *cola)
    {
    t_dato dato;

    FILE *pf;
    pf=fopen("cola.txt","rt");
    if(!pf)
        return 0;

    fscanf(pf,"%d|",&dato.numero);
    while(!feof(pf))
        {
        acolar(cola,&dato);
        fscanf(pf,"%d|",&dato.numero);
        }

    fclose(pf);
    return 1;
    }
