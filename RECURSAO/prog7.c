#include <stdio.h>
#include <stdlib.h>

int calculaMDC(int numero1,int numero2,int i, int MDC){

	if(i==numero1+1 || i==numero2+1) return MDC;
	if(numero1%i==0 && numero2%i==0) calculaMDC(numero1,numero2,i+1, i);
	else calculaMDC(numero1,numero2,i+1, MDC);

}

int MDCgeral(int numero1, int i,int * numeros,int N){
	if(i==N) return numero1; 	

	return MDCgeral(calculaMDC(numero1,numeros[i], 1,1),i+1,numeros,N);
}

int main(){

	int N,*numeros,i;

	scanf("%d",&N);

	numeros=(int *) malloc(sizeof(int)*N);
	
	for(i=0;i<N;i++) scanf("%d",&numeros[i]);
	
	printf("%d\n",MDCgeral(numeros[0],1,numeros,N));
	
	return 0;
}

