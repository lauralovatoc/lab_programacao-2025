//imprimir um número binário de 4 digitos usando putchar
#include<stdio.h>

void putdig(int num){
    putchar('0' + num);
}

void put2dig(int num){
    putdig(num/2);
    putdig(num%2);
}

void put3dig(int num){
    put2dig(num/2);
    putdig(num%2);
}

void put4dig(int num){
    put3dig(num/2);
    putdig(num%2);
}

int main(){
    unsigned int binary_num = 0b0101; //número binário 0101 = 5
    put4dig(binary_num);
}
