/*
Funções para inicializar uma matriz NxN de forma que:
d. cada elemento seja a soma dos índices da linha com a coluna
*/

#include <stdio.h>

void printar_matriz(int dim, int matriz[][dim]){
    for(int i=0;i<dim;i++){
        printf("\t");
        for(int j=0;j<dim;j++){
            printf("%3d ",matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int N;
    printf("digite um numero: ");
    scanf("%d",&N);

    int matriz[N][N];

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            matriz[i][j]=i+j;
        }
    }

    printar_matriz(N, matriz);
}
