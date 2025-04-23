//inverter a ordem de um vetor

#include<time.h>
#include <stdio.h>
#include<stdlib.h>

void preencher_vetor(int tam, int vetor[tam]){
    for(int i=0;i<tam;i++){
        vetor[i]=rand() % 100;
    }
}

void printar_vetor(int tam, int vetor[tam]){
    printf("\n\tValores no vetor: ");
    for(int i=0;i<tam;i++){
        printf("%d ", vetor[i]);
    }
}

void inverter_vetor(int tam, int vetor[tam]){
    for(int i=0;i<tam/2;i++){
        int aux = vetor[tam-i-1];
        vetor[tam-i-1]= vetor[i];
        vetor[i]=aux;
        
    }
}

int main()
{
    srand(time(NULL));

    int N;
    printf("Tamanho do vetor: ");
    scanf("%d",&N);

    int vetor[N];

    preencher_vetor(N, vetor);
    printar_vetor(N, vetor);

    inverter_vetor(N, vetor);
    printar_vetor(N, vetor);
}
