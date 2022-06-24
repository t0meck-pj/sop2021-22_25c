#include <stdio.h>
int main(){
    int x;
    int i;
    int c[10];
    scanf("%d",&x);
    for(i=0;i<x;i++){
        scanf("%d",&c[i]);
    }
    for (i=0;i<x;i++){
        printf("%i \n",c[i]);
    }
    return 0;
}