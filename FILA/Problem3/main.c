#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no No;

struct fila {
	int tamanho;
	int maxTamanho;
	No * inicio;
	No * fim;
};
struct no {
	char * elemento;
	struct no * proximo;
};

typedef struct fila Fila;

Fila * fila_cria (int maxTamanho);
Fila * fila_copia (Fila * p);
void fila_libera (Fila * p);
int fila_insere (Fila * p, char * elemento);
char * fila_remove (Fila * p);
char * fila_obtem_primeiro (Fila * p);
int fila_obtem_tamanho (Fila * p);
int fila_se_vazia (Fila * p);
int fila_se_cheia (Fila * p);
char * fila_imprime (Fila * p);

Fila * fila_cria (int maxTamanho) {
	Fila * q = (Fila *) malloc(sizeof(Fila));
	if (q!=NULL) {
		q->tamanho = 0;
		q->maxTamanho = maxTamanho;
		q->inicio = NULL;
		q->fim    = NULL;
	}
	return q;
}
Fila * fila_copia (Fila * p) {
	if(p==NULL) return NULL;
	int i;
	Fila * q=fila_cria(p->maxTamanho);

	for(i=fila_obtem_tamanho(p);i>0;i--){	
		char * aux=fila_remove(p);
		fila_insere(p,aux);
		fila_insere(q,aux);
	}

	return q;
}

void fila_libera (Fila * p) {
	if(p!=NULL){
		No * aux;
		while(p->inicio!=NULL){
			aux=p->inicio;
			p->inicio=p->inicio->proximo;
			free(aux);
		}
		free(p);
	}
}
int fila_insere (Fila * p, char * elemento) {
	if(p==NULL) return 0;
	if(fila_se_cheia(p)==1) return 0;
	No * no=(No *) malloc(sizeof(No));
	if(no==NULL) return 0;

	no->elemento=elemento;
	no->proximo=NULL;

	if(p->fim==NULL) p->inicio=no;
	else p->fim->proximo=no;
	p->fim=no;

	p->tamanho++;
	return 1; // insercao com sucesso	
}
char * fila_remove (Fila * p) {

	char * retorno;
	
	if(p==NULL) return NULL;
	if(fila_se_vazia(p)==1) return NULL;
	retorno=p->inicio->elemento;
	
	No * no=p->inicio;

	p->inicio=p->inicio->proximo;
	if(p->inicio==NULL) p->fim=NULL;//fila vazia
	p->tamanho--;	

	free(no);
	return retorno;
}
char * fila_obtem_primeiro (Fila * p) {
	if(p==NULL) return NULL;
	return p->inicio->elemento;
}
int fila_obtem_tamanho  (Fila * p) {
	if(p==NULL) return 0;
	return p->tamanho;
}
int fila_se_vazia (Fila * p) {
	if(p==NULL) return -1;
	if(fila_obtem_tamanho(p)==0) return 1;
	return 0;
}
int fila_se_cheia (Fila * p) {
	if(p==NULL) return -1;
	if(fila_obtem_tamanho(p)==p->maxTamanho) return 1;
	return 0;
}
char * fila_imprime  (Fila * p) {
	char * retorno = (char *) malloc(sizeof(char)*10*p->maxTamanho);
	retorno [0] = '\0';
	int tam;
	for (tam = fila_obtem_tamanho(p); tam > 0; tam--) {
		char * aux = fila_remove(p);
		strcat(retorno, aux);
		strcat(retorno, " ");
		fila_insere(p, aux);
	}
	retorno = realloc(retorno, strlen(retorno)+1);
	return retorno;
}
 
int main(){

	char  * str, * pessoa;
	int i;
	Fila * p=fila_cria(100);

	str=(char *) malloc(sizeof(char)*20);	
	
	
	while(strcmp(str,"finalizar")){

		char * temp=NULL;
		
		scanf(" %s",str);
		if(strcmp(str,"inserir")==0){
			pessoa=(char *) malloc(sizeof(char)*20);
			scanf(" %s",pessoa);
			fila_insere(p,pessoa);
		}else if(strcmp(str,"remover")==0){
			pessoa=(char *) malloc(sizeof(char)*20);
			scanf(" %s",pessoa);	
			for (i=fila_obtem_tamanho(p);i>0;i--) {
 				char * aux = fila_remove(p);
				if(strcmp(aux,pessoa)) fila_insere(p,aux);
				else temp=aux; 	
			}
			if(temp!=NULL) fila_insere(p,temp);// tal if é para saber se "temp" foi de fato preenchida para que assim se saiba se existia o elemento desejado na fila	 
		}else if(strcmp(str,"consultar")==0){
			printf("%s\n",fila_imprime(p));
		}
	}
	
	fila_libera(p);

	return 0;
}



