//encontrar o maior valor em um array de 10 numeros

#include<stdio.h>

int main(){
    int vetor[10], maior;

    printf("Digite 10 numeros para um vetor: ");

    for(int i=0;i<10;i++){
    //inicializando vetor
        scanf("%d",&vetor[i]);
    }

    maior = vetor[0];

    for(int i =0;i<10;i++){
    //encontrando o maior numero
        if(vetor[i]>maior){
            maior = vetor[i];
        }
    }

    printf("\n\tO maior numero do vetor e: %d", maior);
}
