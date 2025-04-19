//Fun��o que altera a ordem dos elementos de um vetor de 30 posi��es. O primeiro elemento dever� ser o
//�ltimo, e assim por diante. Este vetor dever� ser preenchido com o uso de um la�o de repeti��o. Imprimir
//o vetor antes e depois da invers�o. Usar apenas uma vari�vel auxiliar para fazer a troca

#include<stdio.h>

int main(){
    int vetor[30], aux, N=10;

    printf("Digite %d termos para preencher o vetor: ",N);

    //inicializar o vetor
    for(int i=0;i<N;i++){
        scanf("%d",&vetor[i]);
    }

    //printar o vetor inicial
    for(int i=0;i<N;i++){
        printf("%d ",vetor[i]);
    }

    aux=vetor[0];

    //modificacoes no vetor
    for(int i=0;i<N/2;i++){
        aux = vetor[i];
        vetor[i] = vetor[N-1-i]; //coloca o "ultimo" no "primeiro"
        vetor[N-1-i] = aux; //bota esse "primeiro" no "ultimo"
    }

    printf("\n\n");
    //printar novo vetor
    for(int i=0;i<N;i++){
        printf("%d ",vetor[i]);
    }
}
