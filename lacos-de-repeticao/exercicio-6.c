//Faça uma função que imprime a tabuada do número recebido em argumento, no seguinte formato (caso receba 2 como argumento):
#include<stdio.h>
#include<stdlib.h>

int main(){
   int num, cont=1;
   
   printf("Digite um numero de 1 a 9:\n");
   scanf("%d",&num);
   
   printf("\tTabuada do %d\n", num);
   while(cont<=9){
       printf("\t%dx%d = %2d\n", num, cont, num*cont);
       cont++;
   }
}
