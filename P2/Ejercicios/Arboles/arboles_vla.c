#include"ARBOLES_VLA.H"

int main(){
    Nodo *arbol = NULL;


    arbol = insertar(arbol,25);
    arbol = insertar(arbol,14);
    arbol = insertar(arbol,30);
    arbol = insertar(arbol,32);
    arbol = insertar(arbol,31);
    arbol = insertar(arbol,42);
    arbol = insertar(arbol,52);

    /*arbol = insertar(arbol,29);
    arbol = insertar(arbol,19);
    arbol = insertar(arbol,12);
    arbol = insertar(arbol,50);
    arbol = insertar(arbol,30);
    arbol = insertar(arbol,60);
    arbol = insertar(arbol,55);
    arbol = insertar(arbol,78);
    arbol = insertar(arbol,95);*/

    /*arbol = insertar(arbol,23);
    arbol = insertar(arbol,32);
    arbol = insertar(arbol,18);
    arbol = insertar(arbol,7);
    arbol = insertar(arbol,14);
    arbol = insertar(arbol,21);
    arbol = insertar(arbol,29);
    arbol = insertar(arbol,40);*/

    /*arbol = insertar(arbol,60);
    arbol = insertar(arbol,50);
    arbol = insertar(arbol,30);
    arbol = insertar(arbol,55);
    arbol = insertar(arbol,78);
    arbol = insertar(arbol,95);*/

    /*arbol = insertar(arbol,40);
    arbol = insertar(arbol,20);
    arbol = insertar(arbol,80);
    arbol = insertar(arbol,10);
    arbol = insertar(arbol,30);
    arbol = insertar(arbol,50);
    arbol = insertar(arbol,90);
    arbol = insertar(arbol,45);
    arbol = insertar(arbol,75);
    arbol = insertar(arbol,60);*/

    /*arbol = insertar(arbol,40);
    arbol = insertar(arbol,20);
    arbol = insertar(arbol,80);
    arbol = insertar(arbol,10);
    arbol = insertar(arbol,30);
    arbol = insertar(arbol,50);
    arbol = insertar(arbol,90);
    arbol = insertar(arbol,25);
    arbol = insertar(arbol,35);
    arbol = insertar(arbol,28);*/


    printf("\nPRE-ORDER\n");
    ver_PRE(arbol);


    return 0;
}

