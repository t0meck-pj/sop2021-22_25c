#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

 

int main(int argc, char* argv[])
{
    int i=0;
    int liczba;
    double suma;
    
    if(argc !=2)/*Jeżeli nie podałeś drugiego argumentu*/
    {
        printf("Bład argumentów\n");
        return 1;
    }
    /*Konwersja string do integer*/
    liczba = atoi(argv[1]);
    if(liczba <= 0)
    {
        printf("Bład\nLiczba musi byc wieksza od 0\n");
        return 1;
    }
    /*Jeżeli fork jest większy od 0 to jest to proces rodzica, a jeżeli jest równy 0 jest to proces dziecka*/
    if(fork() > 0)/*Następuje utworzenie drugiego procesu*/
    {
        wait(NULL);/*Czekamy aż dzieci się zakończą*/
        for(i=0; i<=liczba; i++)
        {
            suma+=i;
        }
        printf("Suma wynosi: %f\n",suma);
    }
    else
    {
        printf("Suma wynosi: ");
        for(i=1;i<=liczba;i++)
        {
            if(i%2 == 1)
            {
                printf("%d ",i);
            }
        }
        printf("\n");
    }
    return 0;
}
