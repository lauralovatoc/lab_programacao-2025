//Altere o programa das médias, para que calcule duas médias, a dos valores pares e a dos ímpares.
#include <stdio.h>

int main(){
    int n, cont_impares = 0, cont_pares = 0, num;
    float soma_impares = 0, soma_pares = 0;
    
    printf("Numero de termos:");
    scanf("%d",&n);
    printf("\nDigite %d numeros\n",n);
    for (int i=0;i<n;i++){
        scanf("%d",&num);
        
        if(num % 2==0){
            soma_pares+=num;
            cont_pares++;
        }else{
            soma_impares+=num;
            cont_impares++;
        }
    }
    
    printf("\n\tMedia dos numeros impares: %.2f\n", soma_impares/cont_impares);
    printf("\tMedia dos numeros pares: %.2f", soma_pares/cont_pares);
}
