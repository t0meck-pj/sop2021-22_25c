///* Zajęcia 6: Zadanie 1 Sockets - Serwer
/*
1. Korzystając z przykładów (albo samodzielnie, lub na podstawie manuala) przygotuj programy - klient oraz serwer.
- Niech serwer będzie udostępniał wybrany plik.
- Niech klient będzie miał możliwość pobrania wybranego przez klienta pliku.
- Jako uproszczenie przyjmujemy że serwer nie dba o żadne zasady bezpieczeństwa.
- Protokół komunikacji niech wygląda tak:

KLIENT                                  SERWER

długość_nazwy_pliku               >

nazwa_pliku[długość_nazwy_pliku]  >

                                  <   wielkość_pliku

                                  <   paczka_1[wielkość_pliku]

--zamknij połączenie--                --zamknij połączenie--

Serwer powinien działać w pętli.

2. Niech serwer, w sytuacji, jeśli pliku nie udało się otworzyć, wysyła wielkość pliku jako -1. [ V ? ]
3. Niech serwer zakończy w elegancki sposób pracę w momencie naciśnięcia przez użytkownika Ctrl+C. Chodzi o zamknięcie gniazda nasłuchującego. [ V ]
4. Niech serwer zapisuje logi do pliku - to znaczy informacje o tym kto się podłączył (jego IP oraz port) oraz o jaki plik poprosił.


Moja notatka:
1. Algorytm komunikacji klient-serwer: [ V ]
    I. Klient - długosc_nazwy_pliku -> Serwer.
    II. Klient - nazwa_pliku -> Serwer.
    III. Serwer - wielkosc_pliku -> Klient
    IV. Serwer - zawartość pliku(? prawdopodobnie w pakietach) -> Klient
    V. Obaj: zamknij połączenie.
    VI. Klient: Zakończ działanie, ew. wyświetl zawartość pliku.
    VII. Serwer: Bądź gotowy na kolejne połączenie.
2. Dodatkowe wymagania:
    I. Serwer niech wysyła wielkość pliku '-1' jeśli nie udało się go otworzyć (+ klient powinien to handlować). [ V ? ]
    II. Serwer kończy prace w momencie naciśnięcia Ctrl+C z zamknięciem gniazda nasłuchowego. [ V ]
    III. Serwer działa w pętli, wyłącza się dopiero, gdy dostanie sygnał. [ V ]
    IV. Serwer zapisuje logi - info ma zawierać co najmniej: [ V ]
        - Kto się podłączył: IP + port.
        - o jaki plik poprosił (nazwa pliku).
        - (dopisek mój) dobrze by pasował jeszcze timestamp.
*/

///

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


// Handler błędów
void error(char *msg)
{
    perror(msg);
    exit(1);
}


///

int main(int argc, char *argv[])
{
    FILE *fp;
    char buffer[256];
    char c;

// Obsługa read:
    int filename_length;
    char filename[256];

// Obsługa write:
    int filesizeInt = 0;
    size_t size;
    char eof[256] = {1};

// Obsługa timestamps
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

// Inicjalizacja zmiennych socket'u.
    int sockfd, newsockfd, portno, clilen;

    struct sockaddr_in serv_addr, cli_addr;
    int n;

// Instalacja handlera z zamykaniem portu.
    void my_handler(int signum)
{
    printf("\n[0]Dostałem sygnał. Do widzenia.\n");
    close(sockfd);
    exit(0);
}
    signal(SIGINT, my_handler);

// Sprawdź, czy został wybrany numer portu (jako argument przy inicjalizacji)
    if (argc < 2) {
        fprintf(stderr,"[-]Błąd! Nie wyznaczono adresu portu!\n");
        exit(1);
    }
// Utwórz socket za pomocą funkcji 'socket', a następnie wykonaj test:
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
       error("[-]Błąd podczas otwierania socketu!\n");

    printf("[+]Socket został poprawnie otworzony!\n");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

// Użyj funkcji 'bind', żeby połączyć socket ze specyficznym portem, a następnie wykonaj test.
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
             error("[-]Błąd w trakcie bindowania.\n");

// Rozpocznij nasłuch na otwartym porcie:
    listen(sockfd,5);
    printf("[+]Nasłuch na porcie %i uruchomiony.\n", portno);

// Pętla nasłuchu
    while (1==1) // Docelowo wyłączenie programu-serwera ma być możliwe wyłącznie przez kill.
    {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        // Test nawiązywania połączenia:
        if (newsockfd < 0) error("[-]Błąd podczas akceptowania połączenia!\n");

        printf("[0]Nawiązano przychodzące połączenie. Socket: %i\n", newsockfd);


        // W tym miejscu połączenie z klientem powinno już zostać nawiązane, więc można przejść do wymiany informacji zgodnie ze specyfikacją.
        /*
        I. Klient - długosc_nazwy_pliku -> Serwer.
        II. Klient - nazwa_pliku -> Serwer.
        III. Serwer - wielkosc_pliku -> Klient
        IV. Serwer - zawartość pliku(? prawdopodobnie w pakietach) -> Klient
        V. Obaj: zamknij połączenie.
        VI. Klient: Zakończ działanie, ew. wyświetl zawartość pliku.
        VII. Serwer: Bądź gotowy na kolejne połączenie.
        */


        // Blok read I: Odczytaj długość nazwy pliku.
        bzero(buffer,256);
        n = read(newsockfd,buffer,255);
        if (n < 0) error("[-]Błąd podczas czytania z gniazda!");


        filename_length = atoi(buffer);
        if (filename_length <= 0)
        {
            printf("[-]Błąd! Niepoprawna długość pliku!\n");
            continue;
        }
        printf(" # Długość nazwy pliku: %i\n",filename_length);

        // Blok read II: Odczytaj nazwę pliku.
        bzero(buffer,256);
        n = read(newsockfd,buffer,255);
        if (n < 0) error("[-]Błąd podczas czytania z gniazda!");


        strcpy(filename, buffer);
        bzero(buffer,256);

        if (strlen(filename) == 0) error("[!]Niepoprawna nazwa pliku.\n");
        else printf(" # Nazwa pliku: %s\n",filename);

        // Pisanie do pliku log
        FILE *logfile;
        logfile = fopen("/tmp/server/log", "a");
        char time[256];
        int port = cli_addr.sin_port;
        int addr = cli_addr.sin_addr.s_addr;

        fprintf(logfile, "[ %s ] IP: %i Port: %i Nazwa pliku: %s\n", asctime(timeinfo), addr, port, filename  );
        fclose(logfile);

        // Spróbuj otworzyć plik.
        fp = fopen(filename, "r");
        if (fp == NULL)
        {
            printf("[!]Nie udało się otworzyć pliku o podanej nazwie!\n");
            continue;
        }
        printf("[+]Plik znaleziony i otwarty.\n");
        printf(" # Zawartość wczytanego pliku to: \n\t");
        // Wyświetla zawartość pliku po jednym znaku.
        c = fgetc(fp);
        while (c != EOF)
        {
            printf ("%c", c);
            c = fgetc(fp);
        }

        // Uzyskaj wielkość pliku

        fseek(fp, 0L, SEEK_END);        // Przeskocz do końca pliku
        filesizeInt = ftell(fp);       // Uzyskaj długość pliku w bajtach
        rewind(fp);                // Powróć do początku pliku
        bzero(buffer,256);
        int length = snprintf( NULL, 0, "%d", filesizeInt );

        n = snprintf(buffer, 255, "%d", filesizeInt);
        if (n < 0)
        {
            perror("[-]Błąd w trakcie rekodowania!\n");
            fclose(fp);
            close(sockfd);
            exit(1);
        }

        printf(" ***********************\n# Wielkość pliku wynosi: %i B\n", filesizeInt);


        // Blok write I: Wyślij klientowi informację o wielkości pliku.
        size = sizeof(buffer);
        n = write(newsockfd, buffer, size + 1);
        if (n < 0) error("[-]Błąd w trakcie pisania do socketu.\n");

        printf("[+]Poprawnie przesłano wielkość pliku.\n");
        // Blok write II: Wyślij klientowi zawartość pliku.
        size = sizeof(buffer);
        bzero(buffer,256);

        while(fgets(buffer, 256, fp) != NULL)
        {
            if (send(newsockfd, buffer, size, 0) == -1)
            {
                perror("[-]Błąd w trakcie wysyłania pliku!\n");
                fclose(fp);
                close(sockfd);
                exit(1);
            }

        }


        send(newsockfd, eof, size, 0);
        printf("[+]Udało się przesłać plik do klienta!\n");
        bzero(buffer,256);
        close(newsockfd);
    }

    fclose(fp);
    close(sockfd);
    return -1;
    }


