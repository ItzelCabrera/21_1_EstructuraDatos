#include<stdio.h> //flujo de datos
#include<stdlib.h>

void fFPUTC(FILE *F,char c){
    fputc(c,F);
}

void fFPUTS(FILE *F){
    fputs("HEY",F);
}

void fFPRINTF(FILE *F){
    fprintf(F,"HELLO");
}

void fFGETC(FILE *F){
    char c;

    while(feof(F) == 0){
        c = fgetc(F);
        printf("%c",c);
    }
}

void fFSCANF(FILE *F){
    char c[20]; //tamaño del array es arbitraria
    int n1,n2,n3;

    while(feof(F) == 0){
        fscanf(F,"%s\t%i\t%i\t%i",&c,&n1,&n2,&n3); //lee el flujo y va almacenando lo leido en las variables
        printf("%s\t%i\t%i\t%i\n",c,n1,n2,n3);
    }
}

void fFREAD(FILE *F){
    fseek(F,0,SEEK_END);//me coloco al final del archivo
    int nElementos = ftell(F); //no elementos en el archivo
    rewind(F); //me vuelvo a colocar al inicio del archivo

    //Reservamos memoria para almacenar lo leído del archivo
    char *cadena = (char*)calloc(sizeof(char),nElementos); //cadena de carac de forma dinámica
    if (cadena == NULL){
        fprintf(stderr,"Error al gestionar memoria");
        exit(1);
    }

    //Verifica que se haya leído todo el archivo
    int nElLeidos = fread(cadena,sizeof(char),nElementos,F);
    if (nElementos != nElLeidos){
        fprintf(stderr,"No se leyo todo el archivo");
        exit(1);
    }

    printf("%s",cadena); //imprime todo lo que leyó
    free(cadena);//libera el espacio de memoria

}

void fWRITE(FILE *F){

}


int main(){
    //crea un apuntador de tipo FILE
    FILE *FO = fopen("Archivo_E1.txt","r");
    FILE *FI =fopen("ArchivoNuevo_E1.txt","w");

    if ( FO != NULL && FI != NULL){ //intenta abrir el stream (r)

        while(feof(FO) == 0){
            int n1,n2,n3;
            char c[20]; //tamaño del array es arbitraria

            fscanf(FO,"%s\t%i\t%i\t%i\n",&c,&n1,&n2,&n3); //lee el flujo y va almacenando lo leido en las variables
            int sumN = n1 + n2 - n3;
            printf("%s\t%i\t%i\t%i\n",c,n1,n2,n3);
            fprintf(FI,"Respuesta %s\t%i\n",&c,sumN);
        }


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
