#include "listas.h"


// Ejercicio 1: Actualizar deudas
void actualizarDeudas(PunteroNodo *deudas, PunteroNodo *deudasActualizadas){
    int montoOriginal, montoActualizado;

    PunteroNodo aux;
    crearLista(&aux);

    while(!esVacia(*deudas)){
        sacarElemento(deudas, &montoOriginal);

        if(montoOriginal < 10000){
            montoActualizado = montoOriginal * 1.10;
        } else if(montoOriginal < 50000){
            montoActualizado = montoOriginal * 1.25;
        } else if(montoOriginal < 100000){
            montoActualizado = montoOriginal * 1.35;
        } else if(montoOriginal >= 100000){
            montoActualizado = (montoOriginal * 1.50) + 20000;
        }

        insertarFinal(deudasActualizadas, montoActualizado);
        insertarFinal(&aux, montoOriginal);
    }

    *deudas = aux;
}

