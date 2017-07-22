#include "header.h"
void inicializar_vector(int v[],int ce)
    {
    int k;
    for(k=0;k<ce;k++)
        v[k]=0;
    }
void cargar_tabla(int t[][EQUIPOS],int equipos)
    {
    int i,j,band;
    for(i=0;i<equipos;i++)
        {
        printf("\n");
        for(j=0;j<equipos;j++)
            if(i!=j)
                {
                band=0;
                do
                    {
                    if(band==1)
                        printf("\n\n Los puntos ingresados son incorrectos. Reingréselos: \n");
                    printf("\n\t Equipo %d VS Equipo %d: \t",i+1,j+1);
                    scanf("%d",&t[i][j]);
                    band=1;
                    }
                while(!(DATO_VALIDO(t[i][j],0,3)&&t[i][j]!=2));
                }
        }
    }
void puntos_por_equipo(int t[][EQUIPOS],int v[],int equipos)
    {
    int i,j;
    for(i=0;i<equipos;i++)
        {
        printf("\n");
        for(j=0;j<equipos;j++)
            if(i!=j)
                {
                if(t[i][j]==1)
                    {
                    v[i]++;
                    v[j]++;
                    }
                else
                    if(t[i][j]==0)
                        v[j]+=3;
                    else
                        v[i]+=3;
                }
        }
    }
void mostrar_puntos(int v[],int equipos)
    {
    int k;
    for(k=0;k<equipos;k++)
        printf("\n %d \t\t %d",k+1,v[k]);
    }
void campeon_del_torneo(int v[],int equipos)
    {
    int k,campeon,puntos_del_campeon,cant=0;
    for(k=0;k<equipos;k++)
        if(k==0||v[k]>puntos_del_campeon)
            puntos_del_campeon=v[k];
    for(k=0;k<equipos;k++)
        if(v[k]==puntos_del_campeon)
            {
            cant++;
            campeon=k+1;
            }
    if(cant==1)
        printf("\n\n EL CAMPEÓN DEL TORNEO ES EL EQUIPO %d, CON %d PUNTOS \n\n",campeon,puntos_del_campeon);
    else
        {
        printf("\n\n Para conocer al campeón, debe realizarse un desempate entre: \n");
        for(k=0;k<equipos;k++)
            if(v[k]==puntos_del_campeon)
                printf("\n Equipo %d",k+1);
        }
    }
