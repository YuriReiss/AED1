#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int * numeros, int n){
	
	int i, fim, aux;
	
	for(fim=n-1;fim>0;fim--){
		for(i=0;i<fim;i++){
			if(numeros[i]>numeros[i+1]){
				printf("%d <-> %d\n", numeros[i],numeros[i+1]);
				aux=numeros[i];
				numeros[i]=numeros[i+1];
				numeros[i+1]=aux;		
			}
		}
	}
}

int main(){
	
	int * numeros, n,i,j;
	scanf("%d",&n);

	numeros=(int *) malloc(sizeof(int)*n);

	for(i=0;i<n;i++) scanf("%d",&numeros[i]);

	bubbleSort(numeros,n);

	for(i=0;i<n;i++) printf("%d ",numeros[i]);

	free(numeros);
	return 0;
}
