//degrade horizontal

#include<stdio.h>

void cor_fundo(int r, int g, int b){
    printf("%c[48;2;%d;%d;%dm", 27, r, g, b);
}

void cor_normal(){
    printf("%c[0m", 27);
}

void imprimir_linha(int r, int g, int b){
    for(int i=0; i<32;i++){
        cor_fundo(r*8,g*8,b*8);
        putchar(' ');
        r++;
        g++;
        b++;
    }
    putchar('\n');
}

int main(){
    int cont=1;
    while(cont<=16){
        imprimir_linha(1,1,1);
        cont++;
    }
}
