#include <stdio.h>
#include <stdlib.h>

//adaptado para ordenar a matriz repeticoesDigitos recebida e para que em caso de empate, o desempate seja feito a partir do código em si, ou seja, a primeira posição de cada linha na matriz

void selectionSort(int repeticoesDigitos[9][2]){

	int aux[2],i,j,min;
		
	for(i=0;i<10;i++){
		min=i;
		for(j=i+1;j<10;j++){
			if((repeticoesDigitos[j][1]<repeticoesDigitos[min][1]) || (repeticoesDigitos[j][1]==repeticoesDigitos[min][1] && repeticoesDigitos[j][0]<repeticoesDigitos[min][0])){
				min=j;
			}
		}
		if((repeticoesDigitos[i][1]!=repeticoesDigitos[min][1]) || (repeticoesDigitos[i][1]==repeticoesDigitos[min][1] && repeticoesDigitos[i][0]!=repeticoesDigitos[min][0])){
			aux[0]=repeticoesDigitos[i][0];
			aux[1]=repeticoesDigitos[i][1];
			
			repeticoesDigitos[i][0]=repeticoesDigitos[min][0];			
			repeticoesDigitos[i][1]=repeticoesDigitos[min][1];			
		
			repeticoesDigitos[min][0]=aux[0];			
			repeticoesDigitos[min][1]=aux[1];		
		}
	}

}

int main(){

	int repeticoesDigitos[10][2];

	int i,j,digito1, digito2;

	scanf("%d %d",&digito1,&digito2);

	for(i=0;i<10;i++) repeticoesDigitos[i][0]=i;

	for(i=0;i<10;i++) repeticoesDigitos[i][1]=0;	

	for(i=digito1;i<=digito2;i++){
		j=i;
		while(j>=1){
			repeticoesDigitos[j%10][1]++;
			j/=10;
		}
	}

	selectionSort(repeticoesDigitos);

	for(i=0;i<10;i++) printf("%d : %d\n",repeticoesDigitos[i][0],repeticoesDigitos[i][1]);

	return 0;
}
