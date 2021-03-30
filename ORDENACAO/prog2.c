#include <stdio.h>
#include <stdlib.h>
 
//bubbleSort que realiza comparações apenas entre as partes inteiras dos números
void bubbleSort(float * numeros, int n){
	
	int i, fim;
	float aux;
	
	for(fim=n-1;fim>0;fim--){
		for(i=0;i<fim;i++){
			if((int)numeros[i]>(int)numeros[i+1]){
				aux=numeros[i];
				numeros[i]=numeros[i+1];
				numeros[i+1]=aux;		
			}
		}
	}
}
int main(){
 
    int i,n;
    float * numeros;
    
    scanf("%d",&n);
    
    numeros=(float *) malloc(sizeof(float)*n);
    
    for(i=0;i<n;i++) scanf("%f",&numeros[i]);
    
    bubbleSort(numeros,n);
    
    for(i=0;i<n;i++) printf("%.2f\n",numeros[i]);
 
     free(numeros);
 
    return 0;
}
