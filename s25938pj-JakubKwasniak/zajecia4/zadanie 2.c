#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv)
{
    char nazwaPLiku[260];//Maksymalny rozmiar sciezki do pliku - 260(max_path)
    char *pojedynczaLinia;
    FILE *uchwyt;   //można dzięki temu otworzyć plik i jest on zablokowany dla innych procesów
    struct stat abc; // Zmienna przechowujaca informacje na temat rozmiaru pliku(w bajtach)
    int *tabela; //przechowuje wartość liczbową z danej linijki
    int rozmiar; //Zmienna przechowująca liczbe lini w pliku
    int liczba; //Zmienna reprezentująca element liczby każdej linijki pliku
    int i;  //Zmienna do iteracji
  
    // Instrukcja warunkowa gdy nie wykrywamy argumentów (pliku)
    if (argc >= 1)
    {
        printf("Nie wykrylismy zadnego pliku\n Podaj prosze jego pelna nazwe");
        if (!scanf( "%s", (char *)&nazwaPLiku));
            
        {
            printf("Wystąpił błąd");
            return 0;
        }
    }
    else if (argc == 2)
    {
        //Kopiowanie między łańcuchami znaków, z argumentu do zmiennej nazwaPliku
        strcpy(nazwaPLiku, argv[1]);
    }
    // Otwieranie pliku z atrybutem r(read/odczyt pliku)
    uchwyt = fopen(nazwaPLiku, "r");
    if (uchwyt == NULL)
    {
        printf("Problem z otwarciem pliku");
        return 0;
    }
    // dynamiczna alokacja pamięci dla pojedynczej linii
    pojedynczaLinia = (char *)malloc(abc.st_size); //Alokuje pamięć do rozmiaru całego pliku wiedząc że linijka tego pliku nie wyniesie więcej niż rozmiar pliku
    // Instrukcja waunkowa która wykrywa błąd rezerwacji pamięci funkcją malloc
    if (pojedynczaLinia = NULL)
    {
        printf("Błąd rezerwacji pamięci funkcją malloc");
        return 0;
    }
    // Czytanie od 1 lini
    //Szukanie całych linijek do momentu gdy linia się zakończy (stąd na końcu EOF)
    if (fscanf(uchwyt, "%[^\n] ", pojedynczaLinia) != EOF) //EOF - End of file/Koniec Pliku
    {
        // Pojedyncza linia na liczbe
        rozmiar = atoi(pojedynczaLinia);
        // Instrukcja waunkowa która wykrywa błąd gdy nie przekonwertowało nam atoi-em
        if (rozmiar == 0)
        {
            printf("Błąd konwersji poprzez funkcje atoi");
            // Zwalnianie zalokowanej pamięci funkcją free
            free(pojedynczaLinia);
            return 0;
        }
        // dynamiczna alokacja pamięci dla tabeli
        tabela = (int *)malloc(sizeof(int) * rozmiar);
        // Instrukcja warunkowa która wykrywa błąd podczas rezerwacji pamięci
        if (tabela == NULL)
        {
            printf("Błąd rezerwacji pamięci funkcją malloc");
            // zwalnianie pamięci
            free(tabela);
            free(pojedynczaLinia);
            return 0;
        }
        // pętla czytająca linijki taką ilość razy, jaką wartość posiada zmienna rozmiar
        for (i = 0; i < rozmiar; i++)
        {
            if (fscanf(uchwyt,"%[^\n] ", pojedynczaLinia) !=EOF)
            {
                //Zamiania lini na liczbe funkcją atoi
                liczba=atoi(pojedynczaLinia);
                if(liczba==0)
                {
                    printf("Nie można przekonwertować lini na liczbe\n");
                    free(tabela);
                    free(pojedynczaLinia);
                    return 0;
                }
                *(tabela=i)=liczba;
            }
        }
        i = rozmiar -1;
        for(i=0;i>=0;i--)
        {
            printf("%d\n", *(tabela+i));
        }
        //Zwalnianie pamieci
        free(tabela);
    }
    free(pojedynczaLinia);
    //Zamykanie pliku
    if(uchwyt != NULL)
    {
        fclose(uchwyt);
    }
    return 0;
}
