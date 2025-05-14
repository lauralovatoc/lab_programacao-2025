//dada uma matriz NxM, diga se existem duas colunas com mesma soma de valores

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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

bool verificar(int dim, int matriz[][dim]){
    int sum, sum_aux, cont=1;
    for(int j=0;j<dim/2;j++){
        while(cont<dim){
            sum=0, sum_aux=0;
            for(int i=0;i<dim;i++){
                sum+= matriz[i][j];
                sum_aux+=matriz[i][j+cont];
            }
            if(sum==sum_aux){
                return true;
            }
            cont++;
        }
    }
    return false;
}

int main(){
    int N;
    printf("digite uma dimensao: ");
    scanf("%d",&N);
    
    int matriz[N][N];
    
    incializar_matriz(N,N,matriz);
    imp_matriz(N,N,matriz);
    
    if(verificar(N,matriz))
        printf("Existem colunas com mesma soma de valores");
}
