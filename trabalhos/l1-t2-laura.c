//matriz 4x4

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void imp_tabuleiro(int linhas, int colunas, int matriz[][colunas]){
    //mostrar o tabuleiro atual
    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            printf(" %02d |", matriz[i][j]);
        }
    printf("\n");
    }
}

int posicao_zero(char caractere, int linhas, int colunas, int matriz[][colunas]){
    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            if(matriz[i][j]==0){

            //retornar a linha
            if(caractere=='i')
                return i;

            //retornar a coluna
            if(caractere=='j')
                return j;
            }
        }
    }

    //se der erro (caracatere invalido enviado)
    return -1;
}

bool vitoria(int linhas, int colunas, int matriz[][colunas]){
    int valor=1;

    //verificar se os numeros estao alinhados
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i==3 && j==3){
                //se nao tiver um zero na ultima posicao
                if (matriz[i][j] != 0) return false;
            //se o numero na posicao [i][j] nao for o numero ordenado
            }else if(matriz[i][j]!=valor) return false;

            valor++;
        }
    }

    return true;
}

//mover
void mover(int linhas, int colunas, int matriz[][colunas], char caractere){
    int aux; //variavel para auxiliar movimentos do tabuleiro

    //encontrar coordenadas do 0
    int linha_zero = posicao_zero('i',linhas, colunas, matriz);
    int coluna_zero = posicao_zero('j',linhas, colunas, matriz);

    //verificar movimento escolhido (WSDA) e se ele esta valido para o tabuleiro atual
    if(caractere == 'S'){
        //para mover para CIMA, deve ter algo embaixo do zero
        if(linha_zero==3){ //invalido
            printf("Movimento invalido!\n");
            return;
        }

        aux = matriz[linha_zero][coluna_zero];
        matriz[linha_zero][coluna_zero]  = matriz[linha_zero+1][coluna_zero];
        matriz[linha_zero+1][coluna_zero] = aux;
        //origem : coordenadas do zero
        //destino: linha_zero + 1(abaixo), coluna mesma
    }

    if(caractere == 'W'){
        //para mover para BAIXO, deve ter algo acima do zero
        if(linha_zero==0) {//invalido
            printf("Movimento invalido!\n");
            return;
        }

        aux = matriz[linha_zero][coluna_zero];
        matriz[linha_zero][coluna_zero]  = matriz[linha_zero-1][coluna_zero];
        matriz[linha_zero-1][coluna_zero] = aux;
        //origem : coordenadas do zero
        //destino: linha_zero - 1(acima), coluna mesma
    }

    if(caractere == 'A'){
        //para mover para DIREITA, deve ter algo à esquerda do zero
        if(coluna_zero==0) {//invalido
            printf("Movimento invalido!\n");
            return;
        }

        aux = matriz[linha_zero][coluna_zero];
        matriz[linha_zero][coluna_zero]  = matriz[linha_zero][coluna_zero-1];
        matriz[linha_zero][coluna_zero-1] = aux;
        //origem : coordenadas do zero
        //destino: mesma linha, coluna_zero-1(esquerda)
    }

    if(caractere == 'D'){
        //para mover para ESQUERDA, deve ter algo à direita do zero
        if(coluna_zero==3) {//invalido
            printf("Movimento invalido!\n");
            return;
        }

        aux = matriz[linha_zero][coluna_zero];
        matriz[linha_zero][coluna_zero]  = matriz[linha_zero][coluna_zero+1];
        matriz[linha_zero][coluna_zero+1] = aux;
        //origem : coordenadas do zero
        //destino: mesma linha, coluna_zero+1(direita)
    }
}

int main(){
    srand(time(NULL));

    char movimento;
    int matriz[4][4] ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
    int linhas = 4, colunas = 4;

    /* inicio embaralhar tabuleiro */
    for(int i=0;i<5;i++){
        int num = (rand() % 4) + 1;
        if(num==1){
            movimento='W';
        } else if(num==2){
            movimento='S';
        } else if(num==3){
            movimento='D';
        }else if(num==4){
            movimento='A';
        }

        mover(linhas, colunas, matriz, movimento);
    }
    /* fim embaralhar tabuleiro */

    imp_tabuleiro(linhas,colunas,matriz);

    bool resultado=false;

    do{
        printf("\nEscolha um movimento WSDA: ");
        scanf(" %c",&movimento);

        //testar entrada do usuario
        if(movimento=='W' || movimento=='S' || movimento=='D' || movimento=='A'){
            mover(linhas, colunas, matriz,movimento);
        }else{
            printf("Caracatere invalido!\n");
        }

        resultado=vitoria(linhas, colunas, matriz);
        imp_tabuleiro(linhas, colunas, matriz);

    }while(resultado==false);

    printf("\n\tVoce ganhou!");

}
