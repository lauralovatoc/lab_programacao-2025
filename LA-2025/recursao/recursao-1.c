//Imprimir os números inteiros de 1 a 20

#include<stdio.h>

void imprimir(int num){
    if(num>20){
        return;
    }
    printf("%d ", num);
    imprimir(num+1);
}

int main(){
    imprimir(1);
}
