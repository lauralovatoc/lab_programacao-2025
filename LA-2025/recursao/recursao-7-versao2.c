/*
Fun��o para o c�lculo do fatorial de um n�mero, em v�rias vers�es:
a. F = 5*4*3*2*1 (multiplica��o ap�s retorno da fun��o)
b. F = 1*2*3*4*5
*/

#include<stdio.h>

int fatorial(int num, int N){
    int fat;
    if(num==N){
        return num;
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
