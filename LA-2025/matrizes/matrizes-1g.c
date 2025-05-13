/*
Funcoes para inicializar uma matriz NxN de forma que:
g. os elementos do centro sejam maiores que os dos extremos (como uma função gaussiana)
*/


#include <stdio.h>
#include <stdlib.h>

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

    int centro =  N/2;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int distancia = abs(i-centro) + abs(j-centro);
            matriz[i][j]= N - distancia;
        }
    }

    printar_matriz(N, matriz);
}
