//encontrar o maior e menor valor de 5 números lidos pelo usuário

#include<stdio.h>

int main(){
    int vetor[5], maior, menor;

    printf("Digite 10 numeros para um vetor: ");

    for(int i=0;i<5;i++){
    //inicializando vetor
        scanf("%d",&vetor[i]);
    }

    maior = vetor[0];
    menor = vetor[0];

    for(int i=0; i<5;i++){
        if(vetor[i]>maior){
            maior=vetor[i];
        }
        if(vetor[i]<menor){
            menor=vetor[i];
        }
    }

    printf("\n\tMaior: %d\n\tMenor: %d", maior, menor);
}
