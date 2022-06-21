#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    if(fork()==0)
    {
        printf("Jestem rodzicem");
    }
    else 
    {
        printf("Jestem dzieckiem")
    }
    printf("PID: %d\n", getpid());
    printf("PPID: %d\n", getppid());
    return 0;
}
