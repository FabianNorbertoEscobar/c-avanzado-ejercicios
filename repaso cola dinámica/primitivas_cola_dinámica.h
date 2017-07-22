#include "dato.h"

#include<stdio.h>
#include<stdlib.h>

#define     COLA_VACIA          0
#define     MEMORIA_LLENA       0
#define     OK                  1

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *sig;
}t_nodo;

typedef struct
{
    t_nodo *pri;
    t_nodo *ult;
}t_cola;

void crear_cola(t_cola*);
int cola_vacia(const t_cola*);
int cola_llena(const t_cola*);
int acolar(t_cola*,const t_dato*);
int desacolar(t_cola*,t_dato*);
int ver_primero(const t_cola*,t_dato*);
int ver_ultimo(const t_cola*,t_dato*);
void vaciar_cola(t_cola*);
