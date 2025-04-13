//Imprimir a sequência 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1

#include<stdio.h>

void imprimir(int num){
    if(num>6){
        return;
    }

    printf("%d ", num);
    imprimir(num+1);
    if(num!=6){
        printf("%d ", num);
    }

}

int main(){
    imprimir(1);
}
