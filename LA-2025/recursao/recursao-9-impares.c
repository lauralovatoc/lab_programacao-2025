/*
Função para calcular:
a. S = 5*1 + 4*2 + 3*3 (para N impar)
b. S = 6*1 + 5*2 + 4*3 (para N par)
*/

#include<stdio.h>

int calcular(int num, int N){
    int produto;

    if(num==N){
        return num*num;
    }

    produto = num * N + calcular(num+1, N-1);

    return produto;
}

int main(){
    int N;
    printf("Digite um numero impar: ");
    scanf("%d",&N);

    int result = calcular(0,N+1);
    printf("Resultado: %d", result);
}
