///* Zajęcia 6: Zadanie 1 Sockets - Klient
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

2. Niech serwer, w sytuacji, jeśli pliku nie udało się otworzyć, wysyła wielkość pliku jako -1.
3. Niech serwer zakończy w elegancki sposób pracę w momencie naciśnięcia przez użytkownika Ctrl+C. Chodzi o zamknięcie gniazda nasłuchującego.
4. Niech serwer zapisuje logi do pliku - to znaczy informacje o tym kto się podłączył (jego IP oraz port) oraz o jaki plik poprosił.
*/

///
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SIZE 256

// Funkcja handlera błędów
void error(char *msg)
{
    perror(msg);
    exit(0);
}
/*
// Funkcja, która odbiera i wypisuje zawartość pobranego od serwera pliku do pliku 'recv'.txt'.
void read_file(int sockfd, int wielkosc_pliku){
  int n;
  FILE *fp;
  char *filename = "/tmp/server/recv.txt";
  char buffer[SIZE];

  fp = fopen(filename, "w");
  while (1==1) {
    n = recv(sockfd, buffer, SIZE, 0);
    if (n <= 0){
      break;
      return;
    }
    fprintf(fp, "%s", buffer);
    bzero(buffer, SIZE);
  }
  return;
}
*/
int main(int argc, char *argv[])
{
    int sockfd, portno, n;

    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    char c;
    int filesizeCheck = 0;
    char eof[254] = {1};

    // Obecnie nazwa i długość pliku zostaną zahardcodowane do zmiennych dla wygodn(iejsz)ego testowania.
    FILE *fp;
    char filename[] = "/tmp/server/file";
    char output[] = "/tmp/server/output";
    char namelength[254];
    int lenInt = strlen(filename);
    sprintf(namelength, "%d", lenInt);
    size_t size;

    int wielkosc_pliku;

    // Instalacja handlera z zamykaniem portu.
    void my_handler(int signum)
    {
        printf("\n[0]Dostałem sygnał. Do widzenia.\n");
        close(sockfd);
        exit(0);
    }
    signal(SIGINT, my_handler);


    printf("[+] Klient zainicjalizowany.\n # Nazwa (/adres) pliku: %s\n # Jej długość to: %s\n======================\n", filename, namelength);
    // Jeśli za mało argumentów napisz instrukcję stawiania klienta:
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);


    if (sockfd < 0)
        error("[-]Błąd podczas otwierania gniazda!\n");
    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"[-]Błąd! Nie ma takiego hosta.\n");
        close(sockfd);
        exit(0);
    }
    printf("[+]Socket zainicjalizowany poprawnie!\n");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

/// W tym momencie połączenie z serwerem powinno już być nawiązane.

    printf("[+]Połączenie z serwerem nawiązane.\n");

    // A. Blok write I: Wyślij długość nazwy pliku.

    size = sizeof(namelength);
    n = write(sockfd,namelength,size + 1);
    if (n < 0)
    {
        perror("[-]Błąd w trakcie pisania do socketu.\n");
        close(sockfd);
        exit(0);
    }
    n = 0;
    printf("[+]Wysłano długośc nazwy pliku.\n");

    // B. Blok write II: Wyślij nazwę (ścieżkę) pliku.
    size = sizeof(filename);
    n = write(sockfd,filename,size + 1);
    if (n < 0)
    {
        perror("Błąd w trakcie pisania do socketu.\n");
        close(sockfd);
        exit(0);
    }
    printf("[+]Wysłano nazwę pliku.\n");

    // C. Blok read I: Odbierz wielkość pliku.
    bzero(buffer,256);
    size = sizeof(buffer);
    n = read(sockfd,buffer, size);
    if (n < 0)
    {
        perror("[-]Błąd w trakcie odczytywania z socketu.\n");
        close(sockfd);
        exit(0);
    }
    //printf("Buffer: %s\n", buffer);
    wielkosc_pliku = atoi(buffer);
    n = 0;
    if (wielkosc_pliku <= 0)
    {
        perror("[-]Otrzymano niepoprawną wielkość pliku.\n");
        close(sockfd);
        exit(0);
    }

    printf("[+]Udało się otrzymać info o wielkości pliku:\n # Odebrana wielkość pliku wynosi: %i B\n", wielkosc_pliku);

    // D. Blok read II: Odbierz, wyświetl i zapisz plik.
    fp = fopen(output, "w");
    if (fp == NULL)
    {
        perror("[!]Nie udało się otworzyć pliku wyjściowego (1)!\n");
        close(sockfd);
        exit(0);
    }
    printf("[+]Poprawnie otworzono plik wyjściowy (1).\n================================\n");



    bzero(buffer,256);
    size = sizeof(buffer);
    //for (int i = 0; i <= wielkosc_pliku; i += 256)
    while (1)
    {

        n = read(sockfd, buffer, size-1);
        fprintf(fp, "%s", buffer);
        //printf("Pobrano: %i\n", i);
        printf("[256] Tekst: %s\n", buffer);
        fprintf(fp, "%s", buffer);

        if (strcmp(buffer, eof ) == 0) {printf("\n[0]Odebrano oznaczenie EOF, kończę odbieranie.\n"); break; }
        if (n <= 0)
        {
            perror("[!]Błąd podczas odczytywania pliku!\n");
            close(sockfd);
            fclose(fp);
            exit(0);
        }
        bzero(buffer,256);
    }

    close(sockfd);
    printf("[+]Połączenie z serwerem zostało zamknięte.\n");
    fclose(fp);

    // Wyświetl zawartość pliku wyjściowego
    fp = fopen(output, "r");
    if (fp == NULL)
    {
        perror("[!]Nie udało się otworzyć pliku wyjściowego(2)!\n");
        exit(0);
    }

    printf("[+]Poprawnie otworzono plik wyjściowy (2).\n");
    printf(" # Zawartość pobranego pliku to: \n\t");
    // Wydrukuj zawartość pliku wyjściowego w ramach testu.
    c = fgetc(fp);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fp);
    }

    printf("[0]Do widzenia!\n");

    return 0;
}

/*
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
*/
