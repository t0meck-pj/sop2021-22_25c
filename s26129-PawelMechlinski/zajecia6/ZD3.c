#include<stdio.h>
#include<signal.h>
#include<unistd.h>

///* Zajęcia 6: Zadanie 1 Sygnały
/*
Przygotuj program, który będzie pozwalał na uruchomienie tylko jednej swojej instancji.
Dodatkowo w momencie próby uruchomienia drugiej instancji będzie powiadamiał już uruchomiony proces o tym.
Można to zrobić tak:
- Program uruchamia się i sprawdza, czy jest plik /tmp/lock
- Jeśli taki plik nie istnieje, wtedy:
- tworzony jest taki plik. Do niego zapisywany jest PID bieżącego procesu
- program instaluje obsługę sygnału USR1, która w momencie otrzymania sygnału wypisuje tekst:
- Wyrkyto probe uruchomienia drugiej instancji programu.
- program instaluje obsługę sygnału generowanego przez CTRL+C (poszukaj jaki to sygnał), która w momencie otrzymania tego sygnału skasuje plik /tmp/lock i spowoduje wyjście z pętli nieskończonej (patrz następny punkt)
- program wykonuje pętlę nieskończoną zawierającą tylko instrukcję sleep.
*/

///


void my_handler(int signum)
{
    printf("Otrzymałem sygnał.\n");
    if(remove("/tmp/lock") == -1) perror("Nastąpił błąd przy próbie usunięcia pliku.");
    printf("Do widzenia!");
    exit(0);
}


int main()
{
    int pid;
    pid = getpid();
    printf("PID=%i\n", pid);


    FILE *fp;
    fp = fopen("/tmp/lock","r");
    if (fp != NULL) // plik już istnieje
    {
        int innyPID;
        fscanf(fp, "%i", innyPID );
        printf("Już działa instancja programu o PID: %i, ten program zostanie wyłączony.\n", innyPID);
        kill(innyPID, SIGUSR1);
        exit(0);
    }
    if(fp == NULL) // plik nie istnieje
    {
        // utwórz plik:
        printf("Brak pliku lock.\n");
        fp = fopen("/tmp/lock", "w");
        printf("Plik lock utworzony\n");
        fprintf(fp, "%i", getpid());
            //fclose(fp);
    }

    signal(SIGINT, my_handler);

    while(1 == 1)
    {
        sleep(1);
    }

    return 0;
}

// Cóż, program zakończył się po skillowaniu... :)
