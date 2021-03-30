#include <stdio.h>
#include <stdlib.h>

int N,cont,contChamadas;

int verificaPosicao(char ** tabuleiro,int i,int j, int iOriginal, int jOriginal){

	contChamadas++;
	//Verifica se saiu do tabuleiro
	if(i==N || j==N || i<0 || j<0) return 1; 

	//Verifica se entrou em loop
	if(i==iOriginal && j==jOriginal){
		cont++;
		if(cont==2) return 0;
	}

	//Verifica se não é nenhum dos dois
	if(contChamadas==N*N) return 2;

	if(tabuleiro[i][j]=='<') return verificaPosicao(tabuleiro,i,j-1,iOriginal,jOriginal);
	if(tabuleiro[i][j]=='>') return verificaPosicao(tabuleiro,i,j+1,iOriginal,jOriginal);
	if(tabuleiro[i][j]=='A') return verificaPosicao(tabuleiro,i-1,j,iOriginal,jOriginal);
	if(tabuleiro[i][j]=='V') return verificaPosicao(tabuleiro,i+1,j,iOriginal,jOriginal);
	 
}

	

int main(){

	int i,j,teste;	
	
	char **tabuleiro;

	scanf("%d",&N);		

	tabuleiro = (char **) malloc(sizeof(char *)*N);
	
	for(i=0;i<N;i++) tabuleiro[i]=(char *) malloc(sizeof(char)*N);
		
	for(i=0;i<N;i++) for(j=0;j<N;j++) scanf(" %c", &tabuleiro[i][j]);
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			cont=contChamadas=0;
			teste=verificaPosicao(tabuleiro,i,j,i,j);
			if(teste==0) printf("L");
			else if(teste==1) printf("O");
			else printf("I");
		}
		printf("\n");
	}
	
	return 0;
}
