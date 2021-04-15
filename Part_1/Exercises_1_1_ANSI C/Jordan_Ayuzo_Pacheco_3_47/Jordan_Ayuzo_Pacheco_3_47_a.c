/*escriba un programa entero no negativo y calcule e imprima su factorial*/
#include<stdio.h>
int main(){
	int num,num2,factorial=1;
	printf("Escribe un numero para poder obtener el factorial: ");
	scanf("%d",&num);
	if (num>=0){
		num2 = num;
		while(num2>0){
			factorial*=num2;
			num2--;
		}
	printf("El factorial de %d es: %d\n\n",num,factorial);
	}
	else
		printf("\a No hay factoriales negativas\n\n");	

	system("pause");
	return 0;
}
