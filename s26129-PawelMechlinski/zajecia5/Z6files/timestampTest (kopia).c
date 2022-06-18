#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include <stdio.h>
#include <time.h>

int main ()
{
   FILE *fp;

   fp = fopen("/tmp/test.txt", "a");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);

  return 0;
}

