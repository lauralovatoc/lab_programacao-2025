/*
Assumindo-se que se tenha um vetor de inteiros randômicos com tamanho M. Implemente as seguintes funções, sem ordenar o vetor:
a. Mostrar os valores do vetor
b. encontrar o maior valor deste vetor
c. encontrar os dois maiores valores do vetor, com apenas uma leitura do vetor
d. encontrar os N maiores valores do vetor, com a mesma restrição do item anterior. N é fornecido
pelo usuário (NAO FIZ)**
e. Função para calcular a média dos valores do vetor
f. Função para dizer se existem dois valores iguais no vetor
*/

#include<stdio.h>
#include<stdbool.h>

void mostrar_valores(int vetor[], int tam){
    printf("\tValores no vetor: ");
    for(int i=0;i<tam;i++){
        printf("%d ",vetor[i]);
    }
}

int maior_num(int vetor[], int tam){
    int maior = vetor[0];
    for(int i=0;i<tam;i++){
        if(vetor[i]>maior){
            maior = vetor[i];
        }
    }
    return maior;
}

int segundo_maior(int vetor[], int tam){
    int maior = maior_num(vetor, tam);
    int scn_maior = vetor[0];
    for(int i=0;i<tam;i++){
        if(vetor[i]!=maior&&vetor[i]>scn_maior){
            scn_maior = vetor[i];
        }
    }
    return scn_maior;
}

float media(int vetor[], int tam){
    float sum = 0;
    for(int i=0;i<tam;i++){
        sum+=vetor[i];
    }
    return sum/tam;

}

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
    int N;
    printf("Digite um tamanho para o vetor: ");
    scanf("%d",&N);

    int vetor[N];

    printf("Digite %d termos: ",N);
    for(int i=0;i<N;i++){
        scanf("%d",&vetor[i]);
    }

    mostrar_valores(vetor, N);
    printf("\n\tMaior numero: %d", maior_num(vetor, N));
    printf("\n\tSegundo maior numero: %d", segundo_maior(vetor, N));
    printf("\n\tMedia de todos os termos: %.2f", media(vetor, N));
    if(repetido(vetor, N)){
        printf("\n\tExistem numeros repetidos neste vetor");
    } else {
        printf("\n\tNao existem numeros repetidos neste vetor");
    }
}
