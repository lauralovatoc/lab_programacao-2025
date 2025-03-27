#include<stdio.h>

void ratao(){
    puts(" _   _ ");
    puts("(_)_(_)");
    puts(" (o o) ");
    puts("==\\o/==");
}

int increment(int num){
    num++;
    return num;
}

void gatinhos(int num, int count){
    if(num>count){
        puts("=^..^=");
        int x = increment(count);
        gatinhos(num, x);
    }
}

int main (){
    int n=5;
    //ratao();
    gatinhos(n, 0); //printar n vezes
}
