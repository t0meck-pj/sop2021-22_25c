#include<stdio.h>
#include<stdlib.h>

/* IO.1.2
    Napisz program, który będzie pozwalał na wyświetlenie dowolnego pliku w postaci takiej, jak w heksedytorach.

    Program powinien wypisać zawartość pliku w postaci liczb szesnastkowych będących wartościami kolejnych bajtów tego pliku.

    Warto zrobić tak, aby kolejne wartości były pogrupowane po 16, 8 albo po 4 w celu poprawy czytelności.

    Pamiętaj!

       > Nie wszystkie bajty da się wydrukować

       > Niektóre są znakami specjalnymi

        UX:
        Wywołanie:
        ./hexviewer inputData

        Header:
        Loading file: inputData

        Wzór kolumny body:

        adres_w_pliku  kolejne_N_bajtów_w_formie_hexadecymalnej  konkretne_bajty_wydrukowane_jako_tekst

        Stopka:
        Closing file: inputData
*/
void heks(char buf[], int i)
{
    if (*buf == '\0')
    return;

    heks(buf + 2, i + 1);
    buf[1] = strtol(buf, NULL, 16);
    *buf = '\0';
}

int main (int argc, char *argv[]) {
    char *filename;
    FILE *fptr = NULL;
    filename = (char *) malloc(15);
    char tmp[15];

    if( argc == 2 )
    {
        printf("Nazwa pliku podana w argumencie to: %s\n", argv[1]);
        fptr = fopen(argv[1], "rb");
        printf("Poprawnie otworzono plik %s\n", argv[1]);
    }
    else if( argc > 2 ) {
    printf("Za dużo argumentów.\n");
    return 2;
    }
    else {
        printf("Podaj nazwę pliku, który chcesz przekształcić na heksy.\nUwaga! Żeby program działał poprawnie plik musi znajdować	się w tym samym katalogu, co ten program.\n");
        scanf("%s", &tmp);
        strcpy(filename, tmp);
        filename[sizeof(filename - 1)] = '\0';
        for (size_t i = 0; i < sizeof(filename); i++) if (filename[i] == '\0') break;
        fptr = fopen(filename, "rb");
        printf("> Poprawnie otworzono plik o nazwie: %s\n", filename);
    }

    // Część powyżej wygląda na poprawną...

    // Odczytywanie pliku:
    char *buffer;
    long filelen;

    fseek(fptr, 0, SEEK_END);          // Przeskocz do końca pliku
    filelen = ftell(fptr);             // Uzyskaj długość pliku w bajtach
    rewind(fptr);                      // Powróć do początku pliku

    buffer = (char *)malloc(filelen * sizeof(char)); // Zaalokuj wystarczającą ilość pamięci dla pliku
    fread(buffer, filelen, 1, fptr); // Odczytaj cały plik
    fclose(fptr); // Zamknij plik - wszystkie interesujące nas dane mamy już w buffer.

// printf("%s", buffer); // --> Działa, wyświetla cały tekst.

    // Rysowanie kolumn danych w formacie:
    // adres_w_pliku  kolejne_N_bajtów_w_formie_hexadecymalnej  konkretne_bajty_wydrukowane_jako_tekst
//    printf("%i", filelen);

    int adres = 0, byte_counter = 0;
        if (filelen >= 16)
        {
            adres = 16;
            do
            {
                int tmp_byte_counter = 0;
                printf("%05x | ", adres);

                while(byte_counter < adres)
                {
                    printf("%x ", buffer[byte_counter]);
                    byte_counter++;
                    tmp_byte_counter = byte_counter;
                }
                printf("| ");
                byte_counter = adres - 16;

                while(byte_counter < adres)
                {
                    printf("%c", buffer[byte_counter]);
                    byte_counter++;
                }

                byte_counter = tmp_byte_counter;
                printf("\n");
                adres += 16;
            } while (adres <= filelen);
        } else printf("%x  ||  %s", buffer, buffer);

        // Dodatkowy warunek na wydrukowanie niepełnej szesnastki na końcu, jeśli występuje.
        if (adres > filelen && byte_counter < filelen)
        {
            int tmp_byte_counter = byte_counter;
            printf("%05x | ", filelen);
            while(byte_counter <= filelen)
            {
                printf("%x ", buffer[byte_counter]);
                byte_counter++;
                //printf("BYTECOUNT: %i, FILELEN: %i", byte_counter, filelen);
            };
            printf("|");
            while(tmp_byte_counter <= filelen)
            {
                printf("%c", buffer[tmp_byte_counter]);
                tmp_byte_counter++;
            }
        };

  /*  char adres[256];
    char buf;
    int i;

    while (fscanf(fptr, "%c", buf) == 1)
    {
    printf("%co", &buf);
    }
    if (feof(fptr))
    {
    printf("KONIECPLIKU!\n");
    }
    else
    {
    return -1;
    } */

 // Koniec
	printf("> Plik %s zamknięty.\n", filename);
	free(filename);
	free(buffer);
	printf("> Zaalokowana pamięć po nazwie pliku zwolniona. Do widzenia!\n");
	return 0;

}
