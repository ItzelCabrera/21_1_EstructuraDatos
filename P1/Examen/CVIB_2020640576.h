#ifndef _PILA_H_
#define _PILA_H_
#include <stdio.h>
#include <stdlib.h>
#include"FILA.h"

typedef struct _NODO{
    char dato;
    struct _NODO *siguiente;
}Nodo;

Nodo * crear(char d){
    Nodo * nuevo;
    nuevo = (Nodo *)malloc(sizeof(Nodo)); //si malloc no logra retornar un puntero va a retornar un null 0 o un -1 --> por lo tanto, hay que realizar una comparación y manejar un error
    nuevo->dato = d; //el operador -> funciona para acceder a ese miembro pero mediante un puntero
    nuevo->siguiente = NULL;

    return nuevo;
}

Nodo * apilar(Nodo * cima, char d){
    Nodo * nuevo;
    nuevo = crear(d);
    //la nueva cajita que se va a crear se tiene que referenciar a la cajita que esta en la cima; para ello hay que verificar la cima primero:
    if (cima != NULL){ //por lo menos hay una cajita
        nuevo->siguiente = cima; //con esto no se pierden las relaciones entre las cajitas; es comoreemplazarnos entre los vectores con los indices
    }
    return nuevo;
}

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

void verP (Nodo * cima){
    if(cima == NULL){
        printf("\nNo hay ningun elemento en la pila\n");
    }else{
        while(cima != NULL){
        //hay que ir moviendo las cimas hasta llegar a null
        printf("\nDato: %c",cima->dato);
        cima = cima->siguiente;
        }
    }
}

Nodo *vaciar(Nodo *cima){
    while(cima != NULL){
        cima = desapilar(cima);
    }
    return cima;
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
int revisarCima(Nodo *cima,char c){
    if ( (c == '}') && (cima->dato) == '{'){
        return 1;
    }
    if ( (c == ']') && (cima->dato) == '['){
        return 1;
    }
    if ( (c == ')') && (cima->dato) == '('){
        return 1;
    }

    return 2;

}

int revisarPila(Nodo *cima){
    if (cima == NULL){ //la pila vacía --> éxito
        return 1;
    }
    /*if (cima->dato == 'X'){//la pila tiene una X --> fail (se encontr+o una inconsistencia antes de llegar a \n)
        return 2;
    }*/
    //if(cima != 'X'){ //revisar la pila
        return 3;
    //}

}

int revisarSignos(Nodo *cima){
    while(cima != NULL){
        if ( (cima->dato == '}') && (cima->siguiente->dato == '{') && (cima->siguiente != NULL) ){
            cima = cima->siguiente->siguiente;
        }
        if ( (cima->dato == ')') && (cima->siguiente->dato == '(') && (cima->siguiente != NULL) ){
            cima = cima->siguiente->siguiente;
        }
        if ( (cima->dato == ']') && (cima->siguiente->dato == '[') && (cima->siguiente != NULL) ){
            cima = cima->siguiente->siguiente;
        }
        else{
            return 2;
        }
    }
    return 1;
}

int revisarChar(char c){
    if ( (c == '{') || (c == '(') || (c == '[') ){
        return 1;
    }
    if( (c == '}') || (c == ')') || (c == ']') ){
        return 2;
    }
    if( (int)c == 10) {
        return 3;
    }

    return 4;
}

void revisarUltEcuacion(Nodo *pila, Nodo2 *fila){
    int i = 0, p = 0;
    i = revisarPila(pila);
    switch(i){
        case 1://éxito
            fila = insertarElem2(fila,1);
            break;
        /*case 2://fail (encontró un inconsistencia antes de \n)
            fila = insertarElem(fila,0);
            break;*/
        case 3: //revisar pila
            p = revisarSignos(pila);
            switch(p){
                case 1://exito
                    pila = vaciar(pila);
                    printf("\nEXITO");
                    //fila = insertarElem(fila,1);
                    break;
                case 2://fail
                    pila = vaciar(pila);
                    printf("\nERROR");
                    //fila = insertarElem(fila,0);
                    break;
            }
            break;
        default:
            break;
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

