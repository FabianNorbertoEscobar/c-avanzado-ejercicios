#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int v[TOPE],n,op,*dir;
    printf("\n\n DIRECCIÓN DE MEMORIA DE UN ELEMENTO DENTRO DE UN ARRAY \n");
    printf("\n Se le solicita que cargue un array de enteros, con %d posiciones \n\n",TOPE);
    cargar_array(v,TOPE);
    printf("\n\n El array fue cargado correctamente \n\n");
    printf("\n\n Sus elementos son: \n");
    mostrar_array(v,TOPE);
    printf("\n\n BUSCAR ELEMENTO \n");
    do
        {
        printf("\n Ingrese un entero para buscar su dirección de memoria dentro del array: \n\n\t\t");
        scanf("%d",&n);
        dir=buscar_direccion(v,TOPE,n);
        if(dir!=NULL)
            printf("\n Dirección de memoria: \t %p",dir);
        else
            printf("\n El elemento buscado no se encuentra en el array \n\n\a\a");
        printf("\n\n Para realizar una nueva búsqueda presione 1 \n Caso contrario, presione cualquier tecla: \t");
        scanf("%d",&op);
        }
    while(op==1);
    printf("\n\n \t\t\t\t\t Fin del programa... \n\n");
    getch();
    return 0;
    }
