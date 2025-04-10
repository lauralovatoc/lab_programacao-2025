/*Use a função de selecionar a cor de fundo para desenhar um quadrado degradê cinza vertical na tela. Desenhe 16 linhas, com 32 espaços cada. 
No início de cada linha, escolha a cor com os componentes R, G e B iguais ao número da linha (0 a 15) multiplicado por 16. 
No final de cada linha, escolha a cor normal antes do enter.
*/

#include<stdio.h>

void cor_fundo(int r, int g, int b){
    printf("%c[48;2;%d;%d;%dm", 27, r, g, b);
}

void cor_normal(){
    printf("%c[0m", 27);
}

void imprimir_linha(int r, int g, int b){
    cor_fundo(r*16,g*16,b*16);
    for(int i=0; i<32;i++){
        putchar(' ');
    }
    putchar('\n');
    cor_normal();
}

int main(){
    int cont=1;
    while(cont<=16){
        imprimir_linha(cont,cont,cont);
        cont++;
    }
}

/* degrade invertido
#include<stdio.h>

void cor_fundo(int r, int g, int b){
    printf("%c[48;2;%d;%d;%dm", 27, r, g, b);
}

void cor_normal(){
    printf("%c[0m", 27);
}

void imprimir_linha(int r, int g, int b){
    cor_fundo(r*16,g*16,b*16);
    for(int i=0; i<32;i++){
        putchar(' ');
    }
    putchar('\n');
    cor_normal();
}

int main(){
    int cont=16;
    while(cont>=1){
        imprimir_linha(cont,cont,cont);
        cont--;
    }
}
*/
