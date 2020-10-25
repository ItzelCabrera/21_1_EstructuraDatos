#include "PILA.h"

int main(){
    abrirS();

    Nodo *pila = NULL;

    int opc,dato;
    char resp;

    do{
        system("cls");
        printf("Manejo de pilas\n\n");
        printf("\n1.- Apilar");
        printf("\n2.- Desapilar");
        printf("\n3.- Ver pila");
        printf("\n4.- Ver tamanio");
        printf("\n5.- Agregar datos a una pila desde un archivo");
        printf("\n6.- Descargar pila en un archivo");
        printf("\n7.- Cerrar programa");

        printf("\n\nIngrese la opcion deseada___");
        scanf("%d",&opc);

        switch(opc){
            case 1:
                printf("Ingrese el valor a almacenar__");
                scanf("%d",&dato);
                pila = apilar(pila,dato);
                break;
            case 2:
                pila = desapilar(pila);
                break;
            case 3:
                ver(pila);
                break;
            case 4:
                printf("\nNumero elementos: %d\n",contar(pila));
                break;
            case 5:
                pila = apilar_F(pila,FL);
                break;
            case 6:
                copiar_F(pila,FE);
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Algo salio mal :c");
                break;
        }

        fflush(stdin);
        printf("\n\n¿Desea volver al menu? (S/N)");
        resp = getchar();
        resp = toupper(resp);

    }while(resp == 'S');

        fclose(FL);//cierra el stream
        fclose(FE);//cierra el stream

    return 0;
}

void abrirS(){
    FILE *FL = fopen("L_pila.txt","r");
    FILE *FE =fopen("E_pila.txt","a");

    if (FL == NULL && FE == NULL){
            fprintf(stderr,"Algun archivo no se puede abrir");
            exit(1);
    }
}
