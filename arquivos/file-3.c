/*
Faça uma função que recebe um nome de arquivo, um tamanho de vetor e um vetor de inteiros desse tamanho, e lê os inteiros que estão nesse 
arquivo para dentro do vetor. A função não deve ler mais inteiros que cabem no vetor, e deve retornar o número de inteiros que foram 
colocados no vetor. Não esqueça de fechar o arquivo.
*/

#include<stdio.h>
#include<string.h>

void imp_vetor(int tam, int vetor[tam]){
    for(int i=0;i<tam;i++){
        printf("%d ",vetor[i]);
    }
}

//vai retornas a quantidade de numeros alocados
void alocar_inteiros_vetor(int tam, int vetor[tam], char arquivo[], int *num_alocados){
    FILE *arq;
    int i; //vai representar a quantidade de numeros alocados

    arq=fopen(arquivo, "r");

    if(arq==NULL){
        printf("Nao foi possivel abrir o arquivo '%s' para leitura\n", arquivo);
        return;
    }

    for(i=0;i<tam;i++){
        int num;

        if(fscanf(arq, "%d", &num)==1){
            vetor[i]=num;
        }else if(fscanf(arq,"%d", &num)==EOF){
            //evitar lixo no vetor, mantem o numero zerado
            for(int j=i;j<tam;j++){
                vetor[j]=0;
            }
            break;
        }else {
            fscanf(arq,"%*s");
            i--;
        }
    }

    *num_alocados = i;
    fclose(arq);
}

int main(int argc, char *argv[]){
    if(argc<2){
        printf("Quantidade minima de parametros nao foi atingida");
        return -1;
    }

    char arquivo[100];
    strcpy(arquivo, argv[1]);

    int num_alocados;

    int N;
    printf("Digite um numero de termos para o vetor: ");
    scanf("%d",&N);

    int vetor[N];

    alocar_inteiros_vetor(N,vetor,arquivo,&num_alocados);

    printf("\n%d numeros foram alocados", num_alocados);
    printf("\nO vetor com os numeros alocados:\n");
    imp_vetor(N, vetor);
}