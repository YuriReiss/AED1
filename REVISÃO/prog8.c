#include <stdio.h>

int main(){

	int qnt,i,numero,j,k,cont;
	scanf("%d",&qnt);
	
	for(i=0;i<qnt;i++){	
		scanf("%d",&numero);
		cont=0;
		for(j=1;j<=(numero/2);j++) if(numero%j==0) cont++;
		printf("%d ",numero);

		if(cont==1) printf("S");
		else printf("N");
		
		for(j=numero+1;;j++){	
			cont=0;
			for(k=1;k<=(j/2);k++) if(j%k==0) cont++;
			if(cont==1){
				printf(" %d\n", j);
				break;
			}
		}			
	}

	return 0;
}
