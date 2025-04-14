/*Função para calcular a somatória de N termos. S = 1 + 2 + 3 + ... + N
a. Com dois argumentos na função
b. Com 1 argumento na função
*/

#include<stdio.h>

int somatorio(int num){
    int sum;
    if(num==0){
        return num;
    }
    sum = num + somatorio(num-1);
    return sum;
}

int main(){
    int N;
    printf("Digite um numero N de termos:\n");
    scanf("%d",&N);

    int sum = somatorio(N);
    printf("%d ", sum);
}
