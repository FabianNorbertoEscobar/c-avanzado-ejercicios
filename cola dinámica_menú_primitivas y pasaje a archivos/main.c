#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 8B");

    t_cola cola;
    t_dato dato;
    int op,respuesta,bandera,existe_cola=0;

    op=menu();
    system("cls");
    while(op!=0)
        {
        switch(op)
            {

            case 1: if(existe_cola)
                        {
                        printf("\n\n Ya se ha creado una cola. ¿Desea reemplazarla? \a\a");
                        printf("\n 1- SI \t 2- NO \t\t Opción: \t");
                        bandera=0;
                        do
                            {
                            if(bandera==1)
                                printf("\n\n La opción ingresada es incorrecta. Ingrese una opción válida: \t\a\a");
                            scanf("%d",&respuesta);
                            bandera=1;
                            }
                        while(!DATO_VALIDO(respuesta,1,2));
                        if(respuesta==2)
                            {
                            system("cls");
                            printf("\n\n Creación de cola cancelada \a\a");
                            break;
                            }
                        }
                    crear_cola(&cola);
                    existe_cola=1;
                    printf("\n\n Se ha creado una cola \n\a\a");
                    break;

            case 2: if(!existe_cola)
                        {
                        printf("\n\n No se ha creado una cola. No puede acolar.\n\a\a");
                        break;
                        }
                    if(cola_llena(&cola))
                        {
                        printf("\n\n La cola está llena. No puede acolar \n\a\a");
                        break;
                        }
                    cargar_dato(&dato);
                    system("cls");
                    acolar(&cola,&dato);
                    printf("\n\n El dato ha sido acolado exitosamente \n\a\a");
                    break;

            case 3: if(!existe_cola)
                        {
                        printf("\n\n No se ha creado una cola. No puede desacolar.\n\a\a");
                        break;
                        }
                    if(cola_vacia(&cola))
                        {
                        printf("\n\n La cola está vacía. No puede desacolar. \n\a\a");
                        break;
                        }
                    desacolar(&cola,&dato);
                    printf("\n\n El dato fue desacolado exitosamente \n\a\a");
                    mostrar_dato(&dato);
                    break;

            case 4: if(!existe_cola)
                        {
                        printf("\n\n No se ha creado una cola \n\a\a");
                        break;
                        }
                    printf("\n La cola %s está llena \n\a\a",cola_llena(&cola)?"":"no");
                    break;

            case 5: if(!existe_cola)
                        {
                        printf("\n\n No se ha creado una cola.\n\a\a");
                        break;
                        }
                    printf("\n La cola %s está vacía \n\a\a",cola_vacia(&cola)?"":"no");
                    break;

            case 6: if(!existe_cola)
                        {
                        printf("\n\n No se ha creado una cola. No puede ver el primero de la cola.\n\a\a");
                        break;
                        }
                    if(cola_vacia(&cola))
                        {
                        printf("\n\n La cola está vacía. No tiene sentido ver el primero de la cola. \a\a");
                        break;
                        }
                    ver_primero_en_cola(&cola,&dato);
                    printf("\n\n El primero de la cola es: \t %d \n\a\a",dato.numero);
                    break;

            case 7: if(!existe_cola)
                        {
                        printf("\n\n No se ha creado una cola. No puede ver el último de la cola.\n\a\a");
                        break;
                        }
                    if(cola_vacia(&cola))
                        {
                        printf("\n\n La cola está vacía. No tiene sentido ver el último de la cola. \a\a");
                        break;
                        }
                    ver_ultimo_en_cola(&cola,&dato);
                    printf("\n\n El último de la cola es: \t %d \n\a\a",dato.numero);
                    break;

            case 8: if(!existe_cola)
                        {
                        printf("\n\n No se ha creado una cola. No puede vaciar la cola.\n\a\a");
                        break;
                        }
                    if(cola_vacia(&cola))
                        {
                        printf("\n\n La cola está vacía. No tiene sentido vaciarla. \a\a");
                        break;
                        }
                    vaciar_cola(&cola);
                    printf("\n\n La cola ha sido vaciada exitosamente \n\a\a");
                    break;

            case 9: if(!existe_cola)
                        {
                        printf("\n\n No se ha creado una cola. No se la puede borrar. \a\a");
                        break;
                        }
                    existe_cola=0;
                    printf("\n\n La cola fue borrada exitosamente \a\a");
                    break;

            case 10: if(!existe_cola)
                        {
                        printf("\n\n No se ha creado una cola. No se la puede exportar. \a\a");
                        break;
                        }
                    if(cola_vacia(&cola))
                        {
                        printf("\n\n La cola está vacía. No tiene sentido exportarla. \a\a");
                        break;
                        }
                    if(!exportar_cola_a_archivo_bin(&cola))
                        {
                        printf("\n\n Falló la exportación de la cola a archivo binario \a\a");
                        break;
                        }
                    printf("\n\n La cola ha sido exportada a archivo binario exitosamente \a\a");
                    getch();
                    system("cls");
                    printf("\n\n La cola quedó vacía. Si quiere recuperarla puede cargarla desde el archivo. \a\a");
                    break;

            case 11:if(!existe_cola)
                        {
                        printf("\n\n No se ha creado una cola. No se la puede exportar. \a\a");
                        break;
                        }
                    if(cola_vacia(&cola))
                        {
                        printf("\n\n La cola está vacía. No tiene sentido exportarla. \a\a");
                        break;
                        }
                    if(!exportar_cola_a_archivo_txt(&cola))
                        {
                        printf("\n\n Falló la exportación de la cola a archivo de texto \a\a");
                        break;
                        }
                    printf("\n\n La cola ha sido exportada a archivo de texto exitosamente \a\a");
                    getch();
                    system("cls");
                    printf("\n\n La cola quedó vacía. Si quiere recuperarla puede cargarla desde el archivo. \a\a");
                    break;

            case 12:if(existe_cola)
                        {
                        printf("\n\n Ya se ha creado una cola. ¿Desea reemplazarla? \a\a");
                        printf("\n 1- SI \t 2- NO \t\t Opción: \t");
                        bandera=0;
                        do
                            {
                            if(bandera==1)
                                printf("\n\n La opción ingresada es incorrecta. Ingrese una opción válida: \t\a\a");
                            scanf("%d",&respuesta);
                            bandera=1;
                            }
                        while(!DATO_VALIDO(respuesta,1,2));
                        if(respuesta==2)
                            {
                            system("cls");
                            printf("\n\n Carga de cola cancelada \a\a");
                            break;
                            }
                        existe_cola=0;
                        }
                    system("cls");
                    if(!cargar_cola_desde_archivo_bin(&cola))
                        {
                        printf("\n\n Falló la carga de la cola desde archivo binario \a\a");
                        break;
                        }
                    existe_cola=1;
                    printf("\n\n Se ha cargado una cola desde archivo binario exitosamente \n\a\a");
                    break;

            case 13:if(existe_cola)
                        {
                        printf("\n\n Ya se ha creado una cola. ¿Desea reemplazarla? \a\a");
                        printf("\n 1- SI \t 2- NO \t\t Opción: \t");
                        bandera=0;
                        do
                            {
                            if(bandera==1)
                                printf("\n\n La opción ingresada es incorrecta. Ingrese una opción válida: \t\a\a");
                            scanf("%d",&respuesta);
                            bandera=1;
                            }
                        while(!DATO_VALIDO(respuesta,1,2));
                        if(respuesta==2)
                            {
                            system("cls");
                            printf("\n\n Carga de cola cancelada \a\a");
                            break;
                            }
                        existe_cola=0;
                        }
                    system("cls");
                    if(!cargar_cola_desde_archivo_bin(&cola))
                        {
                        printf("\n\n Falló la carga de la cola desde archivo de texto \a\a");
                        break;
                        }
                    existe_cola=1;
                    printf("\n\n Se ha cargado una cola desde archivo de texto exitosamente \n\a\a");
                    break;
            }

        getch();
        system("cls");
        op=menu();
        system("cls");
        }

    printf("\n\n \t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    return 0;
    }
