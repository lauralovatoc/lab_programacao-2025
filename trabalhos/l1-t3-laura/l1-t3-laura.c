//aluna: Laura Lovato Camponogara (CC1)

#include "janela.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define tam 7
#define arquivo "resultados.txt"

/*Descrição de como cores e etapas vão funcionar:
Serão 5 etapas e a partir da 6ª, todas serão iguais à 5ª
    1 etapa: 4 cores
    2 etapa: 5 cores
    3 etapa: 6 cores
    4 etapa: 7 cores
    5 etapa: 8 cores
*/

cor_t tabuleiro[tam][tam];

//cores do TABULEIRO
cor_t cor_1 = {0.92, 0.7, 0.8, 1.0}; //rosinha
cor_t cor_2 = {0.7, 0.87, 0.7, 1.0}; //verdinho menta
cor_t cor_3 = {0.95, 0.88, 0.45, 1.0}; //amarelinho
cor_t cor_4 = {0.87, 0.86, 0.98, 1.0}; //lilás
cor_t cor_5 = {0.85, 0.98, 0.98, 1.0}; //azulzinho
cor_t cor_6 = {0.97, 0.9, 0.84, 1.0}; //laranjinha
cor_t cor_7 = {0.76, 0.7, 0.96, 1.0}; //lilas + escuro
cor_t cor_8 = {0.72, 0.97, 0.5, 1.0}; //verdinho

//struct que representa o jogo
typedef struct {
    tamanho_t tamanho_janela;
    retangulo_t contorno_janela;
    tecla_t tecla;
    bool fim;
    bool inicio; //obs utilizado apenas no primeiro jogo para sair da tela inicial
    bool possivel;
    bool fechar_programa;

    //para registro:
    int pontos; //pontuação final
    int etapa; // etapa do jogo
    char apelido[30]; //apelido do jogador

    int cont_embaralhadas;

    bool lin; 
    //lin == true : linhas selecionas p/ movimentar
    //lin == false: colunas selecionas p/ movimentar
    
    int col_atual;
    int lin_atual;

    double tempo_inicio; 
    double tempo_na_etapa;
    bool tempo_processado;

    rato_t mouse;
} jogo_t;

//cores basicas para interface
cor_t azul_marinho = {0.13, 0.2, 0.8, 1.0};
cor_t cor_fundo = {0.48, 0.67, 0.88, 1.0};
cor_t branco = {1.0, 1.0, 1.0, 1.0};

retangulo_t fundo = { //retangulo que cobre toda a janela (background)
    .inicio = {0, 0},
    .tamanho = {1500,1500}
};

void grava_arquivo(char **nome, int *etapa, int *pontos, int linhas){
    //grava o resultado final
    FILE *arq = fopen(arquivo, "w");

    if(arq == NULL){
        printf("Noa foi possivel abrir o arquivo");
        fclose(arq);
        return;
    }

    for(int i=0;i<linhas;i++){
        fprintf(arq, "%d %d %s\n", etapa[i], pontos[i], nome[i]);
    }

    fclose(arq);
}

int index_menor(int *pontos,int limite){
    //acha a menor pontuação dentro do vetor e retorna seu endereco
    int menor = pontos[0];
    int i_menor = 0;

    for(int i=1;i<=limite;i++){
        if(pontos[i]< menor){
            menor = pontos[i];
            i_menor = i;
        }
    }
    return i_menor;
}

void trocar_int(int *vet, int origem , int destino){
    //faz processo de trocar para um vetor de inteiros
    int aux = vet[origem];
    vet[origem] = vet[destino];
    vet[destino] = aux;
}

void trocar_string(char **vet, int i, int j) {
    //faz processo de troca para um vetor de strings, considerando strings um vetor de caracteres
    char aux[30];
    strcpy(aux, vet[i]);
    strcpy(vet[i], vet[j]);
    strcpy(vet[j], aux);
}

void ordenar_valores(char **nome, int *etapa, int *pontos, int linhas) {
    //ordenacao: acha o menor valor coloca no final -> acha o proximo menor valor excluindo o ultimo(menor absoluto)
    int ultimo = linhas-1;
    for(int i=0;i<linhas-1;i++){
        //acha o menor numero do vetor pontos e depois aloca todos os vetores igualmente de acordo com nova ordenação
        int idx_menor = index_menor(pontos, ultimo);
        
        trocar_string(nome, idx_menor, ultimo);
        trocar_int(etapa, idx_menor, ultimo);
        trocar_int(pontos, idx_menor, ultimo);

        ultimo--;
    }
}

int contar_linhas_arquivo(){
    FILE *arq = fopen(arquivo, "r");
    int linhas = 0;
    char c;

    if(arq==NULL){
        fclose(arq);
        return -1;
    }

    while ((c = fgetc(arq)) != EOF) {
        if (c == '\n') {
            linhas++;
        }
    }
    fclose(arq);//fecha para liberar o arquivo para a proxima funcao
    return linhas;
}

void leitura_arquivo_resultados(char ***ptr_nome, int **ptr_etapa, int **ptr_pontos, jogo_t *jogo, int *linhas){
    //funcao que le os arquivos que contem os resultados no formato (%d %d %s) -> (etapa pontos nome)
    *linhas = contar_linhas_arquivo();

    //alocar 3 vetores (int int string) com malloc, considerando numero de linhas
    //linhas  + 1 para poder guardar espaço para o jogo atual
    int *etapa = malloc((*linhas + 1) * sizeof(int));
    int *pontos = malloc((*linhas + 1) * sizeof(int));
    char **nome = malloc((*linhas + 1) * sizeof(char*));

    for (int i = 0; i <= *linhas; i++) {
        nome[i] = malloc(30 * sizeof(char)); // Aloca espaço para cada nome --> string de no max 30 char
    }

    FILE *arq = fopen(arquivo, "r");
    if (arq != NULL) {
        for (int i = 0; i < *linhas; i++) {
            int leitura = fscanf(arq, "%d %d %29s", &etapa[i], &pontos[i], nome[i]);//%29s pois um caractere é guardado par /0
            //&nome[i] é errado pois nome é um ponteiro de ponteiro
            if (leitura != 3) {
                printf("Arquivo nao segue o padrao esperado\n");
                fclose(arq);
                return;
            }
        }
        fclose(arq);
    }

    //adiciona os resultados
    etapa[*linhas] = jogo->etapa;
    pontos[*linhas] = jogo->pontos;
    strcpy(nome[*linhas], jogo->apelido);
    (*linhas)++; //atualiza numero de linhas

    //atualiza os ponteiros da função main
    *ptr_etapa = etapa;
    *ptr_pontos = pontos;
    *ptr_nome = nome;
}

cor_t cor_aleatoria(int etapa){
    //seleciona cores aleatorias de acordo com a etapa
    if(etapa>5)
        etapa=5;

    int num = rand() % (etapa+3); //nao pode ser zero
    num++; 

    if(num==1) return cor_1;
    if(num==2) return cor_2;
    if(num==3) return cor_3;
    if(num==4) return cor_4;
    if(num==5) return cor_5;
    if(num==6) return cor_6;
    if(num==7) return cor_7;
    if(num==8) return cor_8;

    return branco;
}

//verifica se um valor cor_t existe na linha lin
bool valor_em_linha(cor_t cor, int lin){
    for(int j=0;j<tam;j++){
        //nao testei opacidade, pois usei todas como 1.0
        if(tabuleiro[lin][j].vermelho == cor.vermelho && tabuleiro[lin][j].verde == cor.verde && tabuleiro[lin][j].azul== cor.azul)
            return true; //o valor cor_t existe nessa linha
    }
    return false;
}

void verifica_jogo(jogo_t *jogo){
    //testa se existe uma cor que tenha pelo menos uma celula em cada linha
    for(int j=0;j<tam;j++){
        for(int i=0;i<tam;i++){
            cor_t cor = tabuleiro[i][j];
            int cont_lin=0;

            for(int lin=0;lin<tam;lin++){
                if(valor_em_linha(cor, lin)){
                   cont_lin++;
                }
            }
            
            //se tiver ao menos uma celula cor em cada linha (cont_lin = tam)
            if(cont_lin == tam){
                jogo->possivel = true;
                return;
            }
        }
    }
    jogo->possivel = false;
}

void embaralha_tabuleiro(jogo_t *jogo){
    //display de cores de forma aleatoria
    while(!jogo->possivel){
        //embaralha ate o jogo ser possivel
        for(int i=0;i<tam;i++){
            for(int j=0;j<tam;j++){
                tabuleiro[i][j] = cor_aleatoria(jogo->etapa);
            }
        }
        verifica_jogo(jogo);
    } 
}

void inicializa_jogo(jogo_t *jogo){
    //default do jogo
    jogo->tamanho_janela =(tamanho_t){ 1300, 1300 };
    jogo->fim = false;    
    jogo->pontos = 0;
    jogo->etapa = 1;
    jogo->lin = true;
    jogo->lin_atual = 0;
    jogo->col_atual =0;
    jogo->possivel = false;
    jogo->tempo_inicio = j_relogio();
    jogo->tempo_processado = false;
    jogo->cont_embaralhadas = 0;
    jogo->fechar_programa = false;
    embaralha_tabuleiro(jogo);
}


void desenha_tela_final(jogo_t *jogo){
    j_retangulo(fundo, 0, cor_fundo, cor_fundo);
    ponto_t texto = {500,300};
    
    //retangulo como "tabela"
    retangulo_t tabela = {
        .inicio = {texto.x - 15, texto.y - 40},
        .tamanho = {300, 150} 
    };

    j_retangulo(tabela, 2, azul_marinho, cor_fundo);

    char nome[40];
    sprintf(nome, "Jogador: %s", jogo->apelido);

    j_seleciona_fonte(NULL, 30);
    j_texto(texto, azul_marinho, nome);

    char pontuacao[40];
    sprintf(pontuacao, "Pontuação: %d", jogo->pontos);

    texto.y += 40;
    j_texto(texto, azul_marinho,pontuacao);

    char etapa[40];
    sprintf(etapa, "Etapa: %d", jogo->etapa);

    texto.y += 40;
    j_texto(texto, azul_marinho, etapa);

    //botao que pergunta ao jogador se ele vai jogar novamente
    retangulo_t botao = {
        .inicio = {500, 650},
        .tamanho = {250,70}
    };

    j_retangulo(botao, 0, azul_marinho, azul_marinho);

    ponto_t botao_texto = {botao.inicio.x + 20, botao.inicio.y + 45};

    j_seleciona_fonte(NULL, 20);
    j_texto(botao_texto, branco, "JOGAR NOVAMENTE");

    //botao para nao jogar mais
    botao.inicio.y += 100;
    j_retangulo(botao,0,azul_marinho,azul_marinho);

    botao_texto.y+=100;
    j_seleciona_fonte(NULL, 20);
    j_texto(botao_texto, branco, "NAO QUERO JOGAR");


    jogo->mouse = j_rato();
    // desenha um cursor na posição do mouse
    circulo_t cursor = { jogo->mouse.posicao, 5 };
    j_circulo(cursor, 3, azul_marinho, azul_marinho);

    //processa mouse
    if(jogo->mouse.clicado[0]){

        if(jogo->mouse.posicao.x>= botao.inicio.x && 
        jogo->mouse.posicao.x <= botao.inicio.x + botao.tamanho.largura &&
        jogo->mouse.posicao.y >= botao.inicio.y -100 &&
        jogo->mouse.posicao.y <= botao.inicio.y + botao.tamanho.altura -100){
            inicializa_jogo(jogo); //jogar de novo
        }

        if(jogo->mouse.posicao.x>= botao.inicio.x && 
        jogo->mouse.posicao.x <= botao.inicio.x + botao.tamanho.largura &&
        jogo->mouse.posicao.y >= botao.inicio.y &&
        jogo->mouse.posicao.y <= botao.inicio.y + botao.tamanho.altura){
            jogo->fechar_programa = true;//nao quero jogar
        }
    }
    j_mostra();
}

void registrar_nome(jogo_t *jogo){
    //armazenar nome do jogador antes da partida começar
    char nome[30]= "\0";
    int tam_nome = 0;

    j_seleciona_fonte(NULL, 20);

    for(;;) {
        j_retangulo(fundo, 0, cor_fundo, cor_fundo);

        ponto_t pos_digiteNome = {500, 250};
        j_texto(pos_digiteNome, azul_marinho, "Digite seu nome: ");

        ponto_t pos_nome = {500, 300};
        j_texto(pos_nome, azul_marinho, nome);
        
        j_mostra();

        //verifica tecla 
        if (j_tem_tecla()) {
            tecla_t t = j_tecla();
        
            if (t==T_ENTER) {
                //enter para completar o nome
                break;
            } else if ((t==T_BACKSPACE || t== T_BS) && tam_nome > 0) {
                //apagar
                tam_nome--; //apaga a "posicao" da letra apagada
                nome[tam_nome] = '\0';

            } else if (t >= 32 && t <= 126 && tam_nome < 100 - 1) { //tamanho do vetor nome[100]
                //caractere valido
                nome[tam_nome] = (char)t;
                tam_nome++;
                nome[tam_nome] = '\0';
            }
        } 
    }

    strcpy(jogo->apelido,nome);
}

void desenha_tela_inicial(jogo_t *jogo){
    //fundo da tela
    jogo->mouse = j_rato();
    j_retangulo(fundo, 0, cor_fundo, cor_fundo);

    //texto principal
    ponto_t pos_texto = {500, 400};
    j_seleciona_fonte(NULL, 40);
    j_texto(pos_texto, azul_marinho, "Vamos jogar!");

    //botao para iniciar jogo
    bool buttonClick = false;
    retangulo_t botao = {
        .inicio = {535, 500},
        .tamanho = {200, 50}
    };

    ponto_t texto_principal = {
        .x = botao.inicio.x + 50,
        .y = botao.inicio.y + botao.tamanho.altura -15
    };

    j_retangulo(botao, 0, azul_marinho, azul_marinho);
    j_seleciona_fonte(NULL, 20);
    j_texto(texto_principal, branco, "JOGAR");

    // desenha um cursor na posição do mouse
    circulo_t cursor = { jogo->mouse.posicao, 5 };//posicao do mouse com raio de 5px
    j_circulo(cursor, 3, azul_marinho, azul_marinho);

    //verifica se o o botao foi clicado
    if(buttonClick == false){

        if(jogo->mouse.clicado[0] && 
        jogo->mouse.posicao.x >= botao.inicio.x && 
        jogo->mouse.posicao.x <= botao.inicio.x + botao.tamanho.largura &&
        jogo->mouse.posicao.y >= botao.inicio.y &&
        jogo->mouse.posicao.y <= botao.inicio.y + botao.tamanho.altura){
            buttonClick=true;
            jogo->inicio = true;
        }      
    }
    j_mostra();
}

//move a linha selecionada
void selecionar_linha(jogo_t *jogo, bool para_cima){
    if(para_cima){
        if(jogo->lin_atual == 0)
            return; //a linha zero nao pode selecionaa uma linha acima
        
        jogo->lin_atual--;

    } else {
        if(jogo->lin_atual == tam-1)
            return; //a ultima linha nao pode selecionar a linha abaixo

        jogo->lin_atual++;
    }
}

//move a coluna 
void selecionar_coluna(jogo_t *jogo, bool para_esquerda){
    if(para_esquerda){
        if(jogo->col_atual == 0)
            return; //a coluna zero nao pode ir pra esquerda
        
        jogo->col_atual--;

    } else {
        if(jogo->col_atual == tam-1)
            return; //a ultima coluna nao pode ir para direita

        jogo->col_atual++;
    }
}

void arrasta_linha(jogo_t *jogo, int desloc){
    //deslocamento +1 : arrasta para direita
    //deslocamento -1 : arrasta para esquerda
    cor_t aux;

    //esquerda
    if(desloc == -1){
        aux = tabuleiro[jogo->lin_atual][0];
        for(int j = 0; j < tam - 1; j++){
            tabuleiro[jogo->lin_atual][j] = tabuleiro[jogo->lin_atual][j + 1];
        }
        tabuleiro[jogo->lin_atual][tam - 1] = aux;
    }

    //direita
    if(desloc==1){
        aux = tabuleiro[jogo->lin_atual][tam-1];
        for(int j=tam-1;j>0;j--){
            tabuleiro[jogo->lin_atual][j]=tabuleiro[jogo->lin_atual][j-1];
        }
        tabuleiro[jogo->lin_atual][0] = aux;
    }
}

bool verifica_celula_branca(int i, int j){
    //verifica se um celula [i][j] é branca
    if(tabuleiro[i][j].vermelho == branco.vermelho && tabuleiro[i][j].verde == branco.verde && tabuleiro[i][j].azul == branco.azul)
        return true;
    
    return false;
}

bool coluna_vazia(int col){
    //indica se a coluna tem todas as celulas brancas
    int conta_brancos = 0;
    for(int i=0;i<tam;i++){
        if(verifica_celula_branca(i,col))
            conta_brancos++;
    }

    if(conta_brancos==tam)
        return true;
    
    return false;
}

bool coluna_completa(int col){
    //indica se a coluna tem todas as linhas de mesma cor
    cor_t cor_coluna = tabuleiro[0][col];

    if(coluna_vazia(col))
        return false;//nao pode considerar uma coluna branca como completa  

    for(int i=1;i<tam;i++){
        if(tabuleiro[i][col].vermelho != cor_coluna.vermelho || tabuleiro[i][col].verde != cor_coluna.verde || tabuleiro[i][col].azul != cor_coluna.azul)
            return false;
    }

    return true;
}

bool coluna_colorida(int col){
    //verifica se a coluna nao tem nenhum buraco branco no meio
    for(int i=0;i<tam;i++){
        if(verifica_celula_branca(i,col))
            return false;
    }
    return true;

}

void arrasta_coluna_pbaixo(int col){
    //perde a lin tam-1 e arrasta as celulas de cima uma unidade para baixo
    for(int i=tam-1;i>0;i--){
        if(verifica_celula_branca(i,col))
            break;
        tabuleiro[i][col]=tabuleiro[i-1][col];
    }
    tabuleiro[0][col]=branco;
}

void move_coluna(jogo_t *jogo, tecla_t t){
    int col = jogo->col_atual;

    if(!coluna_vazia(col)){//coluna atual nao pode estar completa
        int primeira_lin_vazia =-1; //verifica coluna de baixo para cima ate achar um espaco vazio, pega o valor da linha 

        if(t == T_A){
            //move a primeira celula da coluna col para cima da coluna da esquerda
            if (col > 0){
                if(!coluna_colorida(col-1)){

                for(int i=0;i<tam;i++){
                    if(!verifica_celula_branca(i, col-1)){//primeira celula pintada  na coluna vizinha
                        primeira_lin_vazia = i-1;
                        break;
                    }
                }

                if(coluna_vazia(col-1)){
                    tabuleiro[tam-1][col-1]=tabuleiro[tam-1][col];
                }
                tabuleiro[primeira_lin_vazia][col-1] = tabuleiro[tam-1][col];
                arrasta_coluna_pbaixo(col);
                }
            }    
        }

        if(t == T_D){
            //move a primeira celula da coluna col para cima da coluna da direita
            if (col < tam-1){
                if(!coluna_colorida(col+1)){

                for(int i=0;i<tam;i++){
                    if(!verifica_celula_branca(i, col+1)){//primeira celula pintada na coluna vizinha
                        primeira_lin_vazia = i-1;
                        break;
                    }
                }
                if(coluna_vazia(col+1)){
                    tabuleiro[tam-1][col+1]=tabuleiro[tam-1][col];
                }
                tabuleiro[primeira_lin_vazia][col+1] = tabuleiro[tam-1][col];
                arrasta_coluna_pbaixo(col);
                }
            }  
        }
    }
}

void apaga_linha(jogo_t *jogo){
    for(int j=0;j<tam;j++){
        tabuleiro[jogo->lin_atual][j] = branco;
    }
    jogo->pontos-=2;
}

/*
descrição de como as teclas funcionam:

se for linhas:
    T_CIMA = seleciona linha acima
    T_BAIXO = seleciona linha abaixo
    T_ESQUERDA: linha roda pra esquerda
    T_DIREITA: linha roda pra direita
    T_DEL: apaga linha

se for colunas:
    T_ESQUERDA: vai para coluna da esquerda
    T_DIREITA: vai para coluna da direita

    ** para enviar celula de baixo para colunas vizinhas: A(esquerda) ou D(direita)
*/

void processa_teclado(jogo_t *jogo){
    //deve verificar a tecla clicada durante o jogo
    if (j_tem_tecla()) {
        tecla_t t = j_tecla();

        //linhas
        if(jogo->lin==true){
            if(t == T_CIMA){
                selecionar_linha(jogo,true);
            } 

            if(t==T_BAIXO){
                selecionar_linha(jogo, false);
            }

            if(t == T_ESQUERDA){
                //funcao que roda a linha para esquerda
                arrasta_linha(jogo, -1);
            }

            if(t == T_DIREITA){
                //funcao que roda a linha para a direita
                arrasta_linha(jogo,1);
            }

            if(t == T_DEL){
                //apagar linha -> jogador perde 2 pontos
                apaga_linha(jogo);
            }
        }

        //colunas
        if(jogo->lin==false){
            if(t == T_ESQUERDA){
                //passa para a coluna do lado
                selecionar_coluna(jogo, true);
            }

            if(t == T_DIREITA){
                //passa para coluna da direita
                selecionar_coluna(jogo, false);
            }

            if(t == T_A || t == T_D){ //IMPORTANTE: declarei essas teclas na biblioteca
                //passa primeira celula para topo da coluna vizinha
                move_coluna(jogo, t);
            }
        }
    }
}

retangulo_t but_lin = {.inicio = {50, 800},.tamanho = {130, 60}}; //jogo->lin = true
retangulo_t but_col = {.inicio = {200, 800},.tamanho = {130, 60}}; //jogo->lin =false
retangulo_t but_desistir = {.inicio = {800, 800},.tamanho = {130, 60}}; //jogo->fim = true


void processa_mouse(jogo_t *jogo){
//identifica se o jogador clicou em algum dos botoes (linha/coluna/desistir) durante a tela de jogo
    jogo->mouse = j_rato();

    if(jogo->mouse.clicado[0]){

        //botao linhas
        if(jogo->mouse.posicao.x >= but_lin.inicio.x && 
        jogo->mouse.posicao.x <= but_lin.inicio.x + but_lin.tamanho.largura &&
        jogo->mouse.posicao.y >= but_lin.inicio.y &&
        jogo->mouse.posicao.y <= but_lin.inicio.y + but_lin.tamanho.altura)
            jogo->lin = true;

        //botao colunas
        if(jogo->mouse.posicao.x >= but_col.inicio.x && 
        jogo->mouse.posicao.x <= but_col.inicio.x + but_col.tamanho.largura &&
        jogo->mouse.posicao.y >= but_col.inicio.y &&
        jogo->mouse.posicao.y <= but_col.inicio.y + but_col.tamanho.altura)
            jogo->lin = false;

        //botao desistir
        if(jogo->mouse.posicao.x>=but_desistir.inicio.x &&
        jogo->mouse.posicao.x<= but_desistir.inicio.x + but_desistir.tamanho.largura &&
        jogo->mouse.posicao.y>= but_desistir.inicio.y &&
        jogo->mouse.posicao.y<= but_desistir.inicio.y + but_desistir.tamanho.altura)
            jogo->fim = true;
    }
}

void imprime_tabuleiro(jogo_t *jogo){
    //interface grafica do jogo
    retangulo_t celulas_tab = {
        .inicio = {40,40},
        .tamanho = {90,60}
    };

    //desenhar fundo branco
    j_retangulo(fundo, 0, branco, branco);

    int inicio_y = 30;
    int inicio_x = 30;
    int tam_lin_x = 100;
    int tam_lin_y = 70;

    /*LINHA OU COLUNA SELECIONADA*/
    if(jogo->lin){
        //linha 
        retangulo_t selecao = {
            .inicio = {inicio_x, inicio_y + (jogo->lin_atual * tam_lin_y)},
            .tamanho = {tam_lin_x*tam + 10, tam_lin_y + 10} 
        };

        j_retangulo(selecao, 0,azul_marinho,azul_marinho);
    } else {
        //coluna
        retangulo_t selecao ={
            //refazer medidas depois
            .inicio = {inicio_x + (jogo->col_atual * tam_lin_x), inicio_y},
            .tamanho = {tam_lin_x + 10, tam_lin_y*tam + 10}
        };

        j_retangulo(selecao, 0,azul_marinho,azul_marinho);
    }


    int incremento_x = 100;
    int incremento_y = 70;

    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            j_retangulo(celulas_tab, 0, tabuleiro[i][j], tabuleiro[i][j]);
            celulas_tab.inicio.x += incremento_x;
            
        }
        celulas_tab.inicio.y += incremento_y;
        celulas_tab.inicio.x = 40;
    }

    //botao linhas e colunas
    j_retangulo(but_lin,0,azul_marinho, azul_marinho);
    j_retangulo(but_col,0,azul_marinho,azul_marinho);

    ponto_t texto = {.x = but_lin.inicio.x + 30,.y = but_lin.inicio.y + 35};

    j_seleciona_fonte(NULL, 20);
    j_texto(texto, branco, "LINHAS");
    
    texto.x += 140;

    j_seleciona_fonte(NULL, 20);
    j_texto(texto, branco, "COLUNAS");

    //botao desistir
    j_retangulo(but_desistir, 0 , azul_marinho, azul_marinho);

    ponto_t desist = {.x = but_desistir.inicio.x + 20, .y = but_desistir.inicio.y + 35 };
    j_seleciona_fonte(NULL, 20);
    j_texto(desist, branco, "DESISTIR");

    //informações:
    //etapa
    ponto_t etapa = {.x = 1100, .y = 30};
    char str_etapa[20];
    sprintf(str_etapa, "ETAPA: %d", jogo->etapa);
    j_seleciona_fonte(NULL, 20);
    j_texto(etapa, azul_marinho, str_etapa);

    //pontuação
    ponto_t ponts = {.x = 1100, .y = 50};
    char str_ponts[30];
    sprintf(str_ponts, "PONTUAÇÃO: %d", jogo->pontos);
    j_seleciona_fonte(NULL,20);
    j_texto(ponts, azul_marinho, str_ponts);

    //cronometro para acompanhar tempo de jogo em cada etapa
    ponto_t tempo = {.x = 1100, .y = 70};
    char str_tempo[30];
    sprintf(str_tempo, "TEMPO: %.0f s", jogo->tempo_na_etapa);
    j_seleciona_fonte(NULL, 20);
    j_texto(tempo, azul_marinho, str_tempo);

    // desenha um cursor na posição do mouse
    circulo_t cursor = { jogo->mouse.posicao, 5 };//posicao do mouse com raio de 5px
    j_circulo(cursor, 3, azul_marinho, azul_marinho);

    //instruções para o jogador
    ponto_t titulo = {50,600};
    j_seleciona_fonte(NULL,30);
    j_texto(titulo, azul_marinho, "INSTRUÇÕES");

    //LINHAS: 
    j_seleciona_fonte(NULL, 25);
    ponto_t linhas = {50, 650};
    j_texto(linhas, azul_marinho, "Linhas:");

    ponto_t instrucoes = {50, 680};

    j_seleciona_fonte(NULL, 15);
    j_texto(instrucoes, azul_marinho, "• Para mexer nas linhas, clique no botao 'LINHAS'");
    instrucoes.y += 30;
    j_texto(instrucoes, azul_marinho, "• Para seleciona a linha, mexa com as setas ← e →");
    instrucoes.y += 30;
    j_texto(instrucoes, azul_marinho, "• Para arrastar a linha selecionada, mexa com as setas ↑ e ↓");
    instrucoes.y += 30;
    j_texto(instrucoes, azul_marinho, "• Para apagar a linha selecionada, aperte DEL");

    //COLUNAS:
    j_seleciona_fonte(NULL, 25);
    ponto_t colunas = {550, 650};
    j_texto(colunas, azul_marinho, "Colunas:");

    ponto_t instrucoes_2 = {550, 680};
    j_seleciona_fonte(NULL, 15);
    j_texto(instrucoes_2, azul_marinho, "• Para mexer nas colunas, clique no botao 'COLUNAS'");
    instrucoes_2.y += 30;
    j_texto(instrucoes_2, azul_marinho, "• Para adicionar a primeira célula da coluna selecione a coluna do lado com A ou D");

    //OBJETIVO DO JOGO:
    ponto_t objetivo = {800, 200};
    j_seleciona_fonte(NULL, 25);
    j_texto(objetivo, azul_marinho, "REGRAS:");

    j_seleciona_fonte(NULL, 15);
    ponto_t obj = {800,240};
    j_texto(obj, azul_marinho, "• A cada célula retirada será atribuido 1 ponto se ");
    obj.y += 30;
    j_texto(obj, azul_marinho, "estiver na etapa 1, 2 se estiver na etapa 2,...");
    obj.y += 40;
    j_texto(obj, azul_marinho, "• Para passar de etapa: eliminar 50% do tabuleiro em 30s");
    obj.y += 40;
    j_texto(obj, azul_marinho, "• Deletar uma linha faz você perder 2 pontos");
    obj.y += 40;
    j_texto(obj, azul_marinho, "• Ao passar da etapa 1, você ganha 50 pontos,");
    obj.y += 30;
    j_texto(obj, azul_marinho, "ao passar da etapa 2 recebe 100 pontos,...");
    obj.y += 40;
    j_texto(obj, azul_marinho, "• Até a etapa 5, será adicionada uma cor ao passar de etapa");


    j_mostra();
}

void verifica_colunas(jogo_t *jogo){
    //quando uma coluna esta completa(todas as cores iguais)-->esvazia (torna todas as celulas brancas)
    for(int j=0;j<tam;j++){
        if(coluna_completa(j)){
            //esvazia --> seta cor para branco
            for(int i=0;i<tam;i++){
                tabuleiro[i][j] = branco;
            }
            //aumenta pontos
            jogo->pontos += jogo->etapa * tam; //multiplica por tam pq foram retiradas tam peças
        }
    }
}

void preenche_buracos_coluna(int col){
    for (int i=tam-1;i>=0;i--){//percorre de cima para baixo
        if (verifica_celula_branca(i, col)) {
            int lin_acima = i -1;

            while(lin_acima>=0 && verifica_celula_branca(lin_acima,col))//verifica buracos acima do primeiro buraco
                lin_acima--; //sobe mais 

            if(lin_acima>=0){
                //mover blocos para cima
                tabuleiro[i][col]=tabuleiro[lin_acima][col]; //puxa a cor de cima do buraco e depois transforma ela em branco
                tabuleiro[lin_acima][col]=branco;
            }    
        }
    }
}

void verifica_buracos(){
    //analisa todas as colunas, aquelas com buraco serao encaminhadas para uma outra função preencher
    for(int j=0;j<tam;j++){
        if(!coluna_vazia(j)){
            preenche_buracos_coluna(j);
        }        
    }
}

bool primeira_linha_vazia(){
    //indica se a primeira linha esta toda branca
    int cont_brancos = 0;
    for(int j=0;j<tam;j++){
        if(verifica_celula_branca(0,j))
            cont_brancos ++;
    }

    if(cont_brancos == tam)
        return true;

    return false;

}

void verifica_primeira_linha(jogo_t *jogo){
    //verificar se existe alguma peça na primeira linha --> se nao, adicionar uma celula nova 
    while(primeira_linha_vazia()){
        int col = rand()%(tam-1);

        tabuleiro[0][col] = cor_aleatoria(jogo->etapa);
    }
}

int conta_celulas_brancas(){
    int cont=0;
    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            if(verifica_celula_branca(i, j))
                cont++;
        }
    }
    return cont;
}

void aviso_embaralhando(){
    j_retangulo(fundo,0, cor_fundo, cor_fundo);
    ponto_t texto = {500, 300};
    char aviso[] = "Você está sem jogadas, embaralhando tabuleiro...";

    j_seleciona_fonte(NULL,40);
    j_texto(texto,azul_marinho,aviso);

    j_mostra();
    j_cochila(3);
}

void aviso_nova_etapa(jogo_t *jogo){
    j_retangulo(fundo,0, cor_fundo, cor_fundo);
    ponto_t texto = {350, 300};
    char aviso[100];
    sprintf(aviso, "Você passou para a etapa %d", jogo->etapa);

    j_seleciona_fonte(NULL,40);
    j_texto(texto,azul_marinho,aviso);

    j_mostra();
    j_cochila(3);
}

void verifica_nova_etapa(jogo_t *jogo){
    if(conta_celulas_brancas() >= (tam*tam)/2){
    //if(conta_celulas_brancas() >= 15){ //--> para testar a passagem de etapas (quase impossivel tirar metade das celulas)
        jogo->etapa++;
        aviso_nova_etapa(jogo);
        embaralha_tabuleiro(jogo);

        jogo->tempo_inicio = j_relogio();
        jogo->tempo_processado = false;  
        jogo->pontos += 50 * (jogo->etapa - 1);
    }else{
        jogo->fim = true;
    }
}

void processa_tempo(jogo_t *jogo){
    jogo->tempo_na_etapa = j_relogio() - jogo->tempo_inicio;

    if (!jogo->tempo_processado && jogo->tempo_na_etapa >= 30) {
        jogo->tempo_processado = true;
        verifica_nova_etapa(jogo);
    }
}

typedef struct{
    char nome[30];
    int pontos;
    int etapa;
}ganhadores_t;

int ler_podio(ganhadores_t *podio){ //vetor podio[3]
//retorna quantos numeros foram lidos
    FILE *arq = fopen(arquivo, "r");
    if(arq == NULL){
        printf("Nao foi possivel ler o arquivo");
        fclose(arq);
        return 0;
    }

    int numeros_lidos=0;

    for(int i=0;i<3;i++){
        int leitura = fscanf(arq, "%d %d %s", &podio[i].etapa, &podio[i].pontos, podio[i].nome);
        if(leitura==3) {
            numeros_lidos++;
        } else if(leitura == EOF){
            break;
        }else{
            printf("Arquivo nao segue o padrao esperado");
            fclose(arq);
            return 0;
        }
    }
    fclose(arq);

    return numeros_lidos;
}

void desenha_podio(){
    j_retangulo(fundo,0, cor_fundo, cor_fundo);
    
    //titulo da pagina
    ponto_t titulo = {500, 230};
    j_seleciona_fonte(NULL, 40);
    j_texto(titulo, azul_marinho, "MELHORES JOGOS");

    //desenha bolinhas para mostrar os numeros (1, 2, 3)
    ponto_t circulo ={370, 400};
    circulo_t circulo_num = {circulo, 20};
    j_circulo(circulo_num, 3, azul_marinho, cor_fundo);

    circulo.y += 65;
    circulo_num.centro = circulo;
    j_circulo(circulo_num, 3, azul_marinho, cor_fundo);

    circulo.y += 65;
    circulo_num.centro = circulo;
    j_circulo(circulo_num, 3, azul_marinho, cor_fundo);

    //colocar os numeros 1, 2 e 3 dentro das bolinhas
    j_seleciona_fonte(NULL, 30);
    ponto_t numeros = {360, 410};
    j_texto(numeros, azul_marinho, "1");
    numeros.y += 65;
    j_texto(numeros, azul_marinho, "2");
    numeros.y += 65;
    j_texto(numeros, azul_marinho, "3");

    //tabela (nome pontos etapa)
    ponto_t tabela = {410, 300};
    j_texto(tabela, azul_marinho, "PONTOS");
    tabela.x += 150;
    j_texto(tabela, azul_marinho, "ETAPA");
    tabela.x += 140;
    j_texto(tabela, azul_marinho, "JOGADOR");

    //mostrar resultados 
    ganhadores_t podio[3];
    int numeros_lidos = ler_podio(podio);

    j_seleciona_fonte(NULL, 20);

    for(int i=0;i<numeros_lidos;i++){
        ponto_t ponto = {410, 330 + 70 * (i+1)};
        char pontos[10];
        char etapa[5];

        sprintf(pontos, "%d", podio[i].pontos);
        j_texto(ponto, azul_marinho, pontos);

        sprintf(etapa, "%d", podio[i].etapa);
        ponto.x += 150;
        j_texto(ponto, azul_marinho, etapa);

        ponto.x += 150;
        j_texto(ponto, azul_marinho, podio[i].nome);
    }

    j_mostra();
}

int main(void){
    int *etapa, *pontos;
    char **nome;
    int linhas;

    srand(time(NULL));

    jogo_t jogo;
    jogo.tamanho_janela = (tamanho_t){ 1300, 1300 };
    j_inicializa(jogo.tamanho_janela, "Jogo: Laura Lovato, CC1");

    //desenha uma tela inicial
    jogo.inicio = false;
    while(!jogo.inicio){
        desenha_tela_inicial(&jogo);
    }    
    
    //registra o nome do jogador
    registrar_nome(&jogo);

    //inicia um novo jogo
    inicializa_jogo(&jogo);

    // laço principal
    while (!jogo.fim) {
        verifica_primeira_linha(&jogo);//cada linha deve ter ao menos uma celula

        while(jogo.possivel==false){
            if(jogo.cont_embaralhadas>0) aviso_embaralhando(); //nao mostra na primeira embaralhada
            embaralha_tabuleiro(&jogo);
            jogo.cont_embaralhadas++;
        }

        verifica_colunas(&jogo);
        verifica_buracos();
        
        processa_tempo(&jogo);
        processa_teclado(&jogo); 
        processa_mouse(&jogo);

        imprime_tabuleiro(&jogo);

        if(jogo.fim){
            //le arquivo e faz vetores alocados dinamicamente, adiciona jogo atual
            leitura_arquivo_resultados(&nome, &etapa, &pontos, &jogo, &linhas);
            
            //ordena todos as linhas de resultado baseado nas maiores pontuações
            ordenar_valores(nome, etapa, pontos, linhas);

            //gravar valores ordenados linha por linha no arquivo
            grava_arquivo(nome, etapa, pontos, linhas);
           
           //liberando memoria
            for (int i = 0; i < linhas; i++) {
                free(nome[i]);
            }
            free(nome);
            free(etapa);
            free(pontos);
        }

        while(jogo.fim){
            desenha_tela_final(&jogo);
            if(jogo.fechar_programa) break; 
        }
    }

    desenha_podio();
    j_cochila(5);
    j_finaliza();
}