#include <stdio.h>
#include <stdlib.h>

void troca(int ** horario, int i){

	int aux[1][2];
	
	aux[0][0]=horario[i][0];
	aux[0][1]=horario[i][1];

	horario[i][0]=horario[i-1][0];	
	horario[i][1]=horario[i-1][1];
	
	horario[i-1][0]=aux[0][0];
	horario[i-1][1]=aux[0][1];
}

//com algumas alterações para que seja comparada cada linha de uma dada matriz
void insertionSort(int ** horario, int n){

	int i,j;
	
	for(i=1;i<n;i++){
		j=i;
		while(j>0 && horario[j-1][0]>=horario[j][0]){
			if(horario[j-1][0]==horario[j][0]){
				if(horario[j-1][1]>horario[j][1]) troca(horario,j);
			}else troca(horario,j);
			j--;
		}
	}
}


int main(){

	int ** horario, hora, n, t,l,i,j,cont,maior, teste,minutosReferenciais,iTeste;

	scanf("%d",&t);
	
	for(l=0;l<t;l++){
		scanf("%d",&n);
		
		horario=(int **) malloc(sizeof(int *)*n);
	
		for(i=0;i<n;i++) horario[i]=(int*) malloc(sizeof(int)*2);
	
		for(i=0;i<n;i++) for(j=0;j<2;j++) scanf("%d",&horario[i][j]);
		
		insertionSort(horario, n);

		maior=cont=1;
		minutosReferenciais=horario[0][1];

		for(i=0;i<n-1;i++){
			if(horario[i][0]==horario[i+1][0]){
				if((horario[i+1][1]-minutosReferenciais)>=2){//If utilizado para manipular o contador				
					cont=1;					
					minutosReferenciais=horario[i+1][1];	
					iTeste=i;				
					while((minutosReferenciais-horario[i][1])<2) i--;			
					if(iTeste!=i) i++;
				}
				if((horario[i+1][1]-horario[i][1])<2) cont++;
				if(cont>maior) maior=cont;
			}else{
				cont=1;
				minutosReferenciais=horario[i+1][1];
			}
		}		

		printf("%d\n",maior);	

		free(horario);
	}
	return 0;

}
