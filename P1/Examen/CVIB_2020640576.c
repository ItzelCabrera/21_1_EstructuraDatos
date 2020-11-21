#include"CVIB_2020640576.h"
#include"FILA.h"

int main(){
    FILE *fL = fopen("ecuaciones.txt","r");
    Nodo *pila = NULL;
    Nodo2 *fila = NULL;

    char c = getc(fL);
    int k = 0, j = 0, i = 0, p = 0;
    char linea[100];

    while(feof(fL) == 0){
        //printf("%c",c);
        k = revisarChar(c);
        switch(k){
        case 1:
            //c es un caracter de apertura
            pila = apilar(pila,c);
            break;
        case 2:
            //c es un caracter de cerradura
            j = revisarCima(pila,c); //revisa si la cima tiene el caracter de apertura correspondiente
            switch(j){
            case 1:
                //caracter de apertura adecuado
                pila = desapilar(pila);
                break;
            case 2:
                //caso que encuentre un error antes de encontrar un salto de linea (caracter de cerradura inadecuado)
                pila = vaciar(pila);
                //pila = apilar(pila,'X');
                while((int)c != 10){
                    c = getc(fL);
                }
                fila = insertarElem2(fila,0);
                //printf("\nERROR");
                break;
            default:
                break;
            }
            break;
        case 3:
            //c es un salto de línea
            i = revisarPila(pila);
            switch(i){
                case 1://éxito
                    //printf("\nEXITO");
                    fila = insertarElem2(fila,1);
                    break;
                case 3: //revisar pila
                    p = revisarSignos(pila);
                    switch(p){
                        case 1://exito
                            pila = vaciar(pila);
                            //printf("\nEXITO");
                            fila = insertarElem2(fila,1);
                            break;
                        case 2://fail
                            pila = vaciar(pila);
                            //printf("\nERROR");
                            fila = insertarElem2(fila,0);
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        case 4:
            //c es un numero o una literal
            break;
        default:
            printf("\nA ocurrido un error!");
            break;
        }
        c = getc(fL);
    }

    revisarUltEcuacion(pila,fila);

    k = 0;

    //Imprimir resultados
    while(fila != NULL){
        k++;
        if (fila->dato == 1){
            printf("\nECUACION %d --> EXITO",k);
        }else{
            printf("\nECUACION %d --> ERROR",k);
        }
        fila = fila->siguiente;
    }

    return 0;
}
