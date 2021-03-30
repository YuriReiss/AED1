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
int lista_insere_inicio (Lista * p, int elemento);
int lista_remove_posicao (Lista * p, int posicao);
int lista_obtem_elemento (Lista * p, int posicao);
int lista_obtem_tamanho (Lista * p);
 
int main(){
 
    Lista * p;
    int n,m,numero,i;
 
    scanf("%d %d",&n,&m);
 
    p=lista_cria();
 
    for(i=0;i<n;i++){
            scanf("%d",&numero);            
            lista_insere_inicio(p,numero);
            if(lista_obtem_tamanho(p)>m && lista_obtem_tamanho(p)%2==0) lista_remove_posicao(p,lista_obtem_tamanho(p)/2);
			if(lista_obtem_tamanho(p)>m && lista_obtem_tamanho(p)%2==1) lista_remove_posicao(p,lista_obtem_tamanho(p)/2+1);
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
 
int lista_insere_inicio (Lista * p, int elemento){
 
    Elemento * elem=(Elemento *) malloc(sizeof(Elemento));

	if(elem!=NULL){    
		elem->elemento=elemento;
		elem->proximo=p->cabeca;
		p->cabeca=elem;
		p->tamanho=lista_obtem_tamanho(p)+1;    
		return 1;//inclusão realizada
	}
	return 0;
}
 
 
int lista_remove_posicao (Lista * p, int posicao){
 
    Elemento * elem;    
    Elemento * aux;

	if(lista_obtem_tamanho(p)==0) return 0;

	if(posicao==1){
		aux=p->cabeca;
		p->cabeca=p->cabeca->proximo;
		free(aux);
		p->tamanho=lista_obtem_tamanho(p)-1; 
		return 1;//exclusão realizada
	}	
	
	elem=p->cabeca;
    while(posicao>2){
        elem=elem->proximo;
        posicao--;
    }
    aux=elem->proximo;
    elem->proximo=elem->proximo->proximo;
    free(aux);
    p->tamanho=lista_obtem_tamanho(p)-1;
 
    return 1;//exclusão realizada
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
