#include"EJ2_FILA.h"
int main(){

    Nodo *filaU = NULL;
    Nodo *fila1 = NULL;
    Nodo *fila2 = NULL;
    /*FILE *fL = fopen("L_fila.txt","r");
    FILE *fE = fopen("E_fila.txt","w");*/

    char resp,name[25];
    int dato,c,n;

    /*if (fL == NULL){
        printf("Hubo un error al tratar de abrir el archivo");
        exit(1);
    }*/

    do{
        int opc = 0;
        system("cls");

        printf("Menu para manejar filas\n\n");

        printf("\n1.-Insertar elemento");
        printf("\n2.-Sacar elemento");
        printf("\n3.-Ver fila");
        printf("\n4.-Ver tamanio");
        /*printf("\n5.-Agregar datos desde un archivo");
        printf("\n6.-Guardar datos en un archivo");*/
        printf("\n7.-Dividir las filas");
        printf("\n8.-Cerrar programa");

        printf("\n\nInserte la opcion deseada__");
        scanf("%d",&opc);

        switch(opc){
            case 1:
                printf("\nIngrese el entero del elemento (1/2)__");
                scanf("%d",&dato);
                printf("\nIngrese el nombre del elemento__");
                scanf("%s",&name);
                //printf("%s",name);
                filaU = insertarElem(filaU,dato,name);
                break;
            case 2:
                filaU = sacarElem(filaU);
                break;
            case 3:
                ver(filaU);
                break;
            case 4:
                c = contar(filaU);
                printf("\nHay %d elementos en nuestra fila",c);
                break;
            /*case 5:
                fila = insertar_F(fila,fL);
                printf("\nSe han insertado los elementos que se encuentran en L_fila.txt");
                break;
            case 6:
                sacar_F(fila,fE);
                printf("\nSe han escrito los elementos de la fila en E_fila.txt");
                break;*/
            case 7:
                while(filaU != NULL){
                    n = filaU->dato;

                    switch(n){
                        case 1:
                            fila1 = insertarElem(fila1,n,filaU->nombre);
                            filaU = sacarElem(filaU);
                            break;
                        case 2:
                            fila2 = insertarElem(fila2,n,filaU->nombre);
                            filaU = sacarElem(filaU);
                            break;
                        default:
                            break;
                    }
                }
                printf("\n\nFILA USUARIO");
                ver(filaU);
                printf("\n\nFILA 1");
                ver(fila1);
                printf("\n\nFILA 2");
                ver(fila2);
                break;
            case 8:
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
    /*fclose(fL);
    fclose(fE);*/

    return 0;
}
