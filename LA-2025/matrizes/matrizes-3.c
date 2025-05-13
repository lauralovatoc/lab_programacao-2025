/*
Função para achar o maior e o menor valor em uma matriz de numeros inteiros
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void incializar_matriz(int lin, int col, int matriz[][col]){
    for(int i=0;i<lin;i++){
        for(int j=0;j<col;j++){
            matriz[i][j]=rand()%10;
        }
    }
}

void imp_matriz(int lin, int col, int matriz[][col]){
    for(int i=0;i<lin;i++){
        printf("\t");
        for(int j=0;j<col;j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}

int maior(int lin, int col, int matriz[][col]){
    int maior = matriz[0][0];
    for(int i=0;i<lin;i++){
        for(int j=0;j<col;j++){
            if(matriz[i][j]>maior){
                maior = matriz[i][j];
            }
        }
    }
    return maior;
}

int menor(int lin, int col, int matriz[][col]){
    int menor = matriz[0][0];
    for(int i=0;i<lin;i++){
        for(int j=0;j<col;j++){
            if(matriz[i][j]<menor){
                menor = matriz[i][j];
            }
        }
    }
    return menor;
}

int main(){
    srand(time(NULL));

    int N,M;
    printf("digite um numero de linhas: ");
    scanf("%d",&N);

    printf("\ndigite um numero de colunas: ");
    scanf("%d",&M);

    int matriz[N][M];

    incializar_matriz(N,M,matriz);
    imp_matriz(N,M,matriz);

    printf("\n\tO maior valor na matriz: %d",maior(N,M,matriz));
    printf("\n\tO menor valor na matriz: %d",menor(N,M,matriz));

}
