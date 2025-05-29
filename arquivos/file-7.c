/*
Faça um programa para corrigir provas do vestibular.

 1- Ele deve ler um arquivo chamado "gabarito", que contém o gabarito da prova, em duas linhas: na primeira linha tem um inteiro com o 
 número "n" de questões da prova, e a segunda tem "n" letras, correspondentes a resposta certa de cada questão. A resposta pode ser uma 
 letra entre A e E, ou X, para indicar que a questão foi anulada.

 2- O segundo arquivo, chamado "provas" contém uma linha para cada candidato, com "n" letras, seguidas de um espaço, seguido de até 40 caracteres 
com o nome do candidato. Cada um dos "n" caracteres pode ser A a E ou X, para uma resposta inválida.

 3- O programa deve gravar um terceiro arquivo, "resultados", contendo uma linha por candidato, cada linha contendo o número de acertos, 
seguido de um espaço, seguido do nome do candidato.

Uma questão que tenha X no gabarito não deve ser considerada correta para nenhum candidato; uma questão que tenha X na resposta deve ser 
considerada errada.

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

bool caractere_valido(char c){
    c = toupper(c);
    if(c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'X')
        return true;

    return false;
}

char* ler_gabarito(char arquivo[],int  *num_questoes){
    FILE *arq;
    arq = fopen(arquivo, "r");

    if(arq==NULL){
        printf("Nao foi possivel ler o arquivo %s\n", arquivo);
        fclose(arq);
        return NULL;
    }

    /*extraindo o numero de questoes no gabarito*/
    if(fscanf(arq, "%d", &*num_questoes)!=1){
        printf("O arquivo nao e compativel com o modelo indicado\n");
        fclose(arq);
        return NULL;
    }

    char *gabarito = malloc((*num_questoes) * sizeof(char));

    /*lendo gabarito*/
    for(int i=0;i<*num_questoes;i++){
        int leitura = fscanf(arq, " %c", &gabarito[i]);
        if(leitura==1){

            if(caractere_valido(gabarito[i])==false){
                printf("Caractere invalido\n");
                fclose(arq);
                free(gabarito);
                return NULL;
            }
        } else if(leitura!=1){
            if(leitura!=EOF){
                printf("Erro ao ler o valor %d do arquivo %s\n", i + 1, arquivo);
                fclose(arq);
                return NULL;
            }
            break;
        }
    }
    fclose(arq);
    return gabarito;
}

int contar_linhas(FILE* arquivo) {
    int linhas = 0;
    char c;
    while ((c = fgetc(arquivo)) != EOF) {
        if (c == '\n') {
            linhas++;
        }
    }
    return linhas;
}

 void gerar_resultados_provas(char arquivo_provas[], int num_questoes, char *gabarito){
    FILE *arq_conta_linhas= fopen(arquivo_provas, "r");
    int num_alunos = 0;
    char c;
    while ((c = fgetc(arq_conta_linhas)) != EOF) {
        if (c == '\n') {
            num_alunos++;
        }
    }

    fclose(arq_conta_linhas);


    FILE *arq_prova = fopen(arquivo_provas, "r");
    FILE *arq_resultados = fopen("resultados.txt", "w");

    if(arq_resultados==NULL || arq_prova==NULL){
        fclose(arq_prova);
        fclose(arq_resultados);
        printf("Nao foi possivel abrir os arquivos\n");
        return;
    }

    typedef struct{
            char respostas[num_questoes];
            char nome[100];
            int pontuacao;
    }aluno;

    aluno alunos[num_alunos];

    //ler arquivo
    for(int j=0;j<num_alunos;j++){
        alunos[j].pontuacao = 0;

        /*extrair resultado do alunos[j]*/
        for(int i=0;i<num_questoes;i++){
            int leitura = fscanf(arq_prova, " %c", &alunos[j].respostas[i]);
            
            if(leitura==1){
                if(!caractere_valido(alunos[j].respostas[i])){
                    printf("Caractere invalido\n");
                    fclose(arq_prova);
                    fclose(arq_resultados);
                    return;
                } else if((toupper(alunos[j].respostas[i]) == toupper(gabarito[i]))&& toupper(gabarito[i])!='X' && toupper(alunos[j].respostas[i]) != 'X'){
                    alunos[j].pontuacao++;
                }

            } else if(alunos[j].respostas[i] != '\0' && alunos[j].respostas[i] != '\n' && alunos[j].respostas[i] != ' '){
                printf("O arquivo nao segue o padrao indicado\n");
                fclose(arq_prova);
                fclose(arq_resultados);
                return;
            }
        }

        /*extrair nome do alunos[j]*/
        fgets(alunos[j].nome, sizeof(alunos[j].nome), arq_prova);
        alunos[j].nome[strcspn(alunos[j].nome, "\n")] = '\0'; // remove \n

    }

    /*imprimir resultados no arquivo gerado (resultados.txt)*/
    for(int i=0;i<num_alunos;i++){
        fprintf(arq_resultados, "%d %s\n", alunos[i].pontuacao, alunos[i].nome);
    }
    
    /*fechar arquivos*/
    fclose(arq_prova);
    fclose(arq_resultados);

}

int main(int argc, char *argv[]){
    //o primeiro arquivo enviado deve ser "gabarito", o segundo "provas"
    if(argc<3){
        printf("A quantidade minima de parametros nao foi atingida\n");
        return -1;
    }

    int num_questoes;

    char arquivo_gabarito[100];
    strcpy(arquivo_gabarito, argv[1]);

    char *gabarito = ler_gabarito(arquivo_gabarito,&num_questoes);//é um vetor indicado por ponteiros

    if(gabarito==NULL){
        printf("Ocorreu algum problema na leitura do arquivo %s\n", arquivo_gabarito);
        exit(0);
    }

    char arquivo_provas[100];
    strcpy(arquivo_provas,argv[2]);

    gerar_resultados_provas(arquivo_provas,num_questoes, gabarito);

    free(gabarito);

}