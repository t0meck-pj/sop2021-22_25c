#include<stdio.h> 
int  main(){
printf("podaj ilość liczb: ");
int x;
int y=0;
int a=0;
scanf("%d",&x);
for (int i=0;i<x;i++){
    scanf("%d",&a);
    y=y+a;
}
    printf("suma to %d\n", y);
return 0;
}