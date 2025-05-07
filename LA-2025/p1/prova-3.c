/*Faça um programa para ler 10 números inteiros maiores que 2. O programa deve dizer se cada um desses números pode ser formado pela somatória dos M
primeiros números primos. A sequencia de números primos é: 2, 3, 5, 7, 11, 13, .... Utilize várias funções para organizar o código
*/

#include<stdio.h>
#include<stdbool.h>

//retorna true se o numero for primo
bool primo(int num){
    int cont=1, sum=0;

     while(cont<num){
        if(num%cont==0){
            sum += cont;
        }
        cont++;
    }

    if(sum==1){
        return true;
    }

    return false;

}

//retorna a soma dos N primeiros numeros primos
int soma_primos(int N){
    int sum=0;
    for(int i=2;i<N;i++){
        if(primo(i)){
            sum+=i;
        }
    }
    return sum;
}

bool verifica(int num){
    for(int i=2;i<num;i++){
        if(num==soma_primos(i)){
            return true;
        }
    }
    return false;
}

int main(){
    int N=10, cont=0;
    int num;

    //receber N numeros maiores que 2
    do{

        printf("Digite um numero:");
        scanf("%d",&num);

        if(num>2){
            cont++;

            if(verifica(num)){
                printf("\n\tPODE ser formado pela somatoria de N primeiros numeros primos\n\n");
            } else{
                 printf("\n\tNAO\n\n");
            }

        }

    }while(cont<N);
}
