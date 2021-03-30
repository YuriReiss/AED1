#include <stdio.h>


int divisores(int n, int q, int * soma){

	int div;

	if(n==0) return 0;
	div= q+divisores(n-1,q,soma);
	printf("%d ", div);
	*soma+=div;
	return div; 
}

int main(){

	int n,q,soma;

	soma=0;	

	scanf("%d %d",&n,&q);

	divisores(n,q,&soma);	

	printf("\n%d\n",soma);

	return 0;
}

