#include "listas.h"
#include "pilas.h"

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

// Ejercicio 2: Cantidad de novelas por código
void novelas(PunteroNodo *novelas){
    PunteroNodo aux;
    crearPila(&aux);
    int codigo;
    int contadores[5] = {0};

    while(!esVacia(*novelas)){
        sacarElemento(novelas, &codigo);
        
        if(codigo == 0001){
            contadores[1]++;
        } else if (codigo == 0002){
            contadores[2]++;
        } else if (codigo == 0003){
            contadores[3]++;
        } else if (codigo == 0004){
            contadores[4]++;
        }

        apilar(&aux, codigo);
    }

    int maxCantidad = contadores[1];
    int maxCodigo = 0001;
    int minCantidad = contadores[1];
    int minCodigo = 0001;

    for(int i = 2; i <= 4; i++){
        if(contadores[i] > maxCantidad){
            maxCantidad = contadores[i];
            maxCodigo = 0000 + i;
        }

        if(contadores[i] < minCantidad){
            minCantidad = contadores[i];
            minCodigo = 0000 + i;
        }
    }

    printf("La novela con mayor cantidad de ventas es la de código %d con %d ventas.\n", maxCodigo, maxCantidad);
    printf("La novela con menor cantidad de ventas es la de código %d con %d ventas.\n", minCodigo, minCantidad);

    while(!esVacia(aux)){
        sacarElemento(&aux, &codigo);
        apilar(novelas, codigo);
    }
}