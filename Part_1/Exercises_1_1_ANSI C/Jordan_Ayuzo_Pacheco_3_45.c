/*3_45escribe un programa que imprima 3 numeros enteros no ceros y que imprima si los lados del triangulo forman un triangulo rectangulo*/
#include <stdio.h>
#include <math.h>
int main(){
	int a ,b ,c,c_2,a_2,b_2 ;
	printf("introduzca el primer numero: ");
	scanf("%i",&a);
	printf("introduzca el segundo numero: ");
	scanf("%i",&b);
	printf("introduzca el tercer numero: ");
	scanf("%i",&c);
	c_2 =  sqrt(pow(a,2)+pow(b,2));
	a_2 = sqrt(pow(c,2)+pow(b,2));
	b_2 = sqrt(pow(a,2)+pow(c,2));
	
	if(c==c_2)
		printf("Si es un Triangulo Rectangulo.\n");
	else{
		if(a==a_2)
			printf("Si es un Triangulo Rectangulo.\n");
		else{
			if(b==b_2)
				printf("Si es un Triangulo Rectangulo.\n");
			else
				printf("No es un triangulo rectangulo.\n");
		}
		
	}
	
	system("pause");
	return 0;
}
