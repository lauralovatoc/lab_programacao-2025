/*
Fa�a uma fun��o que recebe o nome de um arquivo e retorna quantos n�meros inteiros existem nesse arquivo. A fun��o deve abrir o arquivo, ler os diversos n�meros,
contando quantos s�o, at� que o arquivo acabe, e fechar o arquivo.
*/

#include<stdio.h>
#include<string.h>

int conta_numeros(char arquivo[]){
    FILE *arq;
    int cont = 0;

    arq = fopen(arquivo, "r");

    if (arq == NULL) {
        printf("Nao foi possivel abrir o arquivo '%s' para leitura\n", arquivo);
        return -1;
    }

    for(;;){
        int num;
    
        if (fscanf(arq, "%d", &num) == 1) {
            cont++;
        } else if(fscanf(arq, "%d", &num)==EOF){
            break;
        }else {
            // descarta leitura
            fscanf(arq, "%*s");
        }

    }

    fclose(arq);
    return cont;
}

int main(int argc, char *argv[]){
    if(argc<2){
        printf("Quantidade minima de parametros nao foi atingida");
        return -1;
    }

    char nome[100];
    strcpy(nome, argv[1]);

    int nums;

    nums = conta_numeros(nome);

    if(nums!=-1)
        printf("\nNesse arquivo, existem %d numeros inteiros!",nums);
}
