//Função repetido(vetor[], tam) que retorna 1 se existem algum valor repetido dentro de vetor. Deve
//retornar 0 caso contrário.

#include<stdio.h>
#include<stdbool.h>

bool repetido(int vetor[], int tam){
    for(int i=0;i<tam;i++){
        int num= vetor[i];
        for (int j=i+1;j<tam;j++){
            if(num==vetor[j]){
                return true;
            }
        }

    }
    return false;
}

int main(){
    int N,valor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d",&N);

    printf("Digite %d termos: ",N);

    int vetor[N];

    for(int i=0;i<N;i++){
    //inicializar vetor
        scanf("%d", &vetor[i]);
    }

    if(repetido(vetor,N)){
        printf("Existem valores repetidos");
    } else{
        printf("Nao existem valores repetidos");
    }
}
