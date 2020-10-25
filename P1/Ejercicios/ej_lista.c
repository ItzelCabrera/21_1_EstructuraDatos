#include"LISTA.h"


int main(){
    Nodo * lista = NULL;
    lista = insertarInicio(lista,100);
    lista = insertarInicio(lista,200);
    lista = insertarInicio(lista,300);
    lista = insertarInicio(lista,400);
    lista = insertarFinal(lista,10);
    lista = insertarFinal(lista,20);
    lista = insertarXP(lista,2,100);
    lista = insertarFinal(lista,100);

    printf("\n");
    ver(lista);
    /*
    lista = insertarXP(lista,3,1);

    printf("\n");
    ver(lista);

    lista = insertarXP(lista,6,2);
    lista = insertarXP(lista,9,3);

    printf("\n");
    ver(lista);

    lista = borrarInicio(lista);
    lista = borrarFinal(lista);

    printf("\n");
    ver(lista);

    lista = borrarInicio(lista);
    lista = borrarFinal(lista);
    lista = borrarXP(lista,3);*/

    lista = cambiarDato(lista,7,50);

    printf("\n");
    ver(lista);

    return 0;
}
