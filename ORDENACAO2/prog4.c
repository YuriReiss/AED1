#include <stdio.h>
#include <stdlib.h>


//funcao recursiva que verifica as proximas letras após a primeira de cada string
int verificaProximasLetras(char frases[100][100], int j, int min, int c){
	if(frases[j][c]=='\n' || frases[min][c]=='\n') return 0;	

	if(frases[j][c]<frases[min][c]) return c;
	else if(frases[j][c]==frases[min][c]) verificaProximasLetras(frases,j,min,c+1);
	else return 0;

}

//ordena as strings
void selectionSortAdaptado(char frases[100][100],int n){

	int i,j,l,min,c;
	char aux[100];

	for(i=0;i<n-1;i++){
		min=i;
		c=0;
		for(j=i+1;j<n;j++){
			if(frases[j][0]<frases[min][0]){
				min=j;
			}else if(frases[j][0]==frases[min][0] && verificaProximasLetras(frases,j,min,1)){
				c=verificaProximasLetras(frases,j,min,1);
				min=j;			
			}			
		}
		if(frases[i][c]!=frases[min][c]){
			for(l=0;frases[i][l]!='\0';l++) aux[l]=frases[i][l];
			aux[l]='\0';
			for(l=0;frases[min][l]!='\0';l++) frases[i][l]=frases[min][l];
			frases[i][l]='\0';			
			for(l=0;aux[l]!='\0';l++) frases[min][l]=aux[l];
			frases[min][l]='\0';
		}
	}

}

int main(){

	int n,i,j;
	char frases[100][100];
	scanf("%d ",&n);

	for(i=0;i<n;i++){
		for(j=0;;j++){		
			scanf("%c",&frases[i][j]);
			if(frases[i][j]=='\n') break;
		}
	}

	selectionSortAdaptado(frases,n);

	for(i=0;i<n;i++) printf("%s",frases[i]);

	return 0;
}
