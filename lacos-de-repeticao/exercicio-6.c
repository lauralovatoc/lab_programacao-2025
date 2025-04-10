//Faça uma função que imprime a tabuada do número recebido em argumento, no seguinte formato (caso receba 2 como argumento):
#include<stdio.h>

void imprime_tabuada(int n){
    int cont=1;
    printf("\tTabuada do %d\n", n);
    while(cont<=9){
       printf("\t%dx%d = %2d\n", n, cont, n*cont);
       cont++;
   }
}

int main(){
   int num;
   
   printf("Digite um numero de 1 a 9:\n");
   scanf("%d",&num);
   
   imprime_tabuada(num);
}
