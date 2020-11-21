#ifndef _FILA_H_
#define _FILA_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct _NODO2{
    int dato;
    struct _NODO2 *siguiente;
}Nodo2;


Nodo2 * crear2(int d){
    Nodo2 * nuevo;
    nuevo = (Nodo2 *)malloc(sizeof(Nodo2)); //si malloc no logra retornar un puntero va a retornar un null 0 o un -1 --> por lo tanto, hay que realizar una comparación y manejar un error
    nuevo->dato = d;
    nuevo->siguiente = NULL;

    return nuevo;
}

//OPERACION PUSH
Nodo2 * insertarElem2(Nodo2 * frente, int d){
    Nodo2 * nuevo;
    nuevo = crear2(d);

    //si no hay nada, el elemento a insertar será "nuevo"
    if (frente == NULL){
        frente = nuevo;
    }else{
        Nodo2 *aux;
        aux = frente;
        while(aux->siguiente != NULL){//se recorre hasta llegar al ult elemento
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo; //el siguiente elem(ultimo) será "nuevo"
    }

    return frente;
}

//OPERACION POP
Nodo2 *sacarElem2(Nodo2 * frente){
    Nodo2 * aux;
    aux = frente; //se referencia al frente
    //corregir un posible underflow
    if (frente != NULL){
        frente = frente->siguiente;
        free(aux);
    }else{
        printf("\nNo hay elementos en la fila");
    }
    return frente;
}



void verF(Nodo2 * frente){
    if(frente == NULL){
        printf("\nNo hay ningun elemento en la fila\n");
    }else{
        while(frente != NULL){
            printf("\nDato: %d",frente->dato);
            frente = frente->siguiente;
        }
    }
}


int contar2 (Nodo2 * frente){
    int c = 0;
    if(frente == NULL){
        printf("\n0 elementos\n");
    }else{
        while(frente != NULL){
            c++;
            //hay que ir moviendo el frente hasta llegar a null
            frente = frente->siguiente;
        }
        return c;
    }
}

#endif

