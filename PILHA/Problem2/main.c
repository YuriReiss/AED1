#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pilha {
	int tamanho;
	int maxTamanho;
	char ** elementos;
};

typedef struct pilha Pilha;

Pilha * pilha_cria (int maxTamanho);
Pilha * pilha_copia (Pilha * p);
void pilha_libera (Pilha * p);
int pilha_insere (Pilha * p, char * elemento); // push
char * pilha_remove (Pilha * p); // pop
char * pilha_obtem_topo (Pilha * p); // top
int pilha_obtem_tamanho (Pilha * p);
int pilha_se_vazia (Pilha * p);
int pilha_se_cheia (Pilha * p);
char * pilha_imprime (Pilha * p);

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
	
	char * retorno;

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

int main () {

	char * str,* strCompara;
	Pilha * p = pilha_cria (100);
	int teste=0;

	while(1){
		str=(char *) malloc(sizeof(char)*5);		
		scanf("%s%*c", str);
		if(strcmp(str,"fim")){
			if(!strcmp(str,"+") || !strcmp(str,"/") || !strcmp(str,"-") || !strcmp(str,"*") || !strcmp(str,"(") || !strcmp(str,"{") || !strcmp(str,"[")){				
				if(!strcmp(str,"(") && teste==0) pilha_insere(p,"(");
				pilha_insere(p,str);
				if((!strcmp(str,"+") || !strcmp(str,"/") || !strcmp(str,"-") || !strcmp(str,"*"))) teste=1;
			}else if(!strcmp(str,")")){
				while(strcmp(pilha_obtem_topo (p),"(")!=0){
					printf("%s ",pilha_remove(p));
				}
				if(teste==1){
					while(strcmp(pilha_obtem_topo (p),"(")!=0){
						printf("%s ",pilha_remove(p));
					}
					teste=0;
				}
			}else if(!strcmp(str,"}")){
				while(strcmp(pilha_obtem_topo (p),"{")!=0){
					printf("%s ",pilha_remove(p));
				}
			}else if(!strcmp(str,"]")){
				while(strcmp(pilha_obtem_topo (p),"[")!=0){
					printf("%s ",pilha_remove(p));
				}
			}else printf("%s ",str);			
  
		}else{
			
			while(pilha_se_vazia(p)==0){
				printf("%s ",pilha_remove(p));		
			}
			break;
		}
				
	}
			
	pilha_libera(p);

	return 0;	

}



