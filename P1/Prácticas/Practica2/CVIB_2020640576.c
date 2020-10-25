#include"CVIB_2020640576.h"


int main(){
    FILE *fR1 = fopen("calle1.txt","r");
    FILE *fR2 = fopen("calle2.txt","r");
    FILE *fW = fopen("filaFinal.txt","w");

    Nodo *fila1 = NULL;
    Nodo *fila2 = NULL;
    Nodo *filaF = NULL;

    srand(time(NULL)); //agregando una semilla

    if (fR1 == NULL && fR2 == NULL){
        printf("Hubo un error al tratar de leer los archivos");
        exit(1);
    }else{
        printf("Programa para simular un cruce vehicular\n\n");
    }


    //se leen los archivos y se insertan los carros en las filas
    fila1 = insertar_F(fila1,fR1);
    fila2 = insertar_F(fila2,fR2);

    int n = 0;
    char m[25],c[25],p[25];

    printf("Semaforos en operacion\n\n");

    while(fila1 != NULL || fila2 != NULL){
        n = rand()%2;
        switch(n){
            case 0://pasa vehiculo de calle1
                if (fila1 != NULL){//si todavía hay carros por cruzar
                    strcpy(m,fila1->marca);
                    strcpy(c,fila1->color);
                    strcpy(p,fila1->placa);
                    filaF = insertarElem(filaF,m,c,p);
                    fila1 = sacarElem(fila1);
                }
                break;
            case 1://pasa vehiculo de calle2
                if (fila2 != NULL){//si todavía hay carros por cruzar
                    strcpy(m,fila2->marca);
                    strcpy(c,fila2->color);
                    strcpy(p,fila2->placa);
                    filaF = insertarElem(filaF,m,c,p);
                    fila2 = sacarElem(fila2);
                }
                break;
            default:
                printf("El semaforo esta fallando\n");
                exit(1);
                break;
        }
    }

    sacar_F(filaF,fW);//se escribe la fila final en el archivo filaFinal.txt

    printf("El proceso se ha terminado! Revisar la bitacora del cruce en filaFinal.txt\n___VISTA PREVIA ___\n");
    ver(filaF);

    fclose(fR1);
    fclose(fR2);
    fclose(fW);

    return 0;
}
