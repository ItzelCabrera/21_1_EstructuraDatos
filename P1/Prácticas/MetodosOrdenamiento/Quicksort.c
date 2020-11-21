#include"LISTA.h"

int main(){
    Nodo *lista = NULL;

    lista = insertarInicio(lista,2);
    lista = insertarInicio(lista,8);
    lista = insertarInicio(lista,20);
    lista = insertarInicio(lista,4);
    lista = insertarInicio(lista,7);
    lista = insertarInicio(lista,3);
    lista = insertarInicio(lista,1);
    lista = insertarInicio(lista,5);

    lista = ordenar_QUICKSORT(lista);

    printf("\n******");
    ver(lista);
    printf("\n******");





    return 0;
}
