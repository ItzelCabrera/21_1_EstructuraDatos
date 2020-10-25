#ifndef _PILA_H_
#define _PILA_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct _NODO{
    int dato;
    struct _Nodo *siguiente;
}Nodo;

Nodo * crear(int d){
    Nodo * nuevo;
    nuevo = (Nodo *)malloc(sizeof(Nodo)); //si malloc no logra retornar un puntero va a retornar un null 0 o un -1 --> por lo tanto, hay que realizar una comparación y manejar un error
    nuevo->dato = d; //el operador -> funciona para acceder a ese miembro pero mediante un puntero
    nuevo->siguiente = NULL;

    return nuevo;
}

/*OPERACION ALTA O PUSH
-Retorna una variable de tipo puntero nodo
-Debe recibir la cima y el dato que se guarda en la cajita (d)
*/

Nodo * apilar(Nodo * cima, int d){
    Nodo * nuevo;
    nuevo = crear(d);
    //la nueva cajita que se va a crear se tiene que referenciar a la cajita que esta en la cima; para ello hay que verificar la cima primero:
    if (cima != NULL){ //por lo menos hay una cajita
        nuevo->siguiente = cima; //con esto no se pierden las relaciones entre las cajitas; es comoreemplazarnos entre los vectores con los indices
    }
    return nuevo;
}

/*
OPERACION PUSH-PARA ELIMINAR ELEMENTOS DE LA PILA
-Obviamente la cima se tiene que estar actualizando
-Retorna una variable puntero al nodo
-Recibe la referencia a la cima que va a quitar
*/

Nodo *desapilar(Nodo * cima){
    Nodo * aux;
    aux = cima; //se referencia a la cima
    //corregir un posible underflow
    if (cima != NULL){//hay algo
        cima = cima->siguiente;
        free(aux);
    }
    return cima;
}

/*
OPERACION VER LOS ELEMENTOS DE LA PILA_
si pasa una cima == NULL entonces que muestre que es nula
si cima no es nula, que pase el numero de la cajita
*/
void ver (Nodo * cima){
    if(cima == NULL){
        printf("\nNo hay ningun elemento en la pila\n");
    }else{
        while(cima != NULL){
        //hay que ir moviendo las cimas hasta llegar a null
        printf("\nDato: %d",cima->dato);
        cima = cima->siguiente;
        }
    }
}

int contar (Nodo * cima){
    int c = 0;
    if(cima == NULL){
        printf("\n0 elementos\n");
    }else{
        while(cima != NULL){
        //hay que ir moviendo las cimas hasta llegar a null
        c++;
        cima = cima->siguiente;
        }
        return c;
    }
}

//Lee un archivo y de esos elementos leídos los acomode en una pila
Nodo * apilar_F(Nodo * cima, FILE * FL){
    char tittle[15];

    fscanf(FL,"%s\n",&tittle);

    //printf("\nTITULO %s\n",tittle);

    while(feof(FL) == 0){
        int d;
        fscanf(FL,"%i\n",&d); //lee el flujo y va almacenando lo leido en las variables
        //printf("%d\n",d);
        cima = apilar(cima,d);
    }

    return cima;
}

//Los elementos de una pila los acomoda en un archivo
void copiar_F(Nodo * cima, FILE * FE){
    char tittle[15] = "PILA";
    if(cima == NULL){
        printf("\nNo hay ningun elemento en la pila\n");
    }else{
        while(cima != NULL){
        //hay que ir moviendo las cimas hasta llegar a null
        fprintf(FE,"%d\n",cima->dato);
        cima = cima->siguiente;
        }
    }
}
#endif
