//Função F = (1*2*3*4*5*6*7*8*...*N) – N – (N–2) – ... – 6 – 4 – 2
#include<stdio.h>

int pares_negativos = 0;

int funcao(int num){
    int result;

    if(num==1){
        return num;
    }

    //subtrair numeros pares de N termos
    if(num%2==0){
        pares_negativos += num;
    }

    //fatorial de N termos
    result = num * funcao(num-1);

    return result;


}

int main(){
    int N;
    printf("Digite um numero qualquer: ");
    scanf("%d",&N);

    int resultado  = funcao(N) - pares_negativos;

    printf("\n\tO resultado eh: %d",resultado);
}
