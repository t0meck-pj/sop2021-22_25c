#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

///* Zajęcia 5: Zadanie 2
/*
Napisz program, który uruchomi podproces za pomocą komendy fork. Niech proces rodzica oczekuje na proces potomka. Oba procesy powinny wypisać swój PID oraz PPID.
*/

///
int main()
{
    int pid;
    int status;

    printf("RODZIC: PID=%i\n", getpid());
    printf("DZIADEK: PPID=%i\n###\n", getppid());

    pid = fork();
    if (pid == 0)
    {
    printf("POTOMEK: PID=%i\n", getpid());
    printf("RODZIC: PPID=%i\n", getppid());
    sleep(3);
    exit(EXIT_SUCCESS);
    }

    waitpid(pid, &status, 0);

    printf("Jeśli to czytasz to znaczy, że POTOMEK exitował.");

    return 0;

}
