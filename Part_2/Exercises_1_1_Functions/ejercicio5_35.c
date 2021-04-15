#include <stdio.h>
void aleatorio();
void mode();
int n1,n2;
int main(){
	aleatorio();
	printf("Escoge un numero del 1 al 1000 : ");
	do{
		scanf("%d",&n2);
		mode();	
	}while(n1!=n2);
}
void aleatorio(){
	srand(time(NULL));
	n1=1+rand()%1000;
}
void mode(){
	if (n2>n1)
		printf(" Alto :(\n ");
	if (n2<n1)
		printf(" Bajo :( \n");
	if (n2==n1)
		printf("Perfecto :) \n");

}	



	
