#include<stdio.h>
#include<stdlib.h>

///* Zajęcia 5: Zadanie 1
/*
Napisz program, który

    A. przedstawi swój numer PID, oraz PPID
    B. po wypisaniu, będzie czekał na standardowym wejściu na dane od użytkownika.
    C. Uruchom program - nic nie podawaj na wejściu (program powinien czekać w nieskończoność).
    Uruchom nowy terminal. W nim za pomocą komendy kill zamknij ten program korzystając z PID wypisanego przez niego na początku.
*/

///
int main()
{
    printf("PID=%i\n", getpid());
    printf("PPID=%i", getppid());
    getchar();

    return 0;
}

// Cóż, program zakończył się po skillowaniu... :)
