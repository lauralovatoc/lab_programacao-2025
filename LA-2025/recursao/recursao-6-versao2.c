/*Fun��o para calcular a somat�ria de N termos. S = 1 + 2 + 3 + ... + N
a. Com dois argumentos na fun��o
b. Com 1 argumento na fun��o
*/

#include<stdio.h>

int somatorio(int num){
    int sum;
    if(num==0){
        return num;
    }
    sum = num + somatorio(num-1);
    return sum;
}

int main(){
    int N;
    printf("Digite um numero N de termos:\n");
    scanf("%d",&N);

    int sum = somatorio(N);
    printf("%d ", sum);
}
