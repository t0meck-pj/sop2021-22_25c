#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include<string.h>

extern int errno;

void usage()
{
	printf("Usage: \n");
	printf("       ./zad_IO\n");
	printf("       ./zad_IO {filename}\n");
}

int main(int argc, char* argv[])
{
	/* Alokujemy zmienną przechowująca ścieżke do pliku */
	char filename[260];
	struct stat sb;
	FILE* handle;
	char* line;
	int size;
	int* table;
	int i;
	int number;

	/* Jeżeli nie ma argumentów pobieramy ścieżke do pliku za pomocą standardowego wejścia */
	if (argc < 2)
	{
		printf("Podaj nazwe pliku: ");
		
		if (!fscanf(stdin, "%s", (char*)&filename))
		{
			fprintf(stderr, "Wystąpił bład\n");
			
			return EXIT_FAILURE;
		}
	}

	/* Jeżeli jest podany argument (ścieżka do pliku) zapisujemy go do zmiennej */
	else if (argc == 2)
	{
		strcpy(filename, argv[1]);
	}

	/* W innym wypadku wyświetlamy jak korzystać z appki */
	else {
		usage();

		return EXIT_FAILURE;
	}

	/* Uchwyt do czytanego pliku */
	handle = fopen(filename, "r");
	if (handle == NULL) 
	{
		fprintf(stderr, "Error opening %s file: %s\n", filename, strerror(errno));
		
		return EXIT_FAILURE;
	}


	/* Pobieramy informacje o pliku, w tym przypadku sb.st_size - wielkość pliku w bajtach */
	if (stat(filename, &sb) == -1)
	{
		perror("error");

		return EXIT_FAILURE;
	}

	/* Alokujemy zmienną, która ma taki sam rozmiar co czytany plik */
	line = (char*)malloc(sb.st_size);
	if (line == NULL) 
	{
		perror("malloc failed");
		
		return EXIT_FAILURE;
	}

	/* Czytamy pierwszą linijkę */
	if (fscanf(handle, "%[^\n] ", line) != EOF)
	{
		/* Zamieniamy linijke na liczbę */
		size = atoi(line);

		/*Jeżeli liczba jest 0 - oznacza to że wysątpił błąd przy konwersji atoi */
		if (size == 0)
		{
			fprintf(stderr, "Cannot convert line to number\n");
			
			free(line);
			return EXIT_FAILURE;
		}

		/* Alokujemy dynamicznie ilość int'ów podanych w pliku (w pierwszej linijce) */
		table = (int*)malloc(sizeof(int) * size);
		if (table == NULL) 
		{
			perror("malloc failed");
			
			free(line);
			return EXIT_FAILURE;
		}

		/* Czytamy kolejne linijki określoną ilość razy */
		i = 0;
		for (; i < size; i++)
		{
			if (fscanf(handle, "%[^\n] ", line) != EOF)
			{
				/* Zamieniamy linijke na liczbę */
				number = atoi(line);
				if (number == 0)
				{
					fprintf(stderr, "Cannot convert line to number\n");
					
					free(table);
					free(line);
					return EXIT_FAILURE;
				}

				/* Zapisujemy liczbe do tablicy */

				*(table+i) = number;
			}
		}
		i = size - 1;

		/* Wyświetlamy liczby w odwrotnej kolejności */
		for (; i >= 0; i--)
		{
			printf("%d\n", *(table+i));
		}

		free(table);
	}
	
	free(line);

	/* Zamykamy plik */
	if (handle != NULL)
	{
		fclose(handle);
	}

	return EXIT_SUCCESS;
}

