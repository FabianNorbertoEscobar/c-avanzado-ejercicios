#include "header.h"

// ESTE PROGRAMA SOLAMENTE MUESTRA LA LÓGICA DE COMO SIMULARLO
// SE PODRÍAN CARGAR LOS DATOS DE CADA PERSONA QUE ENTRA Y SALE DEL CAJERO
// Y AGREGAR TODO LO QUE A UNO SE LE PUEDA OCURRIR

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    puts("\n\n COLA DE ESPERA EN UN CAJERO AUTOMÁTICO \n\a\a");

    puts("\n\n Simulación de la cola de espera, suponiendo que:");
    puts("\n - cada cliente demora en el cajero un tiempo aleatorio \n de 1, 3 o 5 minutos con igual probabilidad.");
    puts("\n - los clientes llegan al cajero de a uno, con un intervalo \n de arribo aleatorio de 1, 5 o 9 minutos, con igual probabilidad.");
    puts("\n\n La simulación termina después de que la cola queda vacía cinco veces. \n\n");

    puts("\n Para comenzar la simulación, presione una tecla cualquiera \n\n");
    getch();

    puts("\n\n COLA DE CAJERO AUTOMÁTICO");
    puts("\n ------------------------- \n\n");

    t_cola cola;
    crear_cola(&cola);

    t_dato cliente_entrada;
    strcpy(cliente_entrada.persona,"Persona");
    t_dato cliente_salida;
    strcpy(cliente_salida.persona,"Persona");

    cliente_entrada.cont=0;

    int ocurrencia_entrada[3]={1,3,5};
    int ocurrencia_salida[3]={1,5,9};

    int tiempo=0;
    int no_hay_cola=0;
    int tiempo_ocurrencia=rand()%3;

    while(no_hay_cola!=5)
        {
        if(ocurrencia_entrada[tiempo_ocurrencia]==tiempo)
            if(!cola_vacia(&cola))
                {
                desacolar(&cola,&cliente_salida);
                printf("\n\n \t\t\t %s --> Sale \n",cliente_salida.persona);
                if(cola_vacia(&cola))
                    {
                    no_hay_cola++;
                    printf("\n\n Se ha vaciado la cola de espera \n\n");
                    }
                }

        if(ocurrencia_salida[tiempo_ocurrencia]==tiempo)
            {
            cliente_entrada.cont++;
            printf("\n\n  \t Entra --> %s  \n",cliente_entrada.persona);
            if(!cola_llena(&cola))
                acolar(&cola,&cliente_entrada);
            }

        (tiempo==9)?tiempo=0:tiempo++;
        tiempo_ocurrencia=rand()%3;

        }

    puts("\n\n Fin de la simulación \n\n");

    puts("\n\n \t\t\t\t\t Fin del programa.. \n\n\a\a");
    getch();
    return 0;
    }
