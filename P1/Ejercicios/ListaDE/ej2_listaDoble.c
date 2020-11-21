#include"EJERCICIO2_LISTADOBLE.h"

int main(){
    FILE *fL = fopen("calle1.txt","r");
    Nodo *listaD = NULL;

    if (fL == NULL){
        printf("Erro al intentar abrir el archivo!");
        exit(0);
    }

    listaD = fDataI(listaD,fL); //lee el archivo y forma una lista doblemente enlazada

    int opc = 0;
    char resp = ' ';

    int aleatorio = 0;//variable para los numeros aleatorios a generar
    srand(time(NULL));

    char m[25],c[25],p[25]; int pos = 0; //datos para ingresar autos nuevos
    char dN[25]; //nuevo dato por cambiar

    do{
        system("cls");

        printf("Menu para manejar listas doblemente enlazadas\n\n");

        printf("\n1.-Insertar elemento");
        printf("\n2.-Borrar elemento");
        printf("\n3.-Cambiar dato");
        printf("\n4.-Ver lista");
        printf("\n5.-Ver tamanio");
        printf("\n6.-Cerrar programa");

        printf("\n\nInserte la opcion deseada__");
        scanf("%d",&opc);

        switch(opc){
        case 1:
            system("cls");
            aleatorio = rand()%3;
            aleatorio++;

            switch(aleatorio){
            case 1:
                //Piden los datos para ingresar el nuevo auto
                printf("\n\nIngrese la marca__");
                scanf("%s",&m);
                printf("\n\nIngrese el color__");
                scanf("%s",&c);
                printf("\n\nIngrese la placa__");
                scanf("%s",&p);

                listaD = insertarInicio(listaD,m,c,p);
                break;
            case 2:
                //Piden los datos para ingresar el nuevo auto
                printf("\n\nIngrese la marca__");
                scanf("%s",&m);
                printf("\n\nIngrese el color__");
                scanf("%s",&c);
                printf("\n\nIngrese la placa__");
                scanf("%s",&p);

                listaD = insertarFinal(listaD,m,c,p);
                break;
            case 3:
                //Piden los datos para ingresar el nuevo auto
                printf("\n\nIngrese la marca__");
                scanf("%s",&m);
                printf("\n\nIngrese el color__");
                scanf("%s",&c);
                printf("\n\nIngrese la placa__");
                scanf("%s",&p);
                printf("\n\nIngrese la posicion__");
                scanf("%d",&pos);

                listaD = insertarXP(listaD,pos,m,c,p);
                break;
            default:
                exit(0);
                break;
            }

            break;
        case 2:
            system("cls");
            aleatorio = rand()%3;
            aleatorio++;

            switch(aleatorio){
            case 1:
                listaD = borrarInicio(listaD);
                break;
            case 2:
                listaD = borrarFinal(listaD);
                break;
            case 3:
                pos = rand()%(contar(listaD));
                pos++;
                listaD = borrarXP(listaD,pos);
                break;
            default:
                exit(0);
                break;
            }

            break;
        case 3:
            system("cls");
            aleatorio = rand()%3;
            aleatorio++;

            switch(aleatorio){
            case 1:
                printf("\nIngrese la marca que quiere cambiar__");
                scanf("%s",&m);
                printf("\nIngrese la marca nueva__");
                scanf("%s",&dN);

                switch(rand()%2){
                    case 0://desde el inicio
                        listaD = cambiarMarca(listaD,m,dN);
                        break;
                    case 1://desde atrás
                        listaD = cambiarMarcaFromBack(listaD,m,dN);
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                printf("\nIngrese el color que quiere cambiar__");
                scanf("%s",&c);
                printf("\nIngrese el color nuevo__");
                scanf("%s",&dN);

                switch(rand()%2){
                    case 0://desde el inicio
                        listaD = cambiarColor(listaD,c,dN);
                        break;
                    case 1://desde atrás
                        listaD = cambiarColorFromBack(listaD,c,dN);
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                printf("\nIngrese la placa que quiere cambiar__");
                scanf("%s",&p);
                printf("\nIngrese la placa nueva__");
                scanf("%s",&dN);

                switch(rand()%2){
                    case 0://desde el inicio
                        listaD = cambiarPlaca(listaD,p,dN);
                        break;
                    case 1://desde atrás
                        listaD = cambiarPlacaFromBack(listaD,p,dN);
                        break;
                    default:
                        break;
                }
                break;
            default:
                exit(0);
                break;
            }

            break;
        case 4:
            system("cls");
            printf("\nLista normal");
            ver(listaD);
            printf("\n\nLista al reverso");
            verInverso(listaD);
            break;
        case 5:
            printf("\nLa lista tiene %d elementos",contar(listaD));
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



    fclose(fL);

    return 0;
}
