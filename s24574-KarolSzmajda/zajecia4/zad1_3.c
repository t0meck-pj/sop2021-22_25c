
#include <stdlib.h>
#include <stdio.h>

void usage()
{
    printf("Usage: \n");
    printf("       ./zad1_3 {size}\n");
}

int main(int argc, char* argv[])
{
    int size;
    int y = 0;
    int x;

    if (argc != 2)
    {
        usage();

        return 1;
    }

    size = atoi(argv[1]);

    for (; y < size; y++)
    {
        x = 0;
        for (; x < size; x++)
        {
            if (2*abs((size/2)-x) <= y)
            {
                printf("*");
            }
            else {
                printf(" ");
            }
           
        }
        printf("\n");
    }

    y = 0;
    for (; y < 3; y++)
    {
        x = 0;
        for (; x < size; x++)
        {
            if (2 * abs((size / 2) - x) <= 2)
            {
                printf("|");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}

