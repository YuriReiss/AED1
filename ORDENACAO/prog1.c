#include <stdio.h>
#include <stdlib.h>
 
void selectionSort(int * numeros, int n){
 
    int i,j,aux,min;
 
    for(i=0;i<n-1;i++){
		min=i;
        for(j=i+1;j<n;j++){
            if(numeros[j]<numeros[min]) min=j;
        }
        if(numeros[i]!=numeros[min]){
			aux=numeros[i];
			numeros[i]=numeros[min];
			numeros[min]=aux;
        }
    }
}
 
int main(){
    
        int n, * numeros,i;
        scanf("%d",&n);
            
        numeros=(int *) malloc(sizeof(int)*n);
        
        for(i=0;i<n;i++) scanf("%d",&numeros[i]);
    
        selectionSort(numeros,n);
        
        for(i=0;i<n;i++) printf("%d ",numeros[i]);
 
         free(numeros);
 
        return 0;
}
