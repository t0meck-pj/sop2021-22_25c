#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

///* Zajęcia 4: Zadanie 4
/*
Napisz program, który uruchomi 100 procesów w taki sposób, że każdy kolejny potomek stworzy potomka.
Niech każdy proces poczeka na zakończenie procesu potomka.
Możesz korzystać z oczekiwania na wejście lub z komendy sleep i zobacz czy drzewko procesów jest takie
jak się spodziewasz (możesz w tym celu ograniczyć liczbę procesów do 10). Zobacz podpowiedź na początku tej strony.

A. Czyli drzewo procesów ma wynikowo wyglądać tak: główny -> potomek1 -> potomek2 -> ... -> potomek99 -> potomek100
B. Przydatne przy sprawdzaniu: Drzewo procesów można wydrukować poleceniem pstree
*/

///
int main()
{
    int n = 10, i; // Żeby zrobić wersję dla większej liczby procesów, należy zrobić większe n.
    int pid;
    int status;


    for (i = 0; i < n; ++i) {
    pid = fork();
    if (pid > 0) {   // fork() przyjął wartość dodatnią, to znaczy, że jestem rodzicem. Nie rób nic więcej, czekaj na sygnał od potomka.
        break;
    } else if (pid == 0) { // fork() zwraca zero, to znaczy, że mamy do czynienia z potomkiem - W takim razie, trzeba wydrukować info i stworzyć następnego w kolejnej rundzie pętli.
        printf("POTOMEK NR%i o PIDzie %i, utworzony z %i utwórz nowego!\n", i+1, getpid(), getppid());
        if (i+1 == n) // Jesli to ostatnie okrążenie, to czekaj na kliknięcie klawiatury, które skilluje wszystkie procesy po kolei.
        {
        getchar();
        break;
        }
        continue;
    } else { // Jeśli fork() przyjmuje wartość ujemną to znaczy, że coś się sypło...
        printf("fork error\n");
        exit(1);
    }
}


    waitpid(pid, &status, 0);

    return 0;

}
