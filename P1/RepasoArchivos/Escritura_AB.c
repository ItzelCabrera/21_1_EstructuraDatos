#include<stdio.h>
#include<stdlib.h>

int main(){
    //crea un apuntador de tipo FILE
    FILE *FO = fopen("ArchivoNuevo_E1.txt","r");
    FILE *FI = fopen("ArchivoB_E1.bin","wb");
    int numeros[15];
    int i = 0;
    int n1 = 0;
    char c[100]; //tamaño del array es arbitraria
    char s[100];

    if ( FO != NULL ){ //intenta abrir el stream (r)

        while(feof(FO) == 0){
            fscanf(FO,"%s\t%s\t%i\n",&c,&s,&n1); //lee el flujo y va almacenando lo leido en las variables
            //printf("%s",c);
            numeros[i] = n1;

            i++;
        }

        for(int i = 5; i < 15; i++){
            numeros[i] = (i + 10);
        }

        fwrite((int*)numeros,sizeof(int),15,FI);

        fclose(FO);//cierra el stream
        //fflush(FI);//limpia el stream
        fclose(FI);//cierra el stream

    }
    else{
        fprintf(stderr,"Algun archivo no se puede abrir");
        exit(1);
    }



    return 0;
}
