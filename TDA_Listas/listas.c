#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Nodo{
    int dato;
    struct Nodo* siguiente;
} typedef Nodo;

typedef Nodo* PunteroNodo;

void crearLista(PunteroNodo *Lista){
    *Lista = NULL;
}

bool esVacia(PunteroNodo Lista){
    if(Lista == NULL){
        return true;
    } else {
        return false;
    }
}

void nuevoNodo(PunteroNodo *Lista){
    *Lista = (PunteroNodo)malloc(sizeof(Nodo));
    if(esVacia(*Lista)){
        printf("La lista está vacía");
        exit(1);
    }
}

bool existeEnLaLista(PunteroNodo Lista, int valor){
    while(!esVacia(Lista)){
        if(Lista -> dato == valor){
            return true;
        } else {
            Lista = Lista -> siguiente;
        }
    }
    return false;
}

void insertarPrincipio(PunteroNodo *Lista, int valorDato){
    PunteroNodo nuevoN;
    nuevoNodo(&nuevoN);
    nuevoN -> dato = valorDato;
    nuevoN -> siguiente = *Lista;
    *Lista = nuevoN;
}

void insertarFinal(PunteroNodo *Lista, int valorDato){
    PunteroNodo nuevoN;
    nuevoNodo(&nuevoN);
    nuevoN -> dato = valorDato;
    nuevoN -> siguiente = NULL;
    if(esVacia(*Lista)){
        *Lista = nuevoN;
    } else {
        PunteroNodo auxiliar = *Lista;
        PunteroNodo punteroAnterior;
        while(!esVacia(auxiliar)){
            punteroAnterior = auxiliar;
            auxiliar = auxiliar -> siguiente;
        }
        punteroAnterior -> siguiente = nuevoN;
    }
}

void insertarOrdenado(PunteroNodo *Lista, int valorDato){
    PunteroNodo nuevoN;
    nuevoNodo(&nuevoN);
    nuevoN -> dato = valorDato;
    nuevoN -> siguiente = NULL;

    if(esVacia(*Lista) || (*Lista) -> dato >= valorDato){
        nuevoN -> siguiente = *Lista;
        *Lista = nuevoN;
    } else {
        PunteroNodo actual = *Lista;
        while((actual -> siguiente != NULL) && (actual -> siguiente -> dato < valorDato)){
            actual = actual -> siguiente;
        }
        nuevoN -> siguiente = actual -> siguiente; 
        actual -> siguiente = nuevoN;
    }
}

void eliminarElemento(PunteroNodo *Lista, int valorDato){
    if(existeEnLaLista(*Lista, valorDato)){
        PunteroNodo auxiliar = *Lista;
        PunteroNodo nodoEliminado;
        if(auxiliar -> dato == valorDato){
            // Guarda nodo a eliminar en una variable
            nodoEliminado = auxiliar;
            // Asigno al inicio de la lista la dirección del siguiente nodo del cual eliminé
            *Lista = nodoEliminado -> siguiente;
        } else {
            PunteroNodo anterior = auxiliar;
            auxiliar = auxiliar -> siguiente;
            while(auxiliar != NULL && auxiliar -> dato != valorDato){
                anterior = auxiliar;
                auxiliar = auxiliar -> siguiente;
            }
            if(auxiliar != NULL){
                nodoEliminado = auxiliar;
                anterior -> siguiente = nodoEliminado -> siguiente;
            }
        }
        free(nodoEliminado);
    } else {
        printf("El valor no está en la lista\n");
    }
}

void sacarElemento(PunteroNodo *Lista, int *x){
    if (!esVacia(*Lista)) {
        PunteroNodo primerNodo = *Lista;
        *Lista = primerNodo -> siguiente;
        *x = primerNodo -> dato;
        free(primerNodo);
    }
}

void imprimirLista(PunteroNodo Lista){
    while(!esVacia(Lista)){ 
        printf("%d ", Lista -> dato);
        Lista = Lista -> siguiente;
    }
}