#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i =0,h=0, j,k,cont=0,cont2=0;
void reparto(int[][13],int cartas1[5],int palo[5], int *escalera_real);
void mostrar( int wDeck[][13], char*wFace[],char *wSuit[], int *escalera_real);
main()
{
	srand(time(NULL));
    int cartas[5],palo[5];
    char *suit[4] = {"Corazones", "Diamantes", "treboles", "picas"};
    char *face[13] = {"As", "dos", "Tres", "Cuatro", "cinco", "Seis", "Siete", "ocho", "Nueve", "Diez", "Jack", "Queen", "King"};
    int deck[4][13] = {0};
    int escalera_real=0;


    reparto(deck,cartas, palo, &escalera_real);
    mostrar(deck, face, suit, &escalera_real);

    return 0;
}


void reparto(int wDeck[][13], int cartas1[5],int palo[5], int *escalera_real)
{
    int card, row, column;

    for (card = 1; card <= 5; card++)
    {
    	row =rand() % 4;
        column =rand() % 13;
        while (wDeck[row][column] != 0)
        {
            row =rand() % 4;
            column = rand() % 13;

        }
        palo[h]=row;
        h++;
        cartas1[i]=column;
        i++;
        wDeck[row][column] = card;
    }
	for ( j=0; j <= 4; j++) {
			if(palo[0]==palo[j])
				cont2++;
	}
    for ( j=0; j <= 4; j++) {
      for (k = 0; k <= 4; k++) {
      	if (j != k){
          if(cartas1[j]==cartas1[k])
            cont++;
    	    }
      }
    }
    cont/=2;
    for(j=0;j<=4;j++){
    	if(wDeck[j][0]!=0 && wDeck[j][10]!=0 && wDeck[j][11]!=0 && wDeck[j][12]!=0 && wDeck[j][13]!=0)
    		*escalera_real=1;
	}
	
}

void mostrar( int wDeck[][13], char *wFace[], char *wSuit[],int *escalera_real)
{
    int card, row, column;

    for (card = 1; card <= 5; card++)
    {
        for (row = 0; row <= 3; row++)
        {
            for (column = 0; column <= 12; column++)
            {
                if (wDeck[row][column] == card)
                {
                    printf("%5s de %s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
                }
            }
        }
    }
    printf("\n++++++++++++++++++++++++++++++++++\n");
    if (cont==0)
     printf("\nNo hay Pares\n");
    else{
    	if(cont>1){
			if(cont==2)
				printf("\nTienes %d pares \n",cont);
			else{
				if(cont==3)
      				printf("\nTienes %d cartas iguales \n",cont);
      			else{
      				if((cont/2)<5)
      					printf("\nTienes %d cartas iguales \n",cont);
      			}
			  }
      	}
		  else
      		printf("\nTienes %d Par \n",cont);

	}
  if(cont2==5)
	 printf("La Mano Es De Color\n");
  if(*escalera_real==1)
  	printf("Una Escalera real\n");
}
