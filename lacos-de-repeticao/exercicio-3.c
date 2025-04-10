/*Altere novamente para imprimir o valor em decimal e binário, com 2 e 5 casas:
20 10100
21 10101
*/

#include <stdio.h>

int main(){
    int num=20;
    
    while(num<=29){
        printf("%d %05b\n", num,num);
        num++;
    }
}
