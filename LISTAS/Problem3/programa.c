#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento Elemento;

struct elemento {
	char * nome;
	char * fone;
	int ligacao;
	Elemento * proximo;
};

Elemento * elemento_cria (char * nome, char * fone, int ligacao);
Elemento * elemento_copia (Elemento * p);
void elemento_libera (Elemento * p);
void elemento_altera (Elemento * p, char * nome, char * fone, int ligacao);
void elemento_altera_proximo (Elemento * p, Elemento * proximo);
char * elemento_obtem_nome (Elemento * p);
char * elemento_obtem_fone (Elemento * p);
int elemento_obtem_ligacao (Elemento * p);
Elemento * elemento_obtem_proximo (Elemento * p);
char * elemento_imprime  (Elemento * p);
int elemento_compara (Elemento * p1, Elemento * p2);

typedef struct lista Lista;

struct lista {
	Elemento * cabeca;
	int tamanho;
};

Lista * lista_cria ();
Lista * lista_copia (Lista * p);
void lista_libera (Lista * p);
int lista_insere_inicio (Lista * p, Elemento * e);
int lista_insere_final (Lista * p, Elemento * e);
int lista_insere_posicao (Lista * p, Elemento * e, int posicao);
int lista_remove_inicio (Lista * p);
int lista_remove_final  (Lista * p);
int lista_remove_posicao (Lista * p, int posicao);
Elemento * lista_obtem_elemento  (Lista * p, int posicao); /* retorna elemento em uma posicao */
int lista_se_presente  (Lista * p, char * nome); /* retorna posicao do elemento, ou zero se ausente */
int lista_obtem_tamanho  (Lista * p);
char * lista_imprime  (Lista * p);
void lista_ordena (Lista * p);


int main () {
	Lista * p = lista_cria ();
	char teste, nome[100], fone[100];
	int nVezes;

	while(teste!='F'){	
		scanf("%c",&teste);
		if(teste=='I'){
			scanf(" %s %s %d", nome, fone, &nVezes);
			lista_insere_inicio(p, elemento_cria(nome, fone, nVezes));
		}else if(teste=='R'){
			scanf(" %s",nome);
			lista_remove_posicao (p,lista_se_presente(p,nome));	
		}else if(teste=='L'){
			scanf(" %s",nome);
			Elemento * elem= lista_obtem_elemento  (p,lista_se_presente(p,nome));
			elemento_altera (elem,elem->nome,elem->fone, elem->ligacao+1);	
		}
	}

	lista_ordena(p);

	printf("%s",lista_imprime(p));

	lista_libera(p);
	return 0;
}

/*-----------------------------------------------------------------*/
/* OPERACOES PRIVADAS */

int private_elemento_char_obtem_tamanho (char * p) {
	int i;
	for(i=0; p[i] != '\0'; i++)
		;
	return i;
}
char * private_elemento_char_copia (char * p) {
	int i;
	char * q = (char *) malloc(private_elemento_char_obtem_tamanho(p)+1);
	for(i=0; p[i] != '\0'; i++)
		q[i] = p[i];
	q[i] = '\0';
	return q;
}
int private_elemento_char_compara (char * p1, char * p2) {
	int i;
	for (i=0; ;i++) {
		if (p1[i] == '\0')
			if (p2[i] == '\0')
				return 0;
			else
				return -1;
		if (p2[i] == '\0')
			if (p1[i] == '\0')
				return 0;
			else
				return 1;			
		if (p1[i] < p2[i])
			return -1;
		if (p1[i] > p2[i])
			return 1;
	}
	return 0;
}
/*-----------------------------------------------------------------*/
/* OPERACOES PUBLICAS */
Elemento * elemento_cria (char * nome, char * fone, int ligacao) {
	Elemento * q = (Elemento *) malloc(sizeof(Elemento));
	if (q!=NULL) {
		q->nome    = private_elemento_char_copia(nome);
		q->fone    = private_elemento_char_copia(fone);
		q->ligacao = ligacao;
		q->proximo = NULL;
	}
	return q;
}
Elemento * elemento_copia (Elemento * p) {
	Elemento * q = (Elemento *) malloc(sizeof(Elemento));
	if (q!=NULL) {
		elemento_altera (q, elemento_obtem_nome(p), elemento_obtem_fone(p), elemento_obtem_ligacao(p));
		elemento_altera_proximo (q, elemento_obtem_proximo(p));
	}
	return q;
}
void elemento_libera (Elemento * p) {
	if (p->nome != NULL)
		free(p->nome);
	if (p->fone != NULL)
		free(p->fone);
	free(p);
}
void elemento_altera (Elemento * p, char * nome, char * fone, int ligacao) {
	if (p->nome != NULL)
		free(p->nome);
	if (p->fone != NULL)
		free(p->fone);
	p->nome = private_elemento_char_copia(nome);
	p->fone = private_elemento_char_copia(fone);
	p->ligacao = ligacao;
}
void elemento_altera_proximo (Elemento * p, Elemento * proximo) {
	p->proximo = proximo;
}
char * elemento_obtem_nome (Elemento * p) {
	return private_elemento_char_copia(p->nome);
}
char * elemento_obtem_fone (Elemento * p) {
	return private_elemento_char_copia(p->fone);
}
int elemento_obtem_ligacao (Elemento * p) {
	return p->ligacao;
}
Elemento * elemento_obtem_proximo (Elemento * p) {
	return p->proximo;
}
char * elemento_imprime  (Elemento * p) {
	char aux[100];
	sprintf(aux, "%s %s %d", p->nome, p->fone, p->ligacao);
	return private_elemento_char_copia(aux);
}
int elemento_compara (Elemento * p1, Elemento * p2) {
	return private_elemento_char_compara(p1->nome, p2->nome);
}
/*-----------------------------------------------------------------*/
/* OPERACOES PRIVADAS */
int private_lista_char_obtem_tamanho (char * p) {
	int i;
	for(i=0; p[i] != '\0'; i++)
		;
	return i;
}
char * private_lista_char_copia (char * p) {
	int i;
	char * q = (char *) malloc(private_lista_char_obtem_tamanho(p)+1);
	for(i=0; p[i] != '\0'; i++)
		q[i] = p[i];
	q[i] = '\0';
	return q;
}
int private_lista_char_compara (char * p1, char * p2) {
	int i;
	for (i=0; ;i++) {
		if (p1[i] == '\0')
			if (p2[i] == '\0')
				return 0;
			else
				return -1;
		if (p2[i] == '\0')
			if (p1[i] == '\0')
				return 0;
			else
				return 1;			
		if (p1[i] < p2[i])
			return -1;
		if (p1[i] > p2[i])
			return 1;
	}
	return 0;
}
/*-----------------------------------------------------------------*/
/* OPERACOES PUBLICAS */
Lista * lista_cria () {
	Lista * q = (Lista *) malloc(sizeof(Lista));
	if (q!=NULL) {
		q->cabeca = NULL;
		q->tamanho = 0;
	}
	return q;
}
Lista * lista_copia (Lista * p) {
	Lista * q = (Lista *) malloc(sizeof(Lista));
	if (q!=NULL) {
		if (p->tamanho == 0)
			q->cabeca == NULL;
		else {
			q->cabeca = elemento_cria("", "", 0);
			Elemento * p_elem;
			Elemento * q_elem;
			p_elem = p->cabeca;
			q_elem = q->cabeca;
			while (p_elem != NULL) {
				elemento_altera(q_elem, elemento_obtem_nome(p_elem), elemento_obtem_fone(p_elem), elemento_obtem_ligacao(p_elem));
				if (elemento_obtem_proximo(p_elem) == NULL)
					elemento_altera_proximo(q_elem, NULL);
				else
					elemento_altera_proximo(q_elem, elemento_cria("", "", 0));
				q_elem = elemento_obtem_proximo(q_elem);
				p_elem = elemento_obtem_proximo(p_elem);
			}
		}
		q->tamanho = p->tamanho;
	}
	return q;
}
void lista_libera (Lista * p) {	
	Elemento * q = p->cabeca;
	while (q != NULL) {
		Elemento * aux = elemento_obtem_proximo(q);
		elemento_libera(q);
		q = aux;
	}
	elemento_libera(q);
}
int lista_insere_inicio (Lista * p, Elemento * e) {
	return lista_insere_posicao (p, e, 1);
}
int lista_insere_final (Lista * p, Elemento * e) {
	return lista_insere_posicao (p, e, p->tamanho+1);
}
int lista_insere_posicao (Lista * p, Elemento * e, int posicao) {
	if (posicao < 1)
		return 0; // insercao sem sucesso, alem do inicio da lista
	if (posicao > p->tamanho+1)
		return 0; // insercao sem sucesso, alem do final da lista
	if (posicao == 1) {
		if (p->tamanho == 0)
			elemento_altera_proximo(e, NULL);
		else
			elemento_altera_proximo(e, p->cabeca);
		p->cabeca = e;
	} else {
		Elemento * aux = p->cabeca;
		while (posicao>2) {
			aux = elemento_obtem_proximo(aux);
			posicao--;
		}
		elemento_altera_proximo(e, elemento_obtem_proximo(aux));
		elemento_altera_proximo(aux, e);
	}
	p->tamanho = p->tamanho+1;	
	return 1; // inserção com sucesso
}
int lista_remove_inicio (Lista * p) {

	if(p->tamanho==0) return 0;
	
	Elemento * aux=(Elemento *) malloc(sizeof(Elemento));
	aux=p->cabeca;	
	p->cabeca=elemento_obtem_proximo(p->cabeca);
	free(aux);
	p->tamanho=p->tamanho-1;
	return 1; // remocao com sucesso
}

int lista_remove_final  (Lista * p) {

	if(p->tamanho==0) return 0;
	
	Elemento * aux=(Elemento *) malloc(sizeof(Elemento));	

	aux=p->cabeca;
	
	while(aux->proximo->proximo!=NULL) aux->proximo=elemento_obtem_proximo(aux->proximo);
	elemento_libera (elemento_obtem_proximo(aux->proximo));
	aux->proximo=NULL;
	p->tamanho=p->tamanho-1;	
	return 1; // remocao com sucesso
}
int lista_remove_posicao (Lista * p, int posicao) {

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

	Elemento * q = lista_obtem_elemento(p,posicao-1);
	
	Elemento * aux;
	aux=q->proximo;
	q->proximo=q->proximo->proximo;
	free(aux);
	p->tamanho=p->tamanho-1;

	return 1; // remocao com sucesso
}
Elemento * lista_obtem_elemento  (Lista * p, int posicao) {
	if ((posicao<1)||(posicao>p->tamanho))
		return NULL;
	Elemento * q = p->cabeca;
	int i;
	for (i=0; i<posicao-1; i++)
		q = elemento_obtem_proximo(q);
	return q;
}
int lista_se_presente  (Lista * p, char * nome) {

	Elemento * elem=(Elemento *) malloc(sizeof(Elemento));
	int i;

	elem=p->cabeca;
	
	for(i=1;i<=p->tamanho;i++){
		if(strcmp(elemento_obtem_nome(elem),nome)==0) return i;
	}

	if(i<=p->tamanho) return i;
	return 0; // elemento ausente
}
int lista_obtem_tamanho  (Lista * p) {
	return p->tamanho;
}
char * lista_imprime  (Lista * p) {
	char * imprime = (char *) malloc(1);
	imprime[0] = '\0';
	int tamanho = 1;
	Elemento * q = p->cabeca;
	int i;
	for (i=0; i < p->tamanho; i++) {
	char aux [100];
		int j, tam_aux;
		sprintf(aux, "%s\n" , elemento_imprime(q));
		tam_aux = private_lista_char_obtem_tamanho(aux);
		imprime = realloc(imprime, tamanho + tam_aux);
		for (j=0; j<tam_aux; j++)
			imprime[tamanho+j-1] = aux[j];
		tamanho = tamanho + tam_aux;
		imprime[tamanho-1] = '\0';
		q = elemento_obtem_proximo(q);
	}
	return imprime;
}
void lista_ordena (Lista * p) {
	int i,j,troca;
	Elemento * aux1, * e1, * e2;
	
	for(i=lista_obtem_tamanho(p);i>1;i--){
 		troca=0;
 		for(j=1;j<i;j++){
			aux1= lista_obtem_elemento(p,j);
  			if(elemento_compara (aux1, aux1->proximo)==1){
   				++troca;
				elemento_altera_proximo (aux1,aux1->proximo);
			}
		}
		if(troca==0) break;
	}

	return;
}
