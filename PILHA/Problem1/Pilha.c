#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"


struct pilha {
	int tamanho;
	int maxTamanho;
	char ** elementos;
};

Pilha * pilha_cria (int maxTamanho) {
	Pilha * q = (Pilha *) malloc(sizeof(Pilha));
	if (q!=NULL) {
		q->tamanho = 0;
		q->maxTamanho = maxTamanho;
		q->elementos = (char **) malloc(sizeof(char *) * maxTamanho);
	}
	return q;
}
Pilha * pilha_copia (Pilha * p) {
	Pilha * q=pilha_cria(p->maxTamanho);
	int i;
	for (i=pilha_obtem_tamanho(p)-1; i>=0; i--) {
		q->elementos[i]=p->elementos[i];
	}

	return q;
}
void pilha_libera (Pilha * p) {
	free(p);
}
int pilha_insere (Pilha * p, char * elemento) {

	if(p==NULL) return 0;
	if(pilha_se_cheia(p)==1) return 0;
	
	p->elementos[p->tamanho]=elemento;
	p->tamanho++;

	return 1; // insercao com sucesso	
}
char * pilha_remove (Pilha * p) {
	
	char * retorno=(char *) malloc(sizeof(char)*10);

	if(p==NULL) return 0;
	if(pilha_se_vazia(p)==1) return 0;
	retorno=pilha_obtem_topo(p);
	p->tamanho--;	
	
	return retorno;
}
char * pilha_obtem_topo  (Pilha * p) {
	if(p!=NULL) return p->elementos[p->tamanho-1];
	return NULL;
}
int pilha_obtem_tamanho  (Pilha * p) {
	if(p!=NULL) return p->tamanho;
	return -1;
}
int pilha_se_vazia (Pilha * p) {
	if(p==NULL) return -1;
	if(p->tamanho==0) return 1;
	return 0;
}
int pilha_se_cheia (Pilha * p) {
	if(p==NULL) return -1;
	if(p->tamanho==p->maxTamanho) return 1;
	return 0;
}
char * pilha_imprime  (Pilha * p) {
	char * aux = (char *) malloc(sizeof(char)*10*p->maxTamanho);
	aux [0] = '\0';
	int i;
	for (i=pilha_obtem_tamanho(p)-1; i>=0; i--) {
		strcat(aux, p->elementos[i]);
		strcat(aux, " ");
	}
	aux = realloc(aux, strlen(aux)+1);
	return aux;
}
