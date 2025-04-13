//Imprimir os números pares de 10 a 2

#include<stdio.h>

void imprimir(num){
    if(num>10){
        return;
    }
    imprimir(num+1);
    if(num%2==0){
        printf("%d ", num);
    }

}

int main(){
    imprimir(1);
}
