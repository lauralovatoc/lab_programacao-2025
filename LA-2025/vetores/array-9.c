//Dado um vetor com n�meros ordenados de forma n�o decrescente, fa�a uma fun��o que imprime
//somente os n�meros que n�o sejam repetidos

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
