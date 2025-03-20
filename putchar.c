#include<stdio.h>

void putdig(int dig){
    putchar('0'+ dig);
}

void put2dig(int num){
    putdig(num/10);
    putdig(num%10);
}

put3dig(int num){
    int d1, d2, d3;
    put2dig(num/10);
    putdig(num%10);
}

int main(){
    int n1, n2, media;
    n1=123;
    n2=271;

    media=(n1+n2)/2;
    put3dig(media);
}
