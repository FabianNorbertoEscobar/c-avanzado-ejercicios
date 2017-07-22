#include "dato.h"

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

#define     LISTA_VACIA     0
#define     MEMORIA_LLENA   0
#define     OK              1

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *sig;
}t_nodo;

typedef t_nodo* t_lista;

void crear_lista(t_lista*);
int lista_vacia(const t_lista*);
int lista_llena(const t_lista*);
int poner_en_lista(t_lista*,const t_dato*);
int sacar_de_lista(t_lista*,t_dato*);
int ver_primero_de_lista(const t_lista*,t_dato*);
void vaciar_lista(t_lista*);
