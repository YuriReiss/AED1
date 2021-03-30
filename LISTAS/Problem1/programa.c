#include <stdio.h>
#include <stdlib.h>
	
struct elemento{
	int elemento;
	struct elemento * proximo;
};

struct lista{
	struct elemento * cabeca;
	int tamanho;
};

typedef struct lista Lista;

Lista * lista_cria ();
Lista * lista_copia (Lista * p);
void lista_libera (Lista * p);
int lista_insere_inicio (Lista * p, int elemento);
int lista_insere_final (Lista * p, int elemento);
int lista_insere_posicao (Lista * p, int elemento, int posicao);
int lista_remove_inicio (Lista * p);
int lista_remove_final  (Lista * p);
int lista_remove_posicao (Lista * p, int posicao);
int lista_obtem_elemento  (Lista * p, int posicao); /* retorna elemento em uma posicao */
int lista_se_presente  (Lista * p, int elemento); /* retorna posicao do elemento, ou zero se ausente */
int lista_obtem_tamanho  (Lista * p);
char * lista_imprime  (Lista * p);
int lista_compara_elemento (int elemento1, int elemento2);
void lista_ordena (Lista * p);

int main () {
	Lista * p = lista_cria ();
	char teste;
	int p1,p2,inimigo,n,i;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&inimigo);
		lista_insere_final(p,inimigo);
	}
	while(teste!='F'){
		scanf(" %c",&teste);
		if(teste=='I'){
			scanf("%d %d",&p1,&p2);
			lista_insere_posicao (p,p2, lista_se_presente(p,p1)+1);			
		}else if(teste=='R'){
			scanf("%d",&p1);
			lista_remove_posicao (p,lista_se_presente(p,p1));
		}else if(teste=='Q'){
			scanf("%d %d",&p1,&p2);
			printf("%d\n",lista_se_presente(p,p2)-lista_se_presente(p,p1)-1);
		}
	}	

	printf("%s", lista_imprime(p));		
	lista_libera(p);

	return 0;
}

Lista * lista_cria(){
	Lista * q=(Lista *) malloc(sizeof(Lista));
	
	if(q!=NULL){
		q->cabeca=NULL;
		q->tamanho=0;
	}
	return q;
}

Lista * lista_copia(Lista * p){
	Lista * q=(Lista *) malloc(sizeof(Lista));
		
	if(q!=NULL){
		if(p->tamanho==0)
			q->cabeca=NULL;
		else{
			q->cabeca=(struct elemento *) malloc(sizeof(struct elemento));
			struct elemento * q_elem;
			struct elemento * p_elem;
			p_elem=p->cabeca;
			q_elem=q->cabeca;
			while(p_elem!=NULL){	
				q_elem->elemento=p_elem->elemento;
				if(p_elem->proximo==NULL){
					q_elem->proximo=NULL;
				}
				q_elem->proximo=(struct elemento *) malloc(sizeof(struct elemento));	
				q_elem=q_elem->proximo;
				p_elem=q_elem->proximo;
			}
		}
		q->tamanho=p->tamanho;
	}
	return q;
}

void lista_libera(Lista * p){
	
	struct elemento * q=p->cabeca;
	
	while(q!=NULL){
		struct elemento * aux=q->proximo;
		free(q);
		q=aux;
	}
	free(p);
}

int lista_insere_inicio (Lista * p, int elemento){
	
	struct elemento * q=(struct elemento *) malloc(sizeof(struct elemento));
	
	if(q!=NULL){
		q->elemento=elemento;
		q->proximo=p->cabeca;
		p->cabeca=q;
		p->tamanho=p->tamanho+1;
		return 1;
	}
	return 0;
}

int lista_insere_final (Lista * p, int elemento){
	
	struct elemento * q=(struct elemento *) malloc(sizeof(struct elemento));
	
	q->elemento=elemento;
	q->proximo=NULL;
	if(p->tamanho==0)
		p->cabeca=q;
	else{
		struct elemento * aux=p->cabeca;
		while(aux->proximo!=NULL)
			aux=aux->proximo;
		aux->proximo=q;
	}
	p->tamanho=p->tamanho+1;
	return 1;
}

int lista_insere_posicao (Lista * p, int elemento, int posicao){

	int i;

	if(posicao<1 || posicao>p->tamanho+1) return 0; 
	struct elemento * q=(struct elemento *) malloc(sizeof(struct elemento));
	q->elemento=elemento;
	if(posicao==1){
		if(p->tamanho==0) q->proximo=NULL;
		else q->proximo=p->cabeca;
		p->cabeca=q;
	}else{
		struct elemento * aux=p->cabeca;

		for(i=1;i<posicao-1;i++) aux=aux->proximo;
		
		q->proximo=aux->proximo;
		aux->proximo=q;
	}
	p->tamanho=p->tamanho+1;
	return 1;
}
		
int lista_remove_inicio (Lista * p){
	
	if(p->tamanho==0) return 0;

	struct elemento * aux=p->cabeca;	
	p->cabeca=p->cabeca->proximo;
	free(aux);
	p->tamanho=p->tamanho-1;
	
	return 1;
}	

int lista_remove_final  (Lista * p) {

	if(p->tamanho==0) return 0;
	
	struct elemento * q = p->cabeca;
	while(q->proximo!=NULL)
		q=q->proximo;
	free(q->proximo);
	q=NULL;
	
	p->tamanho=p->tamanho-1;
	return 1;
}
			
int lista_remove_posicao (Lista * p, int posicao){

	int i;
	
	if(posicao<1 || posicao>p->tamanho) return 0;

	if(posicao==1){
		lista_remove_inicio(p);
		return 1;
	}

	if(posicao==p->tamanho){
		lista_remove_final(p);
		return 1;
	}

	struct elemento * q= p->cabeca;
	
	for(i=1;i<posicao-1;i++) q=q->proximo;
	
	struct elemento * aux;
	aux=q->proximo;
	q->proximo=q->proximo->proximo;
	free(aux);
	p->tamanho=p->tamanho-1;
	return 1;
}

int lista_obtem_elemento  (Lista * p, int posicao){
	
	if(posicao<1 || posicao>p->tamanho) return 0;
	
	struct elemento * q=p->cabeca;
	
	while(posicao>0){
		q=q->proximo;
		posicao--;
	}
	return q->elemento;
}

int lista_se_presente  (Lista * p, int elemento){
	
	int i=1;
	struct elemento * aux=p->cabeca;
	
	while(aux->elemento!=elemento){
		i++;
		if(aux->proximo==NULL) return 0;		
		aux=aux->proximo;
	}
	return i;
}

int lista_obtem_tamanho  (Lista * p){
	return p->tamanho;
}

char * lista_imprime  (Lista * p){
	
	int i,j,tam_aux;
	char * imprime=(char *) malloc(1);
	imprime[0]='\0';
	int tamanho=1;
	struct elemento * q=p->cabeca;

	for(i=1;i<=p->tamanho;i++){
		char aux[10];
		if(i==1) sprintf(aux,"%d",q->elemento);
		else sprintf(aux, " %d",q->elemento);
		
		for(tam_aux=0;aux[tam_aux]!='\0';tam_aux++);
		imprime=realloc(imprime, tamanho+tam_aux);
		
		for(j=0;j<tam_aux;j++) imprime[tamanho+j-1]=aux[j];
		
		tamanho=tamanho+tam_aux;
		
		imprime[tamanho-1]='\0';
		q=q->proximo;				
	}
	
	return imprime;
}		

int lista_compara_elemento (int elemento1, int elemento2){

	if(elemento1>elemento2) return 1;
	return 0;
}
void lista_ordena (Lista * p){
	int i,j,l,troca,aux2;
	struct elemento * aux1, * e1, * e2;
	
	for(i=lista_obtem_tamanho(p);i>1;i--){
 		troca=0;
 		for(j=1;j<i;j++){
			l=j;
			aux1=p->cabeca;
  			while(l>0){
				aux1=aux1->proximo;
				l--;
			}
  			if(lista_compara_elemento(aux1->elemento,aux1->proximo->elemento)>0){
   				++troca;
				aux2=aux1->proximo->elemento;
				aux1->proximo->elemento=aux1->elemento;
				aux1->elemento=aux2;
			}
		}
		if(troca==0) break;
	}

	return;
}














































	
