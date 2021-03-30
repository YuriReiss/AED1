#include <stdio.h>

void printNumeros(int n);

int main(){

	int n;
	scanf("%d",&n);

	printNumeros(n);

	return 0;
}

void printNumeros(int n){

	if(n==0) return;
	printNumeros(n-1);
	printf("%d ",n);

}

	
