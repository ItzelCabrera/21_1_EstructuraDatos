#ifndef _CVIB_2020640576_H_
#define _CVIB_2020640576_H_
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct _NODO{
    char nombre [15];
    int edad;
    char CURP[20];
    struct _NODO *siguiente;
    struct _NODO *anterior;
}Nodo;

Nodo *crear(char n[], int e, char c[]){
    Nodo * nuevo;
    nuevo = (Nodo *)malloc(sizeof(Nodo));
    strcpy(nuevo->nombre,n);
    nuevo->edad = e;
    strcpy(nuevo->CURP,c);
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    return nuevo;
}

void ver (Nodo *frente){
    if(frente == NULL){
        printf("\nNo hay ningun elemento en la lista doblemente enlazada\n");
    }else{
        while(frente != NULL){
            printf("\nNombre: %s\tEdad: %d\tCURP: %s",frente->nombre,frente->edad,frente->CURP);
            frente = frente->siguiente;
        }
    }
}

void verInverso (Nodo *frente){
    if(frente == NULL){
        printf("\nNo hay ningun elemento en la lista doblemente enlazada\n");
    }else{
        while(frente->siguiente!=NULL){
            frente = frente->siguiente;
        }
        while(frente != NULL){
            printf("\nNombre: %s\tEdad: %d\tCURP: %s",frente->nombre,frente->edad,frente->CURP);
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

Nodo *insertarInicio(Nodo * inicio, char n[], int e, char c[]){
    Nodo * nuevo;
    nuevo = crear(n,e,c);

    if (inicio != NULL){
        nuevo->siguiente = inicio;
        inicio->anterior = nuevo;
    }
    printf("\nPersona insertada al inicio");
    return nuevo;
}

Nodo * insertarXP(Nodo *inicio, int posicion,char n[], int e, char c[]){
    Nodo *nuevo;
    Nodo *aux;
    int longitudLista = contar(inicio);

    nuevo = crear(n,e,c);

    if (posicion >= 1 && posicion <= longitudLista){
        if (posicion == 1){
            inicio = insertarInicio(inicio,n,e,c);
        }
        else{
            aux = inicio;
            for(int i = 1; i < posicion-1; i++){
                aux = aux->siguiente;
            }
            nuevo->siguiente = aux->siguiente;
            nuevo->anterior=aux;
            aux->siguiente = nuevo;
            nuevo->siguiente->anterior = nuevo;
            printf("\nPersona insertada en %d", posicion);
        }
    }else{
        printf("\nPosicion invalida! (%d)",posicion);
    }
    return inicio;
}

Nodo * insertarFinal(Nodo * inicio, char n[], int e, char c[]){
    Nodo * nuevo;
    nuevo = crear(n,e,c);

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

    printf("\nPersona insertada al final");
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
        printf("\nPersona inicial borrada ");
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
            printf("\nPersona %d borrada",posicion);
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
        printf("\nPersona final borrada");

    }
    return inicio;
}

//Lee un fichero y la información la almacena en una lista doblemente enlazada
Nodo *fDataI(Nodo *lst, FILE *fL){
    char nombre[15], CURP[20];
    int edad;
    while(feof(fL) == 0){
        fscanf(fL,"%s\t%d\t%s\n",&nombre,&edad,&CURP);
        lst = insertarFinal(lst,nombre,edad,CURP);
    }
    return lst;
}

//Copia una lista doblemente enlazada en un archivo
Nodo *fDataO(Nodo *lst, FILE *fE){
    Nodo *aux;
    aux = lst;
    while(aux != NULL){
        fprintf(fE,"%s\t%d\t%s\n",aux->nombre,aux->edad,aux->CURP);
        aux = aux->siguiente;
    }
    return lst;
}

Nodo *ordenar(Nodo *frente){
    /*
    Usa el método de inserción.
    No se cambian las cajitas, sólo los datos
    */
    Nodo *aux;
    Nodo *aux2;

    char C1[20] = " ";
    char n1[15] = " ";
    int e1 = 0;

    aux = frente;
    aux = aux->siguiente; //el primer elemento se  considera ya ordenado

    while(aux != NULL){
        aux2 = aux;
        while(aux2->anterior != NULL){
            if(strcmp(aux2->CURP,aux2->anterior->CURP) < 0){ //comparan los datos //aux2->dato < aux2->anterior->dato
                //Cambio de datos
                //Curps
                strcpy(C1,aux2->CURP);
                strcpy(aux2->CURP,aux2->anterior->CURP);
                strcpy(aux2->anterior->CURP,C1);

                //Nombres
                strcpy(n1,aux2->nombre);
                strcpy(aux2->nombre,aux2->anterior->nombre);
                strcpy(aux2->anterior->nombre,n1);

                //Edades
                e1 = aux2->edad;
                aux2->edad = aux2->anterior->edad;
                aux2->anterior->edad = e1;

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


