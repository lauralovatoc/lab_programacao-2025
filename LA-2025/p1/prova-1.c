/*Escreva um algoritmo que lê N números inteiros. N deve ser lido. O algoritmo deve calcular e escrever duas médias: dos elementos cujo valor seja maior
que a posição em que o valor foi lido dos elementos cujo valor seja menor ou igual que a posição em que o valor foi lido.
*/

#include <stdio.h>

int main()
{
    int N;
    float sum_maior = 0, sum_menor = 0;
    int cont_maior = 0, cont_menor = 0;
    printf("Digite um numero de termos: ");
    scanf("%d",&N);

    for(int i=0;i<N;i++){
        int num;
        printf("Digite um numero: ");
        scanf("%d",&num);

        if(num>i){
            sum_maior += num;
            cont_maior++;
        } else if(num<=i){
            sum_menor += num;
            cont_menor++;
        }
    }

    printf("\n\tA media de termos maiores que seu index: %.2f",sum_maior/cont_maior);
    printf("\n\tA media de termos menores ou iguais ao seu index: %.2f", sum_menor/cont_menor);
}
