/*
Funções para inicializar uma matriz NxN de forma que:
c. cada linha possua o mesmo valor, que deverá ser o fatorial do número da linha
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

int fatorial(int num){
    int fat = 1;
    for(int i=num;i>1;i--){
        fat *= i;
    }
    return fat;
}

int main(){
    int N;
    printf("digite um numero: ");
    scanf("%d",&N);

    int matriz[N][N];

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            matriz[i][j]=fatorial(i+1);
        }
    }

    printar_matriz(N, matriz);
}
