#include<stdio.h>

int main(){
    int N, n1=0, n2=1, cont=2, sum;
    printf("Digite um numero: ");
    scanf("%d",&N);

   if(N==1){
    printf("%d ", n1);
   }else{
    printf("%d ", n1);
    printf("%d ", n2);
   }

   while(cont<N){
        sum = n1+n2;
        printf("%d ", sum);
        n1=n2;
        n2=sum;
        cont++;
   }
}
