#include<stdio.h>

int main(){
    int contador=1, N;
    printf("Digite um numero: ");
    scanf("%d",&N);

    while(contador<=N){
        printf("%d", contador);
        int cont = contador;
        while(cont>0){
            printf("%d", cont);
            cont--;
        }
        contador++;
        printf("\n");
    }
}
