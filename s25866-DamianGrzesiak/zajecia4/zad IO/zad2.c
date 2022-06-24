#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv){
    int i;
    int *tab=malloc(sizeof(int)*i);
    FILE * file;
    file = fopen("test.txt","r");
    if(file==NULL){
        printf("nie ma takiego pliku\n");
        return -1;

    }else{
        nfgetc(file);
        for(i=0;i<10;i++){
            printf("%c",num[i]);
        }
     
        fclose(file);
        return 0;

    }

}