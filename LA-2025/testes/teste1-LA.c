#include<stdio.h>

int main(){
    int n1, n2;
    printf("Digite um numero:");
    scanf("%d",&n1);
    printf("\nDigite outro numero:");
    scanf("%d",&n2);

    if(n1==n2){
        printf("Numeros iguais");
    }else{
        while(n1>n2){
        n1--;
        if(n1==n2){
            break;
        }
        printf("%d",n1);
        }

        while(n2>n1){
        n1++;
        if(n1==n2){
            break;
        }
        printf("%d",n1);
        }
    }
}
