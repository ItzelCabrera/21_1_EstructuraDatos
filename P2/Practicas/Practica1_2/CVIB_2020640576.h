#ifndef _CVIB_2020640576_H_
#define _CVIB_2020640576_H_
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

typedef struct _NODO{
    char caracter;
    int frecuencia;
    int marcador;
    struct _NODO *siguiente;
    struct _NODO *anterior;
    struct _NODO *izquierdo;
    struct _NODO *derecho;
    struct _NODO2 *clave;
}Nodo;

typedef struct _NODO2{ //pila clave
    char caracter;
    struct _NODO2 *siguiente;
}Nodo2;

Nodo *crear(char c,int f){
    Nodo * nuevo;
    nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->caracter = c;
    nuevo->frecuencia = f;
    nuevo->marcador = 0;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    nuevo->clave = NULL;

    return nuevo;
}

Nodo *crear_2(char c){
    Nodo * nuevo;
    nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->caracter = c;
    nuevo->frecuencia = 0;
    nuevo->marcador = 0;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    nuevo->clave = NULL;

    return nuevo;
}

Nodo *crear_3(char c,Nodo2 * key){
    Nodo * nuevo;
    nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->caracter = c;
    nuevo->frecuencia = 0;
    nuevo->marcador = 0;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    nuevo->clave = key;

    return nuevo;
}

Nodo2 * crear2(char d){
    Nodo2 * nuevo;
    nuevo = (Nodo2 *)malloc(sizeof(Nodo2)); //si malloc no logra retornar un puntero va a retornar un null 0 o un -1 --> por lo tanto, hay que realizar una comparación y manejar un error
    nuevo->caracter = d; //el operador -> funciona para acceder a ese miembro pero mediante un puntero
    nuevo->siguiente = NULL;

    return nuevo;
}

int contar (Nodo * frente){
    int c = 0;
    if(frente == NULL){
        printf("\n0 elementos\n");
    }else{
        while(frente != NULL){
            c++;
            frente = frente->siguiente;
        }
        return c;
    }
}

int contar2 (Nodo2 * cima){
    int c = 0;
    if(cima == NULL){
        printf("\n0 elementos\n");
    }else{
        while(cima != NULL){
        //hay que ir moviendo las cimas hasta llegar a null
        c++;
        cima = cima->siguiente;
        }
        return c;
    }
}

void ver_PRE(Nodo *padre){
    if(padre != NULL){
        printf("%c[%d],\t",padre->caracter,padre->frecuencia);
        ver_PRE(padre->izquierdo);
        printf("#");
        ver_PRE(padre->derecho);
    }
}

void ver2(Nodo2 *cima){
    if(cima == NULL){
            printf("\nNo hay ningun elemento en la pila\n");
    }else{
        while(cima != NULL){
        //hay que ir moviendo las cimas hasta llegar a null
        printf("\t{%c}",cima->caracter);
        cima = cima->siguiente;
        }
    }
}

void ver (Nodo *frente){
    if(frente == NULL){
        printf("\nNo hay ningun elemento en la lista\n");
    }else{
        while(frente != NULL){
            printf("\n%c\t%d -->",frente->caracter,frente->marcador);
            if(frente->caracter != '*')ver2(frente->clave);
            frente = frente->siguiente;
        }
    }
}

void verInverso (Nodo *frente){
    if(frente == NULL){
        printf("\nNo hay ningun elemento en la lista\n");
    }else{
        while(frente->siguiente!=NULL){
            frente = frente->siguiente;
        }
        while(frente != NULL){
            printf("\n%c\t%d -->",frente->caracter,frente->marcador);
            if(frente->caracter != '*')ver2(frente->clave);
            frente = frente->anterior;
        }
    }
}

void verLista(Nodo *lista){
    printf("\nLista normal");
    ver(lista);
    printf("\nLista inversa");
    verInverso(lista);
}


/*Nodo *insertarInicio(Nodo * inicio, char c,int f){
    Nodo * nuevo;
    nuevo = crear(c,f);

    if (inicio != NULL){
        nuevo->siguiente = inicio;
        inicio->anterior = nuevo;
    }

    return nuevo;
}*/

Nodo * insertarFinal(Nodo * inicio, char dato,int f){
    Nodo * nuevo;
    nuevo = crear(dato,f);

    if (inicio == NULL){
        inicio = nuevo;
    }else{
        Nodo *aux;
        aux = inicio;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
    }

    return inicio;
}

Nodo * insertarFinal_2(Nodo * inicio, char dato){
    Nodo * nuevo;
    nuevo = crear_2(dato);

    if (inicio == NULL){
        inicio = nuevo;
    }else{
        Nodo *aux;
        aux = inicio;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
    }

    return inicio;
}

Nodo * insertarFinal_3(Nodo * inicio, char dato,Nodo2* clave){
    Nodo * nuevo;
    nuevo = crear_3(dato,clave);

    if (inicio == NULL){
        inicio = nuevo;
    }else{
        Nodo *aux;
        aux = inicio;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
    }

    return inicio;
}

Nodo2 * apilar(Nodo2 * cima, char d){
    Nodo2 * nuevo;
    nuevo = crear2(d);
    //la nueva cajita que se va a crear se tiene que referenciar a la cajita que esta en la cima; para ello hay que verificar la cima primero:
    if (cima != NULL){ //por lo menos hay una cajita
        nuevo->siguiente = cima; //con esto no se pierden las relaciones entre las cajitas; es comoreemplazarnos entre los vectores con los indices
    }
    return nuevo;
}

Nodo *borrarInicio(Nodo * inicio){
    Nodo *aux;

    if (inicio != NULL){
        aux = inicio;
        inicio = inicio->siguiente;

        if (inicio != NULL){
        inicio->anterior = NULL;
        }

        free(aux);
    }else{
        printf("\nNo hay elementos en la lista");
    }
    return inicio;
}

Nodo2 *desapilar(Nodo2 * cima){
    Nodo2 * aux;
    aux = cima; //se referencia a la cima
    //corregir un posible underflow
    if (cima != NULL){//hay algo
        cima = cima->siguiente;
        free(aux);
    }
    return cima;
}

void checkAperturaF(FILE *key, FILE *code,FILE *fS){
    //Método que revisa si se abren de forma correcta los archivos
    if( (key == NULL) || (code == NULL) || (fS == NULL)){
        perror("Error al abrir algun archivo");
        exit(1);
    }
}

void cerrarArchivos(FILE *rF, FILE *key,FILE *fS){
    //Método que cierra los archivos
    fclose(rF);
    fclose(key);
    fclose(fS);
}

Nodo *setLista_FromTxt(Nodo *AL, FILE *key){
    //Metodo que arma la lista mientras lee el archivo
    char c = ' ';
    int f = 0;

    while(feof(key) == 0){
        fscanf(key,"%c %d ",&c,&f);
        //printf("%c[%d]\n",c,f);
        AL = insertarFinal(AL,c,f);
    }
    return AL;
}

Nodo *setArbol(Nodo *AL){
    Nodo *aux = AL;
    Nodo *aux2 = NULL;
    Nodo *aux3 = NULL;
    while(aux != NULL){
        //printf("\n%c[%d]/n",aux->caracter,aux->frecuencia);
        if(aux->caracter == '*'){
            //printf("\nASTERISCO [%d]\n",aux->frecuencia);

            for(int i = 0; i < 2;i++){
                aux2 = aux->anterior;
                while(aux2->marcador != 0){
                    //printf("\n%c{%d}\n",aux2->caracter,aux2->frecuencia);
                    aux2 = aux2->anterior;
                }
                if(i == 0){
                    aux->derecho = aux2;
                    aux2->marcador = 1;
                    //printf("\nDERECHA %c\t%\n",aux2->caracter,aux2->frecuencia);
                }
                else{
                    aux->izquierdo = aux2;
                    aux2->marcador = 2;
                    //printf("\nIZQUIERDA %c\t%\n",aux2->caracter,aux2->frecuencia);
                }
            }
        }
        aux3 = aux;
        aux = aux->siguiente;
    }
    free(aux);
    return aux3;
}

char getCaracter(Nodo2 *nodito){
    //Método que obtiene el caracter del nodo
    return nodito->caracter;
}

Nodo2 *reorganizarClave(Nodo2 *cima){
    //Método que invierte la pila de la clave
    Nodo2 *aux = NULL;
    Nodo2 *nuevaClave = NULL;

    char c = ' ';

    if(cima == NULL)
        printf("\nNo hay elementos en la pila");
    aux = cima;
    while(aux != NULL){
        c = getCaracter(aux);
        nuevaClave = apilar(nuevaClave,c);
        aux = aux->siguiente;
    }

    free(aux);
    return nuevaClave;
}

void setClaves(Nodo *padre,Nodo2 *pilaC,int num){
    //Método que asigna las claves de cada caracter

    Nodo2 *nClave = NULL;

    if(padre != NULL){
        if (num == 0){
            //printf("0");
            pilaC = apilar(pilaC,'0');
        }
        if(num ==1){
            //printf("1");
            pilaC = apilar(pilaC,'1');
        }
        if(padre->caracter != '*'){
            //printf("%c[%d],\t",padre->caracter,padre->frecuencia);
            nClave = reorganizarClave(pilaC);
            padre->clave = nClave;
            //ver2(padre->clave);
        }
        setClaves(padre->izquierdo,pilaC,0);
        setClaves(padre->derecho,pilaC,1);
        pilaC = desapilar(pilaC);

    }

}

Nodo2* decimalToBinary(int decimal,Nodo2 *pilaB){
    //METODO QUE PASA UN NUM DECIMAL A BINARIO

    int residuo = 0;
    int c = 0;
    while(decimal != 0){
        c++;
        residuo = decimal%2;
        decimal = decimal/2;
        if(residuo == 0) {
            pilaB = apilar(pilaB,'0');//si es par se apila 0
            //printf("%c",'0');
        }
        else {
            pilaB = apilar(pilaB,'1'); //si es impar se apila 1
            //printf("%c",'1');
        }
    }

    c = 7-c;

    for(int j = 0; j < c; j++){
        pilaB = apilar(pilaB,'0');
        //printf("%c",'0');
    }
    return pilaB;
}

Nodo *setListaB(FILE *fC,Nodo *LB){
    //METODO QUE GENERA UNA LISTA BINARIA PARA DECODIFICARLA MÁS ADELANTE

    Nodo2 *pilaB = NULL;
    int nE = 0;
    char dato = ' ';

    fread(&nE,sizeof(int),1,fC);

    int elementos[nE];
    fread(&elementos,sizeof(int),nE,fC);

    for(int i = 0; i < nE; i ++){
        pilaB = decimalToBinary(elementos[i],pilaB);
        for(int k = 0; k < 7; k++){
            dato = getCaracter(pilaB);
            LB = insertarFinal(LB,dato,0);
            pilaB = desapilar(pilaB);
        }
        //printf("\n");
    }

    return LB;
}

void *setTXTClaves(Nodo *padre,FILE *tF){
    //METODO QUE GENERA UN TEXTO TEMPORAL CON LOS CARACTERES Y CLAVES

    if(padre != NULL){
        if(padre->caracter != '*'){
            Nodo2 *pAux = padre->clave;
            fprintf(tF,"%c\t",padre->caracter);
            while(pAux != NULL){
                fprintf(tF,"%c ",pAux->caracter);
                pAux = pAux->siguiente;
            }
            fprintf(tF,"\n");
        }
        setTXTClaves(padre->izquierdo,tF);
        setTXTClaves(padre->derecho,tF);
    }

}

Nodo *setListaClaves(FILE *tF,Nodo *LC){
    //METODO QUE GENERA UNA LISTA DE LOS CARACTERES CON SUS RESPECTIVAS CLAVES

    char c = ' ';
    char caracter = ' ';
    int cont = 0;
    Nodo2 *pilita = NULL;
    Nodo *aux = NULL;

    c = fgetc(tF);
    while(feof(tF) == 0){
        while((int)c != 10){//si no es un salto de línea
            if(isgraph(c) && !isdigit(c)) {
                caracter = c;
            }
            if (isdigit(c)) {//digito perteneciente a la clave
                pilita = apilar(pilita,c); //va apilando la clave
            }
            c = fgetc(tF);
        }
        cont = contar2(pilita);//numero de dígitos de la clave
        LC = insertarFinal_2(LC,caracter);//inserta el nodo de la lista de claves

        aux = LC;
        while(aux->siguiente != NULL){//busca el último nodo agregado
            aux = aux->siguiente;
        }
        for(int i = 0; i < cont; i++){ //se apila al ult nodo agregado su respectiva clave, mientras se desapila la pila aux
            aux->clave = apilar(aux->clave,pilita->caracter);
            pilita = desapilar(pilita);
        }
        c = fgetc(tF);
    }
    free(pilita);
    free(aux);

    return LC;

}

void setMarcadoresToZero(Nodo *LC){
    Nodo *aux = LC;
    while(aux!= NULL){
        aux->marcador = 0;
        aux = aux->siguiente;
    }
}

void decodificacion(Nodo *LB, Nodo *LC){
    Nodo *auxB = LB;
    Nodo *auxC = NULL;
    Nodo2 *aux = NULL;
    int cont = 0;
    int cont2 = 0;
    int cont3 = 0;
    int nE = 0; //numero de elementos en la pilaClave

    while(auxB!= NULL){
        auxC = LC;
        if (cont == 0){//marcadores se igualan a cero
            setMarcadoresToZero(LC);
        }
        while(auxC!=NULL){
            nE = contar2(auxC->clave);
            aux = auxC->clave;
            if((cont <= nE)&&(auxC->marcador!=1)){
                //for(int j = 0; j<(cont+1);j++){
                  //  aux = aux->siguiente;
                //}
                //printf("{%c}%c\n",auxC->caracter,aux->caracter);

                /*while(cont2 <= (cont)){
                aux = aux->siguiente;
                cont2++;
                }
                cont2 = 0;
                printf("{%c}%c\n",auxC->caracter,aux->caracter);*/

            }else{
                auxC->marcador = 1;
            }
            auxC = auxC->siguiente;
        }
        printf("%d\n",cont);
        cont++;
        auxB = auxB->siguiente;
    }
}

void decodificacion2(Nodo *tree, Nodo *LB, FILE *fS){
    //METODO PARA DECODIFICAR LA LISTA BINARIA

    Nodo *auxB = LB;
    Nodo *auxT = tree;

    if(auxB == NULL || auxT == NULL){
        printf("\nError, no se puede decodificar: no hay claves o no se genero el arbol de forma correcta");
    }else{
        while(auxB!= NULL){ //se recorre toda la lista binaria
            if(auxB->caracter == '0'){//si el caracter es un 0, se mueve a la izquiera y si es una hoja, se escribe en el file
                auxT = auxT->izquierdo;
                if(auxT->caracter != '*'){
                    fputc(auxT->caracter,fS);
                    printf("%c",auxT->caracter);
                    auxT = tree;
                }
            }else if(auxB->caracter == '1'){//si el caracter es un 1, se mueve a la der y si es una hoja, se escribe en el file
                auxT = auxT->derecho;
                if(auxT->caracter != '*'){
                    fputc(auxT->caracter,fS);
                    printf("%c",auxT->caracter);
                    auxT = tree;
                }
            }
            auxB = auxB->siguiente;
        }
    }
    free(auxB);
    free(auxT);
}
#endif
