//Esreva uma função que recebe um parametro N como argumento, lido pelo usuário. Assumindo N = 7, deve imprimir o seguinte resultado: 1234567 65432 345 4

#include<stdio.h>

void imp_seq(int N){
    int cont=1, num=N;

    while(cont<N){
        int j = cont;
        while(j<=num){
            printf("%d", j);
            j++;
        }
        num--;
        cont++;
        printf(" ");

        for(int i=num;i>=cont;i--){
            printf("%d",i);
        }
        num--;
        cont++;
        printf(" ");
    }
}

int main(){
    int N;
    printf("Digite um numero de termos: ");
    scanf("%d",&N);

    imp_seq(N);
}
