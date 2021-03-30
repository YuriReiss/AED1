#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fila {
	int tamanho, inicio, final;
	int maxTamanho;
	char ** elementos;
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
		q->inicio  = 0;
		q->final   = 0;
		q->maxTamanho = maxTamanho;
		q->elementos = (char **) malloc(sizeof(char *) * maxTamanho);
	}
	return q;
}
Fila * fila_copia (Fila * p) {
	Fila * q = fila_cria(p->maxTamanho);
	int i;
	for(i=fila_obtem_tamanho(p);i>0;i--){	
		char * aux=fila_remove(p);
		fila_insere(q,aux);
		fila_insere(p,aux);
	}
	return q;
}

void fila_libera (Fila * p) {
	free(p->elementos);
	free(p);	
}
int fila_insere (Fila * p, char * elemento) {
	if(p==NULL) return 0;
	if(fila_se_cheia(p)==1) return 0;
	p->elementos[p->final]=elemento;
	p->final=(p->final+1)%p->maxTamanho;
	p->tamanho++;
	return 1; // insercao com sucesso	
}
char * fila_remove (Fila * p) {
	
	char * retorno;	
		
	if(p==NULL) return 0;
	if(fila_se_vazia(p)==1) return 0;
	
	retorno = fila_obtem_primeiro(p);

	p->inicio=(p->inicio+1)%p->maxTamanho;
	p->tamanho--;

	return retorno;
}
char * fila_obtem_primeiro  (Fila * p) {
	if(p==NULL) return NULL;
	return p->elementos[p->inicio];
}
int fila_obtem_tamanho  (Fila * p) {
	if(p==NULL) return -1;
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
	int i;
	for (i = p->tamanho; i>0; i--) {
		char * aux = fila_remove(p);
		fila_insere(p, aux);
		strcat(retorno, aux);
		strcat(retorno, " ");
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
			}	 
		}else if(strcmp(str,"consultar")==0){
			printf("%s\n",fila_imprime(p));
		}
	}
	
	fila_libera(p);

	return 0;
}


