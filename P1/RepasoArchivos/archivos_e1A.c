#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *fl = fopen("ArchivoNuevo_E1.txt", "r");
    FILE *fe = fopen("ArchivoB_E1.bin","ab");

    char month[25];
    int n1,n2,n3;

    if(fl != NULL & fe != NULL){
        int leidos;

        fseek(fl,0,SEEK_END);//me coloco al final del archivo
        int nElementos = ftell(fl); //no elementos en el archivo
        rewind(fl); //me vuelvo a colocar al inicio del archivo

        char *buffer = (char*)calloc(sizeof(char),nElementos);

        leidos = fread(buffer,1,nElementos,fl);
        fwrite (buffer, 1, leidos, fe);

        printf("%d\n",leidos);
        printf("%d\n",nElementos);
    }else{
        perror("Error!");
        exit(1);
    }

    fclose(fl);
    fclose(fe);
}
