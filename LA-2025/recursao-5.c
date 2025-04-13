//Imprimir a sequência 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 8, 6, 4, 2

#include<stdio.h>

void imprimir(int num){
    if(num>10){
        return;
    }

    printf("%d ", num);
    imprimir(num+1);
    if(num%2==0 && num!=10){
        printf("%d ", num);
    }
}

int main(){
    imprimir(1);
}
