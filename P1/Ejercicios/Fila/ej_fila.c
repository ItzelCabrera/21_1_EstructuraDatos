#include<stdio.h>
#include<stdlib.h>
#include"FILA.h"

int main(){
    Nodo * fila;
    fila = NULL;

    fila = insertarElem(fila,1);
    fila = insertarElem(fila,2);
    fila = insertarElem(fila,3);
    fila = insertarElem(fila,4);

    ver(fila);

    fila = sacarElem(fila);
    fila = sacarElem(fila);

    ver(fila);


    return 0;
}
