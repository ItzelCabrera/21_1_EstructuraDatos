#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void quicksort(int a[],int pI,int uI){
    int i,j,central,pivote;

    central = (pI + uI)/2;
    pivote = a[central];
    i = pI;
    j = uI;

    int c = 0, z = 0,x = 0,y= 0;

    do{
        c++;
        while(a[i] < pivote){
            i++;
            printf("\nSe recorre el pivote izq a --> %d",i);
        }
        while(a[j] > pivote){
            j++;
            printf("\nSe recorre el pivote der a --> %d",j);
        }
        if(i <= j){
            z++;
            int temp;
            temp = a[i];
            a[i] = a[j]; //intercambia los valores
            a[j] = temp;
            printf("\nIntercambio de elementos --> %d",z);
            j++;
            i--;
        }
    }while(i <= j); //el procedimiento se repetirá hasta que los índices se crucen
    if (pI < j){ //se aplica recursamiento de la  sublista izquiera
        x++;
        printf("\nNumero de sublista izq --> %d",x);
        quicksort(a,pI,j);
    }
    if(uI > i){
        y++;
        printf("\nNumero de sublista der --> %d",y);
        quicksort(a,i,uI); // se aplica recursamiento de la sublista derecha
    }
}

int main(){
    printf("Ejemplo del algoritmo QuickSort\n");

    srand(time(NULL));
    int a[10] = {4,23,3,1,65,2,7,345,765,43};


    /*for(int i=0; i < 10; i++){
        printf("%d\n",a[i]);
    }*/

    quicksort(a,0,9);


return 0;
}
