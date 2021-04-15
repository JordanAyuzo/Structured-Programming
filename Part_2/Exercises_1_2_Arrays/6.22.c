#include<stdio.h>
#define MAX 4
#define MAX_DIAS 5
int vendedor[4],producto[4][5],precio[4][5],tot[4]={0,0,0,0},opt;
void ingresar();
void mostrar();
int main(){
	do{	
		system("cls");
		printf("Bienvenido. Por Favor ingrese Su Informacion\n");
		printf("1)INGRESAR DATOS\n");
		printf("2)Mostrar Datos Del Mes Anterior\n");
		printf("3)Salir\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				ingresar();
				break;
			case 2:
				mostrar();
				break;
			case 3:
				break;
			default:
				break;
				
		}
	}while(opt!=3);	
}
void ingresar(){
	system("cls");
	int i,j;
	for(i=0;i<MAX;i++){
		vendedor[i]=i+1;
		printf("Vendedor: %d\n",vendedor[i]);
		for(j=0;j<MAX_DIAS;j++){
			printf(">>Numero de Producto: ");
			scanf("%d",&producto[i][j]);
			printf(">>Precio de Producto: ");
			scanf("%d",&precio[i][j]);
			tot[i]+=precio[i][j];
		}
	}
}
void mostrar(){
	system("cls");
	int i,j;
	for(i=0;i<MAX;i++){
		printf("\nVendedor: %d\n",vendedor[i]);
		printf("Producto |");
		printf("Precio\n");
		for(j=0;j<MAX_DIAS;j++){
			printf("%d		",producto[i][j]);
			printf(">>%d\n",precio[i][j]);
		}
		printf("				Total: %d\n",tot[i]);
	}
	getch();
}

