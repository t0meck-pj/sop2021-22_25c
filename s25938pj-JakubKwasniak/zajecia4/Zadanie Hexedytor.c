#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include<string.h>

extern int errno;

int main(int argc, char* argv[])
{
    const char* nazwaPliku;
    FILE* uchwyt;
    unsigned char buffer[17];
    int iloscLinijek;
    int i;
    //Sprawdzamy argumenty
    if(argc != 2)
    {
        printf("Błąd argumentów");
        return 0;
    }
    nazwaPliku = argv[1];
    printf("Ładowanie pliku o nazwie: %s\n",nazwaPliku);
    uchwyt = fopen(nazwaPliku, "r");
    if(uchwyt==NULL)
    {
        printf("Błąd podczas otwierania pliku o nazwie: %s\n",nazwaPliku);
        return 0;
    }
    //Czytanie linijek pliku za pomocą pętli
    for(iloscLinijek=0;iloscLinijek<32;iloscLinijek++)
    {
        fread(&buffer, 16,1,uchwyt);buffer[16]=0x00; //Null na koncu
        fseek(uchwyt, 16, SEEK_CUR);
        printf("%08x ", iloscLinijek * 16);
        //Drukowanie 16 bajtow w hex
        for(i=0;i<16;i++)
        {
            printf("%02x ", buffer[i]);
            //Znaki których nie można wypisać zamieniamy na .
            if(!isprint(buffer[i]))
            {
                buffer[i] = '.';
            }
        }
        printf("%s\n",buffer);
    }
    //Zamykamy plik
    printf("Zamykanie pliku");
    fclose(uchwyt);
    return 0;
}