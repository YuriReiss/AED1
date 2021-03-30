#include <stdio.h>
#include <stdlib.h>


void troca(int ** medalhasPorPais, int j){

	int i,aux[5][1];
	
	for(i=0;i<5;i++) aux[i][0]=medalhasPorPais[i][j];
	
	for(i=0;i<5;i++) medalhasPorPais[i][j]=medalhasPorPais[i][j-1];	
	
	for(i=0;i<5;i++) medalhasPorPais[i][j-1]=aux[i][0];		
}

void insertionSort(int ** medalhasPorPais, int n, int i,int j){

	int l;
	if(i==5){
		troca(medalhasPorPais,j);
		return;
	}
	for(l=1;l<n;l++){
		j=l;
		while(j>0 && medalhasPorPais[i][j-1]<=medalhasPorPais[i][j]){
			if(medalhasPorPais[i][j-1]==medalhasPorPais[i][j]){
				insertionSort(medalhasPorPais,n,i+1,j);
			}else troca(medalhasPorPais,j);
			j--;
		}
	}
}


int main(){

	int n,m,j,i,pais, **medalhasPorPais; //Esta matriz é relação de cada tipo de medalha para cada país participante
		
	scanf("%d %d",&n,&m);

	medalhasPorPais= (int **) malloc(sizeof(int *)*5);
		
	for(i=0;i<5;i++) medalhasPorPais[i]=(int *) malloc(sizeof(int)*n);
	
	for(i=1;i<5;i++) for(j=0;j<n;j++) medalhasPorPais[i][j]=0;			
	for(i=0;i<n;i++) medalhasPorPais[0][i]=i; 

	for(i=0;i<m;i++){
		for(j=1;j<5;j++){
			scanf("%d",&pais);
			medalhasPorPais[j][pais-1]++; //Aqui será acrescentado +1 na posição correspondete ao pais e ao tipo de medalha correpondente			
		}
	}

	insertionSort(medalhasPorPais,n,1,0);

	printf("\n");
	for(j=0;j<n;j++) printf("%d ",medalhasPorPais[0][j]+1);
		

	return 0;
}


