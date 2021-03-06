#ifndef _EJERCICIO2_LISTADOBLE_H_
#define _EJERCICIO2_LISTADOBLE_H_
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"time.h"

typedef struct _NODO{
    char marca [15];
    char color[15];
    char placa[25];
    struct _NODO *siguiente;
    struct _NODO *anterior;
}Nodo;

Nodo *crear(char m[], char c[], char p[]){
    Nodo * nuevo;
    nuevo = (Nodo *)malloc(sizeof(Nodo));
    strcpy(nuevo->marca,m);
    strcpy(nuevo->placa,p);
    strcpy(nuevo->color,c);
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    return nuevo;
}

void ver (Nodo *frente){
    if(frente == NULL){
        printf("\nNo hay ningun elemento en la lista\n");
    }else{
        while(frente != NULL){
            printf("\nMarca: %s\tColor: %s\tPlaca: %s",frente->marca,frente->color,frente->placa);
            frente = frente->siguiente;
        }
    }
}

void verInverso (Nodo *frente){
    if(frente == NULL){
        printf("\nNo hay ningun elemento en la lista\n");
    }else{
        while(frente->siguiente!=NULL){
            frente = frente->siguiente;
        }
        while(frente != NULL){
            printf("\nMarca: %s\tColor: %s\tPlaca: %s",frente->marca,frente->color,frente->placa);
            frente = frente->anterior;
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
            frente = frente->siguiente;
        }
        return c;
    }
}

Nodo *insertarInicio(Nodo * inicio, char m[], char c[], char p[]){
    Nodo * nuevo;
    nuevo = crear(m,c,p);

    if (inicio != NULL){
        nuevo->siguiente = inicio;
        inicio->anterior = nuevo;
    }
    printf("\nCarro insertado al inicio");
    return nuevo;
}

Nodo * insertarXP(Nodo *inicio, int posicion, char m[], char c[], char p[]){
    Nodo *nuevo;
    Nodo *aux;
    int longitudLista = contar(inicio);

    nuevo = crear(m,c,p);

    if (posicion >= 1 && posicion <= longitudLista){
        if (posicion == 1){
            inicio = insertarInicio(inicio,m,c,p);
        }
        else{
            aux = inicio;
            for(int i = 1; i < posicion-1; i++){
                aux = aux->siguiente;
            }
            nuevo->siguiente = aux->siguiente;//OK
            nuevo->anterior=aux;
            aux->siguiente = nuevo;//OK
            nuevo->siguiente->anterior = nuevo;
            printf("\nCarro insertado en %d", posicion);
        }
    }else{
        printf("\nPosicion invalida! (%d)",posicion);
    }
    return inicio;
}

Nodo * insertarFinal(Nodo * inicio, char m[], char c[], char p[]){
    Nodo * nuevo;
    nuevo = crear(m,c,p);

    if (inicio == NULL){
        inicio = nuevo;
    }else{
        Nodo *aux;
        aux = inicio;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
    }

    printf("\nCarro insertado al final");
    return inicio;
}

Nodo *borrarInicio(Nodo * inicio){
    Nodo *aux;

    if (inicio != NULL){
        aux = inicio;
        inicio = inicio->siguiente;

        if (inicio != NULL){
        inicio->anterior = NULL;
        }
        printf("\nCarro inicial borrado ");
        free(aux);
    }else{
        printf("\nNo hay elementos en la lista");
    }
    return inicio;
}

Nodo *borrarXP(Nodo *inicio, int posicion){
    int longitud = contar(inicio);
    Nodo *aux;
    Nodo *aux2;

    if (posicion >= 1 && posicion <= longitud){
        if (posicion == 1){
            inicio = borrarInicio(inicio);
        }else{
            aux = inicio;
            for(int i = 1; i < posicion-1; i++){
                aux = aux->siguiente;
            }
            aux2 = aux->siguiente;
            aux->siguiente = aux->siguiente->siguiente;
            aux->siguiente->anterior = aux;
            free(aux2);
            printf("\nCarro %d borrado",posicion);
        }

    }else{
        printf("\nImposible acceder a esa posicion! [%d]",posicion);
    }

    return inicio;
}

Nodo *borrarFinal(Nodo * inicio){
    int longitudLista = contar(inicio);
    Nodo *aux;

    if(inicio == NULL){
        printf("\nNo hay elementos por borrar");
    }
    if (inicio->siguiente == NULL){ //s�lo hay un elemento
        free(inicio);
        return NULL;
    }
    else{
        aux = inicio;
        while(aux->siguiente->siguiente != NULL){
                aux= aux->siguiente;
        }
        free(aux->siguiente);
        aux->siguiente = NULL;
        printf("\nCarro final borrado");

    }
    return inicio;
}

Nodo * cambiarMarca(Nodo * inicio,char mActual[], char mNuevo[]){
    Nodo *aux;
    bool val = false;

    aux = inicio;
    while(aux != NULL){
        if (strcmp(aux->marca,mActual) == 0){
            strcpy(aux->marca,mNuevo);
            val = true;
            break;
        }else{
            aux = aux->siguiente;
        }
    }
    if(!val){
        printf("\nNo existe un elemento con ese marca!");
    }else{
        printf("\nDato cambiado con exito! (Desde el inicio)");
    }

    return inicio;
}

Nodo * cambiarMarcaFromBack(Nodo * inicio,char mActual[], char mNuevo[]){
    Nodo *aux;
    bool val = false;

    aux = inicio;
    while(aux->siguiente !=NULL){
        aux = aux->siguiente;
    }
    while(aux != NULL){
        if (strcmp(aux->marca,mActual) == 0){
            strcpy(aux->marca,mNuevo);
            val = true;
            break;
        }else{
            aux = aux->anterior;
        }
    }
    if(!val){
        printf("\nNo existe un elemento con esa marca!");
    }else{
        printf("\nDato cambiado con exito!(Desde atr�s)");
    }

    return inicio;
}

Nodo * cambiarColor(Nodo * inicio,char cActual[], char cNuevo[]){
    Nodo *aux;
    bool val = false;

    aux = inicio;
    while(aux != NULL){
        if (strcmp(aux->color,cActual) == 0){
            strcpy(aux->color,cNuevo);
            val = true;
            break;
        }else{
            aux = aux->siguiente;
        }
    }
    if(!val){
        printf("\nNo existe un elemento con ese color!");
    }else{
        printf("\nDato cambiado con exito! (Desde el inicio)");
    }

    return inicio;
}

Nodo * cambiarColorFromBack(Nodo * inicio,char cActual[], char cNuevo[]){
    Nodo *aux;
    bool val = false;

    aux = inicio;
    while(aux->siguiente !=NULL){
        aux = aux->siguiente;
    }
    while(aux != NULL){
        if (strcmp(aux->color,cActual) == 0){
            strcpy(aux->color,cNuevo);
            val = true;
            break;
        }else{
            aux = aux->anterior;
        }
    }
    if(!val){
        printf("\nNo existe un elemento con ese color!");
    }else{
        printf("\nDato cambiado con exito! (Desde el atr�s)");
    }

    return inicio;
}

Nodo * cambiarPlaca(Nodo * inicio,char pActual[], char pNuevo[]){
    Nodo *aux;
    bool val = false;

    aux = inicio;
    while(aux != NULL){
        if (strcmp(aux->placa,pActual) == 0){
            strcpy(aux->placa,pNuevo);
            val = true;
            break;
        }else{
            aux = aux->siguiente;
        }
    }
    if(!val){
        printf("\nNo existe un elemento con esa placa!");
    }else{
        printf("\nDato cambiado con exito! (Desde el inicio)");
    }

    return inicio;
}

Nodo * cambiarPlacaFromBack(Nodo * inicio,char pActual[], char pNuevo[]){
    Nodo *aux;
    bool val = false;

    aux = inicio;
    while(aux->siguiente !=NULL){
        aux = aux->siguiente;
    }
    while(aux != NULL){
        if (strcmp(aux->placa,pActual) == 0){
            strcpy(aux->placa,pNuevo);
            val = true;
            break;
        }else{
            aux = aux->anterior;
        }
    }
    if(!val){
        printf("\nNo existe un elemento con esa placa!");
    }else{
        printf("\nDato cambiado con exito! (Desde el atr�s)");
    }

    return inicio;
}

Nodo *fDataI(Nodo *lst, FILE *fL){
    char marca[25], color[25], placa[25];
    while(feof(fL) == 0){
        fscanf(fL,"%s\t%s\t%s\n",&marca,&color,&placa);
        lst = insertarFinal(lst,marca,color,placa);
    }
    return lst;
}

#endif

