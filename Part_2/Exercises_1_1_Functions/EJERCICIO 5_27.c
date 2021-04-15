#include <stdio.h>
#include <math.h>
void numprimo();
int n1,cont=0,fin;
int main(){
	numprimo();
}
void numprimo(){
	printf("Numero hasta que se detendra ");
	scanf("%d",&fin);
	for(n1=1;n1<=fin;n1++){
		int i,a=0;
		for(i=1;i<=n1;i++){
			if(n1%i==0)
			a++;
		}
		if(a==2){
			printf("%d ",n1);
			cont++;
		}
	}
	printf("\n");
	printf("Hay %d numeros primos en %d numeros \n",cont,fin);
}
