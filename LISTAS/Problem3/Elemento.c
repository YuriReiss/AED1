#include <stdio.h>
#include <stdlib.h>
#include "Elemento.h"

struct elemento {
	char * nome;
	char * fone;
	int ligacao;
	Elemento * proximo;
};
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
