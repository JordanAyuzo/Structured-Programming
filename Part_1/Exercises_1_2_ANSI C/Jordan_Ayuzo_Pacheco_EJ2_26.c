/*escriba un programa que lea dos numeros enteros yque determine 
 e imprima si el numero es multiplo del segundo*/
 #include<stdio.h>
 int main(){
 	int num1, num2;
 	printf("Escribir el primer numero: ");
 	scanf("%d", &num1);
 	printf("Escribir el primer numero: ");
 	scanf("%d", &num2);
 	if(num1%num2 != 0)
 		printf("el numero %d no es multiplo de %d\n",num1,num2);
 	else
 		printf("el numero %d  es multiplo de %d\n",num1,num2);	
 	
 	system("pause");
	return(0);	
 }
