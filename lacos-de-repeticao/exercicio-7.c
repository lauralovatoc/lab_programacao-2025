/*Faça um programa que imprime toda a tabuada (de 1 a 9), usando a função do exercício anterior. Separe-as com uma linha contendo 8 caracteres -.
Use uma função para desenhar esses 8 caracteres - essa função deve receber como argumento o caractere e o número de vezes que se quer imprimí-lo.
*/

#include<stdio.h>

void imprime_tabuada(int n){
    int cont=1;
    while(cont<=9){
       printf("\t%dx%d = %2d\n", n, cont, n*cont);
       cont++;
   }
}

void imprime_char(char caractere, int vezes){
    int cont=0;
    putchar('\t');
    while(cont<vezes){
        putchar(caractere);
        cont++;
    }
}

int main(){
   int num=1;
   
   while(num<=9){
       imprime_tabuada(num);
       imprime_char('-',8);
       printf("\n");
       num++;
   }
}
