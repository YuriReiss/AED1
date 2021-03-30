#include <stdio.h>
#include <stdlib.h>

void selectionSort(int * A,int n){

	int aux,i,j,min,contTrocas,contComparacoes;

	contTrocas=contComparacoes=0;
		
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			contComparacoes++;
			if(A[j]<A[min]){
				min=j;
			}
		}
		if(A[i]!=A[min]){
			aux=A[i];
			A[i]=A[min];
			A[min]=aux;
			contTrocas++;
		}
	}

	printf("%d %d",contComparacoes,contTrocas);
}


void insertionSort(int * B, int n){
	
	int i,j,aux,contTrocas,contComparacoes;

	contTrocas=contComparacoes=0;
	j = 0; 
	i = 1;
	aux = 0;
	while (i < n) {
		aux = B[i];
		j = i - 1;
		contComparacoes++;
		while ((j >= 0) && (B[j] > aux)) {
			B[j + 1] = B[j];
			j--;
			contTrocas++;
			if(j<0) break;
			contComparacoes++;
		}
		B[j + 1] = aux;
		i++;	
	}

	printf("%d %d",contComparacoes,contTrocas);
}


		
void bubbleSort(int * C, int n){
	
	int i,fim,aux,testeTroca,contTrocas,contComparacoes;

	contTrocas=contComparacoes=0;

	for(fim=n-1;fim>0;fim--){
		testeTroca=0;
		for(i=0;i<fim;i++){
			contComparacoes++;
			if(C[i+1]<C[i]){
				contTrocas++;
				aux=C[i];
				C[i]=C[i+1];
				C[i+1]=aux;
				testeTroca=1;
			}
		}
		if(testeTroca==0) break;
	}

	printf("%d %d\n",contComparacoes,contTrocas);

}

int main(){

	int *A,*B,*C,n,i;
	scanf("%d",&n);

	A=(int *) malloc(sizeof(int)*n);
	B=(int *) malloc(sizeof(int)*n);
	C=(int *) malloc(sizeof(int)*n);

	for(i=0;i<n;i++) scanf("%d",&A[i]);

	for(i=0;i<n;i++) C[i]=B[i]=A[i];

	printf("selection sort: ");

	selectionSort(A, n);

	printf("\ninsertion sort: ");
	
	insertionSort(B, n);

	printf("\nbubble sort: ");

	bubbleSort(C, n);

	for(i=0;i<n;i++) printf("%d ",A[i]);

	printf("\n");

	free(A);
	free(B);
	free(C);

	return 0;
}
