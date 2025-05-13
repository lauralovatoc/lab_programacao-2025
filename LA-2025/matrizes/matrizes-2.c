//Função que diz qual linha de uma matriz bidimensional possui a maior soma

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printar_matriz(int dim, int matriz[][dim]){
    for(int i=0;i<dim;i++){
        printf("\t");
        for(int j=0;j<dim;j++){
            printf("%3d ",matriz[i][j]);
        }
        printf("\n");
    }
}

void inicializar_matriz(int dim, int matriz[][dim]){
     for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            matriz[i][j]=rand()%10;
        }
    }
}


int main(){
    srand(time(NULL));
    int N;
    printf("digite um numero: ");
    scanf("%d",&N);

    int matriz[N][N];

    inicializar_matriz(N, matriz);

    int maior_linha = 0;
    int maior_soma = 0;

    for(int i=0;i<N;i++){
        //inicializar a maior_soma como a soma dos termos da linha zero
        maior_soma += matriz[0][i];
    }

    for(int i=1;i<N;i++){
        int soma_linha=0;

        for(int j=0;j<N;j++){
            soma_linha+=matriz[i][j];
        }

        if(soma_linha>maior_soma){
            maior_soma = soma_linha;
            maior_linha = i;
        }
    }

    printar_matriz(N, matriz);

    printf("A linha com maior soma de termos: %d, resultando %d", maior_linha+1, maior_soma);
}
