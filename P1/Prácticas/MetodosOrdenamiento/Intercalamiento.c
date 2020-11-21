#include"LISTA.H"

int main(){

    Nodo *lista1 = NULL;
    Nodo *lista2 = NULL;
    Nodo *listaOrdenada = NULL;

    //Llena una lista arbitraria
    lista1 = insertarInicio(lista1,9);
    lista1 = insertarInicio(lista1,4);
    lista1 = insertarInicio(lista1,2);
    lista2 = insertarInicio(lista2,10);
    lista2 = insertarInicio(lista2,10);
    lista2 = insertarInicio(lista2,9);
    lista2 = insertarInicio(lista2,7);
    lista2 = insertarInicio(lista2,4);

    printf("\nLista inicial 1: \n");
    ver(lista1);

    printf("\n\nLista inicial 2: \n");
    ver(lista2);

    listaOrdenada = ordenar_INTERCALACION(lista1,lista2);
    printf("\n\nLista ordenada: \n");
    ver(listaOrdenada);

    free(lista1);
    free(lista2);

    return 0;
}

