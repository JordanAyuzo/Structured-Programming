#include <stdio.h>
#include <math.h>
int	hr[2],min[2],seg[2],tot_seg[2]={0,0},i,resta=0;
void error();
void conversor();
void imprimir();
int main(){
	printf("No importa si primero pone el tiempo inicial o final\n");
 	for(i=0;i<2;i++){
 		printf("\t\tTiempo: %d\n",i+1);
 		conversor();
 		printf("(presione una tecla para continuar)El tiempo en segundos es: %d\n",tot_seg[i]);
 		getch();
	}
	imprimir();
}
void error(){
	printf("Introdujo un dato erroneo\n");
}
void conversor(){
		printf("HORAS \t");
		scanf("%d",&hr[i]);
		if(hr[i]>=0&&hr[i]<=12){
			printf("MINUTOS\t %d : ",hr[i]);
			scanf("%d",&min[i]);
			if(min[i]>=0&&min[i]<60){
				printf("SEGUNDOS %d : %d : ",hr[i],min[i]);
				scanf("%d",&seg[i]);
				if(seg[i]>=0&&seg[i]<60){
					tot_seg[i]=(hr[i]*3600)+(min[i]*60)+seg[i];	
				}
				else 
					error();	
			}
			else
				error();
		}
		else
			error();
}
void imprimir(){
	system("cls");
	resta=abs(tot_seg[1]- tot_seg[0]);
	printf("EL TIEMPO EN SEGUNDOS ENTRE %d:%d:%d y %d:%d:%d es %d \n",hr[0],min[0],seg[0],hr[1],min[1],seg[1],resta);
}
