/*
Funções para inicializar uma matriz NxN de forma que:
b. cada coluna possua o mesmo valor
*/

#include <stdio.h>

void printar_matriz(int dim, int matriz[][dim]){
    for(int i=0;i<dim;i++){
        printf("\t");
        for(int j=0;j<dim;j++){
            printf("%d ",matriz[i][j]);
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
            matriz[i][j]=j;
        }
    }

    printar_matriz(N, matriz);
}
