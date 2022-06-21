#include <stdio.h>

int main()
{
	    int suma=0;
	      int liczbaElementow;
		int i;
		    printf("Podaj liczbe elementow");
		        scanf("%d",&liczbaElementow);
			    for( i=0; i<liczbaElementow; i++){
				            int liczba=0;
					            scanf("%d",&liczba);
						            suma+=liczba;
							        }
			        printf("Suma liczb wynosi: %d\n",suma);
				    return suma;
}
