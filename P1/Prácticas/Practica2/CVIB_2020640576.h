#ifndef _FILA_H_
#define _FILA_H_
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>


typedef struct _NODO{
    char marca[25];
    char color[25];
    char placa[25];
    struct _Nodo *siguiente;
}Nodo;

Nodo * crear(char m[],char c[],char p[]){
    Nodo * nuevo;
    nuevo = (Nodo *)malloc(sizeof(Nodo)); //si malloc no logra retornar un puntero va a retornar un null 0 o un -1 --> por lo tanto, hay que realizar una comparación y manejar un error
    strcpy(nuevo->marca,m);
    strcpy(nuevo->color,c);
    strcpy(nuevo->placa,p);
    nuevo->siguiente = NULL;

    return nuevo;
}


/*OPERACION ALTA O PUSH
-Retorna una variable de tipo puntero nodo
-Debe recibir la frente y el dato que se guarda en la cajita (d)
*/

Nodo * insertarElem(Nodo * frente,char m[],char c[],char p[]){
    Nodo * nuevo;
    nuevo = crear(m,c,p);

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
            printf("\nMarca: %s",frente->marca);
            printf("\tColor: %s",frente->color);
            printf("\tPlaca: %s",frente->placa);
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


Nodo * insertar_F(Nodo * frente, FILE * FL){
    char m[25],c[25],p[25];
    while(feof(FL) == 0){
        fscanf(FL,"%s\t%s\t%s\n",&m,&c,&p);
        frente = insertarElem(frente,m,c,p);
    }

    return frente;
}



void sacar_F(Nodo * frente, FILE * FE){
    char tittle[15] = "Fila Final";
    if(frente == NULL){
        printf("\nNo hay ningun elemento en la fia que se pueda escribir en el archivo\n");
    }else{
        while(frente != NULL){
        //hay que ir moviendo las cimas hasta llegar a null
        fprintf(FE,"%s\t%s\t%s\n",frente->marca,frente->color,frente->placa);
        frente = frente->siguiente;
        }
    }
}
#endif


