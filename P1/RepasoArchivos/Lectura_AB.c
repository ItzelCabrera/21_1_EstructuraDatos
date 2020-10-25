#include<stdio.h>
#include<stdlib.h>

int main(){
    //crea un apuntador de tipo FILE
    FILE *FO = fopen("ArchivoB_E1.bin","rb");
    int numeros[15];

    if ( FO != NULL ){ //intenta abrir el stream (r)
        fread(&numeros,sizeof(int),15,FO);

        for(int i = 0; i < 15; i++){
            printf("%i\n",numeros[i]);
        }

        fclose(FO);//cierra el stream

    }
    else{
        fprintf(stderr,"Algun archivo no se puede abrir");
        exit(1);
    }



    return 0;
}
