/*
Um arquivo contém dados correspondentes a um vetor de inteiros, no seguinte formato:
- o primeiro inteiro é o tamanho do vetor (o número de valores que ele contém)
-os valores seguintes são os valores em cada posição do vetor, em ordem de índice. 

O tamanho do vetor em um arquivo desses está sempre entre 1 e 100, inclusive. Faça uma função que recebe o nome de um arquivo que está 
nesse formato e um vetor onde cabem 100 inteiros, lê os valores do arquivo para o vetor e retorna o tamanho do vetor lido 
(o número de valores que foram colocados no vetor). 

A função deve retornar um número negativo em caso de erro (não conseguiu acessar o arquivo ou o conteúdo do arquivo não está de acordo com o esperado).
*/

#include<stdio.h>
#include<string.h>

#define tam_vetor 100

void imp_vetor(int vetor[]){
    for(int i=0;i<tam_vetor;i++){
        printf("%d ",vetor[i]);
    }
}

int alocar_nums(char arquivo[], int vetor[]){
    FILE *arq;
    arq = fopen(arquivo, "r");

    if(arq == NULL){
        printf("Nao foi possivel ler este arquivo");
        return -1;
    }

    int tamanho;
    if(fscanf(arq, "%d", &tamanho)==1){
        for(int i=0;i<tamanho;i++){
            int num;

            if(i>=tam_vetor){
                break;
            }

            if(fscanf(arq, "%d", &num)==1){
                vetor[i] = num;
            } else if(fscanf(arq, "%d", &num)==EOF){
                for(int j=i;j<tamanho;j++){
                    vetor[j]=0;
                }
                break;
            } else{
                printf("O valor lido nao corresponde a um inteiro");
                return -1;
            }

        }
    } else{
        printf("O primeiro numero nao representa um tamanho");
        return -1;
    }

    fclose(arq);
    return tamanho;
}

int main(int argc, char *argv[]){
    if(argc<2){
        printf("Quantidade minima de parametros nao foi atingida");
        return -1;
    }

    char arquivo[100];
    strcpy(arquivo, argv[1]);

    int vetor[tam_vetor];
    int tamanho = alocar_nums(arquivo, vetor);
    //numero positivo: 1 = sucesso
    if(tamanho>0){
        printf("O vetor foi inicializado com sucesso, tamanho: %d", tamanho);
    } 

    printf("\nVetor:");
    imp_vetor(vetor);
}