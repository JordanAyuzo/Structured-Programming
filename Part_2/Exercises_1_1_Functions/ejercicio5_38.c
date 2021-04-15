#include <stdio.h>
#define MAX 3000000000
void fibonacci(){
	int a=0,b=1,c=0;
	while(a<=MAX){
		printf(" %d ",a);
		c=a+b;
		a=b;
		b=c;
	}
}
int main(){
	fibonacci();
}
