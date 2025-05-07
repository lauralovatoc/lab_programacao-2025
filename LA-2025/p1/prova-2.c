//Escreva um algoritmo para calcular e imprimir a soma dos N primeiros termos da seguinte série: 1/2 + 2/8 + 3/32 +.... O valor de N deve ser lido.
//numerador incrementa 1, denominador multiplica por 4

#include<stdio.h>

float soma(int N){
    float numerador=1, denominador=2;
    float soma = numerador/denominador;

    for(int i=1;i<N;i++){
        numerador++;
        denominador *= 4;
        soma += (numerador/denominador);
    }
    return soma;
}

int main(){
    int N;
    printf("Digite um numero de termos: ");
    scanf("%d",&N);

    float resultado = soma(N);
    printf("O resultado eh: %f", resultado);
}
