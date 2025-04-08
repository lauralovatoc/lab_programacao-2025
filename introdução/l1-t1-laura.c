//imprimir tabela ASCII e bases numéricas de 32 a 126
//aluna: Laura Lovato Camponogara, turma CC1

#include <stdio.h>

int main(){
    for(int valor=32;valor<=126;valor++){
         printf("Decimal: %d  Hexadecimal: %x  Binario: %b  Octal: %o  Caractere: ",valor, valor, valor, valor);
        putchar(valor);
        putchar('\n');
    }
}
