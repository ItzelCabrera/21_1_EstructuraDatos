#include"LISTADOBLE.H"

int main(){

    Nodo *lista = NULL;

    //Llena una lista arbitraria
    lista = insertarInicio(lista,9);
    lista = insertarInicio(lista,4);
    lista = insertarInicio(lista,2);
    lista = insertarInicio(lista,1);
    lista = insertarInicio(lista,3);
    lista = insertarInicio(lista,3);
    lista = insertarInicio(lista,10);
    lista = insertarInicio(lista,4);

    printf("\nLista inicial: \n");
    ver(lista);

    lista = ordenar_INSERCIONSIMPLE(lista);
    printf("\n\nLista ordenada: \n");
    ver(lista);


    return 0;
}
