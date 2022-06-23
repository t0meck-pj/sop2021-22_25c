#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    int n = atoi(argv[1]);
    int i;
    int j;
    for (i=n;i>0;i--){
        for(j=n;j>0;j--){
            if(j<n-i+1){
               printf("*"); 
            }
            else{
                printf(" ");
            }
        }
        for(j=0;j<n;j++){
            if(j<n-i+1){
               printf("*"); 
            }
        }
        printf("\n");
    }
    return 0;
}