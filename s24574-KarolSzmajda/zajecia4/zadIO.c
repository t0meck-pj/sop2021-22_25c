#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void usage()
{
	printf("Usage: \n");
	printf("       ./zad_IO\n");
	printf("       ./zad_IO {filename}\n");
}

int main(int argc, char* argv[])
{
	/* Alokujemy zmienną przechowująca ścieżke do pliku */
	char* Filename = (char*)malloc(sizeof(char) * 260);
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
		if (!fscanf(stdin, "%s", Filename))
		{
			printf("Wystąpił bład\n");
		}
	}

	/* Jeżeli jest podany argument (ścieżka do pliku) zapisujemy go do zmiennej */
	else if (argc == 2)
	{
		Filename = argv[1];
	}

	/* W innym wypadku wyświetlamy jak korzystać z appki */
	else {
		usage();

		return 1;
	}

	/* Uchwyt do czytanego pliku */
	handle = fopen(Filename, "r");


	/* Pobieramy informacje o pliku, w tym przypadku sb.st_size - wielkość pliku w bajtach */
	if (stat(Filename, &sb) == -1)
	{
		perror("error");
		return EXIT_FAILURE;
	}

	/* Alokujemy zmienną, która ma taki sam rozmiar co czytany plik */
	line = (char*)malloc(sb.st_size);

	/* Czytamy pierwszą linijkę */
	if (fscanf(handle, "%[^\n] ", line) != EOF)
	{
		/* Zamieniamy linijke na liczbę */
		size = atoi(line);

		/*Jeżeli liczba jest 0 - oznacza to że wysątpił błąd przy konwersji atoi */
		if (size == 0)
		{
			printf("Cannot convert line to number\n");
			return EXIT_FAILURE;
		}

		/* Alokujemy dynamicznie ilość int'ów podanych w pliku (w pierwszej linijce) */
		table = (int*)malloc(sizeof(int)* size);
		

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
					printf("Cannot convert line to number\n");
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

		if (table != NULL)
		{
			free(table);
		}
	}

	/* Zamykamy plik */
	if (handle != NULL)
	{
		fclose(handle);
	}

	return EXIT_SUCCESS;
}

