/*
Função para o cálculo do fatorial de um número, em várias versões:
a. F = 5*4*3*2*1 (multiplicação após retorno da função)
b. F = 1*2*3*4*5
*/

#include<stdio.h>

int fatorial(int num, int N){
    int fat;
    if(num==N){
        return num;
    }
    fat = num*fatorial(num+1, N);
    return fat;

}

int main(){
    int N;

    printf("Digite o numero para o fatorial: ");
    scanf("%d", &N);

    int result = fatorial(1,N);
    printf("%d", result);
}
