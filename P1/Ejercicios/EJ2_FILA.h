#ifndef _FILA_H_
#define _FILA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODO{
    int dato;
    char nombre[25];
    struct _NODO *siguiente;
}Nodo;


Nodo * crear(int d,char n[]){
    Nodo * nuevo;
    nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = d;
    strcpy(nuevo->nombre,n);
    nuevo->siguiente = NULL;
    return nuevo;
}


Nodo * insertarElem(Nodo * frente, int d,char n[]){
    printf("%s",n);
    Nodo * nuevo;
    nuevo = crear(d,n);

    //si no hay nada, la cajita de referencia será la antes creada
    if (frente == NULL){
        frente = nuevo;
    }else{
        Nodo *aux;
        aux = frente;
        while(aux->siguiente != NULL){//se recorre hasta llegar a la ultima cajita
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo; //se referencia la cajita nueva al siguiente lugar disponible
    }

    return frente;
}


Nodo *sacarElem(Nodo * frente){
    Nodo * aux;
    aux = frente; //se referencia al frente
    //corregir un posible underflow
    if (frente != NULL){//hay por lo menos una cajita en la fila
        frente = frente->siguiente;
        free(aux);
    }else{
        printf("No hay elementos en la fila");
    }
    return frente;
}

void ver (Nodo * frente){
    if(frente == NULL){
        printf("\nNo hay ningun elemento en la fila\n");
    }else{
        while(frente != NULL){
            printf("\nDato: %d",frente->dato);
            printf("\tNombre: %s",frente->nombre);
            frente = frente->siguiente;
        }
    }
}


int contar (Nodo * frente){
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

int getDato(Nodo *cima){
    return cima->dato;
}



#endif


