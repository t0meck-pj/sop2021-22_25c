#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv){
    int* tab;
    int wersy;
  int i;
    FILE * file;
    file = fopen("test.txt","r");
    
    if(file==NULL){
        printf("nie ma takiego pliku\n");
        return -1;

    }else{
        fscanf(file,"%d\r\n", &wersy); /* odczytywanie pełnego wersu*/
        tab = (int*)malloc(wersy * sizeof(int));
        /*printf("tyle wersow czytam %i :\n",wersy);*/
        for (i=0;i<wersy;i++){
           fscanf(file,"%i\r\n", &*tab+i);
         }
         for (i=wersy-2;i>=0;i--){
           printf("%d\n",tab[i]);
         }
       free(tab);
        fclose(file);
        return 0;

    }

}