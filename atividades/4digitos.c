//como 1234 em que 12^2+34^2=1234
#include<stdio.h>
#include<stdbool.h>

int contar_digitos(int num){
    int cont = 0;
    while(num!=0){
        num = num/10;
        cont++;
    }
    return cont;
}

bool testar_num(int num){ //testa se o numero segue o padrao descrito
    int n1 = num/100, n2 = num%100;
    int sum = n1*n1 + n2*n2;
    if(sum==num){
        return true;
    }else{
        return false;
    }

}

int main(){
    int num=1, dig;
    bool teste;

    while(num<=10000){
        dig = contar_digitos(num);
        if(dig==4){
            teste = testar_num(num);
            if(teste == true){
                printf("%d ", num);
                teste = false;
            }
        }

        num++;
    }
}
