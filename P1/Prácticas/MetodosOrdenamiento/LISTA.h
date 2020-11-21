#ifndef _LISTA_H_
#define _LISTA_H_
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct _NODO{
    int dato;
    struct _NODO *siguiente;
}Nodo;

Nodo *crear(int d){
    Nodo * nuevo;
    nuevo = (Nodo *)malloc(sizeof(Nodo)); //si malloc no logra retornar un puntero va a retornar un null 0 o un -1 --> por lo tanto, hay que realizar una comparación y manejar un error
    nuevo->dato = d; //el operador -> funciona para acceder a ese miembro pero mediante un puntero
    nuevo->siguiente = NULL;

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

Nodo *insertarInicio(Nodo * inicio, int d){
    Nodo * nuevo;
    nuevo = crear(d);

    if (inicio != NULL){ //por lo menos hay un elemento
        nuevo->siguiente = inicio;
    }
    return nuevo;
}

Nodo * insertarXP(Nodo *inicio, int posicion, int dato){
    Nodo *nuevo;
    Nodo *aux;
    int longitudLista = contar(inicio);

    nuevo = crear(dato);//crea un elemento

    if (posicion >= 1 && posicion <= longitudLista){ //se realiza la inserción
        if (posicion == 1){//se quiere insertar al inicio
            inicio = insertarInicio(inicio,dato);
        }
        else{//se quiere insertar en el intermedio
            aux = inicio;
            for(int i = 1; i < posicion-1; i++){//se coloca una posicion antes
                aux = aux->siguiente;
            }
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }else{
        printf("\nPosicion invalida! (%d)",posicion);
    }
    return inicio;
}

Nodo * insertarFinal(Nodo * inicio, int dato){
    Nodo * nuevo;
    nuevo = crear(dato);

    //si no hay nada, se va a referenciar al elemento nuevo creado
    if (inicio == NULL){
        inicio = nuevo;
    }else{
        Nodo *aux;
        aux = inicio;
        while(aux->siguiente != NULL){//se recorre hasta llegar al ultimo elemento
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo; //se inserta el elemento al final
    }

    return inicio;
}

Nodo *borrarInicio(Nodo * inicio){
    //corregir un posible underflow
    if (inicio != NULL){
        inicio = inicio->siguiente;
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
            for(int i = 1; i < posicion-1; i++){//se coloca una posicion antes
                aux = aux->siguiente;
            }

            aux2 = aux;
            aux2 = aux2->siguiente;
            aux->siguiente = aux2->siguiente;
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
    Nodo *aux2;

    if(inicio == NULL){
        printf("\nNo hay elementos por borrar");
    }else{
        aux = inicio;
        for(int i = 1; i < longitudLista-1; i++){//se posiciona en el penultimo lugar
                aux = aux->siguiente;
        }
        aux2 = aux;
        aux2 = aux2->siguiente;
        free(aux2);
        aux->siguiente = NULL;

    }
    return inicio;
}

Nodo * cambiarDato(Nodo * inicio,int datoActual, int datoNuevo){
    Nodo *aux;
    bool val = false;

    aux = inicio;
    while(aux != NULL){
        if (aux->dato == datoActual){//se encontró el elem a cambiar
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

Nodo *ordenar_SELECCIONDIRECTA(Nodo *inicio){
    int n = contar(inicio);
    Nodo *x = inicio;
    Nodo *m;
    Nodo *a1;
    int d = 0;

    while(x != NULL){
        m = x;
        a1 = x;
        for(int i = 0;i < (n-1);i++){
            if( (a1->dato > a1->siguiente->dato) && (a1->siguiente->dato < m->dato )){
                m = a1->siguiente;
            }
            a1 = a1->siguiente;
        }
        d = m->dato;
        m->dato = x->dato;
        x->dato = d;
        x = x->siguiente;
        n= n-1;
    }
    free(x);
    return inicio;

}

Nodo *ordenar_INTERCALACION(Nodo* L1, Nodo* L2){
    Nodo *aux = NULL;
    while((L1 != NULL) || (L2 != NULL)){
        if (L1 != NULL){
            if(L1->dato < L2->dato){
                aux = insertarFinal(aux,L1->dato);
                L1 = L1->siguiente;
            }else{
                aux = insertarFinal(aux,L2->dato);
                L2 = L2->siguiente;
            }
        }else{
            aux = insertarFinal(aux,L2->dato);
            L2 = L2->siguiente;
        }
    }

    free(L1);
    free(L2);
    return aux;

}

Nodo *concatenarListas(Nodo *dst, Nodo* src,int v){
    if (v ==1){
        while(src != NULL){
            dst = insertarFinal(dst,src->dato);
            src = src->siguiente;
        }
    }else{
        while(src != NULL){
            dst = insertarInicio(dst,src->dato);
            src = src->siguiente;
        }
    }

    return dst;

}

Nodo *ordenar_QUICKSORT(Nodo *inicio){
    Nodo *aux = NULL;
    Nodo *pivote = NULL;
    Nodo *m = NULL;
    Nodo *M = NULL;
    Nodo *resultado = NULL;

    aux = inicio->siguiente;
    pivote = inicio;
    while(aux != NULL){
        if ( (pivote->dato) > (aux->dato) ){
            m = insertarFinal(m,aux->dato);
        }else{
            M = insertarFinal(M,aux->dato);
        }
        aux = aux->siguiente;
    }

    printf("\n\nLista menor...\n");
    ver(m);

    printf("\n\nPIVOTE: %d\n",pivote->dato);

    printf("\n\nLista mayor...\n");
    ver(M);

    if(contar(m) > 1){
        m = ordenar_QUICKSORT(m);
    }else{
        printf("\nYa solo hay un elemento m \n");
        m = insertarFinal(m,pivote->dato);
        printf("\n\nC menor...\n");
        ver(m);
    }

    if(contar(M) > 1){
        M = ordenar_QUICKSORT(M);
    }else{
        printf("\nYa solo hay un elemento M\n");
        M = insertarInicio(M,pivote->dato);
        printf("\n\nC mayor...\n");
        ver(M);
    }

    return resultado;
}

/*Nodo * pullFromFile(Nodo * frente, FILE * FL){
    char tittle[15];

    fscanf(FL,"%s\n",&tittle);

    //printf("\nTITULO %s\n",tittle);

    while(feof(FL) == 0){
        int d;
        fscanf(FL,"%i\n",&d); //lee el flujo y va almacenando lo leido en las variables
        //printf("%d\n",d);
        frente = insertarElem(frente,d);
    }

    return frente;
}



void pushToFile(Nodo * frente, FILE * FE){
    char tittle[15] = "PILA";
    if(frente == NULL){
        printf("\nNo hay ningun elemento en la fila que se pueda escribir en el archivo\n");
    }else{
        while(frente != NULL){
        //hay que ir moviendo las cimas hasta llegar a null
        fprintf(FE,"%d\n",frente->dato);
        frente = frente->siguiente;
        }
    }
}*/


#endif

