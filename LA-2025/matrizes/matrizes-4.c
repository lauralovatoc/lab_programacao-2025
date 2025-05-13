/*
Fazer troca de duas linhas de uma matriz de NxM: a linha N-1 pela linha M-2.
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

int trocar(int lin, int col, int matriz[][col]){
    int origem = lin-1, destino = col-2;


    if(!(origem>0 && destino<=lin)){
        return;
    }


    int aux;

    for(int i=0;i<lin;i++){
        for(int j=0;j<col;j++){
            if(i==origem){
                aux = matriz[origem][j];
                matriz[origem][j] = matriz[destino][j];
                matriz[destino][j] = aux;
            }
        }
    }

}


int main(){
    srand(time(NULL));

    int N,M;
    printf("digite um numero de linhas: ");
    scanf("%d",&N);

    do{
        printf("\ndigite um numero de colunas: ");
        scanf("%d",&M);
    }while(M-2>=N);

    int matriz[N][M];

    incializar_matriz(N,M,matriz);
    imp_matriz(N,M,matriz);

    trocar(N,M,matriz);
    printf("\nMatriz final apos alteracoes:\n");
    imp_matriz(N,M,matriz);

}
