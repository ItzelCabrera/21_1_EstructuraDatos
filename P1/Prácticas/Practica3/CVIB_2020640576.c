#include"CVIB_2020640576.h"
int main(){
    Nodo *LD = NULL;
    FILE *fL = fopen("personas.txt","r");
    FILE *fE = fopen("personasOrdenadas.txt","w");

    if (fL == NULL && fE == NULL){
        printf("\nNo se pudieron abrir los archivos :c");
        exit(1);
    }

    LD = fDataI(LD,fL); //lectura del fichero

    system("cls");
    printf("Practica 3___Usando listas doblemente enlazadas y metodos de ordenamiento\n");

    printf("\nDatos almacenados: ");
    ver(LD);
    printf("\n\n");

    LD = ordenar(LD);

    printf("\nDatos ordenados: ");
    ver(LD);
    printf("\n\n");

    fDataO(LD,fE); //escritura en el fichero

    printf("Se guardo la lista ordenada en el archivo personasOrdenadas.txt.");

    fclose(fL);
    fclose(fL);

    return 0;
}
