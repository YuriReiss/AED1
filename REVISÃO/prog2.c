#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int numero,i,numeros[3], maior,digito1,digito2,digito3;

	for(i=0;i<3;i++){
		scanf("%d",&numero);
		
		digito1=numero%10;
		digito2=numero%100/10;
		digito3=numero/100;
	
		numeros[i]=digito1*100+digito2*10+digito3;
	}

	maior=0;
	
	for(i=0;i<3;i++) if(numeros[i]>maior) maior=numeros[i];

	printf("%d",maior);	

	return 0;
}
