#ifndef _ARBOLES_H_
#define _ARBOLES_H_
#include<stdlib.h>
#include<stdio.h>
#define MAXIMO(i,d)((i)>(d))? (i):(d)

typedef struct _NODO{
    int dato;
    struct _NODO *izquierdo;
    struct _NODO *derecho;
}Nodo;

Nodo * crear(int d){
    Nodo *nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = d;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;

    return nuevo;
}

Nodo *insertar(Nodo *arbol, int d){
    Nodo *raiz = NULL;
    Nodo *nuevo = crear(d);

    if(arbol == NULL){
        return nuevo;
    }else{
        raiz = arbol;
        while(raiz != NULL){
            if(nuevo->dato > raiz->dato){
                if(raiz->derecho == NULL){
                    raiz->derecho = nuevo;
                    return arbol;
                }else{
                    raiz = raiz->derecho;
                }
            }else{
                if(raiz->izquierdo == NULL){
                    raiz->izquierdo = nuevo;
                    return arbol;
                }else{
                    raiz = raiz->izquierdo;
                }
            }
        }
    }

}

void moverIzquierda(Nodo **arbol){
    Nodo *aux = NULL;   //subarbol
    Nodo *aux1 = NULL; //dato mayor

    aux1 = (*arbol);
    aux = (*arbol)->izquierdo;

    while(aux->derecho != NULL){
        aux1 = aux;
        aux = aux->derecho;
    }

    (*arbol)->dato = aux->dato;

    if(aux1 ==(*arbol)) //si no nos recorrimos
        aux1->izquierdo = aux->izquierdo;
    else
        aux1->derecho = aux->izquierdo;

    (*arbol) = aux;

}

void borrar(Nodo **arbol,int dBuscar){
    Nodo *aux = NULL;

    if(*(arbol) == NULL){//caso que no encuentre el nodo
        printf("\nNo se encuentra el nodo a borrar");
    }else{//si existen nodos
        if(dBuscar < (*arbol)->dato)
            borrar(&(*arbol)->izquierdo,dBuscar);
        else if(dBuscar > (*arbol)->dato)
            borrar(&(*arbol)->derecho,dBuscar);
        if(dBuscar == (*arbol)->dato){
            aux = (*arbol);
            if(aux->izquierdo == NULL)
                (*arbol) = aux->derecho;
            else if(aux->derecho == NULL)
                (*arbol) = aux->izquierdo;
            else //cuando tiene dos hijos
                moverIzquierda(&aux);
            free(aux);
        }
    }

}

void ver_PRE(Nodo *padre){
    if(padre != NULL){
        printf("%d,\t",padre->dato);
        ver_PRE(padre->izquierdo);
        ver_PRE(padre->derecho);
    }
}

void ver_IN(Nodo *padre){
    if(padre != NULL){
        ver_IN(padre->izquierdo);
        printf("%d,\t",padre->dato);
        ver_IN(padre->derecho);
    }
}

void ver_POST(Nodo *padre){
    if(padre != NULL){
        ver_POST(padre->izquierdo);
        ver_POST(padre->derecho);
        printf("%d,\t",padre->dato);
    }
}

int altura(Nodo *arbol){
    if(arbol == NULL)
        return 0;
    else
        return MAXIMO(altura(arbol->izquierdo)+1,altura(arbol->derecho)+1);
}

#endif
