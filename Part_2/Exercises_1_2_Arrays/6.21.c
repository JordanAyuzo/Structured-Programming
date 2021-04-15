#include<stdio.h>
#define FILAS 5
#define COLUMNAS 2
int opt,asiento[FILAS][COLUMNAS],f=0,g=0;
void opcion();
void si();
void no();
void esquema();
int main(){
	do{
	
		do{
			printf("\tBIENVENIDO A AEROLINEAS UTM\n");
			printf("Porfavor Elija Una Opcion: \n");
			printf("1) Para Fumar \n");
			printf("2) Para No Fumar\n");
			scanf("%d",&opt);
		}while(opt!=1&&opt!=2);
	opcion();
	getch();
	system("cls");
	}while(opt!=-1);
}
void opcion(){
	switch(opt){
		case 1:
			si();
			break;
		case 2:
			no();
			break;
		default:
			printf("Usted Eligio una Opcion No Valida\n");
			getch();
	}
}
void si(){
	system("cls");
	if(f<5){
		printf("El numero de asiento que Tienes es %d\n",f+1);
		f++;
		esquema();
	}
	else{
		printf("Ya no Hay mas Lugares.Desea un lugar en el area de No Fumar: \n");
		printf("1)si          2)No\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				no();
				break;
			case 2:
				break;
			Default:
				printf("No ha Elegido una opcion Volverá al menu y podra elegir su tipo de vuelo \n");
				getch();
				break;
		}
	}
}
void no(){
	system("cls");
	if(g<5){
		printf("El numero de asiento que Tienes es %d\n",g+6);
		g++;
		esquema();
	}
	else{
		printf("Ya no Hay mas Lugares.Desea un lugar en el area de No Fumar: \n");
		printf("1)si          2)No\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				si();
				break;
			case 2:
				break;
			Default:
				printf("No ha Elegido una opcion Volverá al menu y podra elegir su tipo de vuelo \n");
				getch();
				break;
		}
	}
}
void esquema(){
	printf("\n_______________________________________________________\n");
	int i;
	for(i=0;i<FILAS;i++){
		asiento[i][0]=i+1;
	}
	for(i=0;i<FILAS;i++){
		asiento[i][1]=i+6;
	}
	
	for(i=0;i<FILAS;i++){
		printf("%d	|",asiento[i][0]);
	}
	printf("AREA DE FUMADORES");
	printf("\n___________________________________\n");
	for(i=0;i<FILAS;i++){
		printf("%d	|",asiento[i][1]);
	}
	printf("AREA DE NO FUMADORES");
	printf("\n___________________________________   _____________________\n");
	printf("                            ENTRADA///ENTRADA\n");
}
