#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int liczba = 0;
    printf("PID: %d\n", getpid());
    printf("PPID: %d\n", getppid());
    printf("Podaj liczbe: ");
    scanf("%d", &liczba);

    printf("%d + %d = %d\n", liczba, liczba, liczba+liczba);
    return 0;
}
