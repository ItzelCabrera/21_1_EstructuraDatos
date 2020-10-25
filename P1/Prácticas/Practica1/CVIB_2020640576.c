//Cabrera Vazquez Itzel Berenice_Practica 1
#include"CVIB_2020640576.H"

int main(){
    FILE* fL = fopen("postfija.txt","r");
    FILE* fE = fopen("postfijaEvaluacion.txt","w");

    if (fL == NULL){
        printf("No se pudo leer el archivo");
        exit(1);
    }else{
        printf("Programa para realizar la evaluacion de una expresion aritmetica postfija.\n\n");

    }

    Nodo *pila = NULL;

    char c;
    while(feof(fL) == 0){
        c = fgetc(fL);
        pila = revisarC(c,pila);
    }
    copiar_F(pila,fE);

    printf("\nListo! Se ha escrito el resultado en \"postfijaEvaluacion.txt\"");
    printf("\n\nResultado: %f\n", pila->dato);

    fflush(stdin);
    fclose(fL);
    fclose(fE);

    return 0;

}


