/*
Altere a função anterior, para que retorne -1 caso o arquivo contenha algo que não é interpretado como um número. Para reconhecer 
essa situação, use o retorno de fscanf e de feof (o fscanf diz que não consegue realizar a conversão mas o feof diz que o arquivo não terminou).
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
            printf("Leitura indesejada");
            printf("\nForam lidos %d numeros\n",cont);
            return -1; //acaba ao ler algo que nao seja inteiro
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
