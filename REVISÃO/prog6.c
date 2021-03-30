#include <stdio.h>
#include <stdlib.h>

int main(){

	int i,menor,qnt, qntTipos, *tipos, tipo; // Já que os tipos vão de 1 a qnt de tipos, aqui usareis as posições dos vetores como representação dos tipos.
	
	scanf("%d %d",&qnt,&qntTipos);
	
	tipos=(int *) malloc(sizeof(int)*qntTipos);
	
	for(i=0;i<qnt;i++){
		scanf("%d", &tipo);
		tipos[tipo-1]++;
	}

	menor=qnt;
	for(i=0;i<qntTipos;i++) if(tipos[i]<menor) menor=tipos[i];
		
	printf("%d\n",menor/2);
	
	return 0;
}

