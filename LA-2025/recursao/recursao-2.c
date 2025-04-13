//Imprimir os números pares de 2 a 10

#include<stdio.h>

void imprimir(num){
    if(num>10){
        return;
    }
    if(num%2==0){
        printf("%d ", num);
    }
    imprimir(num+1);
}

int main(){
    imprimir(1);
}
