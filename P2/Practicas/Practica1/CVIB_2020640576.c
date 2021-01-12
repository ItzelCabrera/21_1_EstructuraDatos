#include"CVIB_2020640576.h"

int main(){

    //ESTRUCTURAS
    Nodo *lista = NULL;
    Nodo *texto = NULL;
    Nodo *arbolito = NULL;
    Nodo2 *pilaC = NULL;


    //FICHEROS
    FILE *rF = fopen("Texto.txt","r");
    FILE *wF = fopen("codigo.bin","ab");
    FILE *key = fopen("llave.txt","a");

    checkAperturaF(rF,wF,key);

    //LECTURA DEL TEXTO
    lista = insertarC_FromTXT(lista,rF);

    rewind(rF);//posiciona al inicio del archivo Texto.txt

    texto = insertar_FromTXT(texto,rF); //crea una lista con los caracteres del texto

    //SORT (dada la frecuencia)
    lista = ordenar(lista);

    printf("\n\nLista ordenada");

    //ASIGNACIÓN DEL NODO ARBOLITO
    arbolito = recorridoLista(lista);

    ver_PRE(arbolito);
    printf("\n\nSe ha creado el arbolito");

    //GENERAN LAS CLAVES DE CADA CARACTER
    setClaves(arbolito,pilaC,2);

    free(pilaC);

    //GENERA EL ARCHIBO BINARIO
    setArchivoBinario(wF,lista,texto);

    //GENERA EL ARCHIVO LLAVE
    setLlave_TXT(arbolito,key);

    printf("\n\nSe ha generado el archivo llave.txt");

    free(arbolito);
    free(lista);
    free(texto);

    cerrarArchivos(rF,key);


    return 0;
}
