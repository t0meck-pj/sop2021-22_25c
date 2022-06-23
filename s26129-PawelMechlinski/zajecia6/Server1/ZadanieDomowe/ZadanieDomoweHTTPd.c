///* Zajęcia 6: Zadanie Domowe - Serwer HTTP
/*
1. Rozwiń/napisz serwer HTTP tak, aby nadawał się do udostępniania strony WWW. [ v ]
Serwer powinien obsługiwać:
- lista zabronionych adresów. [ v ]
- zapis logów zdarzeń. [ v ]

dodatkowo:
- niech serwer pozwala na tworzenie wirtualnych hostów. [ V Implementacja co prawda łopatologiczna, bardziej pewnie by tu pasowało zrobić sprawę obiektowo, ale dwie strony wyświetlane są na :8080 i :8081 ]
- niech nie blokuje się w sytuacji kiedy klient przeciąga połączenie (aby nie blokować innych połączeń); zastosuj fork(). [ V Po odebraniu sygnału forkuje się, żeby obsłużyć socket wyjściowy ]


Moja notatka:
- V. hosting jest typu port-based:
    Strona A: 8080
    Strona B: 8081

Rozwiązanie wzorowałem na:
https://stackoverflow.com/questions/41188684/c-http-web-server-accessed-through-web-browsers
a także posłużyłem się własnym kodem z poprzedniego zadania z serwerem (np. do obsługi timestamps czy logowania).

*/
///

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

char webpage[] =  //                        Najprostsza implementacja z możliwych (chyba),
        "HTTP/1.1 200 OK\r\n" //            czyli HTTP header i html bezpośrednio w char array.
        "Content-length: 194\r\n" //        Można by zaimplementować do tego odbsługę zapytań i
        "Content-Type: text/html\r\n" //    pobieranie/przesyłanie zawartości stron przez Stream.
        "Connection: close\r\n\r\n"
        "<!DOCTYPE html>\r\n"
        "<title>Hello!</title>"
        "</head>"
        "<body>"
        "<h1>Hello World!</h1>"
        "<p>This is a simple paragraph.</p>"
        "</body>";

char webpage2[] =  //                        Najprostsza implementacja z możliwych (chyba),
        "HTTP/1.1 200 OK\r\n" //            czyli HTTP header i html bezpośrednio w char array.
        "Content-length: 194\r\n" //        Można by zaimplementować do tego odbsługę zapytań i
        "Content-Type: text/html\r\n" //    pobieranie/przesyłanie zawartości stron przez Stream.
        "Connection: close\r\n\r\n"
        "<!DOCTYPE html>\r\n"
        "<title>UWAGA!</title>"
        "</head>"
        "<body>"
        "<h1>To jest inna strona testowa!</h1>"
        "<p>Jeśli ją widzisz, to znaczy, że NIE połączyłeś się przez port 8080.</p>"
        "</body>";

int blacklistPorts[] = { 666, 1, 13, 148, 404 };
size_t blacklistPortsSize = sizeof(blacklistPorts)/sizeof(blacklistPorts[0]);

int blacklistIPs[] = { 127001, 127002, 127005, 19216801, 2552552550 };
size_t blacklistIPsSize = sizeof(blacklistIPs)/sizeof(blacklistIPs[0]);

int main(int argc, char *argv[])
{
/// Obsługa timestamps
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

/// Dla logów
    FILE *fp;
    FILE *fp2;

/// Init SockA
    struct sockaddr_in server_addr, client_addr;
    socklen_t sin_len = sizeof(client_addr);
    int fd_server, fd_client;
    char buf[2048];
    int fdimg;
    int on = 1;
    int block = 0;

/// Init SockB
    struct sockaddr_in server_addr2, client_addr2;
    socklen_t sin_len2 = sizeof(client_addr2);
    int fd_server2, fd_client2;
    char buf2[2048];
    int fdimg2;
    int on2 = 1;
    int block2 = 0;

/// Fork
    int pid;
    pid = fork();

///A)
    // Set

    if (pid == 0)
    {
        fd_server = socket(AF_INET, SOCK_STREAM, 0);
        if (fd_server < 0)
        {
            perror("socketA");
            exit(1);
        }

        setsockopt(fd_server, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(int));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr =  INADDR_ANY;
        server_addr.sin_port = htons(8080);

        if (bind(fd_server, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1)
        {
            perror("bind");
            close(fd_server);
            exit(1);
        }

        if (listen(fd_server, 10) == -1)
        {
            perror("listen");
            close(fd_server);
            exit(1);
        }

        // Loop

        while(1)
        {
            // Connect

            fd_client = accept(fd_server, (struct sockaddr *) &client_addr, &sin_len);

            if (fd_client == -1)
            {
                perror("Connection failed......\n");
                continue;
            }

            if (fd_client > 0)
            {
                printf("===============\nGot new client connection!\nIP: %i\nPort: %i \n===============\n", client_addr.sin_addr.s_addr, client_addr.sin_port);


            // Testy przeciwblacklistowe:

                // Porty
                for (int i = 0; i < blacklistPortsSize; i++)
                {
                    if (blacklistPorts[i] == client_addr.sin_port )
                    {
                        printf("Uwaga, ten port objęty jest firewallem. Połączenie zostanie przerwane, a ten incydent zanotowany!");
                        fp = fopen("logfile.log", "a");
                        if (fp == NULL)
                        {
                            perror("Wystąpił problem przy próbie otwarcia logfile!\n");
                            return -1;
                        }

                        fprintf(fp, "%s Ktoś próbował się nielegalnie połączyć przez port:  %i\n", asctime(timeinfo), client_addr.sin_port);
                        fclose(fp);
                        block = 1;
                    }
                }

                // IP
                for (int i = 0; i < blacklistIPsSize; i++)
                {
                    if (blacklistIPs[i] == client_addr.sin_addr.s_addr)
                    {
                        printf("Uwaga, ten IP znajduje się na czarnej liście! Połączenie zostanie przerwane, a ten incydent zanotowany!");
                        fp = fopen("logfile.log", "a");
                        if (fp == NULL)
                        {
                            perror("Wystąpił problem przy próbie otwarcia logfile!\n");
                            return -1;
                        }

                        fprintf(fp, "%s Ktoś próbował się nielegalnie połączyć z adresu: %i\n", asctime(timeinfo), client_addr.sin_addr.s_addr);
                        fclose(fp);
                        block = 1;
                    }
                }

                // Recv fork
                if (!fork() && block != 1)
                {
                    close(fd_server);
                    memset(buf, 0, 2048);
                    read(fd_client, buf, 2047);
                    printf("%s\n",buf);

                    // Write to logs
                    fp = fopen("logfile.log", "a");

                    if (fp == NULL)
                    {
                        perror("Wystąpił problem przy próbie otwarcia logfile!\n");
                        return -1;
                    }

                    fprintf(fp, "%s %s\n", asctime(timeinfo), buf);
                    fclose(fp);

                    // Send to client
                    write(fd_client, webpage, sizeof(webpage) - 1);
                    close(fd_client);
                    printf("closing....\n");
                    exit(0);
                }

                block = 0;
                close(fd_client);
            }
        }
    }

///B)
    // Set

    if (pid > 0)
    {
        fd_server2 = socket(AF_INET, SOCK_STREAM, 0);
        if (fd_server2 < 0)
        {
            perror("socketB");
            exit(1);
        }

        setsockopt(fd_server2, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(int));
        server_addr2.sin_family = AF_INET;
        server_addr2.sin_addr.s_addr =  INADDR_ANY;
        server_addr2.sin_port = htons(8081);

        if (bind(fd_server2, (struct sockaddr *) &server_addr2, sizeof(server_addr2)) == -1)
        {
            perror("bind2");
            close(fd_server2);
            exit(1);
        }

        if (listen(fd_server2, 10) == -1)
        {
            perror("listen2");
            close(fd_server2);
            exit(1);
        }

        // Loop

        while(1)
        {
            // Connect

            fd_client2 = accept(fd_server2, (struct sockaddr *) &client_addr2, &sin_len2);

            if (fd_client2 == -1)
            {
                perror("Connection failed......\n");
                continue;
            }

            if (fd_client2 > 0)
            {
                printf("===============\nGot new client connection!\nIP: %i\nPort: %i \n===============\n", client_addr2.sin_addr.s_addr, client_addr2.sin_port);


            // Testy przeciwblacklistowe:

                // Porty
                for (int i = 0; i < blacklistPortsSize; i++)
                {
                    if (blacklistPorts[i] == client_addr2.sin_port )
                    {
                        printf("Uwaga, ten port objęty jest firewallem. Połączenie zostanie przerwane, a ten incydent zanotowany!");
                        fp2 = fopen("logfile.log", "a");
                        if (fp2 == NULL)
                        {
                            perror("Wystąpił problem przy próbie otwarcia logfile!\n");
                            return -1;
                        }

                        fprintf(fp2, "%s Ktoś próbował się nielegalnie połączyć przez port:  %i\n", asctime(timeinfo), client_addr2.sin_port);
                        fclose(fp2);
                        block2 = 1;
                    }
                }

                // IP
                for (int i = 0; i < blacklistIPsSize; i++)
                {
                    if (blacklistIPs[i] == client_addr2.sin_addr.s_addr)
                    {
                        printf("Uwaga, ten IP znajduje się na czarnej liście! Połączenie zostanie przerwane, a ten incydent zanotowany!");
                        fp2 = fopen("logfile.log", "a");
                        if (fp2 == NULL)
                        {
                            perror("Wystąpił problem przy próbie otwarcia logfile!\n");
                            return -1;
                        }

                        fprintf(fp2, "%s Ktoś próbował się nielegalnie połączyć z adresu: %i\n", asctime(timeinfo), client_addr2.sin_addr.s_addr);
                        fclose(fp2);
                        block2 = 1;
                    }
                }

                // Recv fork
                if (!fork() && block2 != 1)
                {
                    close(fd_server2);
                    memset(buf2, 0, 2048);
                    read(fd_client2, buf2, 2047);
                    printf("%s\n",buf2);

                    // Write to logs
                    fp2 = fopen("logfile.log", "a");

                    if (fp2 == NULL)
                    {
                        perror("Wystąpił problem przy próbie otwarcia logfile!\n");
                        return -1;
                    }

                    fprintf(fp2, "%s %s\n", asctime(timeinfo), buf2);
                    fclose(fp2);

                    // Send to client
                    write(fd_client2, webpage2, sizeof(webpage2) - 1);
                    close(fd_client2);
                    printf("closing....\n");
                    exit(0);
                }

                block = 0;
                close(fd_client2);
            }
        }
    }

    return 0;
}
