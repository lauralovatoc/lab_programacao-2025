/*
Função fatorial modificada para N termos: F=1*2*3*4*5*5 (o último número repete)
*/

#include<stdio.h>

int fatorial(int num, int N){
    int fat;
    if(num==N){
        return num*num;
    }
    fat = num*fatorial(num+1, N);
    return fat;

}

int main(){
    int N;

    printf("Digite o numero para o fatorial: ");
    scanf("%d", &N);

    int result = fatorial(1,N);
    printf("%d", result);
}
