#include"FILA.H";
#include<stdio.h>
#include<stdlib.h>


int main(){
    Nodo *fila = NULL;
    FILE *fL = fopen("L_fila.txt","r");
    FILE *fE = fopen("E_fila.txt","w");

    char resp;
    int dato,c;

    if (fL == NULL){
        printf("Hubo un error al tratar de abrir el archivo");
        exit(1);
    }

    do{
        int opc = 0;
        system("cls");

        printf("Menu para manejar filas\n\n");

        printf("\n1.-Insertar elemento");
        printf("\n2.-Sacar elemento");
        printf("\n3.-Ver fila");
        printf("\n4.-Ver tamanio");
        printf("\n5.-Agregar datos desde un archivo");
        printf("\n6.-Guardar datos en un archivo");
        printf("\n7.-Cerrar programa");

        printf("\n\nInserte la opcion deseada__");
        scanf("%d",&opc);

        switch(opc){
            case 1:
                printf("\nIngrese el entero a almacenar__");
                scanf("%d",&dato);
                fila = insertarElem(fila,dato);
                break;
            case 2:
                fila = sacarElem(fila);
                break;
            case 3:
                ver(fila);
                break;
            case 4:
                c = contar(fila);
                printf("\nHay %d elementos en nuestra fila",c);
                break;
            case 5:
                fila = insertar_F(fila,fL);
                printf("\nSe han insertado los elementos que se encuentran en L_fila.txt");
                break;
            case 6:
                sacar_F(fila,fE);
                printf("\nSe han escrito los elementos de la fila en E_fila.txt");
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Algo salió mal!");
                exit(1);
                break;
        }
        fflush(stdin);
        printf("\n¿Desea volver al menu? (S/N)");
        resp = getchar();
        resp = toupper(resp);


    }while(resp == 'S');

    fflush(stdin);
    fclose(fL);
    fclose(fE);

    return 0;
}
