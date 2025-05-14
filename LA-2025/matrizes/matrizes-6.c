//dada uma matriz NxN, trocar linhas por colunas

#include <stdio.h>
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

void trocar_lincol(int dim, int matriz[][dim]){
    int aux;
    for(int i=0;i<dim;i++){
        for(int j=i+1;j<dim;j++){
            aux=matriz[j][i];
            matriz[j][i]=matriz[i][j];
            matriz[i][j]=aux;
        }
    }
}

int main(){
    int N;
    printf("digite uma dimensao: ");
    scanf("%d",&N);
    
    int matriz[N][N];
    
    incializar_matriz(N,N,matriz);
    imp_matriz(N,N,matriz);
    
    trocar_lincol(N,matriz);
    
    printf("Matriz com linhas e colunas trocadas: \n");
    
    imp_matriz(N,N,matriz);
}
