
///* Zajęcia 4: Zadanie 6 Podejście 2
/*
Napisz prosty program chat-u, który będzie korzystał z pliku w katalogu /tmp do przekazywania wiadomości. Zastanów się jak to zrobić.

Moja propozycja na taką dość prostą wersję rozwiązania (nr 2):
A. Na początku:
- Wybierz swój nick. [ v ]
- Wyświetl ostatnie 5 linijek z pliku czatu (IRL lepiej więcej, ale jest tak dla łatwiejszego debugowania). [ v ]
B. Następnie w pętli:
    I. (READ) W jednym procesie utrzymuj pętlę nasłuchu na plik, która będzie wyświetlać nowe wiadomości).
        - Ale nie Twoje własne, więc trzeba np. trzymać w pamięci liczbę postów i wyświetlać tylko te nowe.
    II. (WRITE) W drugim procesie druga pętla będzie umożliwiała skanowanie tekstu od usera i umieszczała go w pliku.
+ Wyłączenie programu na komendę.

*/
///Ten program powstał jako moje drugie podejście do tej implementacji, tym razem wersja "minimum" (i z forkiem).

///
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include <time.h>


int main()
{
    char nick[24];
  //  char saltedNick[30];
    char buf[255];
    int length = 0;
    int ct = 0;
    int ch;
    int pid;
    int diff;
//    char randomletter;

    // Obsługa timestamps
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    char time[30] = {0};
    int timelen = strlen(time);

    // Otwieranie pliku
    FILE *fp = fopen("/tmp/czat", "r");
    if (fp == NULL) { fprintf(stderr, "Błąd podczas otwierania czatu!\n"); return -1; }


    // Wybierz nickname.- odkomentować, żeby możliwe było wybieranie nicka.
    printf("Witaj w PJATKCZAT. Podaj swój nick:\n");

    scanf("%23s", &nick);


    // DEBUG mode - automatyczny wybór nicka
//    strcpy(nick, "User2");


/*    strcpy(saltedNick, nick);
    for (int i = 0; i < 6; i++)
    {
    randomletter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random () % 26];
    //strcat(saltedNick, randomletter);
    }
*/

    // Oblicz długość pliku czatu - IRL mogłoby wymagać optymalizacji. Np. Wiadomości pow. 256 znaków (minus stopka) będą traktowane jako więcej niż jedna linia).
    while ((ch = fgets(buf, 255, (FILE*)fp)) != NULL )
    {
    length += 1;
    }
    rewind(fp);

    printf("[DEBUG]Czat ma: %i linii długości\n", length);


    while (fgets(buf, 255, (FILE*)fp) != NULL) printf("%s", buf);


    bzero(buf, 255);
    fclose(fp);
    fp = fopen("/tmp/czat", "r+");

	pid = fork();
    printf("\n[DEBUG]Forkowanie powiodło się.\n");



    if (pid == 0) // WRITE to chat - wydaje się działać ok.
    {
        printf("\n[DEBUG]WRITEr rusza.\n");
        while (1)
        {
        fp = fopen("/tmp/czat", "a");
        printf("\n@%s: ",nick);
        scanf("%s", &buf);
        fprintf(fp, "\n%s: %s", nick, buf);
        bzero(buf, 255);

        fclose(fp);
        }
    }

    if (pid > 0) // READ from chat
    {
        printf("\n[DEBUG]READr rusza.\n");

        while (1)
        {
            fp = fopen("/tmp/czat", "r+");
            ct = 0;
            // Oblicz aktualną długość
            while ((ch = fgets(buf, 255, (FILE*)fp)) != NULL )
            {
            ct += 1;
            }
            rewind(fp);
            diff = length - ct;
            printf("[DEBUG]Czat ma teraz: %i linii długości, co oznacza, że trzeba dopisać %i\n", length, diff);

            rewind(fp);
            ct = 0;

            for (;ct < length; ct++)
            {
                fgets(buf,255, (FILE*)fp);
            }

            while (diff > 0)
            {
            fgets(buf,255, (FILE*)fp);
            if (strstr(buf, nick) != NULL) printf("%s", buf);
            diff--;
            }

            // Jeśli ostatnia wiadomość jest napisana przez danego usera (w tym wypadku jest to test user) to zostanie zignorowana - można sprawdzić, czy zawiera nagłówek 'User:'
            //fgets(buf,255, (FILE*)fp);


            sleep(1);
            getchar();

            printf("[DEBUG]Czytam...\n");

            fclose(fp);
        }

    return 0;
}
    }

/*
        while ( ct < length-5 )
        {
        if (ch = fgets(buf, 255, (FILE*)fp == NULL)) break;
        ct += 1;
        }
        while ((ch = fgets(buf, 255, (FILE*)fp)) != NULL )
        {
        printf("%s", buf);
        }

        }

    }
 */

        /*// Sprawdzaj, czy nie zmieniła się długośc pliku -> oblicz obecną długość.
            while ((ch = fgets(buf, 255, (FILE*)fp)) != NULL )
            {
                length += 1;
            }
            rewind(fp);
            printf("%s rzędów.");
            // Jeśli jest dłuższy to wyświetl różnicę:
            // - najpierw przewiń do końca dotychczasowego czatu
            for (int i = 0; i < ct; i++)
            {
                fgets(buf, 255, (FILE*)fp);
            }

            // - następnie wyświetl różnicę:
            while ((ch = fgets(buf, 255, (FILE*)fp)) != NULL )
            {
            length++; printf("\n[DEBUG]Liczba wpisów w czacie powiększyła się.\n");
            // - ... z wyjątkiem własnych postów, oznaczonych Nick'iem
    //        if (strstr(buf, saltedNick) == NULL) continue;
                if (strstr(buf, nick) == NULL) continue;
            printf("%s", buf);
            }
            rewind(fp);
            fclose(fp);
            sleep(1); // DEBUG
            return 0;
        }
    }

    while (1)
    {
        sleep(1);
    }
    return 0;
}*/

