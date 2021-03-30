#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct strings{
	
	char frase1[100];
	char frase2[100];
	char frase3[100];
}Strings;


int verificaLetras(Strings * strings, int j, int min,int iFrase, int c){
	
	if(iFrase==1){
		if(strings[j].frase1[c]<strings[min].frase1[c]) return c;
		else if(strings[j].frase1[c]==strings[min].frase1[c]) verificaLetras(strings,j,min,1,c+1);
		else return -1;
	}else if(iFrase==2){
		if(strings[j].frase2[c]<strings[min].frase2[c]) return c;
		else if(strings[j].frase2[c]==strings[min].frase2[c]) verificaLetras(strings,j,min,2,c+1);
		else return -1;
	}else if(iFrase==3){
		if(strings[j].frase3[c]<strings[min].frase3[c]) return c;
		else if(strings[j].frase3[c]==strings[min].frase3[c]) verificaLetras(strings,j,min,3,c+1);
		else return -1;
	}
}

//selection sort adaptado de uma forma que ordene as structs cumprindo os requisistos do exercício
void selectionSortAdaptado(Strings * strings,int n){

	int i,j,l,min,c;
	int diferente;
	Strings aux;

	for(i=0;i<n-1;i++){
		min=i;
		diferente=0;
		for(j=i+1;j<n;j++){
			if(strcmp(strings[j].frase1, strings[min].frase1)!=0) diferente=1;		
			else if(strcmp(strings[j].frase2, strings[min].frase2)!=0) diferente=2;
			else if(strcmp(strings[j].frase3, strings[min].frase3)!=0) diferente=3;
			else continue;

			if(verificaLetras(strings,j,min,diferente,0)>=0){
				min=j;
			}						
		}

		if(diferente!=0){
			aux=strings[min];
			strings[min]=strings[i];
			strings[i]=aux;
		}
	}

}

int main(){

	int n,i,j;
	Strings * strings;

	scanf("%d",&n);

	strings = (Strings *) malloc(sizeof(Strings)*n);

	for(i=0;i<n;i++){
		scanf(" %[^\n]", strings[i].frase1);
		scanf(" %[^\n]", strings[i].frase2);
		scanf(" %[^\n]", strings[i].frase3);
	}

	selectionSortAdaptado(strings,n);

	for(i=0;i<n;i++) printf("%s, %s, %s\n", strings[i].frase1,strings[i].frase2,strings[i].frase3);
		
	free(strings);

	return 0;
}
