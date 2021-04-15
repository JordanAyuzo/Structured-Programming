/*2.16: Escriba un programa que solicite al usuario que introduzca dos 
numeros tome los dos numeros e imprima la suma, el producto la diferencia el coente
y el modulo de dos numeros*/
#include <stdio.h>
int main(){
	int suma =0, prod = 0,rest = 0, var1 = 0, var2 = 0, modu = 0, divi = 0 ;

	printf("Escribe el primer numero: ");
	scanf("%d",&var1);
	printf("Escribe el segundo numero: ");
	scanf("%d",&var2);

	suma = var1 + var2;
	rest = var1 - var2;
	prod = var1 * var2;
	divi = var1 / var2;
	modu = var1 % var2;

	printf ("La suma de %d y %d es %d \n",var1,var2,suma);
	printf ("La resta de %d y %d es %d \n",var1,var2,rest);
	printf ("La multiplicacion de %d y %d es %d \n",var1,var2,prod);
	printf ("La division de %d y %d es %d \n",var1,var2,divi);
	printf ("El modulo de %d y %d es %d \n",var1,var2,modu);
	system("pause"); /*cuando ejecutaba mi programa.exe salía sin mostrar nada asi que puse esto para detenerlo antes de salir (se lo puse a todos)*/
	return 0;
}

