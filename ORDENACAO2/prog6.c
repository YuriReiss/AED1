#include <stdio.h>
#include <stdlib.h>


int partition(int * A, int p, int r){
	
	int aux, pivo=A[r], i=p-1,j;
	
	for(j=p;j<=r-1;j++){
		if(A[j]<=pivo){
			i++;
			aux=A[i];
			A[i]=A[j];
			A[j]=aux;
		}
	}
	aux=A[i+1];
	A[i+1]=A[r];
	A[r]=aux;

	return i+1;
} 


//quickSort codificado para imprimir o que foi requisitiado pelo exercício

void quickSort(int * A, int p, int r,int n){

	int q,i;
		
	if(p<r){
		q=partition(A,p,r);
		
		printf("v(%d)=%d * ",q+1,A[q]);

		for(i=0;i<p;i++) printf("%d ",A[i]);			

		printf("[");
		for(i=p;i<r;i++) printf("%d ",A[i]);
		printf("%d]",A[i]);

		for(i=r+1;i<n;i++) printf(" %d",A[i]);
		printf("\n");

		quickSort(A,p,q-1,n);
		quickSort(A,q+1,r,n);
	}
}

int main(){

	int n, * A,i;
	scanf("%d",&n);

	A=(int *) malloc(sizeof(int)*n);

	for(i=0;i<n;i++) scanf("%d",&A[i]);
	
	quickSort(A,0,n-1,n);

	for(i=0;i<n;i++) printf("%d ",A[i]);

	return 0;
}
