#include<stdio.h> //flujo de datos
#include<stdlib.h>

int main(){
    int var = 10;
    int *apVar = &var;
    printf("Valor de var: %d\n", var);
    printf("Valor de apVar: %d\n", apVar);
    printf("Direccion de var: %p\n", &var);
    printf("Direccion de apVar: %p\n", &apVar);

    *apVar = 30; //se accede y cambia el contenido de la var a la que se está apuntando
    printf("Valor de var: %d\n", var);
    printf("Valor de apVar: %d\n", apVar);
    printf("Direccion de var: %p\n", &var);
    printf("Direccion de apVar: %p\n", &apVar);

    return 0;
}
