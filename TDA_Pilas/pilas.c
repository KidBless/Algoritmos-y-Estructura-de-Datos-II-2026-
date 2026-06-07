#include "pilas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Nodo{
    int dato;
    struct Nodo* siguiente;
} typedef Nodo;

typedef Nodo* PunteroNodo;

void crearPila(PunteroNodo *Pila){
    *Pila = NULL;
}

bool esVacia(PunteroNodo Pila){
    if(Pila == NULL){
        return true;
    } else {
        return false;
    }
}

void nuevoNodo(PunteroNodo *Pila){
    *Pila = (PunteroNodo)malloc(sizeof(Nodo));
    if(esVacia(*Pila)){
        printf("La pila está vacía");
        exit(1);
    }
}

void apilar(PunteroNodo *Pila, int valorDato){
    PunteroNodo nuevoN;
    nuevoNodo(&nuevoN);
    nuevoN -> dato = valorDato;
    nuevoN -> siguiente = *Pila;
    *Pila = nuevoN;
}

void sacarElemento(PunteroNodo *Pila, int *x){
    if (!esVacia(*Pila)) {
        PunteroNodo primerNodo = *Pila;
        *Pila = primerNodo -> siguiente;
        *x = primerNodo -> dato;
        free(primerNodo);
    } else {
        printf("La pila está vacía\n");
    }
}