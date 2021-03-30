#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct elemento Elemento;

struct elemento {
	int elemento;
	Elemento * proximo;
};

struct lista {
	Elemento * cabeca;
	int tamanho;
};

Lista * lista_cria ();
void lista_libera (Lista * p);
int lista_insere_posicao (Lista * p, int elemento, int posicao);
int lista_obtem_elemento (Lista * p, int posicao);
int lista_obtem_tamanho (Lista * p);

int main(){

	Lista * p;
	int n,numero,i;

	scanf("%d",&n);

	p=lista_cria();

	for(i=0;i<n;i++){
			scanf("%d",&numero);
			lista_insere_posicao(p,numero,lista_obtem_tamanho(p)/2+1);
	}

	for(i=1;i<=lista_obtem_tamanho(p);i++) printf("%d ",lista_obtem_elemento(p,i));

	lista_libera(p);
	
	return 0;
}

Lista * lista_cria(){
	
	Lista * p=(Lista *) malloc(sizeof(Lista));

	if(p!=NULL){	
		p->cabeca=NULL;
		p->tamanho=0;
	}
	return p;
}

void lista_libera(Lista * p){
	Elemento * q, * aux;
	q=p->cabeca;
	while(q!=NULL){
		aux=q;
		free(q);
		q=aux->proximo;
	}
	
	free(p);
}
	
int lista_insere_posicao(Lista * p, int elemento, int posicao){

	Elemento * elem=(Elemento *) malloc(sizeof(Elemento));
	int i;

	elem->elemento=elemento;
	if(posicao==1){
		elem->proximo=p->cabeca;
		p->cabeca=elem;	
		p->tamanho=lista_obtem_tamanho(p)+1;
		return 1;
	}

	Elemento * q=p->cabeca;

	for(i=1;i<posicao-1;i++){
		q=q->proximo;
	}	
	elem->proximo=q->proximo;
	q->proximo=elem;
	p->tamanho=lista_obtem_tamanho(p)+1;
	return 1;
}

int lista_obtem_elemento (Lista * p, int posicao){
	int i;

	if(posicao<1) return 0;//alem das posicoes da lista
	if(posicao>lista_obtem_tamanho(p)) return 0;//alem das posicoes da lista

	Elemento * q=p->cabeca;

	for(i=1;i<posicao;i++){
		q=q->proximo;
	}	
	return q->elemento;
}

int lista_obtem_tamanho (Lista * p){
	return p->tamanho;
}


