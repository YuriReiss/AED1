#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"
#include "Elemento.h"

int main () {
	Pilha * p = pilha_cria (100);
	pilha_insere  (p, elemento_cria("44"));
	pilha_insere  (p, elemento_cria("bola"));
	pilha_insere  (p, elemento_cria("33"));
	pilha_insere  (p, elemento_cria("carro"));
	//printf("Topo   : %s\n", elemento_imprime(pilha_obtem_topo(p)));
	//printf("Remove : %s\n", elemento_imprime(pilha_remove(p)));
	//printf("Topo   : %s\n", elemento_imprime(pilha_obtem_topo(p)));
	printf("[pilha original] #topo# %s\n", pilha_obtem_tamanho(p), pilha_imprime(p));
	Pilha * q = pilha_copia (p);
	printf("[pilha copia   ] #topo# %s\n", pilha_obtem_tamanho(q), pilha_imprime(q));
	pilha_insere  (q, elemento_cria("mostarda"));
	printf("[pilha copia   ] #topo# %s\n", pilha_obtem_tamanho(q), pilha_imprime(q));
	pilha_libera(q); 
	pilha_libera(p);
	return 0;
}
