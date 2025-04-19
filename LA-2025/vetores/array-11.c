//Dado um vetor de inteiros não ordenado, faça uma função que retorne o valor mais próximo de um número fornecido pelo usuário

#include<stdio.h>

int proximo(int vetor[], int tam, int num){
    unsigned int menor_dif =  vetor[0]-num, dif;
    int numero_aproximado = vetor[0];

    for(int i=0;i<tam;i++){
        dif = vetor[i]- num;

        if(dif<menor_dif){
            menor_dif = dif;
            numero_aproximado =  vetor[i];
        }
    }

    return numero_aproximado;
}

int main(){
    int N, num, aprox;

    printf("Digite o tamanho de vetores: ");
    scanf("%d",&N);

    int vetor[N];

    printf("Digtie %d termos: ",N);
    //inicializar
    for(int i=0;i<N;i++){
        scanf("%d",&vetor[i]);
    }

    printf("Digite um numero: ");
    scanf("%d",&num);

    aprox = proximo(vetor, N, num);
    printf("O valor mais proximo a %d eh %d", num, aprox);
}
