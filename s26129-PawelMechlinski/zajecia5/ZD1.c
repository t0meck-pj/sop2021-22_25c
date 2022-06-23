#include<stdio.h>
#include<stdlib.h>

///* Zajęcia 5: Zadanie Domowe - podstawowe.
/*
Napisz program, który wygeneruje drzewko procesów wyglądające tak (oczywiście procesy nie będą się nazywały A, B, ...):

A \

  |\B \

  |   |\D

  |    \E

   \C \

      |\F

       \G

A jest rodzicem 2 procesów - B oraz C, a te są odpowiednio rodzicami D i E, oraz F i G.
*/

///
int main()
{
    int pidA = 1;
    int pidB;
    int pidC;
    int pidD;
    int pidE;
    int pidF;
    int pidG;

    int status;

    printf("Proces pierwszy rodzic A: PID=%i\n", getpid());
    pidB = fork();
    if (pidB == 0)
    {
        printf("Proces B z PID=%i i PPID=%i\n", getpid(), getppid());
        pidD = fork();
        if (pidD == 0)
        {
            printf("Proces D z PID=%i i PPID=%i\n", getpid(), getppid());
            pidE = fork();

            if (pidE == 0)
            {
            printf("Proces E z PID=%i i PPID=%i\n", getpid(), getppid());
            }
        }
    }
    else
    {
        if (pidB > 0)
        {
        pidC = fork();
        if (pidC == 0)
        {
            printf("Proces C z PID=%i i PPID=%i\n", getpid(), getppid());
            pidF = fork();

            if (pidF == 0)
            {
                printf("Proces F z PID=%i i PPID=%i\n", getpid(), getppid());
                pidG = fork();

                if (pidG == 0)
                {
                    printf("Proces G z PID=%i i PPID=%i\n", getpid(), getppid());
                }
            }
        }

        }
    }

   // pidC = fork();

   /* fork();
    if (pid == 0)
    {
    printf("Proces\n POTOMEK: PID=%i\n", getpid());
    getchar();
    exit(EXIT_SUCCESS);
    }

    waitpid(pid, &status, 0);

    printf("Jeśli to czytasz to znaczy, że POTOMEK exitował.");
*/
    getchar();
    return 0;

}
