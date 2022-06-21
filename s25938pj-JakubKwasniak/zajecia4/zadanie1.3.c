#include<stdio.h>
#include<stdlib.h>
int i;
int j;
int n;
int main(int argc, char** argv)
{
  scanf("%d", &n); 
  printf("\n");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n-i;j++)
    {
      printf(" ");
    }
    for(j=1;j<=2*i-1;j++)
    {
      printf("*");
    }
    printf("\n");
  }
  return n;
}

