//Função para calcular o número de repetições de cada elemento do vetor de inteiros.

#include<stdio.h>

int calcular_repeticoes(int vetor[], int tam, int index){
    int cont = 0;
    int num = vetor[index];
    for(int i=0;i<tam;i++){
        if(num==vetor[i]){
            cont++;
        }
    }
    return cont;
}

int main(){
    int N, index;

    printf("Digite um tamanho para o vetor: ");
    scanf("%d",&N);

    int vetor[N];

    printf("Digite %d termos: ", N);

    //inicializando o vetor
    for(int i=0;i<N;i++){
        scanf("%d",&vetor[i]);
    }

    printf("Qual a posicao do valor que deseja ser contado? ");
    scanf("%d",&index);

    int contador = calcular_repeticoes(vetor, N, index);
    printf("\n\tO valor na posicao %d aparece %d veze(s)", index, contador);
}
