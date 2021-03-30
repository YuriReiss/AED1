#include <stdio.h>

void primos(int N2,int N1,int cont){
	
	int i,contLocal=0;

	if(N2<N1){
		printf("%d\n",cont);
		return;
	}
	for(i=2;i<=N2/2;i++) if(N2%i==0) contLocal++;
	if(contLocal==0)cont++;
	primos(N2-1,N1,cont);
	if(contLocal==0) printf("%d ",N2);
}

int main(){
	
	int N1,N2;
	scanf("%d%d",&N1,&N2);
	primos(N2,N1,0);	
	return 0;
}
