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

//mover
bool mover(int linhas, int colunas, int matriz[][colunas], char caractere){
    int aux; //variavel para auxiliar movimentos do tabuleiro

    //encontrar coordenadas do 0
    int linha_zero = posicao_zero('i',linhas, colunas, matriz);
    int coluna_zero = posicao_zero('j',linhas, colunas, matriz);

    //verificar movimento escolhido (WASD) e se ele esta valido para o tabuleiro atual
    if(caractere == 'S'){
        //para mover para CIMA, deve ter algo embaixo do zero
        if(linha_zero==3) //invalido
            return false;

        aux = matriz[linha_zero][coluna_zero];
        matriz[linha_zero][coluna_zero]  = matriz[linha_zero+1][coluna_zero];
        matriz[linha_zero+1][coluna_zero] = aux;
        //origem : coordenadas do zero
        //destino: linha_zero + 1(abaixo), coluna mesma
    }

    if(caractere == 'W'){
        //para mover para BAIXO, deve ter algo acima do zero
        if(linha_zero==0) //invalido
            return false;

        aux = matriz[linha_zero][coluna_zero];
        matriz[linha_zero][coluna_zero]  = matriz[linha_zero-1][coluna_zero];
        matriz[linha_zero-1][coluna_zero] = aux;
        //origem : coordenadas do zero
        //destino: linha_zero - 1(acima), coluna mesma
    }

    if(caractere == 'A'){
        //para mover para DIREITA, deve ter algo à esquerda do zero
        if(coluna_zero==0) //invalido
            return false;

        aux = matriz[linha_zero][coluna_zero];
        matriz[linha_zero][coluna_zero]  = matriz[linha_zero][coluna_zero-1];
        matriz[linha_zero][coluna_zero-1] = aux;
        //origem : coordenadas do zero
        //destino: mesma linha, coluna_zero-1(esquerda)
    }

    if(caractere == 'D'){
        //para mover para ESQUERDA, deve ter algo à direita do zero
        if(coluna_zero==3) //invalido
            return false;

        aux = matriz[linha_zero][coluna_zero];
        matriz[linha_zero][coluna_zero]  = matriz[linha_zero][coluna_zero+1];
        matriz[linha_zero][coluna_zero+1] = aux;
        //origem : coordenadas do zero
        //destino: mesma linha, coluna_zero+1(direita)
    }
    return true;
}

void embaralhar_tabuleiro(int linhas, int colunas, int matriz[][colunas]){
    char movimento;
    int cont = 0;
    while(cont<5){
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

    if(mover(linhas, colunas, matriz, movimento))
        cont++;
    }
}

int main(){
    srand(time(NULL));

    char movimento;
    int matriz[4][4] ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
    int linhas = 4, colunas = 4;

    embaralhar_tabuleiro(linhas,colunas,matriz);

    bool resultado=false;

    printf("\tW move o espaco vazio para cima");
    printf("\n\tS move o espaco vazio para baixo");
    printf("\n\tA move o espaco vazio para a esquerda");
    printf("\n\tD move o espaco vazio para a direita\n\n");

    imp_tabuleiro(linhas,colunas,matriz);

    while(resultado==false){
        printf("\nEscolha um movimento WSDA: ");
        scanf(" %c",&movimento);

        //testar entrada do usuario
        if(movimento=='W' || movimento=='S' || movimento=='D' || movimento=='A'){
            if(mover(linhas, colunas, matriz,movimento)){
                imp_tabuleiro(linhas, colunas, matriz);

            }else{
                printf("Movimento invalido!\n");
            }

        }else{
            printf("Caracatere invalido!\n");
        }

        resultado=vitoria(linhas, colunas, matriz);

    }

    printf("\n\tVoce ganhou!");

}
