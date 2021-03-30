#include <stdio.h>
#include <stdlib.h>

int acertos,naviosDestruidos;

void confereNavegacoes(char ** tabuleiro,int L, int C,int l, int c, int teste){

	
	if(l<0 || c<0 || l>=L || c>=C || tabuleiro[l][c]=='.') return;
	
	if(tabuleiro[l][c]=='N'){
		if(teste==1){
			acertos++;
			naviosDestruidos++;
		}	
		tabuleiro[l][c]='X';
		if(l+1<L) confereNavegacoes(tabuleiro,L,C,l+1,c,0);
		if(c+1<C) confereNavegacoes(tabuleiro,L,C,l,c+1,0);
		if(l-1>=0) confereNavegacoes(tabuleiro,L,C,l-1,c,0);
		if(c-1>=0) confereNavegacoes(tabuleiro,L,C,l,c-1,0);	
	}else if(tabuleiro[l][c]=='X' && teste==1) acertos++;
	
}

int main(){

	int i,j,k,L,C,l,c;	
	
	char **tabuleiro;

	scanf("%d %d",&L,&C);		

	tabuleiro = (char **) malloc(sizeof(char *)*L);
	
	for(i=0;i<L;i++) tabuleiro[i]=(char *) malloc(sizeof(char)*C);
		
	for(i=0;i<L;i++) for(j=0;j<C;j++) scanf(" %c", &tabuleiro[i][j]);

	scanf("%d",&k);
	naviosDestruidos=acertos=0;	

	for(i=0;i<k;i++){
		scanf("%d %d, ",&l,&c);
		confereNavegacoes(tabuleiro,L,C,l-1,c-1,1);
	}

	printf("%d %d %d\n",k-acertos,acertos, naviosDestruidos);

	for(i=0;i<L;i++){
		for(j=0;j<C;j++) printf("%c",tabuleiro[i][j]);
		printf("\n");
	}
	return 0;
}
