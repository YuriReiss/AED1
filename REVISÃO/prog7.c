#include <stdio.h>
#include <stdlib.h>

int main(){

	int i,j,N,M,P,D, * pedrasPossiveis;// Para este vetor "pedrasPossiveis", utilizarei as posições do vetor como representação das posições das pedras.

	scanf("%d %d",&N,&M);

	pedrasPossiveis= (int *) malloc(sizeof(int)*N);

	//As posições possíveis de terem sapos serão preenchidas com "1":	

	for(i=0;i<M;i++){
		scanf("%d %d",&P,&D);
		for(j=P-1;j<N;j+=D) pedrasPossiveis[j]=1;//Primeiramente verifica da posição atual pra frente
		for(j=P-1;j>=0;j-=D) pedrasPossiveis[j]=1;//Verifica da posição atual para trás
	}

	//As posições com "1" serão impressas, pois estas são as possíveis pedras a estarem com sapos:

	for(i=0;i<N;i++) if(pedrasPossiveis[i]==1)printf("%d ", i+1);	
	printf("\n");

	return 0;
}
