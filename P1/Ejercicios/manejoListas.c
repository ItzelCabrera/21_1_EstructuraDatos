#include"LISTA.h"

int main(){

    Nodo *lista = NULL;
    int opc = 0;
    char resp = ' ';

    do{
        system("cls");

        printf("Menu para manejar listas\n\n");

        printf("\n1.-Insertar elemento");
        printf("\n2.-Sacar elemento");
        printf("\n3.-Cambiar dato de algun elemento");
        printf("\n4.-Ver lista");
        printf("\n5.-Ver tamanio");
        printf("\n6.-Cerrar programa");

        printf("\n\nInserte la opcion deseada__");
        scanf("%d",&opc);

        switch(opc){
        case 1:
            system("cls");
            lista = insertar(lista);

            break;
        case 2:
            system("cls");
            lista = borrar(lista);

            break;
        case 3:
            system("cls");
            lista = cambiar(lista);
            break;
        case 4:
            system("cls");
            ver(lista);
            break;
        case 5:
            printf("\nLa lista tiene %d elementos",contar(lista));
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nOpcion incorrecta");
            break;

        }

        fflush(stdin);
        printf("\n\n¿Desea volver al menu? (S/N)");
        resp = getchar();
        resp = toupper(resp);


    }while(resp == 'S');


    return 0;
}

