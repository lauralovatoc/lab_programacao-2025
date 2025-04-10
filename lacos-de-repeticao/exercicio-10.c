//degrade colorido

#include<stdio.h>

void cor_fundo(int r, int g, int b){
    printf("%c[48;2;%d;%d;%dm", 27, r, g, b);
}

void cor_normal(){
    printf("%c[0m", 27);
}

void imprimir_linha(int r, int g, int b){
    cor_fundo(r*13,g*6,b*10);
    for(int i=0; i<32;i++){
        putchar(' ');
    }
    putchar('\n');
    cor_normal();
}

int main(){
    int cont=1;
    //exemplo rosa: rgb(208, 96, 160)
    while(cont<=16){
        imprimir_linha(cont,cont,cont);
        cont++;
    }
}
