#include <stdio.h>
#include <stdlib.h>

int calculaMMC(int soma1,int soma2,int numero1,int numero2){
	if(soma1==soma2) return soma1;
	if(soma1>soma2) calculaMMC(soma1,soma2+numero2,numero1,numero2);
	else calculaMMC(soma1+numero1,soma2,numero1,numero2);
}

int MMCgeral(int numero1, int i,int * numeros,int N){
	if(i==N) return numero1; 	

	return MMCgeral(calculaMMC(numero1,numeros[i],numero1,numeros[i]),i+1,numeros,N);
}

int main(){

	int N,*numeros,i;

	scanf("%d",&N);

	numeros=(int *) malloc(sizeof(int)*N);
	
	for(i=0;i<N;i++) scanf("%d",&numeros[i]);
	
	printf("%d\n",MMCgeral(numeros[0],1,numeros,N));
	
	return 0;
}

