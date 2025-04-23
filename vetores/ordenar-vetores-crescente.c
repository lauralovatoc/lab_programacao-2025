//ordenar - crescente

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

int index_maior(int tam, int vetor[tam]){
    int maior = vetor[0];
    int i_maior = 0;

    for(int i=1;i<tam;i++){
        if(vetor[i]> maior){
            maior = vetor[i];
            i_maior = i;
        }
    }

    return i_maior;
}

void alocar(int tam, int vetor[tam],int origem , int destino){
    int aux = vetor[origem];
    vetor[origem] = vetor[destino];
    vetor[destino] = aux;
}

void ordenar_vetor(int tam, int vetor[tam]){
    int last = tam-1;
    for(int i=0;i<tam-1;i++){
        int maior = index_maior(last, vetor);
        alocar(tam, vetor, maior,last);
        last--;
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

    ordenar_vetor(N, vetor);

    printar_vetor(N, vetor);
}
