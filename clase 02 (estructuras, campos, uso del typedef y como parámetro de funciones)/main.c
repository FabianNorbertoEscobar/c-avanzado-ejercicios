#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct s_alumno al1;
    al1.dni=11111111;
    printf("\n estructura con struct \n");
    printf("\n alumno 1 \n \t dni: \t %d \n\t promedio: \t",al1.dni);
    scanf("%f",&al1.prom);
    t_alumno al2;
    //al2=al1;esto no se puede hacer ya que no son del mismo tipo
    // es conveniente trabajar con typedef;
    //pero si se puede hacer lo siguiente, ya que los tipos de campo sí son los mismos
    al2.dni=al1.dni;
    al2.prom=al1.prom;
    printf("\n estructura con typedef \n");
    printf("\n alumno 2");
    mostrarAl(al2);
    getch();
    return 0;
    }
