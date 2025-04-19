//Função procura(vetor[], valor, tam) que retorna 1 se valor é igual a algum elemento de vetor. Deve
//retornar 0 caso contrário. O parâmetro tam representa o tamanho do vetor

#include<stdio.h>
#include<stdbool.h>

bool procura(int vetor[],int valor,int tam){
    for(int i=0;i<tam;i++){
        if(vetor[i]==valor){
            return true;
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

    printf("Digite o valor a ser encontrado: ");
    scanf("%d",&valor);


    if(procura(vetor,valor, N)){

        printf("O valor %d foi encontrado", valor);
    } else {
        printf("O valor %d nao foi encontrado", valor);
    }

}
