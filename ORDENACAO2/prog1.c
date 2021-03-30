#include <stdio.h>
#include <stdlib.h>

void coutingSort(int * A, int * B, int * C, int n, int k){
	
	int i;

	for(i=0;i<=k;i++) C[i]=0;

	for(i=0;i<n;i++) C[A[i]]++;
	
	for(i=1;i<=k;i++) C[i]+=C[i-1];

	for(i=n-1;i>=0;i--){
		B[C[A[i]]-1]=A[i];
		C[A[i]]--;
	}		

	for(i=0;i<n;i++) A[i]=B[i];
	
}
	

int main(){

	int i,n,k, * A, * B, * C;
	
	scanf("%d %d",&n,&k);
	
	A=(int *) malloc(sizeof(int)*n);
	B=(int *) malloc(sizeof(int)*n);
	C=(int *) malloc(sizeof(int)*(k+1));

	for(i=0;i<n;i++) scanf("%d",&A[i]);
	
	coutingSort(A,B,C,n,k);

	printf("B: ");	
	
	for(i=0;i<n;i++) printf("%d ",B[i]);

	printf("\nC: ");	

	for(i=0;i<=k;i++) printf("%d ",C[i]);

	free(A);
	free(B);
	free(C);

	return 0;
}
