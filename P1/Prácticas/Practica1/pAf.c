#include"NpNf.H"

int main(){
    FILE *fL = fopen("fija.txt","r");
    FILE *fE = fopen("fijaEvaluacion.txt","w");

    Nodo *pilaN = NULL;
    Nodo *pilaO = NULL;

    if(fL == NULL){
        printf("No se puedo abrir el archivo");
        exit(1);
    }

    pilaO = apilar(pilaO,' '); //para que el primer operando se pueda apilar directamente

    int rev;
    char c,x;

    while(feof(fL) == 0){
        c = getc(fL);
        rev = revisar(c); //revisa si es un digito o un operando

        switch(rev){
            case 1:
                pilaN = apilar(pilaN,c); //dig --> apila
                break;
            case 2:
                //Checar prioridades
                if(getJerarquia(c) < getJerarquia(getDato(pilaO))){
                    x = getDato(pilaO); //obtiene el operando de mayor valor
                    pilaO = desapilar(pilaO);//se desapila el operando de mayor valor
                    pilaN = apilar(pilaN,x); //se apila el operando de mayor valor en pilaN
                    pilaO = apilar(pilaO,c); //se apila el operando de menor jerarquia en pilaO
                }else{
                    pilaO = apilar(pilaO,c);
                }
                break;
            case 9:
                break;
            default:
                break;
        }
    }

    char f;
    int j;
    //se van pasando los datos de la pilaN a la pilaO, para obtener el "orden real"
    j = contar(pilaN);
    for(int k = 0; k < j; k++){
        f = getDato(pilaN);
        pilaN = desapilar(pilaN);
        pilaO = apilar(pilaO,f);
    }

    copiar_F(pilaO,fE); //se copia en un fichero

    printf("Se ha escrito en notacion postfija en fijaEvaluacion.txt\n\n");
    printf("Resultado: ");ver(pilaO);

    fflush(stdin);
    fclose(fL);
    fclose(fE);

    return 0;
}
