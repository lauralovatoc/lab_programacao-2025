//todos os numeros primos menores que 10.000
#include<stdio.h>
#include<stdbool.h>

bool verifica_primos(int num){
    int cont=1, sum=0;

    while(cont<num){
        if(sum>1){
            return false;
        }
        if(num%cont==0){
            sum += cont;
        }
        cont++;
    }

    if(sum==1){
        return true;
    }
}

int main(){
    int num=1;
    bool num_primo;

    printf("Numeros primos:\n\n");

    while(num<=10000){
        num_primo = verifica_primos(num);
        if(num_primo == true){
            printf("%d ", num);
            num_primo = false;
        }
        num++;
    }

}
