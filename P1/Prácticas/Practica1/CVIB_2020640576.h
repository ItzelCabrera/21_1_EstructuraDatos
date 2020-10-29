#ifndef _PILA_H_
#define _PILA_H_
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<ctype.h>

typedef struct _NODO{
    float dato;
    struct _NODO *siguiente;
}Nodo;

Nodo * crear(float d){
    Nodo * nuevo;
    nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = d;
    nuevo->siguiente = NULL;

    return nuevo;
}

Nodo * apilar(Nodo * cima, float d){
    Nodo * nuevo;
    nuevo = crear(d);

    if (cima != NULL){
        nuevo->siguiente = cima;
    }
    return nuevo;
}

Nodo *desapilar(Nodo * cima){
    Nodo * aux;
    aux = cima;
    if (cima != NULL){
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
        printf("\nDato: %f",cima->dato);
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
        c++;
        cima = cima->siguiente;
        }
        return c;
    }
}


void copiar_F(Nodo * cima, FILE * FE){
    if(cima == NULL){
        printf("\nNo hay ningun elemento en la pila\n");
    }else{
        while(cima != NULL){
        fprintf(FE,"%f\n",cima->dato);
        cima = cima->siguiente;
        }
    }
}

float getDato(Nodo * cima){ //obtiene el dato de la cima
    return cima->dato;
}

float operar(float d1, float d2,int n){
    float res = 0;
    switch(n){
        case 42://Multiplicación
            res = d2 * d1;
            break;
        case 43://Suma
            res = d2 + d1;
            break;
        case 45://Resta
            res = d2 - d1;
            break;
        case 47://División
            res = d2 / d1;
            break;
        case 94://Potencia
            res = pow(d2,d1);
            break;
        default:
            exit(1);
            break;
    }
return res;
}


Nodo * revisarC(char c,Nodo *pila){
        float n;
        int operador;
        float d[2],res;

        if (isdigit(c)){//revisa si es un dig
            n = (float)c - 48;
            pila = apilar(pila,n); //apila el digito
        }else if( c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^') { //revisa si es un operador
            operador = (int)c;
            //obtiene el dato de la "cajita" y elimina esa "cajita"
            for(int i = 0; i < 2; i++){
                d[i] = getDato(pila);
                pila = desapilar(pila);
                //printf("\n2-->d[%i] = %f",i,d[i]);
            }
            res = operar(d[0],d[1],operador); //opera los ult 2 datos
            pila = apilar(pila,res);//apila el resultado
        }else if( c == ' '){
            printf("");
        }else if(c == EOF){
            printf("");
        }else{ //si no reconoce el caracter
            printf("\nCaracter irreconocible");
            exit(1);
        }
return pila;
}
#endif

/*BIBLIOGRAFÍA:
Alexander Borbón A. Escuela de Matemática Instituto Tecnológico de Costa Rica
[online] nsw. Available at: <https://tecdigital.tec.ac.cr/revistamatematica/ContribucionesV7_n2_2006/Parseador/node9.html>
[Accessed 11 October 2020].*/
