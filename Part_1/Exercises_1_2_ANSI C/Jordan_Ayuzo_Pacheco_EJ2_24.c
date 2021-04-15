/*Escribe un programa que lea un entero y determine e imprima si es par o impar*/
#include<stdio.h>
int main(){
	int num1;
	printf("Escriba un numero entero para evaluar: ");
	scanf("%d", &num1);
	if(num1%2 != 0)
		printf("El numero %d es impar.\n",num1);
	else
		printf("El numero %d es par.\n",num1);
		system("pause");
		return(0);
}
