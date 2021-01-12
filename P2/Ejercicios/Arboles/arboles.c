#include"ARBOLES.h"

int main(){
    Nodo *arbol = NULL;

    arbol = insertar(arbol,23);
    arbol = insertar(arbol,32);
    arbol = insertar(arbol,18);
    arbol = insertar(arbol,7);
    arbol = insertar(arbol,14);
    arbol = insertar(arbol,21);
    arbol = insertar(arbol,29);
    arbol = insertar(arbol,40);

    printf("PRE-ORDER\n");
    ver_PRE(arbol);
    printf("\nIN-ORDER\n");
    ver_IN(arbol);
    printf("\nPOS-ORDER\n");
    ver_POST(arbol);

    printf("\n\nAltura = %d\n\n",altura(arbol));

    borrar((&arbol),21);
    borrar((&arbol),7);
    borrar((&arbol),32);

    printf("\nPRE-ORDER\n");
    ver_PRE(arbol);
    printf("\nIN-ORDER\n");
    ver_IN(arbol);
    printf("\nPOS-ORDER\n");
    ver_POST(arbol);

    return 0;
}
