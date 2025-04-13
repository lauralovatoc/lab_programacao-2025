/*Função para calcular a somatória de N termos. S = 1 + 2 + 3 + ... + N
a. Com dois argumentos na função
b. Com 1 argumento na função
*/

#include<stdio.h>

int sum = 0;

void somatorio(int num){
    if(num<0){
        return;
    }
    sum+=num;
    somatorio(num-1);
}

int main(){
    int N;
    printf("Digite um numero N de termos:\n");
    scanf("%d",&N);

    somatorio(N);
    printf("%d ", sum);
}
