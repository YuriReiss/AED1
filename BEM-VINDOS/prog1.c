#include <stdio.h>
 
int main(){
 
    int i,qnt,ano;
        
    scanf("%d",&qnt);
        
    for(i=0;i<qnt;i++){
        scanf("%d",&ano);
        if(ano%4==0 && ano%100!=0) printf("S\n");
        else if(ano%400==0 && ano%100==0) printf("S\n");
        else printf("N\n");
    }
 
    return 0;
}
