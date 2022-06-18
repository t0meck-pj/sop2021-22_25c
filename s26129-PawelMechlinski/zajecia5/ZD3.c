#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

///* Zajęcia 4: Zadanie 3
/*
Napisz program, który będzie pobierał jeden argument z wiersza poleceń  i będzie obliczał w 2 procesach:
A. Proces rodzica: Wartość sumy liczb od 0 do wartości zadanej jako pierwszy argument wykonania programu.
B. Proces potomny: Wypisujący liczby nieparzyste od 1 do wartości zadanej jako pierwszy argument wykonania programu.
C. Program powinien wypisać wyniki w kolejności takiej, że najpierw wypisze wynik proces potomny, a następnie proces rodzica.
D. *////Nie korzystaj z komendy sleep.

///
int main()
{
    int n;

    int suma(n)
    {
        int suma = 0;
        for (int i = 0; i <= n; i++) suma += i;
        return suma;
    }

    printf("Podaj argument: ");
    scanf("%i", &n);

    int pid;
    int status;



    pid = fork();
    if (pid == 0)
    {
    printf("POTOMEK-NIEPARZYSTOKOPYTNY(PID=%i)\nLiczby nieparzyste mniejsze niż %i to:\n", getpid(), n);
    for (int i = 0; i <= n; i++)
    {
        if (i % 2 != 0) printf("%i ", i);
    }
    exit(EXIT_SUCCESS);
    }

    waitpid(pid, &status, 0);

    printf("\nRODZIC-SUMO (PID=%i):\nSuma liczb od 0 do %i wynosi: %i\n\n***", getpid(), n, suma(n));

    return 0;

}
