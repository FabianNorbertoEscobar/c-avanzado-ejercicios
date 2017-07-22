#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    system("COLOR 8B");

    t_pila pila;
    t_dato dato;
    int op,respuesta,bandera,existe_pila=0;

    op=menu();
    system("cls");
    while(op!=0)
        {
        switch(op)
            {

            case 1: if(existe_pila)
                        {
                        printf("\n\n Ya se ha creado una pila. ¿Desea reemplazarla? \a\a");
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
                            printf("\n\n Creación de pila cancelada \a\a");
                            break;
                            }
                        }
                    crear_pila(&pila);
                    existe_pila=1;
                    printf("\n\n Se ha creado una pila \n\a\a");
                    break;

            case 2: if(!existe_pila)
                        {
                        printf("\n\n No se ha creado una pila. No puede apilar.\n\a\a");
                        break;
                        }
                    if(pila_llena(&pila))
                        {
                        printf("\n\n La pila está llena. No puede apilar \n\a\a");
                        break;
                        }
                    cargar_dato(&dato);
                    system("cls");
                    apilar(&pila,&dato);
                    printf("\n\n El dato ha sido apilado exitosamente \n\a\a");
                    break;

            case 3: if(!existe_pila)
                        {
                        printf("\n\n No se ha creado una pila. No puede desapilar.\n\a\a");
                        break;
                        }
                    if(pila_vacia(&pila))
                        {
                        printf("\n\n La pila está vacía. No puede desapilar. \n\a\a");
                        break;
                        }
                    desapilar(&pila,&dato);
                    printf("\n\n El dato fue desapilado exitosamente \n\a\a");
                    mostrar_dato(&dato);
                    break;

            case 4: if(!existe_pila)
                        {
                        printf("\n\n No se ha creado una pila \n\a\a");
                        break;
                        }
                    printf("\n La pila %s está llena \n\a\a",pila_llena(&pila)?"":"no");
                    break;

            case 5: if(!existe_pila)
                        {
                        printf("\n\n No se ha creado una pila.\n\a\a");
                        break;
                        }
                    printf("\n La pila %s está vacía \n\a\a",pila_vacia(&pila)?"":"no");
                    break;

            case 6: if(!existe_pila)
                        {
                        printf("\n\n No se ha creado una pila. No puede ver el tope.\n\a\a");
                        break;
                        }
                    if(pila_vacia(&pila))
                        {
                        printf("\n\n La pila está vacía. No tiene sentido ver el tope. \a\a");
                        break;
                        }
                    ver_tope(&pila,&dato);
                    printf("\n\n El tope de la pila es: \t %d \n\a\a",dato.numero);
                    break;

            case 7: if(!existe_pila)
                        {
                        printf("\n\n No se ha creado una pila. No puede vaciar la pila.\n\a\a");
                        break;
                        }
                    if(pila_vacia(&pila))
                        {
                        printf("\n\n La pila está vacía. No tiene sentido vaciarla. \a\a");
                        break;
                        }
                    vaciar_pila(&pila);
                    printf("\n\n La pila ha sido vaciado exitosamente \n\a\a");
                    break;

            case 8: if(!existe_pila)
                        {
                        printf("\n\n No se ha creado una pila. No se la puede borrar. \a\a");
                        break;
                        }
                    existe_pila=0;
                    printf("\n\n La pila fue borrada exitosamente \a\a");
                    break;

            case 9: if(!existe_pila)
                        {
                        printf("\n\n No se ha creado una pila. No se la puede exportar. \a\a");
                        break;
                        }
                    if(pila_vacia(&pila))
                        {
                        printf("\n\n La pila está vacía. No tiene sentido exportarla. \a\a");
                        break;
                        }
                    if(!exportar_pila_a_archivo_bin(&pila))
                        {
                        printf("\n\n Falló la exportación de la pila a archivo binario \a\a");
                        break;
                        }
                    printf("\n\n La pila ha sido exportada a archivo binario exitosamente \a\a");
                    getch();
                    system("cls");
                    printf("\n\n La pila quedó vacía. Si quiere recuperarla puede cargarla desde el archivo. \a\a");
                    break;

            case 10:if(!existe_pila)
                        {
                        printf("\n\n No se ha creado una pila. No se la puede exportar. \a\a");
                        break;
                        }
                    if(pila_vacia(&pila))
                        {
                        printf("\n\n La pila está vacía. No tiene sentido exportarla. \a\a");
                        break;
                        }
                    if(!exportar_pila_a_archivo_txt(&pila))
                        {
                        printf("\n\n Falló la exportación de la pila a archivo de texto \a\a");
                        break;
                        }
                    printf("\n\n La pila ha sido exportada a archivo de texto exitosamente \a\a");
                    getch();
                    system("cls");
                    printf("\n\n La pila quedó vacía. Si quiere recuperarla puede cargarla desde el archivo. \a\a");
                    break;

            case 11:if(existe_pila)
                        {
                        printf("\n\n Ya se ha creado una pila. ¿Desea reemplazarla? \a\a");
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
                            printf("\n\n Carga de pila cancelada \a\a");
                            break;
                            }
                        existe_pila=0;
                        }
                    system("cls");
                    if(!cargar_pila_desde_archivo_bin(&pila))
                        {
                        printf("\n\n Falló la carga de la pila desde archivo binario \a\a");
                        break;
                        }
                    existe_pila=1;
                    printf("\n\n Se ha cargado una pila desde archivo binario exitosamente \n\a\a");
                    break;

            case 12:if(existe_pila)
                        {
                        printf("\n\n Ya se ha creado una pila. ¿Desea reemplazarla? \a\a");
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
                            printf("\n\n Carga de pila cancelada \a\a");
                            break;
                            }
                        existe_pila=0;
                        }
                    system("cls");
                    if(!cargar_pila_desde_archivo_bin(&pila))
                        {
                        printf("\n\n Falló la carga de la pila desde archivo de texto \a\a");
                        break;
                        }
                    existe_pila=1;
                    printf("\n\n Se ha cargado una pila desde archivo de texto exitosamente \n\a\a");
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
