//ordenar vetores

#include<stdio.h>

void ordenar_crescente(int vetor[], int tam){
    int aux;
    for(int i=0;i<tam-1;i++){
        for(int j=0;j<tam-i-1;j++){
            if(vetor[j]>vetor[j+1]){
                aux=vetor[j];
                vetor[j]=vetor[j+1];
                vetor[j+1]=aux;
            }
        }
    }

    for(int i=0;i<tam;i++){
        printf("%d ",vetor[i]);
    }
}


int main(){
    int N;

    printf("Digite uma quantidade de termos para um vetor: ");
    scanf("%d",&N);

    int vetor[N];

    //inicializando os dois vetores
    printf("Digite %d valores para o primeiro vetor: ", N);
    for(int i=0;i<N;i++){
        scanf("%d",&vetor[i]);
    }

    printf("Ordenados em ordem crescente: ");
    ordenar_crescente(vetor, N);
}
