//Função F = 1 + 3 + 5 + 7 + 9 + 8 + 6 + 4 + 2 (somados nesta ordem)
#include<stdio.h>

int soma(int num){
    int sum;
    if(num>9 || num==0){
        return 0;
    }

    if(num%2==0){
      sum = num + soma(num-2);
    }else if(num < 9){
        sum = num + soma(num+2);
    }else{
        sum = num + soma(8);
    }

    return sum;

}

int main(){
    int num=1;
    printf("A soma eh: %d",soma(num));
}
