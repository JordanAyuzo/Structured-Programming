#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int da1,da2,sum=0,posibilidades[6][6],cont[6][6],max;
void dados();
void contador();
void tab();
void pos();

int main(){
	printf("ESCRIBE EL NUMERO DE VECES QUE SE TIRARAN LOS DADOS: ");
	scanf("%d",&max);
	pos();
	dados();
	tab();
	getch();
}
void dados(){
	int i;
	for(i=1;i<=max;i++){
		da1=1+rand()%6;
		da2=1+rand()%6;
		sum=da1+da2;
		contador();	
	}
	
}
void contador(){
	int i,j;
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			if(sum==posibilidades[i][j])
			cont[i][j]++;
		}
	}
}
void pos(){
	int i,j;
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			posibilidades[i][j]=(i+1)+(j+1);
		}
	}
	
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			cont[i][j]=0;
		}
	}
}
void tab(){
	system("cls");
	printf("Fueron Tirados %d Veces Dos Dados Estos Fueron Los Resultados: \n",max);
	printf("Suma De Dados   |  Veces Que Cayeron\n");
	int i,j;
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			if(posibilidades[i][j]!=posibilidades[i+1][j-1])
			printf("%d		| %d\n",posibilidades[i][j],cont[i][j]);
		}
	}
}
