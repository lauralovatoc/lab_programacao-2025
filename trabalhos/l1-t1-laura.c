/*
imprimir tabela ASCII e bases numéricas de 32 a 126
aluna: Laura Lovato Camponogara, turma CC1
OBS: tirei as funções para colorir pq também não funcionaram no meu gcc, só funcionaram em outros compiladores
*/

#include <stdio.h>
void putnum7bin(int num)
{
  if (num > 127) {
    putchar('!');
  }
  for (int i = 64; i > 0; i /= 2) {
    putchar('0' + ((num / i) % 2));
  }
}

void print_header(){
    printf("Dec|Hex|Binario|Oct|ASCII|  ");
}


void format_number(int num){
    printf("%3d| %2x|",num,num);
    putnum7bin(num);
    printf("|%3o|  %c  |  ", num, num);
}

void print_lines(int num){
    int cont = 0;

    while(cont<6){
        if(num==127){
            return;
        }

        format_number(num);
        cont++;
        num+=16;
    }

    printf("\n");
}

int main(){
    for(int i=0;i<6;i++){
        print_header();
    }

    printf("\n");

    for(int valor=32;valor<=47;valor++){
        print_lines(valor);
    }
}
