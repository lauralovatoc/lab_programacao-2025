//aluna: Laura Lovato Camponogara (CC1)

#include "janela.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define tam 10

//TODO: 
//acaba jogo -> le arquivo, grava em uma string (malloc), grava no arquivo(oq foi lido + informações do ultimo game)(malloc)

// gravar instruções na tela de jogo(como mexer linhas, como mexer colunas, irá aparecer uma peça nova quando a primeira linha estiver vazia,
//o objetivo é juntar colunas com celulas de mesma cor e esvaziar o maximo possivel)

//CONSERTAR CRONOMETRO****

/*
descrição de como cores e etapas vão funcionar:
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
    bool possivel;

    //para registro:
    int pontos; //pontuação final
    int etapa; // etapa do jogo
    char apelido[100]; //apelido do jogador

    int cont_embaralhadas;

    bool lin; 
    //lin == true : linhas selecionas p/ movimentar
    //lin == false: colunas selecionas p/ movimentar
    
    int col_atual;
    int lin_atual;

    double tempo_inicio; 
    double tempo_na_etapa;
    bool tempo_processado;
} jogo_t;

cor_t azul_marinho = {0.13, 0.2, 0.8, 1.0};
cor_t cor_fundo = {0.48, 0.67, 0.88, 1.0};
cor_t branco = {1.0, 1.0, 1.0, 1.0};

retangulo_t fundo = { //retangulo que cobre toda a janela
    .inicio = {0, 0},
    .tamanho = {1500,1500}
};

//funcao inserida para rodar j_relogio em Windows (com máquina virtual Ubuntu) --> tava bugando a função de tempo do allegro
double j_relogio_novo()
{
  struct timespec agora;
  clock_gettime(CLOCK_REALTIME, &agora);
  return agora.tv_sec + agora.tv_nsec*1e-9;
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

    char nome[150];
    sprintf(nome, "Jogador: %s", jogo->apelido);

    j_seleciona_fonte(NULL, 30);
    j_texto(texto, azul_marinho, nome);

    char pontuacao[50];
    sprintf(pontuacao, "Pontuação: %d", jogo->pontos);

    texto.y += 40;
    j_texto(texto, azul_marinho,pontuacao);

    char etapa[50];
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

    //processa mouse
    rato_t mouse = j_rato();
    if(mouse.clicado[0]){

        if(mouse.posicao.x >= botao.inicio.x && 
        mouse.posicao.x <= botao.inicio.x + botao.tamanho.largura &&
        mouse.posicao.y >= botao.inicio.y &&
        mouse.posicao.y <= botao.inicio.y + botao.tamanho.altura){
            inicializa_jogo(jogo);
        }
    }


    j_mostra();
}

void registrar_nome(jogo_t *jogo){
    //armazenar nome do jogador antes da partida começar
    char nome[100]= "\0";
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

    j_mostra();

    //verifica se o o botao foi clicado
    while(buttonClick == false){
        rato_t mouse = j_rato();

        if(mouse.clicado[0] && 
        mouse.posicao.x >= botao.inicio.x && 
        mouse.posicao.x <= botao.inicio.x + botao.tamanho.largura &&
        mouse.posicao.y >= botao.inicio.y &&
        mouse.posicao.y <= botao.inicio.y + botao.tamanho.altura)

            buttonClick=true;
    }

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

/*
descrição de como as teclas funcionam:

se for linhas:
    T_CIMA = seleciona linha acima
    T_BAIXO = seleciona linha abaixo
    T_ESQUERDA: linha roda pra esquerda
    T_DIREITA: linha roda pra direita

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

            if(t == T_A || t == T_D){
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
    rato_t mouse = j_rato();
    if(mouse.clicado[0]){

        //botao linhas
        if(mouse.posicao.x >= but_lin.inicio.x && 
        mouse.posicao.x <= but_lin.inicio.x + but_lin.tamanho.largura &&
        mouse.posicao.y >= but_lin.inicio.y &&
        mouse.posicao.y <= but_lin.inicio.y + but_lin.tamanho.altura)
            jogo->lin = true;

        //botao colunas
        if(mouse.posicao.x >= but_col.inicio.x && 
        mouse.posicao.x <= but_col.inicio.x + but_col.tamanho.largura &&
        mouse.posicao.y >= but_col.inicio.y &&
        mouse.posicao.y <= but_col.inicio.y + but_col.tamanho.altura)
            jogo->lin = false;

        //botao desistir
        if(mouse.posicao.x>=but_desistir.inicio.x &&
        mouse.posicao.x<= but_desistir.inicio.x + but_desistir.tamanho.largura &&
        mouse.posicao.y>= but_desistir.inicio.y &&
        mouse.posicao.y<= but_desistir.inicio.y + but_desistir.tamanho.altura)
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
            .tamanho = {tam_lin_x + 10, tam_lin_y*10 + 10}
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
    ponto_t texto = {500, 300};
    char aviso[100];
    sprintf(aviso, "Você passou para a etapa %d", jogo->etapa);

    j_seleciona_fonte(NULL,40);
    j_texto(texto,azul_marinho,aviso);

    j_mostra();
    j_cochila(3);
}

void verifica_nova_etapa(jogo_t *jogo){
    if(conta_celulas_brancas() >= (tam*tam)/2){
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

int main(void){
    srand(time(NULL));

    jogo_t jogo;
    jogo.tamanho_janela = (tamanho_t){ 1300, 1300 };
    j_inicializa(jogo.tamanho_janela, "Jogo: Laura Lovato, CC1");

    //desenha uma tela inicial
    desenha_tela_inicial(&jogo);
    
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

        printf("tempo_inicio: %.2f, relogio atual: %.2f, tempo_na_etapa: %.2f\n",jogo.tempo_inicio, j_relogio(), jogo.tempo_na_etapa);

        processa_teclado(&jogo); 
        processa_mouse(&jogo);

        imprime_tabuleiro(&jogo);

        if(jogo.fim){
            //le arquivo de resultados e armazena (malloc) em uma string 
            //ordena resultados por pontuação
            //grava arquivo (string lida  + resultados do ultimo jogo)
        }

        while(jogo.fim){
            desenha_tela_final(&jogo); 
       }
    }
    //desenha_podio(); //usa mesma funcao para ler aquivo, seleciona os 5 primeiros lugares e imprime
    j_finaliza();
}