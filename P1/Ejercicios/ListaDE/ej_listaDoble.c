#include"LISTADOBLE.h"

int main(){
    Nodo *listaDoble;
    listaDoble = NULL;
    listaDoble = insertarInicio(listaDoble,6);
    listaDoble = insertarInicio(listaDoble,2);
    listaDoble = insertarInicio(listaDoble,7);
    listaDoble = insertarInicio(listaDoble,10);
    listaDoble = insertarInicio(listaDoble,1);
    listaDoble = insertarInicio(listaDoble,10);
    listaDoble = insertarInicio(listaDoble,1);

    printf("\n******************\n");
    ver(listaDoble);
    printf("\n******************\n");


    listaDoble = ordenar(listaDoble);
    //listaDoble = cambiarDatoFromBack(listaDoble,50,900);

    printf("\n******************\n");
    ver(listaDoble);
    printf("\n******************\n");

    /*char C1[5] = "ITZE2";
    char C2[5] = "ITZE1";

    if(strcmp(C1,C2) < 0){
        printf("ITZE2 VA PRIMERO");
    }else if(strcmp(C1,C2) > 0){
        printf("ITZE1 VA PRIMERO");
    }else{
        printf("Same");
    }*/

    return 0;
}
