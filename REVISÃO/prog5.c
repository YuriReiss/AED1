#include <stdio.h>


void conversao(int * digitos,int numero, int base){
	
		if(numero==0){
			printf("0 ");
			return;
		}

		int i,k;
		for(i=0;numero!=0;i++){
			digitos[i]=numero%base;
			numero/=base;
		}
		for(k=i-1;k>=0;k--) printf("%d", digitos[k]);
		printf(" ");
}


int main(){

	int qnt,i,numero,digitos[100];

	scanf("%d",&qnt);

	for(i=0;i<qnt;i++){
		scanf("%d",&numero);
		conversao(digitos,numero,3);
		conversao(digitos,numero,4);
		conversao(digitos,numero,5);
		printf("\n");
	}
	return 0;
}

