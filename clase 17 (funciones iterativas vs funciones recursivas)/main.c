#include "header.h"

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n FUNCIONES ITERATIVAS VS FUNCIONES RECURSIVAS \n");

    //las funciones recursivas son aquellas que se invocan a sí misma
    //hay lenguajes que no permiten la recursividad, no es el caso de C
    //todas las funciones iterativas se pueden escribir de forma recursiva, y viceversa, en general
    //las funciones recursivas consumen más memoria y son más lentas que las funciones iterativas
    //pero hay algunos casos en que encontrar la forma iterativa de una función recursiva es muy complicado
    //las funciones recursivas, en algunos casos, son muy fáciles
    //toda función recursiva debe tener una consulta--> la condición de fin
    //las funciones recursivas vasn delegando el problema hasta que se llegue a la condición de fin
    //cada invocación recibe el valor siguiente, pero no lo modifica para el entorno local de quien la invoca

    printf("\n\n factorial_iterativo(5): \t %d",factorial_iterativo(5));
    printf("\n\n factorial_recursivo(5): \t %d",factorial_recursivo(5));

    printf("\n\n \t\t\t\t\t Fin del programa.. \n\n\a\a");
    getch();
    return 0;
}
