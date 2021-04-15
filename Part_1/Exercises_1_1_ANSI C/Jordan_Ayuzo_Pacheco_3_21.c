/* Desarrolle un programa en C que determine la nomina bruta para cada uno de los empleados. La empresa paga "tiempo normal" para las primeras
 40 horas trabajadas de cada empleado y paga "tiempo y medio" para todas las horas trabajadas en exceso de 40 horas. Se le proporciona una lista
  de empleados de la empresa, el numero de horas que cada empleado trabajó la ultima semana y la la tasa horaria de cada empleado.
Su programa debera introducir esta informacion para cada uno de los empleados y determinar  y desplegar la nomina bruta de cada uno de ellos  */

#include<stdio.h>
int main(){
	int cont=1,hor,hor2;
	float nomi,sal,nomi2;
	printf("\t\t Bienvenido\n");
	printf("-1 para salir\n");
	printf("Introduzca las horas trabajadas: ");
	scanf("%d",&hor);
	
	while(hor !=-1){
		printf("\nIntroduzca la nomina del trabajador($00.00): $");
		scanf("%f", &nomi);
		if (hor<=40)
			sal=hor*nomi;
		else
		{
			hor2 = hor - 40;
			hor =hor-hor2;
			nomi2 = nomi/2;
			sal =(hor*nomi)+(hor2*(nomi+nomi2));
		}
		printf("\n \t El salario del Trabajador es : $%.2f\n",sal);
		printf("\t ________________________________________\n");
		printf("-1 para salir\n");
		printf("\nIntroduzca las horas trabajadas: ");
		scanf("%d",&hor);
	}
	system("pause");
	return 0;				
}
