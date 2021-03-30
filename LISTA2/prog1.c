#include <stdio.h>
#include <stdlib.h>

int partition (int *A, int p, int r) {
	int pivo=A[r-1],i=p-2,aux,j;
	for (j=p-1; j<=r-2; j++) {
		if (A[j]<=pivo) {
			i=i+1;
			aux=A[j];
			A[j]=A[i];
			A[i]=aux;
		}
	}
	aux=A[i+1];
	A[i+1]=A[r-1];
	A[r-1]=aux;
	return (i + 2);
}

void quicksort(int * v, int p, int r) {
	int q;
	if (p < r) {
		q = partition (v, p, r);
		quicksort (v, p, q-1);
		quicksort (v, q+1, r);
	}
}

int main(){

	int n,i,*vetor;

	scanf("%d",&n);

	vetor=(int *) malloc(sizeof(int));
	
	for(i=0;i<n;i++) scanf("%d",&vetor[i]);

	quicksort (vetor, 1, n);

	for(i=0;i<n;i++) printf("%d ",vetor[i]);
	
	return 0;
}
