//imprimir o número decimal com 2 casas e ao lado o número binário
#include<stdio.h>

void putdig(int num){
    putchar('0'+ num);
}

void put2dig(int num){
    putdig(num/10);
    putdig(num%10);
}

void put2bits(int num){
    putdig(num/2);
    putdig(num%2);

}

void put3bits(int num){
    put2bits(num/2);
    putdig(num%2);
}

void put4bits(int num){
    put3bits(num/2);
    putdig(num%2);
}


int main(){
    int binary = 0b0000;
    for(int i=0;i<=15;i++){
        put2dig(i);
        putchar(' ');
        put4bits(binary);
        putchar('\n');
        binary++;

    }
}
