//imprimir tabela ASCII e bases numéricas de 32 a 126
//aluna: Laura Lovato Camponogara, turma CC1

#include <stdio.h>
void letra_rosa(){
    printf("%c[38;2;%d;%d;%dm", 27, 229, 108, 165);
}

void cor_fundo(){
    printf("%c[48;2;%d;%d;%dm", 27, 71, 25, 45);
}

void fundo_normal(){
    printf("%c[0m", 27);
}

void header(){https://www.onlinegdb.com/#tab-stdin
    cor_fundo();
    letra_rosa();
    printf("Dec|Hex|Binario|Oct|ASCII|  ");
    fundo_normal();
}

void format_number(int num){
    letra_rosa();
    int cont = 0;
    int N = num;
    while(cont<6){
        printf("%3d| %2x|%07b|%3o|  %c  |  ",N, N, N, N, N);
        cont++;
        N+=16;
    }
}

int main(){
    for(int i=0;i<=6;i++){
    header();
    }
    printf("\n");
    for(int valor=32;valor<=47;valor++){
        format_number(valor);
        printf("\n");
    }
}
