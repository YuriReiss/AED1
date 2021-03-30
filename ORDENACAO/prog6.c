#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int * numeros, int n){
	
	int i, fim, aux;
	
	for(fim=n-1;fim>0;fim--){
		for(i=0;i<fim;i++){
			if(numeros[i]>numeros[i+1]){
				aux=numeros[i];
				numeros[i]=numeros[i+1];
				numeros[i+1]=aux;		
			}
		}
	}
}

int somatoria(int * numeros, int p, int q){

	int soma, i;
	soma=0;

	for(i=p-1;i<=q-1;i++) soma+=numeros[i]; 
	return soma;
}

int main(){

	int *numeros, n,p,q,i;
	scanf("%d",&n);
	
	numeros=(int *) malloc(sizeof(int)*n);

	for(i=0;i<n;i++) scanf("%d",&numeros[i]);

	scanf("%d %d",&p,&q);

	bubbleSort(numeros, n);
	
	printf("%d\n",somatoria(numeros,p,q));

	free(numeros);
	return 0;
}
