#ifndef _LISTADOBLE_H_
#define _LISTADOBLE_H_
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct _NODO{
    int dato;
    struct _NODO *siguiente;
    struct _NODO *anterior;
}Nodo;

Nodo *crear(int d){
    Nodo * nuevo;
    nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = d;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    return nuevo;
}

void ver (Nodo *frente){
    if(frente == NULL){
        printf("\nNo hay ningun elemento en la lista\n");
    }else{
        while(frente != NULL){
            printf("\nDato: %d",frente->dato);
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
            printf("\nDato: %d",frente->dato);
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

Nodo *insertarInicio(Nodo * inicio, int d){
    Nodo * nuevo;
    nuevo = crear(d);

    if (inicio != NULL){
        nuevo->siguiente = inicio;
        inicio->anterior = nuevo;
    }
    return nuevo;
}

Nodo * insertarXP(Nodo *inicio, int posicion, int dato){
    Nodo *nuevo;
    Nodo *aux;
    int longitudLista = contar(inicio);

    nuevo = crear(dato);

    if (posicion >= 1 && posicion <= longitudLista){
        if (posicion == 1){
            inicio = insertarInicio(inicio,dato);
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

        }
    }else{
        printf("\nPosicion invalida! (%d)",posicion);
    }
    return inicio;
}

Nodo * insertarFinal(Nodo * inicio, int dato){
    Nodo * nuevo;
    nuevo = crear(dato);

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
    if (inicio->siguiente == NULL){ //sólo hay un elemento
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


    }
    return inicio;
}

Nodo * cambiarDato(Nodo * inicio,int datoActual, int datoNuevo){
    Nodo *aux;
    bool val = false;

    aux = inicio;
    while(aux != NULL){
        if (aux->dato == datoActual){
            aux->dato = datoNuevo;
            val = true;
            break;
        }else{
            aux = aux->siguiente;
        }
    }
    if(!val){
        printf("\nNo existe un elemento con ese dato!");
    }else{
        printf("\nDato cambiado con exito!");
    }

    return inicio;
}

Nodo * cambiarDatoFromBack(Nodo * inicio,int datoActual, int datoNuevo){
    Nodo *aux;
    bool val = false;

    aux = inicio;
    while(aux->siguiente !=NULL){
        aux = aux->siguiente;
    }
    while(aux != NULL){
        if (aux->dato == datoActual){
            aux->dato = datoNuevo;
            val = true;
            break;
        }else{
            aux = aux->anterior;
        }
    }
    if(!val){
        printf("\nNo existe un elemento con ese dato!");
    }else{
        printf("\nDato cambiado con exito!");
    }

    return inicio;
}

Nodo *ordenar_INSERCIONSIMPLE(Nodo *frente){
    /*
    Usa el método de inserción.
    No se cambian las cajitas, sólo los datos
    */
    Nodo *aux;
    Nodo *aux2;

    int m = 0;
    int M = 0;

    aux = frente;
    aux = aux->siguiente; //el primer elemento se  considera ya ordenado
    while(aux != NULL){
        aux2 = aux;
        while(aux2->anterior != NULL){
            if(aux2->dato < aux2->anterior->dato){ //comparan los datos
                //cambian datos
                m = aux2->dato;
                aux2->dato = aux2->anterior->dato;
                aux2->anterior->dato = m;

                //mueve aux2 para seguir comparando
                aux2 = aux2->anterior;
                continue;
            }else{
                //si el anterior ya esta ordenado, tambien los anteriores
                break;
            }
        }
        aux = aux->siguiente;
    }
    free(aux);

    return frente;
}

#endif
