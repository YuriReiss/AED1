#include <stdio.h>
#include <stdlib.h>

int main(){

	int numeroVezes,i,j,a,cont,numero, digitos[10];//Este vetor "digitos" será utilizado apenas para armazenar os digitos DEPOIS que forem decompostos pelo algoritmo.
	scanf("%d",&numeroVezes);
	
	for(i=0;i<numeroVezes;i++){
		scanf("%d",&numero); //LENDO CADA LINHA COMO UM ÚNICO INTEIRO

		for(j=0;numero>=1;j++){
			digitos[j]=numero%10;
			numero/=10;
		}

		cont=0;
		for(a=0;a<j;a++) if(digitos[a]==digitos[j-a-1]) cont++;
		if(cont==j) printf("S ");
		else printf("N ");
	
		for(a=j-1;a>=0;a--) printf("%c",digitos[a]+65);
		printf("\n");
	}
		
	return 0;
}
