/*
*Faça uma função que recebe um nome de arquivo, um tamanho de vetor e um vetor de inteiros desse tamanho, e escreve esses valores no arquivo, 
um por linha. A função deve retornar um bool informando se a gravação deu certo.
*/

#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

bool gravar_arquivo(int tam, int vetor[tam], char arquivo[]){
    FILE *arq;
    arq = fopen(arquivo, "w");

    if (arq == NULL) {
        printf("Nao foi possivel abrir o arquivo '%s' para leitura\n", arquivo);
        return false;
    }

    for(int i=0;i<tam;i++){
        fprintf(arq, "%d\n", vetor[i]);
    }
    fclose(arq);
    return true;
}

void inicializar_vetor(int tam, int vetor[tam]){
    srand(time(NULL));
    for(int i=0;i<tam;i++){
        vetor[i]= rand() % 10;
    }
}

int main(int argc, char *argv[]){
    if (argc<2){
        printf("Quantidade minima de parametros nao foi atingida");
        return -1;
    }

    char arquivo[100];
    strcpy(arquivo, argv[1]);

    int N;
    printf("\nDigite um tamanho para o vetor:");
    scanf("%d",&N);

    int vetor[N];
    inicializar_vetor(N, vetor);

    if(gravar_arquivo(N,vetor,arquivo)){
        printf("Vetor gravado em arquivo com sucesso");
    } else{
        printf("Nao foi possivel gravar o vetor no arquivo");
    }

}