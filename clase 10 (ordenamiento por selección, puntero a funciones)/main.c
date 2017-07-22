#include "header.h"

int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int i;

    printf("\n\n\t\t ORDENAMIENTO POR SELECCIÓN -- PUNTERO A FUNCIONES \n");
    printf("\n Uso una función que simula a QSORT de la bibioteca stdlib.h");
    printf("\n Sirve para ordenar cualquier cosa");
    getch();

    printf("\n\n ORDENANDO ARRAY DE ENTEROS");
    int v1[10]={2,5,6,4,7,8,1,9,3,0};
    printf("\n\n Antes de ordenar");
    for(i=0;i<10;i++)
        printf("  %d",v1[i]);
    ordenamiento_seleccion(v1,10,sizeof(int),comparar_int);
    printf("\n\n Después de ordenar");
    for(i=0;i<10;i++)
        printf("  %d",v1[i]);
    getch();

    printf("\n\n ORDENANDO ARRAY DE FLOTANTES");
    float v2[10]={2.33,5.26,6.89,4.47,7.18,8.94,1.02,9.23,3.55,0.11};
    printf("\n\n Antes de ordenar");
    for(i=0;i<10;i++)
        printf("  %.2f",v2[i]);
    ordenamiento_seleccion(v2,10,sizeof(float),comparar_float);
    printf("\n\n Después de ordenar");
    for(i=0;i<10;i++)
        printf("  %.2f",v2[i]);
    getch();

    printf("\n\n ORDENANDO ARRAY DE CARACTERES");
    char v3[10]={'r','h','f','o','j','l','a','x','w','s'};
    printf("\n\n Antes de ordenar");
    for(i=0;i<10;i++)
        printf("  %c",v3[i]);
    ordenamiento_seleccion(v3,10,sizeof(char),comparar_char);
    printf("\n\n Después de ordenar");
    for(i=0;i<10;i++)
        printf("  %c",v3[i]);
    getch();

    printf("\n\n ORDENANDO ARRAY DE STRINGS");
    char v4[10][15]={"Perro","Gato","Jirafa","Mono","Tucán","Koala","Toro","Burro","Loro","Delfín"};
    printf("\n\n Antes de ordenar\n");
    for(i=0;i<10;i++)
        printf("  %s",v4[i]);
    ordenamiento_seleccion(v4,10,sizeof(char)*15,comparar_string);
    printf("\n\n Después de ordenar\n");
    for(i=0;i<10;i++)
        printf("  %s",v4[i]);
    getch();

    t_persona personas[10]={    {32659449,"Ortúzar","Oriana Lucía",27},
                                {18564966,"Gutierrez","Enrique Luis",50},
                                {28946356,"Oberto","Jorge Ignacio",35},
                                {26489494,"Echegaray","Malena Romina",33},
                                {25648754,"Ulisotta","Juan Edgardo",34},
                                {16514142,"Borrato","Jorge Esteban",54},
                                {25648754,"Roberto","Sergio",31},
                                {25648754,"Ascacibar","Andrea Julieta",35},
                                {13648754,"Torres Rojas","Gilberto Pancracio",56},
                                {36916554,"Cancarro","Matías Ignacio",25} };

    printf("\n\n ORDENANDO ARRAY DE ESTRUCTURAS PERSONA POR APELLIDO");
    printf("\n\n Antes de ordenar");
    for(i=0;i<10;i++)
        printf("\n DNI: %d \t Apellido/s: \t %s \n\t\t Nombre/s: \t %s \n\t\t Edad: \t\t %d \n",personas[i].dni,personas[i].apellido,personas[i].nombre,personas[i].edad);
    ordenamiento_seleccion(personas,10,sizeof(t_persona),comparar_apellido_personas);
    printf("\n\n Después de ordenar");
    for(i=0;i<10;i++)
        printf("\n DNI: %d \t Apellido/s: \t %s \n\t\t Nombre/s: \t %s \n\t\t Edad: \t\t %d \n",personas[i].dni,personas[i].apellido,personas[i].nombre,personas[i].edad);
    getch();

    printf("\n\n ORDENANDO ARRAY DE ESTRUCTURAS PERSONA POR NOMBRE");
    printf("\n\n Antes de ordenar");
    for(i=0;i<10;i++)
        printf("\n DNI: %d \t Apellido/s: \t %s \n\t\t Nombre/s: \t %s \n\t\t Edad: \t\t %d \n",personas[i].dni,personas[i].apellido,personas[i].nombre,personas[i].edad);
    ordenamiento_seleccion(personas,10,sizeof(t_persona),comparar_nombre_personas);
    printf("\n\n Después de ordenar");
    for(i=0;i<10;i++)
        printf("\n DNI: %d \t Apellido/s: \t %s \n\t\t Nombre/s: \t %s \n\t\t Edad: \t\t %d \n",personas[i].dni,personas[i].apellido,personas[i].nombre,personas[i].edad);
    getch();

    printf("\n\n ORDENANDO ARRAY DE ESTRUCTURAS PERSONA POR DNI");
    printf("\n\n Antes de ordenar");
    for(i=0;i<10;i++)
        printf("\n DNI: %d \t Apellido/s: \t %s \n\t\t Nombre/s: \t %s \n\t\t Edad: \t\t %d \n",personas[i].dni,personas[i].apellido,personas[i].nombre,personas[i].edad);
    ordenamiento_seleccion(personas,10,sizeof(t_persona),comparar_dni_personas);
    printf("\n\n Después de ordenar");
    for(i=0;i<10;i++)
        printf("\n DNI: %d \t Apellido/s: \t %s \n\t\t Nombre/s: \t %s \n\t\t Edad: \t\t %d \n",personas[i].dni,personas[i].apellido,personas[i].nombre,personas[i].edad);
    getch();

    printf("\n\n ORDENANDO ARRAY DE ESTRUCTURAS PERSONA POR EDAD");
    printf("\n\n Antes de ordenar");
    for(i=0;i<10;i++)
        printf("\n DNI: %d \t Apellido/s: \t %s \n\t\t Nombre/s: \t %s \n\t\t Edad: \t\t %d \n",personas[i].dni,personas[i].apellido,personas[i].nombre,personas[i].edad);
    ordenamiento_seleccion(personas,10,sizeof(t_persona),comparar_edad_personas);
    printf("\n\n Después de ordenar");
    for(i=0;i<10;i++)
        printf("\n DNI: %d \t Apellido/s: \t %s \n\t\t Nombre/s: \t %s \n\t\t Edad: \t\t %d \n",personas[i].dni,personas[i].apellido,personas[i].nombre,personas[i].edad);
    getch();

    printf("\n\n \t\t\t\t\t Fin del programa.. \n\n");
    getch();
    return 0;
    }
