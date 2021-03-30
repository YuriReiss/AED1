#include <stdio.h>
#include <stdlib.h>


void merge(int * v, int p, int q, int r){

	int com1=p-1, com2=q, comAux=0, vetorAux[r-p+1];
	
	while(com1<=q-1 && com2<=r-1){
		if(v[com1]<=v[com2]){
			vetorAux[comAux]=v[com1];	
			com1++;
		}else{
			vetorAux[comAux]=v[com2];
			com2++;
		}
		comAux++;
	}

	while(com1<=q-1){
		vetorAux[comAux]=v[com1];
		com1++;
		comAux++;
	}
	
	
	while(com2<=r-1){
		vetorAux[comAux]=v[com2];
		com2++;
		comAux++;
	}

	for(comAux=p-1;comAux<=r-1;comAux++) v[comAux]=vetorAux[comAux-p+1];
}

void mergesort (int * v, int p, int r) {
	int q;
	if (p < r) {
		q = (p + r) / 2;
		mergesort (v, p, q);
		mergesort (v, q+1, r);
		merge (v, p, q, r);
	}
}

int main(){
	
	int  * vetor, n,i;
	scanf("%d",&n);
	vetor=(int *) malloc(sizeof(int)*n);

	for(i=0;i<n;i++) scanf("%d",&vetor[i]);	

	mergesort(vetor, 1, n);	

	for(i=0;i<n;i++) printf("%d ",vetor[i]);

	free(vetor);
	return 0;
}


