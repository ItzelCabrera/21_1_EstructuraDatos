#include "PILA.h"

int main(){

    Nodo *pila;
    pila = NULL; //cuando sea necesario inicizlizar estructuras, se inicializan s null

    pila = apilar(pila,89);
    pila = apilar(pila,1);
    pila = apilar(pila,7);

    ver(pila);
    printf("\nNumero elementos: %d\n",contar(pila));

    pila = desapilar(pila);

    ver(pila);
    printf("\nNumero elementos: %d\n",contar(pila));

    return 0;
}
