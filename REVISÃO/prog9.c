#include <stdio.h>
#define PI 3.1415

int main(){

	int qnt,i;
	float R,r,a,b,B,H;
	char figura;

	scanf("%d",&qnt);

	for(i=0;i<qnt;i++){
		scanf(" %c",&figura);
		
		if(figura=='C'){
			scanf("%f",&R);
			printf("CIRCULO %.3f\n",PI*R*R);
		}else if(figura=='E'){
			scanf("%f %f",&R,&r);
			printf("ELIPSE %.3f\n",PI*R*r);
		}else if(figura=='R'){
			scanf("%f %f",&a,&b);
			printf("RETANGULO %.3f\n",a*b);
		}else if(figura=='T'){
			scanf("%f %f %f",&B,&b,&H);
			printf("TRAPEZIO %.3f\n", ((B+b)*H)/2);
		}
	}
	return 0;
}
