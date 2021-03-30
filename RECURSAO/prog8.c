#include <stdio.h>

int main(){
	
	int S, qntNotas[6];
	scanf("%d",&S);
	
	for(i=0;i<6;i++) scanf("%d",&qntNotas[i]);
	
	determinaPossibilidades(S,qntNotas);
	return 0;
}


