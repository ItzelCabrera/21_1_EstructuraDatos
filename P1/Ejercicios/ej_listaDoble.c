#include"LISTADOBLE.h"

int main(){
    Nodo *listaDoble;
    listaDoble = NULL;
    listaDoble = insertarInicio(listaDoble,10);
    listaDoble = insertarInicio(listaDoble,20);
    listaDoble = insertarFinal(listaDoble,100);
    listaDoble = insertarFinal(listaDoble,50);
    listaDoble = insertarXP(listaDoble,2,50);

    ver(listaDoble);
    printf("\n");
    verInverso(listaDoble);

    listaDoble = cambiarDatoFromBack(listaDoble,50,900);

    printf("\n");
    ver(listaDoble);
    printf("\n");
    verInverso(listaDoble);

    return 0;
}
