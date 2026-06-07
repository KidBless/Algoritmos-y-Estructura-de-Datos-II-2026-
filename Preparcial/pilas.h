#ifndef PILAS_H
#define PILAS_H

#include <stdbool.h>

struct Nodo{
    int dato;
    struct Nodo* siguiente;
} typedef Nodo;

typedef Nodo* PunteroNodo;

void crearPila(PunteroNodo *Pila);
bool esVacia(PunteroNodo Pila);
void nuevoNodo(PunteroNodo *Pila);
void apilar(PunteroNodo *Pila, int valorDato);
void sacarElemento(PunteroNodo *Pila, int *x);

#endif