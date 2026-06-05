#ifndef LISTAS_H
#define LISTAS_H

#include <stdbool.h>

struct Nodo{
    int dato;
    struct Nodo *siguiente;
} typedef Nodo;

typedef Nodo *PunteroNodo;

void crearLista(PunteroNodo *Lista);
bool esVacia(PunteroNodo Lista);
void NuevoNodo(PunteroNodo *Lista);
bool existeEnLista(PunteroNodo Lista, int valor);
void Instertar_Principio(PunteroNodo *Lista, int valorDato);
void Instertar_Final(PunteroNodo *Lista, int valorDato);
void Instertar_Ordenado(PunteroNodo *Lista, int valorDato);
void eliminarElemento(PunteroNodo *Lista, int valorDato);
void sacarElemento(PunteroNodo *Lista, int *x);
void imprimirLista(PunteroNodo Lista);

#endif