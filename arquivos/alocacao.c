/*
Faça uma função que recebe o nome de um arquivo contendo valores float e retorna um vetor dinamicamente alocado preenchido com os números 
contidos no arquivo. A função deve também retornar o tamanho do vetor. O número de valores no arquivo está no início do arquivo. Por exemplo, 
se o arquivo contém os dados "7 14.5 13", o conteúdo do arquivo seria "3 7 14.5 13".
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


float* aloca_vetor(char arquivo[], int *tam){ //retorna o tamanho do vetor (return tam) e retorna a referencia do vetor
    FILE *arq;
    arq = fopen(arquivo, "r");
    int cont = 0 ; //contar quantos valores existem no arquivo --> para calcular quanto de memoria será necessaria

    if(arq==NULL){
        printf("Nao foi possivel abrir o arquivo '%s' para leitura\n", arquivo);
        fclose(arq);
        return NULL;
    }

    /*calcular o tamanho do aquivo*/
    if(fscanf(arq, "%d", &*tam)!=1){
        printf("O primeiro valor no arquivo nao representa o tamanho de um vetor\n");
        fclose(arq);
        return NULL;
    }

    if(*tam == -1){
        printf("Ocorreu um erro em seu arquivo");
        fclose(arq);
        return NULL;
    }

    /*alocar memoria*/
    float *vetor = malloc((*tam) * sizeof(float));

    if(vetor==NULL){
        printf("Memoria insuficiente");
        fclose(arq);
        return NULL;
    }


    for(int i=0;i<*tam;i++){
        if(fscanf(arq, "%f", &vetor[i])!=1){
            if(fscanf(arq, "%f", &vetor[i])!=EOF){
                printf("Erro ao ler o valor %d do arquivo %s\n", i + 1, arquivo);
                fclose(arq);
                return NULL;
            }
            break;
        }
    }
    

    fclose(arq);
    return vetor;
}

int main(int argc, char *argv[]){
    if(argc<2){
        printf("Quantidade minima de parametros nao foi atingida");
        return -1;
    }

    char nome_arquivo[100];
    strcpy(nome_arquivo, argv[1]);

    int tam;

    float *vetor = aloca_vetor(nome_arquivo, &tam);

    if(vetor == NULL){
        printf("\nNao foi possivel operar com o arquivo %s", nome_arquivo);
        free(vetor);
        exit(0);
    }

    printf("\n\tVetor:");
    for(int i=0;i<tam;i++){
        printf("%.2f ", vetor[i]);
    }

    free(vetor);
}