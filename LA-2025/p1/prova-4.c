//Esreva uma função que recebe um parametro N como argumento, lido pelo usuário. Assumindo N = 5,
//deve imprimir o seguinte resultado: 1   5 4 3 2   2   5 4 3   3    5 4   4   5

#include<stdio.h>

void imp_seq(int N){
    int cont=1;
    while(cont<N){
        printf("%d ",cont);

        for(int i=N;i>cont;i--){
            printf("%d",i);
        }
        printf(" ");
        cont++;
    }
}

int main(){
    int N;
    printf("Digite um numero de termos: ");
    scanf("%d",&N);

    imp_seq(N);
}
