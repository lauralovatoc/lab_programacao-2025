//imprimir tabela ASCII
//aluna: Laura Lovato Camponogara, turma CC1

#include <stdio.h>

int main(){
    int hexadecimal = 0x20;
    int binario = 0b100000;
    int octal = 0o40;
    int decimal =32;
    //todos equivalem a 32
    while(decimal<=126){
        printf("Codigo: %d  Hexadecimal: %h  Binario: %b  Octal: %o  Caractere: ",decimal, hexadecimal, binario, octal);
        putchar(decimal);
        putchar('\n');
        decimal++;
        hexadecimal++;
        octal++;
        decimal++;
    }
}
