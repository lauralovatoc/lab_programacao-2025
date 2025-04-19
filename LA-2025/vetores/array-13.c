//Dados dois vetores com um N e M valores, faça uma função para imprimir todos os valores que estão presentes nos dois vetores.

#include<stdio.h>

int main(){
    int N, M;
    printf("Digite uma quantidade de termos para um vetor e outra quantidade para um segundo vetor: ");
    scanf("%d %d",&N,&M);

    int v1[N], v2[M];

    //inicializando os dois vetores
    printf("Digite %d valores para o primeiro vetor: ", N);
    for(int i=0;i<N;i++){
        scanf("%d",&v1[i]);
    }
    printf("Digite %d valores para o segundo vetor: ", M);
    for(int i=0;i<M;i++){
        scanf("%d",&v2[i]);
    }


    printf("Valores em comum: ");
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(v1[i]==v2[j]){
                printf("%d ", v1[i]);
            }
        }
    }

}
