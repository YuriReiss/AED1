#include <stdio.h>
#include <stdlib.h>

void insertionSort(int * numeros, int n){

	int i,j,aux;
	
	for(i=1;i<n;i++){
		j=i;
		while(j>0 && numeros[j-1]>numeros[j]){
			printf("%d <-> %d\n",numeros[j-1],numeros[j]);
			aux=numeros[j];
			numeros[j]=numeros[j-1];
			numeros[j-1]=aux;
			j--;
		}
	}
}

int main(){
	
	int * numeros, n,i,j;
	scanf("%d",&n);

	numeros=(int *) malloc(sizeof(int)*n);

	for(i=0;i<n;i++) scanf("%d",&numeros[i]);

	insertionSort(numeros,n);

	for(i=0;i<n;i++) printf("%d ",numeros[i]);

	free(numeros);
	return 0;
}
