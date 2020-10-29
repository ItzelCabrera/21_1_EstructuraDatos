#include"EJERCICIO2_LISTADOBLE.h"

int main(){
    FILE *fL = fopen("calle1.txt","r");
    Nodo *listaD = NULL;

    if (fL == NULL){
        printf("Erro al intentar abrir el archivo!");
        exit(0);
    }



    fclose(fL);

    return 0;
}
