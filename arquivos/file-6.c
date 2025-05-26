/*
Faça um programa que lê dois vetores de dois arquivos, produz um terceiro com os valores comuns, escreve na tela o conteúdo dos 3 vetores e 
grava em um terceiro arquivo o vetor calculado. O programa deve usar as funções dos exercícios 5, 6, 7, 8.
*/

#include<stdio.h>
#include<string.h>

#define tam_vetor 100

void gravar_interseccao(){

}

void vetor_de_arquivos(){

}

void verificar_termos_iguais(int tam_1, int vetor_1[tam_1], int tam_2, int vetor_2[tam_2]){

}

void alocar_nums(char arquivo[], int vetor[]){ //le um vetor de um arquivo e armazena ele
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
                return;
            } else{
                printf("O valor lido nao corresponde a um inteiro");
                return;
            }

        }
    } else{
        printf("O primeiro numero nao representa um tamanho");
        return -1;
    }

    fclose(arq);
}

int main(int argc, char *argv[]){
    if(argc<3){
        printf("Quantidade minima de parametros nao foi atingida");
        return -1;
    }

    char arquivo_1[tam_vetor];
    strcpy(arquivo_1, argv[1]);
    char arquivo_2[tam_vetor];
    strcpy(arquivo_2, argv[2]);

    int vet1[tam_vetor], vet2[tam_vetor];
    alocar_nums(arquivo_1, vet1);
    alocar_nums(arquivo_2, vet2);

}