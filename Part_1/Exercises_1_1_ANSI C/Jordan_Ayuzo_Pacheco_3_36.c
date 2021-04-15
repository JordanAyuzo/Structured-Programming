/* Introduzca un entero que contenga solo 0s y 1s(ES DECIR UN ENTERO "BINARIO") e imprima su equivalennte decimal*/
#include <stdio.h>
int main()
{
    int num1,num2,contador=1,jcontador=1,decimal,mult=1,resultado,var_deci;
    printf("Introduce un numero binario para trasformarlo a decimal: ");
    scanf("%d",&num1);
 	num2=num1;
    while(num2/10>0)
    {
        num2=num2/10;
        contador++;
    }
    while(jcontador<=contador)
    {
    	decimal = num1%10;
    	num1/=10;
    	var_deci = decimal*mult;
    	resultado+=var_deci;
    	mult*=2;
		jcontador++;
	}
	
	printf("\n\tSu equivalente decimal es : %d\n\n", resultado);
	system("pause");
    return 0;
}
