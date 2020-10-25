#ifndef _PILA_H_
#define _PILA_H_
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<ctype.h>

typedef struct _NODO{
    int dato;
    struct _Nodo *siguiente;
}Nodo;

Nodo * crear(int d){
    Nodo * nuevo;
    nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = d;
    nuevo->siguiente = NULL;

    return nuevo;
}

Nodo * apilar(Nodo * cima, int d){
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
        c++;
        cima = cima->siguiente;
        }
        return c;
    }
}

Nodo * apilar_F(Nodo * cima, FILE * FL){
    char tittle[15];

    fscanf(FL,"%s\n",&tittle);


    while(feof(FL) == 0){
        int d;
        fscanf(FL,"%i\n",&d);
        cima = apilar(cima,d);
    }

    return cima;
}

void copiar_F(Nodo * cima, FILE * FE){
    if(cima == NULL){
        printf("\nNo hay ningun elemento en la pila\n");
    }else{
        while(cima != NULL){
        fprintf(FE,"%d\n",cima->dato);
        cima = cima->siguiente;
        }
    }
}

int getDato(Nodo * cima){ //obtiene el dato de la cima
    return cima->dato;
}

int operar(int d1, int d2,int n){
    int res = 0;
    switch(n){
        case 37://Modulo
            res = d2 % d1;
            break;
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
        printf("\nRevisando");
        int n;
        int d[2],res;

        if (isdigit(c)){//revisa si es un dig
            n = (int)c - 48;
            pila = apilar(pila,n); //apila el digito
        }else if( c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^') { //revisa si es un operador
            n = (int)c;
            //obtiene el dato de la "cajita" y elimina esa "cajita"
            for(int i = 0; i < 2; i++){
                d[i] = getDato(pila);
                pila = desapilar(pila);
            }
            res = operar(d[0],d[1],n); //opera los ult 2 datos
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
