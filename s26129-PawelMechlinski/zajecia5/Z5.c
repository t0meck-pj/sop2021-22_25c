#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

///* Zajęcia 5: Zadanie 5
/*
Napisz program, który uruchomi 100 procesów potomnych w taki sposób, że będzie jeden rodzic i 100 potomków.
Proces główny niech oczekuje na zakończenie wszystkich procesów potomnych.

--->    Przydatne funkcje: waitpid i wait

*/

///
int main()
{
    int n = 10, i; // Żeby zrobić wersję dla większej liczby (sub) procesów, należy zwiększyć n.
    int pid;
    int status;


    for (i = 0; i < n; ++i) {
    pid = fork();
    if (pid > 0) {   // fork() przyjął wartość dodatnią, to znaczy, że jestem rodzicem. Utwórz kolejnego potomka!
        if (i+1 == n) // Jesli to ostatnie okrążenie, to czekaj na kliknięcie klawiatury, które skilluje wszystkie procesy po kolei.
        {
        getchar();
        break;
        }
        continue;

    } else if (pid == 0) { // fork() zwraca zero, to znaczy, że mamy do czynienia z potomkiem - nie rób nic, rodzic będzie tworzył kolejnych potomków.
        printf("POTOMEK NR%i o PIDzie %i, utworzony z %i\n", i+1, getpid(), getppid());
        break;

    } else { // Jeśli fork() przyjmuje wartość ujemną to znaczy, że coś się sypło...
        printf("fork error\n");
        exit(1);
    }
}

    // W tym wypadku waitpid nie jest potrzebny, bo po wyjściu rodzica, wszyscy potomkowie zostaną ubici.

    return 0;

}
