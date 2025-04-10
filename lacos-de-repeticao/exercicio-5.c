/*Um dos programas acima pede para o usuário adivinhar um número secreto. Faça um programa que faz o contrário: pede para o usuário pensar 
em um número e depois chuta valores até acertar. Para cada chute do programa, ele imprime o chute e pede para o usuário responder se acertou 
ou se está acima ou abaixo do valor secreto (digitando 0, 1 ou 2). O chute do programa deve ser um valor aleatório entre os valores que
ainda são possíveis a cada chute. 
*/
#include<stdio.h>
#include<stdlib.h>

int aleatorio_entre(int menor, int maior){
  return menor + rand() % (maior - menor + 1);
}

int main(){
   int num, cont=0, teste=0;
   int x = 100;
   int y = 0;
   char maior_menor;
   
   printf("\tPense em um numero ate 100: \n\n");
   
   do{
       num = aleatorio_entre(y, x);
       printf("Se o numero for %d, digite 1, senao digite qualquer coisa\n", num);
       scanf("%d", &teste);
       
       if(teste!=1){
           printf("Digite M se o numero que vc pensou eh maior e m se o numero for menor:\n");
           scanf(" %c",&maior_menor);
           
           if(maior_menor == 'M'){
               y = num+1;
           }else if (maior_menor == 'm'){
               x = num-1;
           }
       }
       cont++;
   }while(teste!=1);
   
   printf("\n\tForam %d tentativa(s)", cont);
}
