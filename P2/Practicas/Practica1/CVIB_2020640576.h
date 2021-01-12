#ifndef _CVIB_2020640576_H_
#define _CVIB_2020640576_H_
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

typedef struct _NODO{
    char caracter;
    int frecuencia;
    struct _NODO *siguiente;
    struct _NODO *anterior;
    struct _NODO *izquierdo;
    struct _NODO *derecho;
    struct _NODO2 *clave;
}Nodo;

typedef struct _NODO2{ //pila clave
    char caracter;
    int dato;
    struct _NODO2 *siguiente;
}Nodo2;

Nodo *crear(char c,int f){
    Nodo * nuevo;
    nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->caracter = c;
    nuevo->frecuencia = f;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    nuevo->clave = NULL;

    return nuevo;
}

Nodo2 * crear2(char d){
    Nodo2 * nuevo;
    nuevo = (Nodo2 *)malloc(sizeof(Nodo2)); //si malloc no logra retornar un puntero va a retornar un null 0 o un -1 --> por lo tanto, hay que realizar una comparación y manejar un error
    nuevo->caracter = d; //el operador -> funciona para acceder a ese miembro pero mediante un puntero
    nuevo->siguiente = NULL;
    nuevo->dato = 0;

    return nuevo;
}

Nodo2 * crear2_2(int d){
    Nodo2 * nuevo;
    nuevo = (Nodo2 *)malloc(sizeof(Nodo2));
    nuevo->caracter = ' ';
    nuevo->siguiente = NULL;
    nuevo->dato = d;

    return nuevo;
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
            //printf("\nNo hay ningun elemento en la pila\n");
        }else{
            while(cima != NULL){
            //hay que ir moviendo las cimas hasta llegar a null
            printf("\t{%c-->%d}",cima->caracter,cima->dato);
            cima = cima->siguiente;
            }
        }
}

void ver (Nodo *frente){
    if(frente == NULL){
        //printf("\nNo hay ningun elemento en la lista\n");
    }else{
        while(frente != NULL){
            printf("\n%c\t%d --> ",frente->caracter,frente->frecuencia);
            ver2(frente->clave);
            frente = frente->siguiente;
        }
    }
}

void verInverso (Nodo *frente){
    if(frente == NULL){
        //printf("\nNo hay ningun elemento en la lista\n");
    }else{
        while(frente->siguiente!=NULL){
            frente = frente->siguiente;
        }
        while(frente != NULL){
            printf("\n%c\t%d --> ",frente->caracter,frente->frecuencia);
            ver2(frente->clave);
            frente = frente->anterior;
        }
    }
}

void verLista(Nodo *lista){
    printf("\nLista normal");
    ver(lista);
    printf("\nLista inversa");
    verInverso(lista);
    //printf("\nArbolito");
    //ver_PRE(lista);
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

Nodo *insertarInicio(Nodo * inicio, char c,int f){
    Nodo * nuevo;
    nuevo = crear(c,f);

    if (inicio != NULL){
        nuevo->siguiente = inicio;
        inicio->anterior = nuevo;
    }

    return nuevo;
}

void * insertarPC(Nodo *inicio, char c, Nodo *AUX){
    //función para acomodar el nuevo nodo, de forma ascedente.

    int f = AUX->frecuencia + AUX->siguiente->frecuencia; //suma de las frecuencias
    //printf("\nSumaFrecuencias = %d",f);
    Nodo *aux = NULL;
    Nodo *nuevo = NULL;

    nuevo = crear(c,f);

    aux = inicio;
    while((aux->siguiente != NULL) && (aux->siguiente->frecuencia <= f)){ //busca la posicion correcta
        aux = aux->siguiente;
    }

    if(aux->siguiente != NULL){//se debe colocar en medio
        nuevo->siguiente = aux->siguiente;
        nuevo->anterior=aux;
        aux->siguiente = nuevo;
        nuevo->siguiente->anterior = nuevo;
    }else{//se coloca al final
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
    }

    nuevo->izquierdo = AUX;
    nuevo->derecho = AUX->siguiente;
}

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

Nodo2 * apilar(Nodo2 * cima, char d){
    Nodo2 * nuevo;
    nuevo = crear2(d);
    //la nueva cajita que se va a crear se tiene que referenciar a la cajita que esta en la cima; para ello hay que verificar la cima primero:
    if (cima != NULL){ //por lo menos hay una cajita
        nuevo->siguiente = cima; //con esto no se pierden las relaciones entre las cajitas; es comoreemplazarnos entre los vectores con los indices
    }
    return nuevo;
}

Nodo2 * apilar2(Nodo2 * cima, int d){
    Nodo2 * nuevo;
    nuevo = crear2_2(d);
    //la nueva cajita que se va a crear se tiene que referenciar a la cajita que esta en la cima; para ello hay que verificar la cima primero:
    if (cima != NULL){ //por lo menos hay una cajita
        nuevo->siguiente = cima; //con esto no se pierden las relaciones entre las cajitas; es comoreemplazarnos entre los vectores con los indices
    }
    return nuevo;
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

char revisarChar(char c){
    //Método que revisa que tipo de caracter es
    if(isspace(c) != 0) //Espacio
        return '_';
    if(isalpha(c) != 0) //Letra
        return toupper((int)c);
    if(ispunct(c) != 0) //Puntuación
        return c;
    if((int)c == -61)
        return '*';
    if((int)c == -68)//Dieresis
        return 'U';
    if((int)c == -79)//Ñ
        return 'N';
    if((int)c == -95)//A acento
        return 'A';
    if((int)c == -87) //E acento
        return 'E';
    if((int)c == -83) //I acento
        return 'I';
    if((int)c == -77)//O acento
        return 'O';
    if((int)c == -70)//U acento
        return 'U';
    else
        return '*';
}

bool isinList(Nodo *inicio,char c){
    //Método que revisa si el caracter c se encuentra en la lista
    Nodo *aux = NULL;
    bool v = false; //no se ha encontrado

    if (inicio == NULL){//si la lista está vacía, entonces el caracter no se encuentra
        return false;
    }

    aux = inicio;
    while((aux != NULL) && (v == false)){
        if(aux->caracter != c) //si no es el mismo caracter, que siga recorriendo la lista
            aux = aux->siguiente;
        else //si es el mismo caracter, que deje de recorrer la lista
            v = true;

    }

    if(v == true)
        return true;
    else
        return false;
    free(aux);
}

Nodo * setFrecuencia(Nodo * inicio,char c){
    /*
    Se asigna la frecuencia del caracter c.
    Si el caracter ya se encuentra en la lista--> suma su frecuencia
    Si el caracter no esta en la lista --> se crea un nuevo nodo
    */
    Nodo *aux;
    bool val = false;

    aux = inicio;
    while(aux != NULL){
        if (aux->caracter == c){
            aux->frecuencia = aux->frecuencia + 1;
            val = true;
            break;
        }else{
            aux = aux->siguiente;
        }
    }
    if(!val){
        printf("\nNo existe un elemento con ese dato!");
    }

    return inicio;
}

Nodo* recorridoLista(Nodo* inicio){
    //Método que arma la lista con sus respectivos apuntadores izquierdo y derecho

    Nodo *aux = NULL;
    Nodo *nuevo = NULL;

    if (inicio == NULL){
        printf("\nNo hay lista por recorrer");
        free(aux);
    }else{
        aux = inicio;
        while(aux->siguiente != NULL){
            insertarPC(inicio,'*',aux);
            aux = aux->siguiente->siguiente;
        }
        //printf("\nARBOLITO\n");
        //ver_PRE(aux);
    }
    return aux;
}

Nodo *ordenar(Nodo *frente){
    /*
    Usa el método de inserción.
    No se cambian las cajitas, sólo los datos
    */
    if(frente == NULL){
        printf("\nNo hay elementos por ordenar");
        return frente;
    }

    Nodo *aux = NULL;
    Nodo *aux2 = NULL;

    int m = 0;
    int M = 0;
    char c = ' ';
    char C = ' ';

    aux = frente;
    aux = aux->siguiente; //el primer elemento se  considera ya ordenado
    while(aux != NULL){
        aux2 = aux;
        while(aux2->anterior != NULL){
            if(aux2->frecuencia < aux2->anterior->frecuencia){ //comparan los datos
                //cambian datos
                m = aux2->frecuencia;
                c = aux2->caracter;
                M = aux2->anterior->frecuencia;
                C = aux2->anterior->caracter;
                aux2->frecuencia = M;
                aux2->caracter = C;
                aux2->anterior->frecuencia = m;
                aux2->anterior->caracter = c;

                //mueve aux2 para seguir comparando
                aux2 = aux2->anterior;
                continue;
            }else{
                //si el anterior ya esta ordenado, tambien los anteriores
                break;
            }
        }
        aux = aux->siguiente;
    }
    free(aux);

    return frente;
}

void cerrarArchivos(FILE *rF, FILE *key){
    //Método que cierra los archivos

    fclose(rF);
    fclose(key);
}

void checkAperturaF(FILE *rF, FILE *wF, FILE *key){
    //Método que revisa si se abren de forma correcta los archivos
    if( (rF == NULL) || (wF == NULL) || (key == NULL)){
        perror("Error al abrir algun archivo");
        exit(1);
    }
}

Nodo *insertarC_FromTXT(Nodo *lista,FILE *rF){
//Inserta los caracteres (hojas del futuro arbol) y sus frecencias
    char c = ' ';
    c = getc(rF);
    bool v = false;
    while(feof(rF) == 0){
        c = revisarChar(c);
        if (c != '*'){
            v = isinList(lista,c);
            if (v == true){ //si el caracter ya está en la lista, aumenta su frecuencia
                lista = setFrecuencia(lista,c);
            }else{//si el caracter no esta en la lista, se inserta un nodo con el caracter y con frecuencia 1
                lista = insertarFinal(lista,c,1);
            }
        }
        c = getc(rF);
        v = false;
    }
    return lista;
}

Nodo *insertar_FromTXT(Nodo *txt,FILE *rF){
    //Inserta TODOS los caracteres del texto

    char c = ' ';
    c = getc(rF);
    while(feof(rF) == 0){
        c = revisarChar(c);
        if (c != '*')
            txt = insertarFinal(txt,c,0);
        c = getc(rF);
    }
    return txt;
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

void setLlave_TXT(Nodo *padre,FILE *key_TEXT){
    //Método que crea el texto del recorrido postarbol de nuestro árbol
    if(padre != NULL){
        setLlave_TXT(padre->izquierdo,key_TEXT);
        setLlave_TXT(padre->derecho,key_TEXT);
        fprintf(key_TEXT,"%c %d ",padre->caracter,padre->frecuencia);
        //printf("\nC : %c\tF : %d",padre->caracter,padre->frecuencia);
    }
}

Nodo2 *getClave(Nodo *lista,char c){
    //Método que regresa la clave del caracter c, este caracter debe estar en nuestra lista
    Nodo *aux = NULL;
    aux = lista;

    while(aux != NULL){
        if(aux->caracter == c){
            //printf("\nCARACTER ENCONTRADO");
            break;
        }else{
            aux = aux->siguiente;
        }
    }

    return aux->clave;

}

void setArchivoBinario(FILE *wF,Nodo *lista,Nodo *texto){
    //Método que rellena el archivo binario con decimales
    FILE *textoAUX  = tmpfile();
    Nodo *aux = texto;
    Nodo2 *aux2 = NULL;
    Nodo2 *clave = NULL;
    int contador = 1;
    int contador2 = 0;
    char caracter = ' ';

    //ESCRITURA DE LA FRASE CON LAS CLAVES EN TEXTOAUX
    while(aux != NULL){ //recorrimiento de la lista frase
        //printf("\n%c[%d]",aux->caracter,contador);
        clave = getClave(lista,aux->caracter); //obtención pila clave
        aux2 = clave;
        while(aux2 != NULL){//recorrido de mi pila clave
            caracter = getCaracter(aux2);//obtención 1 o 0
            fprintf(textoAUX,"%c",caracter);//inserta el 1 o 0 en el texto temporal
            aux2 = aux2->siguiente;
            contador ++;
        }
        aux = aux->siguiente;

    }

    //SE ESCRIBEN LOS CEROS RESTANTES EN TEXTOAUX
    contador = 7-(contador%7)+1;
    for (int i = 0; i < contador; i++){
        fprintf(textoAUX,"%c",'0');
    }

    free(aux);
    free(aux2);
    free(clave);

    rewind(textoAUX);

    //GENERA UNA PILA DE LOS CARACTERES DEL TEXTO AUX
    Nodo2 *pilaB = NULL;
    int numero = 0;
    caracter = fgetc(textoAUX);

    while(feof(textoAUX) == 0){//se apilan los caracteres del texto aux
        pilaB = apilar(pilaB,caracter);
        caracter = fgetc(textoAUX);
    }

    //CONVERSION DE DECIMAL A BINARIO
    Nodo2 *aux3 = pilaB;
    Nodo2 *aux4 = NULL;
    while(aux3 != NULL){//recorrido de la pila de los caracteres del texto aux
        for (int i = 0; i < 7; i++){
            numero = numero + (((int)aux3->caracter-48)*pow(2,i));
            aux3 = aux3->siguiente;
        }
        aux4 = apilar2(aux4,numero);
        //printf("%d[%d]\t",numero,contador2);
        contador2++;
        numero = 0;
    }

    //ESCRITURA AL ARCHIVO BINARIO
    Nodo2 *aux5 = aux4;
    int numeros[1];
    numeros[0] = contador2;
    fwrite((int*)numeros,sizeof (numeros[0]),1,wF);

    while(aux5 != NULL){//recorrido de mi pila de numeros decimales
        //printf("\n[%d]",aux5->dato);
        numeros[0] = aux5->dato;
        fwrite((int*)numeros,sizeof (numeros[0]),1,wF);
        aux5 = aux5->siguiente;
    }

    fclose(wF);
    /*FILE *f = fopen("codigo","rb");
    int datos[7];
    fread(&datos,sizeof(int),7,f);

    printf("\nDATOS RECUPERADOS DEL ARCHIVO BINARIO");
    for(int i = 0; i<7;i++){
        printf("\n%d",datos[i]);
    }*/

    free(aux3);
    free(aux4);
    free(aux5);
    free(pilaB);
    //fclose(f);
}

#endif
