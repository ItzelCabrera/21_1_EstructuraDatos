#ifndef _ARBOLES_VLA_H_
#define _ARBOLES_VLA_H_
#include<stdlib.h>
#include<stdio.h>
#define MAXIMO(i,d)((i)>(d))? (i):(d)

typedef struct _NODO{
    int dato;
    int fe;
    struct _NODO *izquierdo;
    struct _NODO *derecho;
}Nodo;

Nodo * crear(int d){
    Nodo *nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = d;
    nuevo->fe = 0;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;

    return nuevo;
}

int altura(Nodo *arbol){
    if(arbol == NULL)
        return 0;
    else
        return MAXIMO(altura(arbol->izquierdo)+1,altura(arbol->derecho)+1);
}

int FE(Nodo *arbol){
    if(arbol == NULL)
        return 0;
    else
        return ( (altura(arbol->derecho)) - (altura(arbol->izquierdo)) ); //retorna el fe
}

void actualizarFE(Nodo *raiz){
    if(raiz != NULL){
        raiz->fe = FE(raiz);
        actualizarFE(raiz->izquierdo);
        actualizarFE(raiz->derecho);
    }
}
void ver_PRE(Nodo *padre){
    if(padre != NULL){
        printf("%d[%d],\t",padre->dato,padre->fe);
        ver_PRE(padre->izquierdo);
        printf("*");
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

Nodo *Rotacion_LL(Nodo *r){
    printf("\nLL");
    Nodo *ri = NULL;
    ri = r->izquierdo;

    r->izquierdo = ri->derecho;
    ri->derecho = r;
    r = ri;

return r;
}

Nodo *Rotacion_RR(Nodo *r){
    Nodo *rd = NULL;
    rd = r->derecho;
    printf("\nRR");

    //ver_PRE(rd);
    //printf("\n");
    //ver_PRE(r);

    r->derecho = rd->izquierdo;
    //printf("\n1");
    //ver_PRE(r);

    rd->izquierdo = r;
    //printf("\n2");
    //ver_PRE(rd);

    r = rd;
    //printf("\n3");
    //ver_PRE(r);
    //ver_PRE(rd);
return r;
}

Nodo *Rotacion_LR(Nodo *r){
    printf("\nLR");
    Nodo *ri = r->izquierdo;
    Nodo *rd = ri->derecho;

    ri->derecho = rd->izquierdo;
    rd->izquierdo = ri;
    r->izquierdo = rd->derecho;
    rd->derecho = r;
    r = rd;

return r;
}

Nodo *Rotacion_RL(Nodo *r){
    printf("\nRL");
    Nodo *rd = r->derecho;
    Nodo *ri = rd->izquierdo;

    rd->izquierdo = ri->derecho;
    ri->derecho = rd;
    r->derecho = ri->izquierdo;
    ri->izquierdo = r;
    r = ri;

return r;
}

void *Rotacion(Nodo *arbol){
    Nodo *r = NULL; //desconecto el arbol
    if(arbol != NULL){
        if( (arbol->fe) < (-1)){
            r = arbol->izquierdo;
            if((r->izquierdo->fe) < 0)
                arbol->izquierdo = Rotacion_LL(r); //reconecto ya rotado
            else
                arbol->izquierdo = Rotacion_RL(r);//reconecto ya rotado
        }else if( (arbol->fe) > 1){
            r = arbol->derecho;
            if((r->derecho->fe) > 0)
                arbol->derecho = Rotacion_RR(r);//reconecto ya rotado
            else
                arbol->derecho = Rotacion_LR(r);//reconecto ya rotado

        }else{
            printf("\nArbol equilibrado");
        }

        actualizarFE(arbol);

    }
    /*if(arbol != NULL){
        if( (arbol->fe < 0) && (arbol->izquierdo->fe < 0)){
            r = arbol->izquierdo;
            arbol->izquierdo = Rotacion_LL(r); //reconecto ya rotado
        }else if( (arbol->fe > 0) && (arbol->derecho->fe > 0)){
            r = arbol->derecho;
            arbol->derecho = Rotacion_RR(r); //reconecto ya rotado
        }else if( (arbol->fe > 0) && (arbol->derecho->fe < 0)){
            r = arbol->derecho;
            arbol->derecho = Rotacion_LR(r); //reconecto ya rotado
        }else if( (arbol->fe < 0) && (arbol->izquierdo->fe > 0)){
            r = arbol->izquierdo;
            arbol->izquierdo = Rotacion_RL(r); //reconecto ya rotado
        }else
            printf("\nArbol equilibrado");


        actualizarFE(arbol);
    }*/
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
                    actualizarFE(arbol);
                    return arbol;
                }else{
                    raiz = raiz->derecho;
                }
            }else{
                if(raiz->izquierdo == NULL){
                    raiz->izquierdo = nuevo;
                    actualizarFE(arbol);
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
            actualizarFE((*arbol));
        }
    }

}



#endif
