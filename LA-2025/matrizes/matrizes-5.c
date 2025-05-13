/*
Dada uma matriz NxN, trocar linhas por colunas (matriz transposta)
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void incializar_matriz(int lin, int col, int matriz[][col]){
    for(int i=0;i<lin;i++){
        for(int j=0;j<col;j++){
            matriz[i][j]=rand()%20;
        }
    }
}

void imp_matriz(int lin, int col, int matriz[][col]){
    for(int i=0;i<lin;i++){
        printf("\t");
        for(int j=0;j<col;j++){
            printf("%2d ",matriz[i][j]);
        }
        printf("\n");
    }
}

void transpor_matriz(int lin, int col, int matriz[][col]){
    int trans[col][lin];

    for(int i=0;i<col;i++){
        for(int j=0;j<lin;j++){
            trans[i][j]= matriz[j][i];
        }
    }

    imp_matriz(col,lin,trans);
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

    printf("\nMatriz transposta:\n");
    transpor_matriz(N,M,matriz);

}
