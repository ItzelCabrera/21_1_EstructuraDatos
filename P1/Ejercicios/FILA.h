#ifndef _FILA_H_
#define _FILA_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct _NODO{
    int dato;
    struct _Nodo *siguiente;
}Nodo;


Nodo * crear(int d){
    Nodo * nuevo;
    nuevo = (Nodo *)malloc(sizeof(Nodo)); //si malloc no logra retornar un puntero va a retornar un null 0 o un -1 --> por lo tanto, hay que realizar una comparación y manejar un error
    nuevo->dato = d;
    nuevo->siguiente = NULL;

    return nuevo;
}

//OPERACION PUSH
Nodo * insertarElem(Nodo * frente, int d){
    Nodo * nuevo;
    nuevo = crear(d);

    //si no hay nada, el elemento a insertar será "nuevo"
    if (frente == NULL){
        frente = nuevo;
    }else{
        Nodo *aux;
        aux = frente;
        while(aux->siguiente != NULL){//se recorre hasta llegar al ult elemento
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo; //el siguiente elem(ultimo) será "nuevo"
    }

    return frente;
}

//OPERACION POP
Nodo *sacarElem(Nodo * frente){
    Nodo * aux;
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



void ver (Nodo * frente){
    if(frente == NULL){
        printf("\nNo hay ningun elemento en la fila\n");
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


//Lee un archivo y lo que lee lo acomoda en una fila
Nodo * insertar_F(Nodo * frente, FILE * FL){
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


//Escribe en un fichero los elementos de una fila
void sacar_F(Nodo * frente, FILE * FE){
    char tittle[15] = "PILA";
    if(frente == NULL){
        printf("\nNo hay ningun elemento en la pila que se pueda escribir en el archivo\n");
    }else{
        while(frente != NULL){
        //hay que ir moviendo las cimas hasta llegar a null
        fprintf(FE,"%d\n",frente->dato);
        frente = frente->siguiente;
        }
    }
}
#endif

