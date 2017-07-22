#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

typedef long t_info;

typedef struct s_nodo{
    struct s_nodo *sig;
    t_info info;
}t_nodo;

typedef struct {
    t_nodo * frente;
    t_nodo * fondo;
}t_cola;

void crearCola(t_cola *cola);
int colaVacia(const t_cola *cola);
int colaLLena(const t_cola *cola);
int ponerEnCola(t_cola *cola, const t_info *info);
int sacarDeCola(t_cola *cola, t_info *info);
int primeroEnCola(const t_cola *cola, t_info *info);
void vaciarCola(t_cola *cola);

#endif // COLA_H_INCLUDED
