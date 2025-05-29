//aluna Laura Lovato Camponogara, CC1
//quadradinhos deslizantes

#include "teclado.h"
#include "video.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define colunas 4
#define linhas 4

int matriz[4][4] ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
cor_t cor_textos={137, 26, 45}; 
cor_t cor_fundo={178, 74, 78};

void imp_tabuleiro() {
    cor_t celulas = {229, 188, 214};
    cor_t zero = {255, 212, 228};

    char buffer[5];
    posicao_t p;

    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            p.linha = i + 2;       // ajusta posição da linha
            p.coluna = j * 5 + 5;  // espaça bem as colunas
            vid_pos(p);

            if (matriz[i][j] == 0) {
                vid_cor_fundo(zero);
                vid_imps("    ");  // espaço vazio
            } else {
                vid_cor_fundo(celulas);
                sprintf(buffer, " %02d ", matriz[i][j]);
                vid_imps(buffer);
            }
            vid_cor_fundo(cor_fundo);
        }
    }

    vid_atualiza();
}

void posicao_zero(int *lin,int *col){
    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            if(matriz[i][j]==0){
                *lin=i;
                *col=j;
            }
        }
    }
}

bool vitoria(){
    int valor=1;

    //verificar se os numeros estao alinhados
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i==3 && j==3){
                //se nao tiver um zero na ultima posicao
                if (matriz[i][j] != 0) return false;
            //se o numero na posicao [i][j] nao for o numero esperado
            }else if(matriz[i][j]!=valor) return false;

            valor++;
        }
    }

    return true;
}

/* inicio funcoes WASD -- movimentos no tabuleiro */
bool mover_cima(){
    int aux; //variavel para auxiliar movimentos do tabuleiro
    int linha_zero, coluna_zero;
    //encontrar coordenadas do 0
    posicao_zero(&linha_zero,&coluna_zero);

    if(linha_zero==0) //movimento invalido
            return false;

    //origem : coordenadas do zero
    //destino: linha_zero - 1(acima), mesma coluna
    aux = matriz[linha_zero][coluna_zero];
    matriz[linha_zero][coluna_zero]  = matriz[linha_zero-1][coluna_zero];
    matriz[linha_zero-1][coluna_zero] = aux;

    return true;

}

bool mover_baixo(){
    int aux;
    int linha_zero, coluna_zero;
    posicao_zero(&linha_zero,&coluna_zero);

    if(linha_zero==3) //invalido
            return false;

    //destino:linha_zero +1 (abaixo), mesma coluna
    aux = matriz[linha_zero][coluna_zero];
    matriz[linha_zero][coluna_zero]  = matriz[linha_zero+1][coluna_zero];
    matriz[linha_zero+1][coluna_zero] = aux;

    return true;

}

bool mover_esquerda(){
    int aux;
    int linha_zero, coluna_zero;
    posicao_zero(&linha_zero,&coluna_zero);

    if(coluna_zero==0) //invalido
            return false;

    //destino: mesma linha, coluna_zero-1(esquerda)
    aux = matriz[linha_zero][coluna_zero];
    matriz[linha_zero][coluna_zero]  = matriz[linha_zero][coluna_zero-1];
    matriz[linha_zero][coluna_zero-1] = aux;

    return true;

}

bool mover_direita(){
    int aux;
    int linha_zero, coluna_zero;
    posicao_zero(&linha_zero,&coluna_zero);

    if(coluna_zero==3) //invalido
        return false;

    //destino: mesma linha, coluna_zero+1(direita)
    aux = matriz[linha_zero][coluna_zero];
    matriz[linha_zero][coluna_zero]  = matriz[linha_zero][coluna_zero+1];
    matriz[linha_zero][coluna_zero+1] = aux;

    return true;
}
/* fim das funcoes de movimento */

void embaralhar_tabuleiro(){
    int cont = 0;

    while(cont<10){
    //fazer 5 movimentos validos
        int num = (rand() % 4) + 1;

        if(num==1){
            if(mover_cima()) // as funcoes de movimento retornam true ou false (todas as 4 WASD)
                cont++;
        }else if(num==2){
            if(mover_baixo())
                cont++;
        }else if(num==3){
            if(mover_direita())
                cont++;
        }else if(num==4){
            if(mover_esquerda())
                cont++;
        }
    }
}

int main(){
    srand(time(NULL));

    tecla_t movimento;

    embaralhar_tabuleiro();

    bool resultado = false;

    tec_inicia();
    vid_inicia();


    vid_cor_fundo(cor_fundo);
    vid_limpa();
    vid_cor_texto(cor_textos);
    vid_atualiza();

    vid_imps("Quadrdinhos deslizantes \r\n\r\n");

    imp_tabuleiro();

    while(resultado==false){
        tecla_t movimento = tec_tecla();

        bool movimento_executado=false;

        /* inicio redirecionamento de funcao de movimento pelo caractere enviado */
        if(movimento==T_CIMA){
            movimento_executado = mover_cima();

        } else if(movimento==T_BAIXO){
            movimento_executado = mover_baixo();

        } else if(movimento==T_DIREITA){
            movimento_executado = mover_direita();

        } else if(movimento==T_ESQUERDA){
            movimento_executado = mover_esquerda();
        }
        /* fim do redirecionamento das funcoes de movimento */


       if(movimento_executado){
            imp_tabuleiro();
       }else{
            //printf("Movimento invalido!\r\n");
       }

        resultado=vitoria();

    }

    vid_limpa();
    posicao_t p = {10, 10};
    vid_pos(p);
    vid_imps("Voce ganhou!");
    vid_atualiza();
    sleep(3);

    tec_fim();
    vid_fim();
}
