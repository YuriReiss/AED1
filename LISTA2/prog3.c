#include <stdio.h>
#include <stdlib.h>

typedef struct vetor Vetor;

struct vetor {
	int * numeros;
	int tamanho;
	int tamanho_maximo;
};

Vetor * vetor_cria (int tamanho_maximo);
void vetor_libera (Vetor * p);
void vetor_insere (Vetor * p, int numero);
void vetor_remove (Vetor * p, int numero);
int vetor_obtem_minimo (Vetor * p);
int vetor_obtem_tamanho (Vetor * p);

int main(){
	
	int tm,i,numero;		
	char teste;
	scanf("%d",&tm);
	Vetor * v= vetor_cria(tm);
	
	while(teste!='F'){	
		scanf(" %c",&teste);
		if(teste=='I'){	
			scanf("%d",&numero);
			vetor_insere(v,numero);
		}else if(teste=='R'){		
			scanf("%d",&numero);
			vetor_remove(v,numero);
		}else if(teste=='M'){
			printf("%d\n",vetor_obtem_minimo(v));
		}
	}

	vetor_libera(v);
	return 0;
}

Vetor * vetor_cria (int tamanho_maximo){
	
	Vetor  * vetor=(Vetor *) malloc(sizeof(Vetor));
	if(vetor!=NULL){
		vetor->numeros=NULL;
		vetor->tamanho=0;
		vetor->tamanho_maximo=tamanho_maximo;
	}
	return vetor;
}

void vetor_libera (Vetor * p){
	if(vetor_obtem_tamanho(p)<0) free(p->numeros);
	free(p);
}

void vetor_insere (Vetor * p, int numero){
	
	int i;
	
	if(vetor_obtem_tamanho(p)==p->tamanho_maximo) return;

	for(i=0;i<vetor_obtem_tamanho(p);i++) if(p->numeros[i]==numero) return;

	p->tamanho=vetor_obtem_tamanho(p)+1;
	if(vetor_obtem_tamanho(p)==1)	
		p->numeros=(int *) malloc(sizeof(int)*vetor_obtem_tamanho(p));
	else
		p->numeros=(int *) realloc(p->numeros,sizeof(int)*vetor_obtem_tamanho(p));
	
	for(i=vetor_obtem_tamanho(p)-1;i>0;i--) p->numeros[i]=p->numeros[i-1];

	p->numeros[0]=numero;
	
}	

void vetor_remove (Vetor * p, int numero){
	
	int i,j;
	
	for(i=0;i<vetor_obtem_tamanho(p);i++){
		if(p->numeros[i]==numero){
			for(j=i;j<vetor_obtem_tamanho(p)-1;j++){	
				p->numeros[i]=p->numeros[i+1];
			}
			break;
		}
	}
	if(i<vetor_obtem_tamanho(p)){	
		p->tamanho=vetor_obtem_tamanho(p)-1;
		p->numeros=(int *) realloc(p->numeros,sizeof(int)*vetor_obtem_tamanho(p));
	}
}

int vetor_obtem_minimo (Vetor * p){
	
	int i, menor=-1,maior=0;

	if(vetor_obtem_tamanho(p)==0) return menor;	
	
	for(i=0;i<vetor_obtem_tamanho(p);i++) if(p->numeros[i]>maior) maior = p->numeros[i];
		
	menor=maior;

	for(i=0;i<vetor_obtem_tamanho(p);i++){		
		if(p->numeros[i]<menor) menor = p->numeros[i];
	}

	return menor;
	
}

int vetor_obtem_tamanho (Vetor * p){
	return p->tamanho;
}




