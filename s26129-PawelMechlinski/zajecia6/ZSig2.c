#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

///* Zajęcia 6: Zadanie 2 Sygnały
/*
Przygotuj program, który będzie pozwalał na uruchomienie tylko jednej swojej instancji.
Dodatkowo w momencie próby uruchomienia drugiej instancji będzie powiadamiał już uruchomiony proces o tym.
Można to zrobić tak:
- Program uruchamia się i sprawdza, czy jest plik /tmp/lock
- Jeśli taki plik nie istnieje, wtedy:
- tworzony jest taki plik. Do niego zapisywany jest PID bieżącego procesu [ v ]
- program instaluje obsługę sygnału USR1, która w momencie otrzymania sygnału wypisuje tekst:
    "Wykryto próbę uruchomienia drugiej instancji programu."
- program instaluje obsługę sygnału generowanego przez CTRL+C (poszukaj jaki to sygnał), która w momencie otrzymania tego sygnału skasuje plik /tmp/lock i spowoduje wyjście z pętli nieskończonej (patrz następny punkt) [ v ]
- program wykonuje pętlę nieskończoną zawierającą tylko instrukcję sleep. [ v ]

Jeśli taki plik istnieje, wtedy:
- Wczytywana jest zawartość tego pliku - pid procesu uruchomionego [ v ]
- generowany jest sygnał USR1 do procesu o pid takim jak wczytany [ v ]
- program kończy pracę [ v ]
*/

///


void my_handler(int signum) // Kom. dla mnie: To powinno być ok.
{
    printf("\nOtrzymałem sygnał.\n");
    if(remove("/tmp/lock") == -1) perror("Nastąpił błąd przy próbie usunięcia pliku.");
    printf("Do widzenia!\n");
    exit(0);
}

void user_handler(int signum)
{
    printf("\nWykryto próbę uruchomienia drugiej instancji programu.\n");
}


int main()
{
    int pid;
    pid = getpid();
    printf("PID tej instancji programu to %i\n", pid);
    signal(SIGINT, my_handler);

    signal(SIGQUIT, user_handler);

    FILE *fp;

    fp = fopen("/tmp/lock","r");

    if (fp != NULL) // plik już istnieje - wyślij sygnał i umrzyj.
    {
        int innyPID;
        fscanf(fp, "%i", &innyPID );
        fclose(fp);
        printf("Już działa instancja programu o PID: %i, ta instancja programu zostanie wyłączona.\n", innyPID);
        kill(innyPID, SIGQUIT);
        exit(0);
    }

    if(fp == NULL) // plik nie istnieje, ta instrukcja warunkowa działa.
    {
        // utwórz plik:
        printf("Brak pliku lock.\n");
        fp = fopen("/tmp/lock", "w");
        if (fp == NULL) { perror("Nastąpił błąd przy próbie utworzenia pliku lock."); exit(0); };
        printf("Plik lock utworzony\n");
        fprintf(fp, "%i", getpid());
        fclose(fp);
        printf("Stream z plikiem został wyłączony.\n");
    }

    while(1 == 1)
    {
        sleep(1);
    }

    return 0;
}

// Cóż, program zakończył się po skillowaniu... :)
