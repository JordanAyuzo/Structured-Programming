/*Escriba un programa que entre un numero de cinco digitos separe sus numeros en
numeros individuales e imprima los digitos separados unos de otros mediante tres espacios*/
#include<stdio.h>
int main(){
	int num1, n1, n2, n3, n4;
	printf("escribe un numero de cinco digitos: ");
	scanf("%d", &num1);
	n1 = num1/10000;
	num1 = num1%10000;
	n2 = num1/1000;
	num1 = num1%1000;
	n3 = num1/100;
	num1 = num1%100;
	n4 = num1/10;
	num1 = num1%10;
	//me percaté de que "num1" se dividiría en 1 lo cual daría lo mismo asi que me ahorré un paso
	printf("%d   %d   %d   %d   %d\n", n1, n2, n3, n4, num1);
	system("pause");	
	return(0);
}
