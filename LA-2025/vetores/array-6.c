//Fazer troca de posição de elementos de um vetor usando uma variável auxiliar. As posições origem e
//destino devem ser lidas

#include<stdio.h>

int main(){
    int N, origem, destino;

    printf("Digite o tamanho do vetor: ");
    scanf("%d",&N);

    int vetor[N];

    printf("Digite %d termos: ",N);

    for(int i=0;i<N;i++){
    //inicializando
        scanf("%d",&vetor[i]);
    }

    printf("Digite a posicao de origem: ");
    scanf("%d",&origem);
    printf("Digite a posicao d destino: ");
    scanf("%d",&destino);

    int aux = vetor[origem];
    vetor[origem]=vetor[destino];
    vetor[destino]=aux;

    for(int i=0;i<N;i++){
        printf("%d", vetor[i]);
    }

}
