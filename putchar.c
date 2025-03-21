#include<stdio.h>

void putdig(int dig){
    putchar('0'+ dig);
}

void put2dig(int num){
    putdig(num/10);
    putdig(num%10);
}

void put3dig(int num){
    put2dig(num/10);
    putdig(num%10);
}

void put4dig(int num){
    put3dig(num/10);
    putdig(num%10);
}

void put5dig(int num){
    put4dig(num/10);
    putdig(num%10);
}

void put6dig(int num){
    put5dig(num/10);
    putdig(num%10);
}

int main(){
    int n1, n2, media;
    n1=123457;
    n2=271457;

    media=(n1+n2)/2;
    put6dig(media);
}
