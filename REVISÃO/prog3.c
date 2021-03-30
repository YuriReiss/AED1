#include <stdio.h>
#include <math.h>

int main(){

	int maiorNumero,P,Q,R,resultado;
	char C1,C2;
	scanf("%d",&maiorNumero);

	scanf("%d%*c",&P);
	scanf("%c%*c",&C1);
	scanf("%d%*c",&Q);
	scanf("%c%*c",&C2);
	scanf("%d",&R);

	resultado=0;

	if(C1=='*'){
		resultado=P*Q;
		if(C2=='*') resultado*=R;
		else resultado+=R;
	}else{
		if(C2=='*') resultado=Q*R;
		else resultado=Q+R;
		resultado+=P;
	}

	printf("%d ",resultado);

	if(resultado>=(pow(2,maiorNumero)*(-1)) && resultado<=(pow(2,maiorNumero)-1)) printf("OK\n");
	else printf("OVERFLOW\n");
	return 0;
}
