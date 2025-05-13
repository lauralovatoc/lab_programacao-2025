/*
Funções para inicializar uma matriz NxN de forma que:
a. os elementos da diagonal principal tenham valor 1 e os demais valor 0.
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
            if(i==j){
                matriz[i][j]=1;
            }else{
                matriz [i][j]=0;
            }
        }
    }

    printar_matriz(N, matriz);
}
