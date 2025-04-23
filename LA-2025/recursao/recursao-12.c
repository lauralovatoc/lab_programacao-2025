/*
Função fatorial modificada para N termos. Não podem ser criadas funções auxiliares. Elabore soluções
com 1 e 2 chamadas recursivas. Neste exemplo N=5.
F = 1 * 2*2 * 3*3*3 * 4*4*4*4 * 5*5*5*5*5.
*/

#include<stdio.h>

int fatorial_complex(int num, int N){
    int resultado;
    if(num>N){
        return 1;
    }

    int cont = 1;

    int produto = 1;
    while(cont<=num){
        //printf("%d ", num);
        produto *= num;
        cont ++;
    }
    //printf("\n");
    resultado =  produto * fatorial_complex(num+1, N);

    return resultado;
}

int main(){
    int N;
    printf("Digite um numero qualquer: ");
    scanf("%d",&N);

    int resultado = fatorial_complex(1, N);

    printf("\n\tResultado: %d", resultado);


}
