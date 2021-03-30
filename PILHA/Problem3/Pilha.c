#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

/* IMPLEMENTACAO COM ELEMENTOS EM VETOR */
typedef struct no No;
struct pilha {
	int tamanho;
	int maxTamanho;
	No * topo;
};
struct no {
	char * elemento;
	struct no * proximo;
};

Pilha * pilha_cria (int maxTamanho) {
	Pilha * q = (Pilha *) malloc(sizeof(Pilha));
	if (q!=NULL) {
		q->tamanho = 0;
		q->maxTamanho = maxTamanho;
		q->topo = NULL;
	}
	return q;
}
Pilha * pilha_copia (Pilha * p) {	
	
	Pilha * q=pilha_cria(p->maxTamanho);
	
	while(!pilha_se_vazia(p)){
		pilha_insere(q,pilha_obtem_topo(p));
		pilha_remove(p);
	}		

	return NULL;
}
void pilha_libera (Pilha * p) {
	if(p==NULL) return 0;
	No * no=p->topo;
	while(no!=NULL);
}

int pilha_insere (Pilha * p, char * elemento) {
	if(p==NULL) return 0;

	No * no= (No *) malloc(sizeof(No));
	if(no==NULL) return 0;
	no->elemento=elemento;
	no->proximo=q->topo;
	p->topo=elem;
	return 1; // insercao com sucesso	
}

char * pilha_remove (Pilha * p) {

	char * retorno = (char *) malloc(sizeof(char)*10);

	if(p==NULL) return 0;

	No * no=p->topo;	
	retorno=no->elemento;
	no=no->proximo;
	free(p->topo);

	return retorno;
}
char * pilha_obtem_topo  (Pilha * p) {
	return p->topo->elemento;
}
int pilha_obtem_tamanho  (Pilha * p) {
	return p->tamanho;
}
int pilha_se_vazia (Pilha * p) {
	if(p->tamanho==0) return 1;
	return -1;
}
int pilha_se_cheia (Pilha * p) {
	if(p->tamanho==p->maxTamanho) return 1;
	return -1;	
}
char * pilha_imprime  (Pilha * p) {
	char * retorno = (char *) malloc(sizeof(char)*10*p->maxTamanho);
	retorno [0] = '\0';
	Pilha * q = pilha_cria(p->maxTamanho);
	while (!pilha_se_vazia(p)) {
		char * aux = pilha_remove(p);
		strcat(retorno, aux);
		strcat(retorno, " ");
		pilha_insere(q, aux);
	}
	while (!pilha_se_vazia(q))
		pilha_insere(p, pilha_remove(q));	
	retorno = realloc(retorno, strlen(retorno)+1);
	return retorno;
}
