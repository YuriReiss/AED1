#include <stdio.h>
#include <stdlib.h>

int f (int v [], int n);

int main(){

	int * v,i,n;

	scanf("%d",&n);	

	v= (int *) malloc(sizeof(int)*n);

	for(i=0;i<n;i++) scanf("%d",&v[i]);

	n=f(v,n);

	for(i=0;i<n;i++) printf("%d ",v[i]);

	return 0;
}

int f (int v [], int n) {

	int i,j;

	for(i=0;i<n;i++){
		if(v[i]==0){
			for(j=i;j<n-1;j++){
				v[j]=v[j+1];
			}
			n--;
			i--;
		}
	}
	return n;
}
