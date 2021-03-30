#include <stdio.h>
#include <stdio.h>

int fibonacci(int n, int numero1,int numero2){
	
	if(n==0) return numero1;
	fibonacci(n-1,numero1+numero2,numero1);
}

int main(){

	int n;
	scanf("%d",&n);

	if(n==1 || n==2) printf("1\n");
	else printf("%d\n",fibonacci(n-2,1,1));

	return 0;
}
