#include <stdio.h>
#include <stdlib.h>


//funcao recursiva que verifica as proximas letras após a primeira de cada string
int verificaProximasLetras(char strings[100][303], int j, int min, int c1, int c2){
	if(strings[j][c1]=='\n' || strings[min][c2]=='\n') return 0;	

	while(strings[j][c1]==',' && strings[min][c2]!=',') c2++; 
	while(strings[j][c1]!=',' && strings[min][c2]==',') c1++; 

	if(strings[j][c1]<strings[min][c2]) return c;
	else if(strings[j][c1]==strings[min][c2]) verificaProximasLetras(strings,j,min,c1+1,c2+1);
	else return 0;

}

//ordena as strings
void selectionSortAdaptado(char strings[100][303],int n){

	int i,j,l,min,c;
	char aux[100];

	for(i=0;i<n-1;i++){
		min=i;
		c=0;
		for(j=i+1;j<n;j++){
			if(strings[j][0]<strings[min][0]){
				min=j;
			}else if(strings[j][0]==strings[min][0] && verificaProximasLetras(strings,j,min,1,1)){
				c=verificaProximasLetras(strings,j,min,1,1);
				min=j;			
			}			
		}
		if(strings[i][c]!=strings[min][c]){
			for(l=0;strings[i][l]!='\0';l++) aux[l]=strings[i][l];
			aux[l]='\0';
			for(l=0;strings[min][l]!='\0';l++) strings[i][l]=strings[min][l];
			strings[i][l]='\0';			
			for(l=0;aux[l]!='\0';l++) strings[min][l]=aux[l];
			strings[min][l]='\0';
		}
	}

}

int main(){

	int n,i,j,cont;
	char strings[100][303];
	scanf("%d ",&n);

	for(i=0;i<n;i++){
		cont=0;
		for(j=0;;j++){		
			scanf("%c",&strings[i][j]);
			if(strings[i][j]=='\n'){
				cont++;
				if(cont==3) break;
				strings[i][j]=',';
				j++;
				strings[i][j]=' ';
			}
		
		}
	}

	selectionSortAdaptado(strings,n);

	for(i=0;i<n;i++) printf("%s",strings[i]);

	return 0;
}
