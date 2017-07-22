#include "header.h"
int main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int tabla[EQUIPOS][EQUIPOS],puntos[EQUIPOS];
    inicializar_vector(puntos,EQUIPOS);
    printf("\n TORNEO DE FÚTBOL \a\a");
    printf("\n ----------------");
    printf("\n Cantidad de equipos participantes: \t %d \n",EQUIPOS);
    printf("\n Cargue los puntos que obtuvieron los equipos locales en cada partido \n");
    printf("\n\t Victoria: 3 \n");
    printf("\n\t Empate: 1 \n");
    printf("\n\t Derrota: 0 \n\n");
    cargar_tabla(tabla,EQUIPOS);
    puntos_por_equipo(tabla,puntos,EQUIPOS);
    printf("\n PUNTOS DE CADA EQUIPO \n\n");
    printf("\n EQUIPO \t PUNTOS");
    mostrar_puntos(puntos,EQUIPOS);
    campeon_del_torneo(puntos,EQUIPOS);
    printf("\n\n Fin del programa...... \a\a \n\n");
    getch();
    return 0;
    }
