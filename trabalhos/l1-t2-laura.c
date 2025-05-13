//aluna: Laura Lovato Camponogara, CC1
//quadradinhos deslizantes

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void imp_tabuleiro(int linhas, int colunas, int matriz[][colunas]){
    //mostrar o tabuleiro atual
    for(int i=0;i<linhas;i++){
        printf("\t");
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
            //se o numero na posicao [i][j] nao for o numero esperado
            }else if(matriz[i][j]!=valor) return false;

            valor++;
        }
    }

    return true;
}

/* inicio funcoes WASD -- movimentos no tabuleiro */
bool mover_cima_W(int linhas, int colunas, int matriz[][colunas]){
    int aux; //variavel para auxiliar movimentos do tabuleiro

    //encontrar coordenadas do 0
    int linha_zero = posicao_zero('i',linhas, colunas, matriz);
    int coluna_zero = posicao_zero('j',linhas, colunas, matriz);

    if(linha_zero==0) //movimento invalido
            return false;

    //origem : coordenadas do zero
    //destino: linha_zero - 1(acima), mesma coluna
    aux = matriz[linha_zero][coluna_zero];
    matriz[linha_zero][coluna_zero]  = matriz[linha_zero-1][coluna_zero];
    matriz[linha_zero-1][coluna_zero] = aux;

    return true;

}

bool mover_baixo_S(int linhas, int colunas, int matriz[][colunas]){
    int aux;
    int linha_zero = posicao_zero('i',linhas, colunas, matriz);
    int coluna_zero = posicao_zero('j',linhas, colunas, matriz);

    if(linha_zero==3) //invalido
            return false;

    //destino:linha_zero +1 (abaixo), mesma coluna
    aux = matriz[linha_zero][coluna_zero];
    matriz[linha_zero][coluna_zero]  = matriz[linha_zero+1][coluna_zero];
    matriz[linha_zero+1][coluna_zero] = aux;

    return true;

}

bool mover_esquerda_A(int linhas, int colunas, int matriz[][colunas]){
    int aux;
    int linha_zero = posicao_zero('i',linhas, colunas, matriz);
    int coluna_zero = posicao_zero('j',linhas, colunas, matriz);

    if(coluna_zero==0) //invalido
            return false;

    //destino: mesma linha, coluna_zero-1(esquerda)
    aux = matriz[linha_zero][coluna_zero];
    matriz[linha_zero][coluna_zero]  = matriz[linha_zero][coluna_zero-1];
    matriz[linha_zero][coluna_zero-1] = aux;

    return true;

}

bool mover_direita_D(int linhas, int colunas, int matriz[][colunas]){
    int aux;
    int linha_zero = posicao_zero('i',linhas, colunas, matriz);
    int coluna_zero = posicao_zero('j',linhas, colunas, matriz);

    if(coluna_zero==3) //invalido
        return false;

    //destino: mesma linha, coluna_zero+1(direita)
    aux = matriz[linha_zero][coluna_zero];
    matriz[linha_zero][coluna_zero]  = matriz[linha_zero][coluna_zero+1];
    matriz[linha_zero][coluna_zero+1] = aux;

    return true;
}
/* fim das funcoes de movimento */

void embaralhar_tabuleiro(int linhas, int colunas, int matriz[][colunas]){
    char movimento;
    int cont = 0;

    while(cont<5){
    //fazer 5 movimentos validos
        int num = (rand() % 4) + 1;

        if(num==1){
            if(mover_cima_W(linhas, colunas, matriz)) // as funcoes de movimento retornam true ou false (todas as 4 WASD)
                cont++;
        }else if(num==2){
            if(mover_baixo_S(linhas, colunas, matriz))
                cont++;
        }else if(num==3){
            if(mover_direita_D(linhas, colunas, matriz))
                cont++;
        }else if(num==4){
            if(mover_esquerda_A(linhas, colunas, matriz))
                cont++;
        }
    }
}

int main(){
    srand(time(NULL));

    char movimento;
    int matriz[4][4] ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
    int linhas = 4, colunas = 4;

    embaralhar_tabuleiro(linhas,colunas,matriz);

    bool resultado;

    printf("\tW move o espaco vazio para cima");
    printf("\n\tS move o espaco vazio para baixo");
    printf("\n\tA move o espaco vazio para a esquerda");
    printf("\n\tD move o espaco vazio para a direita\n\n");

    imp_tabuleiro(linhas,colunas,matriz);

    while(resultado==false){
        printf("\nEscolha um movimento WSDA: ");
        scanf(" %c",&movimento);

        bool movimento_executado;

        /* inicio redirecionamento de funcao de movimento pelo caractere enviado */
        if(movimento=='W'){
            movimento_executado = mover_cima_W(linhas, colunas, matriz);

        } else if(movimento=='S'){
            movimento_executado = mover_baixo_S(linhas, colunas, matriz);

        } else if(movimento=='D'){
            movimento_executado = mover_direita_D(linhas, colunas, matriz);

        } else if(movimento=='A'){
            movimento_executado = mover_esquerda_A(linhas, colunas, matriz);
        }
        /* fim do redirecionamento das funcoes de movimento */


       if(movimento_executado){
            imp_tabuleiro(linhas, colunas, matriz);
       }else{
            printf("Movimento invalido!\n");
       }

        resultado=vitoria(linhas, colunas, matriz);

    }

    printf("\n\tVoce ganhou!");

}
