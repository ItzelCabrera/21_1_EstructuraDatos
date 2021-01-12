#include"CVIB_2020640576.H"

int main(){
    printf("Programa para realizar la decodificacion/descompresion de Huffman.\n\n");

    FILE *fK = fopen("llave.txt","r");
    FILE *fC = fopen("codigo.bin","rb");
    FILE *tmpF = tmpfile();
    FILE *fS = fopen("frase.txt","w");

    Nodo *AL = NULL; //crea arbolista
    Nodo *tree = NULL; //crea arbolito
    Nodo2 *pilaC = NULL; //crea pila temporal de claves
    Nodo *LB = NULL; //crea lista binaria
    Nodo *LC = NULL; //crea lista claves

    checkAperturaF(fK,fC,fS);

    //CREA LA LISTA APARTIR DEL TXT
    AL = setLista_FromTxt(AL,fK);

    //GENERA EL ARBOL APARTIR DE LA LISTA
    tree = setArbol(AL);

    //GENERA LAS CLAVES DE CADA CARACTER
    setClaves(tree,pilaC,2);

    //GENERA LA LISTA BINARIA A DECODIFICAR
    LB = setListaB(fC,LB);

    //ESCRIBE EN UN TMPFILE LOS CARACTERES Y SUS RESPECTIVAS CLAVES
    setTXTClaves(tree,tmpF);
    rewind(tmpF);

    //CREA UNA LISTA EXCLUSIVAMNETE PARA LOS CARACTERES Y SUS CLAVES
    LC = setListaClaves(tmpF,LC);

    printf("Decodificacion/descompresion exitosa.\n\nRevisar el archivo generado <<frase.txt>>\n\n");
    printf("TEXTO DECODIFICADO: ");decodificacion2(tree,LB,fS);

    free(AL);
    free(tree);
    free(pilaC);
    free(LB);
    free(LC);

    cerrarArchivos(fK,fC,fS);
return 0;
}
