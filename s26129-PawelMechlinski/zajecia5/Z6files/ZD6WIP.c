#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include <time.h>

///* Zajęcia 4: Zadanie 6
/*
Napisz prosty program chat-u, który będzie korzystał z pliku w katalogu /tmp do przekazywania wiadomości. Zastanów się jak to zrobić.

Moja propozycja na taką dość prostą wersję rozwiązania:
Plik w /tmp można by potraktować jako element implementacji systemu kolejkowego/bazę danych. Wiadomość ma jeden wiersz i następujący format:

nadawca odbiorca timestamp 'treść'

Program ma następujące funkcje:
1. Zarejestruj się: należy podać login i hasło.
2. Zaloguj się: należy podać login i hasło zgodne z istniejącym w bazie.
    Dla zalogowanych:
    3. Sprawdź skrzynkę.
    4. Wyślij wiadomość.
5. Zakończ sesję.

*/
///Ten program powstał jako moje pierwsze podejście do implementacji, niestety poległem na jego odrobaczeniu. Jest też napisany bez używania fork, zostawiam jako ciekawostkę (?).

///

void menu();
void newuser();
void registry();
void login();
int check_login_in_db();
int check_password();
int checkUsername();
void getUsername();
void getAllUsers();
void showChatHistory();
void post();
void userlogin();


int main()
{

    // Zmienne session-wide:
    char session_login[128];
    char session_password[128];
    char nickname[128];

    while(1 == 1)
    {
        menu();
    }

    return 0;

}

   void menu() // Funkcja menu głównego. Nic nadzwyczajnego, powinna działać.
    {
        int proper = 0, option = 0;

        while(proper == 0)
        {
            printf("\n=======\nWitaj w konsolowym kliencie czatu PJATKCZAT!\nCo chcesz zrobić?\n(1)Zarejestrować się do systemu.\n(2)Zalogować się.\n(3)Wyjść.\n");
            scanf("%i", &option);
            if (option < 1 || option > 3) printf("Wybrano niepoprawną opcję :( spróbuj ponownie!\n");
            else proper = 1;
        }

        switch(option)
        {
            case 1:
                registry();
                break;
            case 2:
                login();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Coś poszło nie tak!");
                return;
            }
        }


    void newuser(char nickname[128], char login[128], char password[128]) // Funkcja dopisująca nowego usera do bazy. Sprawdzona, działa.
    {

        FILE *fp = fopen("/tmp/users", "a");

        fprintf(fp, "%s %s %s\n", nickname, login, password);

        fclose(fp);
        return;
    }

    void registry() // Powinna działać, funkcja sprowadza się do pobierania danych od użytkownika i przepisywania ich do pliku.
    {
        char nickname[128];
        char session_login[128];
        char session_password[128];

        printf("Aby zarejestrować się, podaj najpierw swój nick:\n");
        scanf("%s", &nickname); // TODO: Sprawdzanie, czy login nie pokrywa się z już istniejącym.
        printf("Następnie podaj swój login:\n");
        scanf("%s", &session_login); // TODO: Sprawdzanie, czy login nie pokrywa się z już istniejącym.
        printf("\nJeszcze tylko podaj hasło:\n");
        scanf("%s", &session_password);
        printf("Konto utworzone poprawnie, możesz się zalogować!\n");
        newuser(nickname, session_login, session_password);
        return;
    }

    void login(char *session_login[128], char *session_password[128])  // Działa, ale logika do odchwaszczenia... np. wystarczy mniej warunków, zmienne session* możliwe, że są bezzasadne?
    {
        int creds_valid = 0;
        char try_login[128];
        char try_password[128];
        int tries = 0;
        int passcheck;

        while (creds_valid == 0 && tries < 3 && passcheck != 0)
        {
        printf("Podaj swój login: ");
        scanf("%s", &try_login);
        printf("Wybrałeś login: %s\n", try_login);
        int check = 0;
        check = check_login_in_db(try_login);
        if (check != 0)
        { /*
        char check;
        printf("Ups! Nie mamy takiego loginu w bazie! Czy chcesz go wpisać jeszcze raz [y/n]?\n");
        scanf("%c", &check);
        printf("\nWybrałeś: %c", check);
        switch (check)
        {
            case 'y':
                continue;
            case 'n':
                exit(0);
            default: */
        printf("Nie zrozumiałem. Może spróbuj wpisać ponownie?");
        tries++;
        continue;
        }

        *session_login = try_login;
        printf("\nLogin wydaje się w porządku.");


        for (int i = 3; i > 0; i--)
        {
            printf(" Wpisz proszę swoje hasło: ");
            scanf("%s", &try_password);

            passcheck = check_password(try_login, try_password);

            // printf("\nWybrałeś hasło: %s, passcheck: %i", try_password, passcheck);

            if (passcheck == 0)
            {
            //*session_password = try_password;
            printf("\nHasło jest poprawne.\n");
            break;
            }

            if (passcheck != 0) continue;
        }
        }

        if (passcheck == 0)
        {
            printf("Witaj, ");
            getUsername(try_login);
            printf(" jesteś zalogowany");
            userlogin(try_login, try_password);
        }

        return;
    }




    /*
    Dane w users mają następujący format:
    nickaname login password
    */
    int check_login_in_db (char try_login[128]) // Wygląda na to, że jest ok. Do zapamiętania: strcmp daje wynik '0' dla równych stringów.
    {
        printf("Sprawdzam login '%s' w bazie...", try_login);
        FILE *fp = fopen("/tmp/users", "r");
        if (fp == NULL) { printf("Błąd! Brak bazy użytkowników."); exit(0); };

        int result = 0;
        char buf[128];

        while (fscanf(fp, "%*s %s %*s ", buf) == 1)
        {
            result = strcmp(try_login, buf);
            if (result == 0)
            {
                printf("\n(Login ok)");
                fclose(fp);
                return result;
            }
        }
        fclose(fp);
        return result;
    }

    int check_password(char session_login[128], char try_password[128]) // Ważna uwaga, fscanf zwraca integera równego ILOŚCI POBRANYCH ZMIENNYCH, a nie 1 zawsze, gdy nie EOF. Teraz już działa.
    {
        FILE *fp = fopen("/tmp/users", "r");
        if (fp == NULL) { printf("Błąd! Brak bazy użytkowników."); exit(0); };

        int result = 0;
        char bufLog[128];
        char bufPass[128];

        while (fscanf(fp, "%*s %s %s ", bufLog, bufPass) == 2)
        {
        //printf("\nbufLog: %s, bufPass: %s", bufLog, bufPass);
            if (strcmp(session_login, bufLog) == 0)
            {
                if (strcmp(try_password, bufPass) == 0)
                {
                    printf("\n(Hasło ok)");
                    fclose(fp);
                    return 0;
                }
            }
        }

        fclose(fp);
        printf("\nHasło i login nie pasują do siebie.");
        return 1;
    }

    int checkUsername(char tryString[128])
    {
        FILE *fp = fopen("/tmp/users", "r");
        if (fp == NULL) { printf("Błąd! Brak bazy użytkowników."); exit(0); };

        char buf[128];

        while (fscanf(fp, "%*s %s %s ", buf) == 2)
        {
            if (strcmp(tryString, buf) == 0){
            fclose(fp);
            return 1;
            }
        }

        fclose(fp);
        return 0;
    }

    void getUsername(char session_login[128]) // Działa, choć lepiej by było gdyby zwracała string, a nie printowało.
    {
        FILE *fp = fopen("/tmp/users", "r");
        if (fp == NULL) { printf("Błąd! Brak bazy użytkowników."); exit(0); };

        char buf[128];
        static char nick[128];

        while (fscanf(fp, "%s %s %*s ", nick, buf) == 2)
        {
        //printf("\n%s vs. %s = %i", session_login, buf, strcmp(session_login, buf));

            if (strcmp(session_login, buf) == 0){
            printf("%s", nick);
            fclose(fp);
            return;
            }
        }

        fclose(fp);
        printf("\nCoś poszło nie tak, nie mogę znaleźć nicka!");
        return;
    }

    void getAllUsers(char current[128])  // Funkcja pokazująca "książeczkę adresową"
    {
        FILE *fp = fopen("/tmp/users", "r");
        if (fp == NULL) { printf("Błąd! Brak bazy użytkowników."); exit(0); };

        char buf[128];
        char meCheck[128];

        while (fscanf(fp, "%s %s %*s ", buf, meCheck) == 2)
        {
            printf("\n%s", buf);
            if(strcmp(meCheck, current) == 0) { printf(" [Ty]"); continue;}
        }
        fclose(fp);
        printf("\n==========");
        return;
    }

    void showChatHistory (char secondUser[128])
    {
    FILE *fp = fopen("/tmp/tmp", "r");
    if (fp == NULL) { printf("Błąd! Brak bazy wiadomości."); exit(0); };
    // nadawca odbiorca timestamp 'treść'

    char nadawca[128];
    char odbiorca[128];
    char timestamp[128];
    char tresc[256];

    while (fscanf(fp, "%s %s %s %s ", nadawca, odbiorca, timestamp, tresc) == 1)
    {
        if (strcmp(nadawca, secondUser) == 1 || strcmp(odbiorca, secondUser) == 1)
        {
        printf("FROM: %s\n[ %s ] %s\n", nadawca, timestamp, tresc);
        }
    }
    fclose(fp);
    return;

    }

    void post(const char nadawca[128], char adresat[128], char wiadomosc[256])
    {
            // Zmienne czasu:
        time_t rawtime;
        struct tm * timeinfo;


        FILE *fp = fopen("/tmp/tmp", "a");
        if (fp == NULL) { printf("Błąd! Brak bazy wiadomości."); exit(0); };

    // nadawca odbiorca timestamp 'treść'

        printf("%s %s %s %s", nadawca, adresat, asctime (timeinfo), wiadomosc);

        fclose(fp);
        return;
    }


    void userlogin(char username[128], char password[128]) // Funkcja kontrolna dla zalogowanego użytkownika
    {
        printf("\nAktualni użytkownicy czatu to:\n");
        getAllUsers(username);

        char contact[128];

        // Pętla wyboru osoby do czatowania:
        int valid = 1;
        while (valid != 0)
        {
            printf("\nNapisz EXIT jeśli chcesz wyjść lub napisz nick użytkownika, z którym czat chcesz otworzyć:\n");
            //printf("TEST"); getchar();
            scanf("%127s", &contact);
            if (strcmp(contact, "EXIT") == 0) exit(0);
            printf("Szukam użytkownika o nicku: %s", contact);



            valid = checkUsername(contact);
            if (valid != 0)
            {
            printf("Nie znalazłem użytkownika o takim nicku!");
            continue;
            }
            else valid = 0;
        }

        printf("Wybrano użytkownika: %s", contact);
        showChatHistory(contact);
        while (1 == 1)
        {
        printf("\n***\n");
        char tresc[128];
        scanf("%s", &tresc);
        if (strcmp(tresc, "EXIT")) exit(0);
        post(username, contact, tresc);
        }

    }

