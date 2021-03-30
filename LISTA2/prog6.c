#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palavra Palavra;

struct palavra {
	char * nome;
	char * sinonimo;
};

Palavra * palavra_cria (char * nome, char * sinonimo);
void palavra_libera (Palavra * p);
char * palavra_obtem_nome (Palavra * p);
char * palavra_obtem_sinonimo (Palavra * p);
int palavra_compara (Palavra * p1, Palavra * p2);

int main(){

	int n,fim,i;
	char teste, * nome, * sinonimo;
	Palavra * aux;
	scanf("%d",&n);
	
	Palavra * vetor[n];
		
	for(i=0;i<n;i++){
		nome=(char *) malloc(sizeof(char)*50);		
		sinonimo=(char *) malloc(sizeof(char)*50);
		
		scanf(" %s %s",nome,sinonimo);	
		vetor[i]=palavra_cria(nome, sinonimo);
	}

	char consulta[50];	

	while(teste!='F'){
		scanf(" %c",&teste);
		if(teste=='C'){
			scanf(" %s",consulta);
			for(i=0;i<n;i++) if(strcmp(consulta,palavra_obtem_nome(vetor[i]))==0) break;
			if(i==n){
				printf("CONSULTA %s INEXISTENTE\n",consulta);
				continue;
			}
			printf("CONSULTA %s %s\n",palavra_obtem_nome(vetor[i]),palavra_obtem_sinonimo(vetor[i]));
		}
	}	
	
	for(fim=n-1;fim>0;fim--){
		teste=0;
		for(i=0;i<fim;i++){
			if(palavra_compara (vetor[i], vetor[i+1])>0){
				aux=vetor[i];
				vetor[i]=vetor[i+1];
				vetor[i+1]=aux;
				teste++;
			}
		}
		if(teste==0) break;//nenhuma troca foi realizada
	}
		
	for(i=0;i<n;i++) printf("%s %s\n",palavra_obtem_nome(vetor[i]),palavra_obtem_sinonimo(vetor[i]));

	return 0;
}

Palavra * palavra_cria (char * nome, char * sinonimo){
	Palavra * p=(Palavra *) malloc(sizeof(Palavra));
	if(p!=NULL){
		p->nome=nome;
		p->sinonimo=sinonimo;
	}
	return p;
}

void palavra_libera (Palavra * p){
	if(p!=NULL){
		free(p->nome);
		free(p->sinonimo);
		free(p);
	}
}

char * palavra_obtem_nome (Palavra * p){
	return p->nome;
}

char * palavra_obtem_sinonimo (Palavra * p){
	return p->sinonimo;
}

int palavra_compara (Palavra * p1, Palavra * p2){
	return strcmp(p1->nome,p2->nome);
}
