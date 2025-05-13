/*
Funções para inicializar uma matriz NxN de forma que:
e. elementos acima da diagonal superior sejam 1, e o resto zero
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
            if(j>i){
                matriz[i][j]=1;
            } else {
                matriz[i][j]=0;
            }
        }
    }

    printar_matriz(N, matriz);
}
