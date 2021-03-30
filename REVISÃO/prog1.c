#include <stdio.h>
#define anoPassagem 1986

int verificaProximoAno(int ano);

int main(){

	int ano;
	
	scanf("%d",&ano);
	
	printf("%d\n",verificaProximoAno(ano));

	return 0;
}

int verificaProximoAno(int ano){

	int i;

	if(ano<anoPassagem){
			if((anoPassagem-ano)%76==0) return ano+76;		
			return ano+(anoPassagem-ano)%76;
	}
	else return ano+(76-(ano-anoPassagem)%76);

	//As linhas anteriores, em suma, verificam o quanto falta para que o cometa passe novamente e, então, soma ao ano lido.
}
