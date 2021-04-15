/*2.19 Escriba un programa de c que entren tres enteros diferentes del teclado,
y acontinuacion imprima la suma el promedio el producto el mas pequeño y el mas grande de estos numeros 
utilice solamente la forma de una seleccion if que usted aprendió*/
#include<stdio.h>
int main(){
	int num1, num2,num3,sum, prom, mult;
	printf("Escribir el primer numero uno: ");
	scanf("%d", &num1);
	printf("Escribir el primer numero dos: ");
	scanf("%d", &num2);
	printf("Escribir el primer numero tres: ");
	scanf("%d", &num3);
	sum = num1 + num2 + num3;
	prom = sum / 3;
	mult = num1 * num2 *num3;
	printf("La suma de los numeros %d, %d y %d  son %d.\n", num1, num2, num3, sum);
	printf("El promedio de los numeros %d, %d y %d es %d.\n", num1, num2, num3, prom);
	printf ("El producto de los numeros %d, %d y %d es %d.\n", num1, num2, num3, mult);
	if(num1 > num2 && num1 > num3)
		printf("El primer numero: %d es el mayor.\n"), num1;
	if(num2 > num1 && num2 > num3)
		printf("El segundo numero: %d es el mayor.\n"), num2;	
	if(num3 > num1 && num3 > num2)
		printf("El tercer numero: %d es el mayor.\n"), num2;
	if(num1 < num2 && num1 < num3)
		printf("El primer numero: %d es el menor.\n"), num1;
	if(num2 < num1 && num2 < num3)
		printf("El segundo numero: %d es el menor.\n"), num2;	
	if(num3 < num1 && num3 < num2)
		printf("El tercer numero: %d es el menor.\n"), num3;		
		
	system("pause");
	return(0);	
}
