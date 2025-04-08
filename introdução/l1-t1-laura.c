//imprimir tabela ASCII
//aluna: Laura Lovato Camponogara, turma CC1

#include <stdio.h>

int main(){
    for(int valor=32;valor<=126;valor++){
        printf("Codigo: %d   Caractere: ",valor);
        putchar(valor);
        putchar('\n');
    }
}
