/*3.40 escribir el patron mostrado en el libro*/
#include<stdio.h>
int main()
{
	int cont=1,cont2=0;
	while(cont2<=7)
	{
		
		
		while(cont<=8)
		{
			printf("* ");
			cont++;
		}
		printf("\n");
		cont=1;
		if(cont2%2 == 0)
			printf(" ");		
		cont2++;
	}
	system("pause");
	return 0;
}
