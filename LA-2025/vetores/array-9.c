//Dado um vetor com números ordenados de forma não decrescente, faça uma função que imprime
//somente os números que não sejam repetidos

#include<stdio.h>

void retirar_repeticoes(int vetor[], int tam){
    int cont=0;
    for(int i=0;i<tam;i++){
        int num= vetor[i];
        for(int j=0;j<tam;j++){
            if(num==vetor[j]){
                cont++;
            }
        }
        if(cont==1){
            printf("%d ", vetor[i]);
        }
        cont=0;
    }
}

int main(){
    int N;

    printf("Digite um tamanho para o vetor: ");
    scanf("%d",&N);

    int vetor[N];

    printf("Digite %d valores para o vetor: ", N);

    //inicializando o vetor
    for(int i=0;i<N;i++){
        scanf("%d",&vetor[i]);
    }

    printf("Vetor sem repeticoes de valor: ");
    retirar_repeticoes(vetor, N);

}
