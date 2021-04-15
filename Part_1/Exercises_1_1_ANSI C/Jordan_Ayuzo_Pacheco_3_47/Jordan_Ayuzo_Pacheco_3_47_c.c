/*escriba un programa que calcule e^x, utilizando la formula dada en el libro*/
#include <stdio.h>
int main(){
	int	i=1;
	float var1,poten=1,e=1;
	printf("%cpor cuanto elevar%c e%c: e^",168,160,63);
	scanf("%f",&var1);
	while(i<=200){
		poten=(poten*var1)/i;
		e=e+poten;
		i++;
	}
	printf("\tEl resultado es %f\n\n",e);
	system("pause");
	return 0;
}
