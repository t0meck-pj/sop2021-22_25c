#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include<string.h>

extern int errno;

int main(int argc, char* argv[])
{
	const char* filename; /* Deklarujemy zmienną okreslającą ścieżke do pliku */
	FILE* handle; /* Uchwyt do czytanego pliku */
	unsigned char buffer[17]; /* Bufor 16 bajtów z pliku, unsigned char można rozumieć jako typ byte */ /* 16 znaków + 1 na null'a */
	int o = 0; /* iterator dla pętli */
	int i = 0; /* iterator dla pętli */
	
	
	/* Spradzamy poprawność argumentów */
	if(argc != 2)
	{
		printf("Usage: \n");
		printf("	./hex filename\n\n");

		/* Zwracamy błąd na stderr */
		return EXIT_FAILURE;
	}

	filename = argv[1];

	printf("Loading file: %s\n", filename);

	handle = fopen(filename, "r");
	if (handle == NULL) 
	{
		fprintf(stderr, "Error opening %s file: %s\n", filename, strerror(errno));
		
		return EXIT_FAILURE;
	}
	
	/* Czytamy 32 linijki po 16 bajtów z pliku */
	for(; o < 32; o++)
	{
		/* Czytamy 16 bajtów z pliku do bufora */
		fread(&buffer, 16, 1, handle); buffer[16] = 0x00; /* Znak null na końcu string'a */

		/* Przechodzimy o 16 bajtów dalej względem aktualnej pozycji kurosora */
		fseek(handle, 16, SEEK_CUR);
		
		/* Drukujemy adres w pliku w formie hex */
		printf("%08x ", o * 16);
		
		/* Drukujemy 16 bajtów w formie hex */
		for(i = 0; i < 16; i++)
		{
			printf("%02x ", buffer[i]);

			/* Znaki nie drukowalne zamieniamy na kropkę */
			if (!isprint(buffer[i]))
			{
				buffer[i] = '.';
			}
		}
		/* Drukujemy konkretne bajty jako tekst */
		printf("%s\n", buffer);
	}

	/* Zamykamy plik, zwalniająć tym samym dostęp do pliku innym procesom */
	printf("Closing file: %s\n", filename);
	fclose(handle);

	/* Zwracamy kod 0, Success */
	return EXIT_SUCCESS;
}
