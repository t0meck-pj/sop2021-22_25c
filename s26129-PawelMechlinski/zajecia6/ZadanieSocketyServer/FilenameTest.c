#include<stdio.h>
#include <unistd.h>
#include <string.h>

int main () {
    char filename[] = "/tmp/server/file";
    size_t n = sizeof(filename);
    char filesize[256];
    snprintf(filesize, sizeof filesize, "%zu", n);

    printf("Filename: %s \nand it's size: %s", filename, filesize);
    // Filesize here will be 10, probably because of + \0

    FILE *fp;
    fp = fopen(filename, "r");
    fseek(fp, 0L, SEEK_END);        // Przeskocz do końca pliku
    int filesizeInt = ftell(fp);       // Uzyskaj długość pliku w bajtach
    rewind(fp);                    // Powróć do początku pliku
printf("Długość pliku wynosi: %iB", filesizeInt);
    fclose(fp);

	return 0;
}
