#include<stdio.h>
#include<signal.h>
#include<unistd.h>

///* Zajęcia 6: Zadanie 1 Sygnały
/*
Przygotuj prosty programik, który:
- Wypisze na ekranie swój PID
- Będzie czekał w pętli nieskończonej do momentu otrzymania sygnału użytkownika (SIGUSR1)
- W momencie otrzymania tego sygnału program powinien wypisać na ekranie, że dostał sygnał i się zakończyć.
*/

///


void my_handler(int signum)
{
    printf("Dostałem sygnał. Do widzenia.\n");
    exit(0);
}


int main()
{
    printf("PID=%i\n", getpid());
    while(1 == 1)
    {
        signal(SIGINT, my_handler);
    }

    return 0;
}

// Cóż, program zakończył się po skillowaniu... :)
