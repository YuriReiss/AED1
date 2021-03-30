#include <stdio.h>
 
int main(){
 
    int i,qnt,ano;
        
    scanf("%d",&qnt);
        
    for(i=0;i<qnt;i++){
        scanf("%d",&ano);
		printf("%d ",ano);
        if((ano%4==0 && ano%100!=0) || (ano%100==0 && ano%400==0)) printf("S");
        else printf("N");
		ano++;
		while(!((ano%4==0 && ano%100!=0) || (ano%100==0 && ano%400==0)))ano++;
		printf(" %d\n", ano);
    }
 
    return 0;
}
