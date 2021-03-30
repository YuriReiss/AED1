#include <stdio.h>
#include <stdlib.h>

struct lista {
	int * elementos;
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
		q->elementos=NULL;
		q->tamanho=0;
	}
	return q;
}

Lista * lista_copia (Lista * p) {
	Lista * q = (Lista *) malloc(sizeof(Lista));
	if (q!=NULL) {
		if (p->tamanho == 0) 
			q->elementos = NULL;
		else {
			int i;
			q->elementos = (int *) malloc(sizeof(int) * p->tamanho);
			for (i=0; i < p->tamanho; i++)
				q->elementos[i] = p->elementos[i];
		}
		q->tamanho = p->tamanho;	
	}
	return q;
}
void lista_libera (Lista * p) {
	if (p->tamanho > 0)
		free(p->elementos);
	free(p);
}
int lista_insere_inicio (Lista * p, int elemento) {
	p->tamanho = p->tamanho + 1;
	if (p->tamanho == 1)
		p->elementos = (int *) malloc(sizeof(int) * p->tamanho);
	else
		p->elementos = (int *) realloc(p->elementos, sizeof(int) * p->tamanho);
	int i;
	for (i = p->tamanho-1; i > 0; i--)
		p->elementos[i] = p->elementos[i-1];
	p->elementos[0] = elemento;
	return 1; // insercao com sucesso
}
int lista_insere_final (Lista * p, int elemento) {
	p->tamanho = p->tamanho + 1;	
	if (p->tamanho == 1)
		p->elementos = (int *) malloc(sizeof(int) * p->tamanho);
	else
		p->elementos = (int *) realloc(p->elementos, sizeof(int) * p->tamanho);
	p->elementos[p->tamanho-1] = elemento;
	return 1; // insercao com sucesso	
}
int lista_insere_posicao (Lista * p, int elemento, int posicao) {

	int i;	

	if (posicao < 1)
		return 0; // insercao sem sucesso, alem do inicio da lista
	if (posicao > p->tamanho+1)
		return 0; // insercao sem sucesso, alem do final da lista
	p->tamanho = p->tamanho + 1;
	if (p->tamanho == 1)
		p->elementos = (int *) malloc(sizeof(int) * p->tamanho);
	else
		p->elementos = (int *) realloc(p->elementos, sizeof(int) * p->tamanho);
	for (i = p->tamanho-1; i > posicao-1; i--)
		p->elementos[i] = p->elementos[i-1];
	p->elementos[posicao-1] = elemento;
	return 1; // inserção com sucesso
}
int lista_remove_inicio (Lista * p) {

	int i;

	if(p->tamanho==0) return 0;
	for(i=0;i<p->tamanho-1;i++) p->elementos[i]=p->elementos[i+1];
	p->tamanho=p->tamanho-1;
	p->elementos=(int *) realloc(p->elementos,sizeof(int)*p->tamanho);
	return 1;
}
int lista_remove_final  (Lista * p) {

	if(p->tamanho==0) return 0;
	p->tamanho=p->tamanho-1;
	p->elementos=(int *) realloc(p->elementos,sizeof(int)*p->tamanho);

	return 1;
}
int lista_remove_posicao (Lista * p, int posicao) {

	int i;

	if(p->tamanho==0) return 0;
 
	for(i=posicao-1;i<p->tamanho-1;i++) p->elementos[i]=p->elementos[i+1];
	p->tamanho=p->tamanho-1;
	p->elementos=(int *) realloc(p->elementos,sizeof(int)*p->tamanho);
	
	return 0;
}
int lista_obtem_elemento  (Lista * p, int posicao) {
	if ((posicao<1)||(posicao>p->tamanho))
		return -1;
	return p->elementos[posicao-1];
}
int lista_se_presente  (Lista * p, int elemento) {

	int i;

	for(i=0;i<p->tamanho;i++)
		if(p->elementos[i]==elemento) return i+1;

	return 0;
}
int lista_obtem_tamanho  (Lista * p) {
	return p->tamanho;
}
char * lista_imprime  (Lista * p) {
	char * imprime = (char *) malloc(1);
	imprime[0] = '\0';
	int i;
	int tamanho = 1;
	for (i=0; i < p->tamanho; i++) {
		char aux[10];
		int j, tam_aux;
		if (i==0)
			sprintf(aux, "%d" , p->elementos[i]);
		else
			sprintf(aux, " %d", p->elementos[i]);
		for (tam_aux=0; aux[tam_aux] != '\0'; tam_aux++)
			;
		imprime = realloc(imprime, tamanho + tam_aux);
		for (j=0; j<tam_aux; j++)
			imprime[tamanho+j-1] = aux[j];
		tamanho = tamanho + tam_aux;
		imprime[tamanho-1] = '\0';
	}
	return imprime;
}
int lista_compara_elemento (int elemento1, int elemento2) {
	
	if(elemento1>elemento2) return 1;
	return 0;
}
void lista_ordena (Lista * p) {

	int maior,i;

	Lista * c=(Lista *) malloc(sizeof(int)*p->tamanho);//auxiliar
	Lista * b=(Lista *) malloc(sizeof(int)*p->tamanho);//vetor ordenado

	maior=0;

	for(i=0;i<p->tamanho;i++) if(p->elementos[i]>maior) maior=p->elementos[i];
	
	c->tamanho=maior;
	b->tamanho=p->tamanho;

	for(i=0;i<c->tamanho;i++) c->elementos[i]=0;//inicia auxiliar com 0
	
	for(i=0;i<p->tamanho;i++) c->elementos[p->elementos[i]]++;//contagem das ocorrencias 

	for(i=1;i<c->tamanho;i++) c->elementos[i]=c->elementos[i]+c->elementos[i-1];

	for(i=p->tamanho-1;i>=0;i--){
		b->elementos[c->elementos[p->elementos[i]-1]-1]=p->elementos[i];
		c->elementos[p->elementos[i]-1]--;			
	}

	for(i=0;i<p->tamanho;i++) p->elementos[i]=b->elementos[i];

}
		
