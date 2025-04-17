//todos os numeros inteiros perfeitos (numero é igual a soma de seu divisores inteiros) menores que 10.000
#include<stdio.h>
#include<stdbool.h>

bool verifica_perfeicao(int num){
    int cont=1, sum=0;

    while(cont<num){
        if(num%cont==0){
            sum += cont;
        }
        cont++;
    }

    if(num == sum){
        return true;
    }else {
        return false;
    }
}

int main(){
    int num=1;
    bool num_perfeito;

    printf("Numeros perfeitos:\n\n");

    while(num<=10000){
        num_perfeito = verifica_perfeicao(num);
        if(num_perfeito == true){
            printf("%d ", num);
            num_perfeito = false;
        }
        num++;
    }

}
