/*escriba un programa que estime el valor de la constante matematica e utilizando la formula del libro*/
#include <stdio.h>
int main(){
	int denominador=1, contador=1, jcontador=1,precicion;
	float e=1;
	printf("escriba la precision de e: ");
	scanf("%d",&precicion);
	while(contador<=precicion){
		denominador*=contador;
		e+=(1/(float)denominador);
		contador++;
	}
	printf("\tEl numero de e es: %.9f\n",e);
	
	system("pause");
	return 0;
	
}
