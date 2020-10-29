#ifndef _PILA_H_
#define _PILA_H_
#include <stdio.h>
#include <stdlib.h>

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

void ver (Nodo * cima){
    if(cima == NULL){
        printf("\nNo hay ningun elemento en la pila\n");
    }else{
        while(cima != NULL){
        //hay que ir moviendo las cimas hasta llegar a null
        printf("%c",cima->dato);
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
/*Nodo * apilar_F(Nodo * cima, FILE * FL){
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
}*/

void copiar_F(Nodo * cima, FILE * FE){
    char tittle[15] = "PILA";
    if(cima == NULL){
        printf("\nNo hay ningun elemento en la pila\n");
    }else{
        while(cima != NULL){
        //hay que ir moviendo las cimas hasta llegar a null
        fprintf(FE,"%c\n",cima->dato);
        cima = cima->siguiente;
        }
    }
}

char getDato(Nodo * cima){ //obtiene el dato de la cima
    return cima->dato;
}


int getJerarquia(char c){
    switch(c){
    case '^':
        return 2;
        break;
    case '*':
        return 1;
        break;
    case '/':
        return 1;
        break;
    case '+':
        return 0;
        break;
    case '-':
        return 0;
        break;
    default:
        return -1;
        break;

    }
}

int revisar(char c){
    if(isdigit(c)){
        return 1;
    }else if(c == '^' || c == '*' || c == '/' || c == '+' || c == '-'){
        return 2;
    }else if(c == ' '){
        printf("");
    }else if(c == EOF){
        printf("");
    }else {
        printf("Caracter irreconocible");
    }

    return 9;
}
#endif

