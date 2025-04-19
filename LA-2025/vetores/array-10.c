//Ler dois vetores A e B com C elementos cada e dizer quantos elementos de A são maiores que qualquer elemento de B.

#include<stdio.h>

int comparar(int A[], int B[], int C){
    int cont =0;
    for(int i=0;i<C;i++){
        int numA = A[i];
        for(int j=0;j<C;j++){
            if(A[i]>B[j]){
                cont++;
                break;
            }
        }

    }
    return cont;
}

int main(){
    int C;

    printf("Digite um tamanho para o vetor: ");
    scanf("%d", &C);

    int vA[C],vB[C];

    printf("Digite %d valores para o vetor A: ",C);

    //inciializando vetores
    for (int i=0;i<C;i++){
        scanf("%d",&vA[i]);
    }

    printf("Digite %d valores para o vetor B: ",C);

    //inciializando vetores
    for (int i=0;i<C;i++){
        scanf("%d",&vB[i]);
    }

    int resultado = comparar(vA, vB, C);
    printf("O vetor A tem %d elementos maiores que qualquer elemento de B", resultado);

}
